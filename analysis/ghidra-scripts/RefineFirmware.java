// Annotate verified roles and repair compiler jump-table reachability.
// @category Octominer
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.data.*;
import java.nio.file.*;
import java.util.*;

public class RefineFirmware extends GhidraScript {
    public void run() throws Exception {
        AddressSpace code=currentProgram.getAddressFactory().getDefaultAddressSpace();
        String[][] names={{"438","reset_startup"},{"472","unexpected_interrupt_reset"},{"722","usb_poll"},{"1710","gpio_input_init"},{"177c","pwm_timer_init_from_eeprom"},{"2056","application_main"},{"2352","usb_setup_dispatch"},{"37c6","gcc_tablejump_helper"},{"3880","eeprom_read_byte"},{"3890","eeprom_read_word"},{"7000","bootloader_entry"},{"713e","bootloader_runtime_startup"},{"741a","bootloader_isp_command"},{"74b6","bootloader_usb_main"},{"90c","twi_init"},{"91e","twi_start_address_bounded"},{"966","twi_stop"},{"96e","twi_send_byte_bounded"},{"9ea","oled_send_commands"},{"a2e","oled_send_pixel_data"},{"a6e","oled_set_text_cursor"},{"ab8","oled_reset_cursor"},{"af2","oled_clear"},{"b56","oled_init_ssd1306_family"},{"bae","oled_set_inverse"},{"be2","oled_set_enabled"},{"c16","oled_set_contrast"},{"c3a","oled_render_character"},{"ef6","oled_set_scale"},{"efc","oled_print_ram_string"},{"f14","oled_print_flash_string"},{"183e","twi_read_length_prefixed_block"},{"197c","twi_write_read_transaction"},{"1a80","startup_display_and_eeprom_text"},{"1c10","bme280_discovery_and_calibration"},{"3712","avr_multiply_32bit"},{"3732","avr_unsigned_divide_16bit"},{"375a","avr_signed_divide_16bit"},{"3782","avr_unsigned_divide_32bit"},{"3816","integer_to_string"},{"389c","eeprom_update_byte"},{"38c0","eeprom_update_word"},{"38cc","eeprom_write_word"},{"38f6","eeprom_write_byte"},{"3912","terminal_exit_loop"}};
        for(String[] row:names){
            Address a=code.getAddress(Long.parseLong(row[0],16));Function f=getFunctionAt(a);
            if(f!=null)f.setName(row[1],SourceType.USER_DEFINED);
        }
        Function helper=getFunctionAt(code.getAddress(0x37c6));helper.setInline(true);
        // The four GCC lookup tables are verified directly from flash bytes.
        for(String row:Files.readAllLines(Paths.get(getScriptArgs()[0],"jump-tables.tsv"))){
            String[] c=row.split("\t");Address target=code.getAddress(Long.parseLong(c[1],16));
            createLabel(target,"case_"+c[2],false,SourceType.USER_DEFINED);disassemble(target);
        }
        Function dispatch=getFunctionAt(code.getAddress(0x2352));
        dispatch.setBody(new AddressSet(code.getAddress(0x2352),code.getAddress(0x3711)));
        StructureDataType setup=new StructureDataType("UsbSetupPacket",0);
        setup.add(ByteDataType.dataType,"bmRequestType",null);setup.add(ByteDataType.dataType,"bRequest",null);
        setup.add(UnsignedShortDataType.dataType,"wValue",null);setup.add(UnsignedShortDataType.dataType,"wIndex",null);setup.add(UnsignedShortDataType.dataType,"wLength",null);
        DataType st=currentProgram.getDataTypeManager().addDataType(setup,DataTypeConflictHandler.REPLACE_HANDLER);
        Parameter arg=new ParameterImpl("setup",new PointerDataType(st),new VariableStorage(currentProgram,currentProgram.getRegister("R25R24")),currentProgram);
        ReturnParameterImpl ret=new ReturnParameterImpl(ByteDataType.dataType,new VariableStorage(currentProgram,currentProgram.getRegister("R24")),currentProgram);
        dispatch.updateFunction("__stdcall",ret,Function.FunctionUpdateType.CUSTOM_STORAGE,true,SourceType.USER_DEFINED,arg);
        Function eeread=getFunctionAt(code.getAddress(0x3880));
        Parameter eeArg=new ParameterImpl("eeprom_address",UnsignedShortDataType.dataType,new VariableStorage(currentProgram,currentProgram.getRegister("R25R24")),currentProgram);
        eeread.updateFunction("__stdcall",ret,Function.FunctionUpdateType.CUSTOM_STORAGE,true,SourceType.USER_DEFINED,eeArg);
        Function eeword=getFunctionAt(code.getAddress(0x3890));
        ReturnParameterImpl retWord=new ReturnParameterImpl(UnsignedShortDataType.dataType,new VariableStorage(currentProgram,currentProgram.getRegister("R25R24")),currentProgram);
        eeword.updateFunction("__stdcall",retWord,Function.FunctionUpdateType.CUSTOM_STORAGE,true,SourceType.USER_DEFINED,eeArg);
        setPlateComment(code.getAddress(0x37c6),"GCC tablejump helper. Marked inline so each caller's flash-table base is visible. Actual12entry tables at BYTEcc/e4/fc/114; targets WORD-addressed. Verify generated switch output against source bytes.");
        AddressSpace mem=currentProgram.getAddressFactory().getAddressSpace("mem");
        String[][] globals={{"353","usb_reply_buffer","1","256"},{"483","calibration_ticks_remaining","1","1"},{"484","host_elapsed_ticks","2","1"},{"486","dangerous_command_counter","1","1"},{"487","led_modes","1","4"},{"4a9","usb_reply_pointer","2","1"},{"4ce","host_watchdog_mode","1","1"},{"4d9","temperature_samples","2","4"},{"4e1","tach_edge_counts","2","18"},{"505","voltage_samples","2","4"},{"52f","tach_results","2","18"},{"55d","extra_recovery_attempts","1","1"},{"55e","host_watchdog_threshold","2","1"},{"56c","signature_serial_bytes","1","10"},{"59a","host_watchdog_retry_stage","1","1"}};
        for(String[] row:globals){
            Address a=mem.getAddress(Long.parseLong(row[0],16));int width=Integer.parseInt(row[2]),count=Integer.parseInt(row[3]);
            // Only label large shared reply storage: it overlaps other persistent state
            // after its actual short responses; do not assign a256-byte data type there.
            createLabel(a,row[1],true,SourceType.USER_DEFINED);
            if(row[1].equals("usb_reply_buffer"))continue;
            DataType base=width==1?ByteDataType.dataType:UnsignedShortDataType.dataType;
            DataType type=count==1?base:new ArrayDataType(base,count,width);
            clearListing(a,a.add(width*count-1));createData(a,type);
        }
        analyzeAll(currentProgram);
        println("Verified role labels, explicit EEPROM/USB ABI and jump-table targets applied.");
    }
}
