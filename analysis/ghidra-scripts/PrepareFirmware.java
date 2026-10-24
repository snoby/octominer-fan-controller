// Correct generic AVR8 defaults for this ATmega324PB image before analysis.
// @category Octominer
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.data.*;
import java.nio.file.*;
import java.util.*;

public class PrepareFirmware extends GhidraScript {
    public void run() throws Exception {
        String[] args=getScriptArgs();
        Path config=Paths.get(args[0]);
        AddressSpace code=currentProgram.getAddressFactory().getDefaultAddressSpace();
        AddressSpace mem=currentProgram.getAddressFactory().getAddressSpace("mem");
        println("CODE address unit="+code.getAddressableUnitSize()+"; byte438 -> "+code.getAddress(0x438));
        if(code.getAddressableUnitSize()!=2)throw new Exception("Expected AVR word-addressed code");
        Memory memory=currentProgram.getMemory();
        SymbolTable symbols=currentProgram.getSymbolTable();
        // Generic pspec describes ATmega64, with wrong vector and peripheral labels.
        ArrayList<Symbol> remove=new ArrayList<>();
        SymbolIterator syms=symbols.getAllSymbols(true);
        while(syms.hasNext()){
            Symbol s=syms.next();Address a=s.getAddress();
            if((a.getAddressSpace().equals(mem)&&a.getOffset()>=0x20&&a.getOffset()<0x100)||
                (a.getAddressSpace().equals(code)&&a.getOffset()<0xcc))remove.add(s);
        }
        for(Symbol s:remove){symbols.removeExternalEntryPoint(s.getAddress());s.delete();}
        MemoryBlock ram=memory.getBlock(mem.getAddress(0x100));
        if(ram!=null&&ram.getStart().getOffset()==0x100)memory.removeBlock(ram,monitor);
        MemoryBlock sram=memory.createUninitializedBlock("ATmega324PB_SRAM",mem.getAddress(0x100),0x800,false);
        sram.setRead(true);sram.setWrite(true);sram.setExecute(false);
        if(memory.getBlock(mem.getAddress(0xf0))==null){MemoryBlock x=memory.createUninitializedBlock("IO_tail",mem.getAddress(0xf0),0x10,false);x.setVolatile(true);}
        MemoryBlock io=memory.getBlock(mem.getAddress(0x20));if(io!=null)io.setVolatile(true);
        HashSet<Long> primary=new HashSet<>();
        for(String row:Files.readAllLines(config.resolve("registers.tsv"))){
            String[] c=row.split("\t");long off=Long.parseLong(c[0],16);Address a=mem.getAddress(off);
            if(!primary.contains(off)){
                createLabel(a,c[1],true,SourceType.USER_DEFINED);primary.add(off);
                try{if(c[2].equals("16"))createWord(a);else createByte(a);}catch(Exception e){println("Register data note "+c[1]+": "+e.getMessage());}
            }else createLabel(a,c[1],false,SourceType.USER_DEFINED);
        }
        HashSet<Long> handlerStarts=new HashSet<>();
        for(String row:Files.readAllLines(config.resolve("vectors.tsv"))){
            String[] c=row.split("\t");long off=Long.parseLong(c[0],16),target=Long.parseLong(c[1],16);
            Address vector=code.getAddress(off),dest=code.getAddress(target);
            createLabel(vector,"vector_"+c[2],true,SourceType.USER_DEFINED);symbols.addExternalEntryPoint(vector);
            disassemble(vector);
            if(handlerStarts.add(target)){
                disassemble(dest);
                String name=target==0x472?"default_interrupt":(off==0?"reset_startup":"isr_"+c[2]);
                Function f=getFunctionAt(dest);if(f==null)f=createFunction(dest,name);else f.setName(name,SourceType.USER_DEFINED);
                symbols.addExternalEntryPoint(dest);
            }
        }
        Address boot=code.getAddress(0x7000);createLabel(boot,"bootloader_entry",true,SourceType.USER_DEFINED);symbols.addExternalEntryPoint(boot);disassemble(boot);
        Address bootStart=code.getAddress(0x713e);disassemble(bootStart);if(getFunctionAt(bootStart)==null)createFunction(bootStart,"bootloader_runtime_startup");
        createLabel(code.getAddress(0x23fc),"usb_get_version_block",true,SourceType.USER_DEFINED);
        setPlateComment(code.getAddress(0),"ACTUAL installed FW3.0 read twice from cmp-100. SHA256186930d0fe8e4caa6fa2873e151225df6c7d1a6f6c4811a82601b113f65c6ddf. Code display addresses are WORDS; exported index uses BYTE offsets. Register labels corrected from AVR-libc iom324pb.h. Inferred function names are NOT original symbols.");
        println("Prepared ATmega324PB register labels and51vector entries; removed "+remove.size()+" generic symbols.");
    }
}
