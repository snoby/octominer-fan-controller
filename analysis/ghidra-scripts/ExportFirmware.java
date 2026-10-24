// Export genuine Ghidra decompiler output, function/call index and native project.
// @category Octominer
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.app.util.exporter.GzfExporter;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import java.nio.file.*;
import java.io.*;
import java.util.*;

public class ExportFirmware extends GhidraScript {
    public void run() throws Exception {
        Path out=Paths.get(getScriptArgs()[0]);Files.createDirectories(out);Files.createDirectories(out.resolve("functions"));
        try(DirectoryStream<Path> stale=Files.newDirectoryStream(out.resolve("functions"),"*.c")){for(Path p:stale)Files.delete(p);}
        DecompInterface decomp=new DecompInterface();
        DecompileOptions options=new DecompileOptions();options.grabFromProgram(currentProgram);decomp.setOptions(options);
        decomp.toggleCCode(true);decomp.toggleSyntaxTree(true);decomp.setSimplificationStyle("decompile");
        if(!decomp.openProgram(currentProgram))throw new Exception(decomp.getLastMessage());
        int total=0,ok=0,fail=0;
        try(PrintWriter index=new PrintWriter(out.resolve("functions.tsv").toFile());
            PrintWriter all=new PrintWriter(out.resolve("firmware-3.0-ghidra.c").toFile());
            PrintWriter calls=new PrintWriter(out.resolve("calls.tsv").toFile());
            PrintWriter asm=new PrintWriter(out.resolve("ghidra-listing.tsv").toFile())){
            all.println("/* MACHINE-GENERATED GHIDRA PSEUDOCODE, NOT ORIGINAL OR BUILDABLE SOURCE. */");
            all.println("/* FW3.0 SHA256186930d0fe8e4caa6fa2873e151225df6c7d1a6f6c4811a82601b113f65c6ddf */");
            all.println("/* AVR code labels use WORD addresses. Every section below also states BYTE address. */");
            index.println("byte_address\tghidra_word_address\tname\tbody_bytes\tdecompiled\terror");
            calls.println("caller_byte\tcaller_name\tcallee_byte\tcallee_name");
            asm.println("byte_address\tword_address\tlength_bytes\tinstruction");
            InstructionIterator instructions=currentProgram.getListing().getInstructions(true);
            while(instructions.hasNext()){
                Instruction i=instructions.next();Address a=i.getAddress();
                if(a.getAddressSpace().equals(currentProgram.getAddressFactory().getDefaultAddressSpace()))asm.printf("0x%04x\t%s\t%d\t%s%n",a.getOffset(),a,i.getLength(),i.toString());
            }
            FunctionIterator funcs=currentProgram.getFunctionManager().getFunctions(true);
            while(funcs.hasNext()&&!monitor.isCancelled()){
                Function f=funcs.next();if(f.isExternal())continue;total++;
                DecompileResults res=decomp.decompileFunction(f,90,monitor);
                boolean success=res.decompileCompleted()&&res.getDecompiledFunction()!=null;
                String err=res.getErrorMessage()==null?"":res.getErrorMessage().replace('\t',' ').replace('\n',' ');
                index.printf("0x%04x\t%s\t%s\t%d\t%s\t%s%n",f.getEntryPoint().getOffset(),f.getEntryPoint(),f.getName(),f.getBody().getNumAddresses(),success,err);
                for(Function called:f.getCalledFunctions(monitor))calls.printf("0x%04x\t%s\t0x%04x\t%s%n",f.getEntryPoint().getOffset(),f.getName(),called.getEntryPoint().getOffset(),called.getName());
                if(success){ok++;String text=res.getDecompiledFunction().getC();String hdr=String.format("/* BYTE0x%04x; WORD%s; %s */%n",f.getEntryPoint().getOffset(),f.getEntryPoint(),f.getName());all.print(hdr);all.println(text);Files.writeString(out.resolve("functions").resolve(String.format("byte_%04x_%s.c",f.getEntryPoint().getOffset(),f.getName().replaceAll("[^A-Za-z0-9_]","_"))),hdr+text);}
                else{fail++;all.printf("/* DECOMPILATION FAILED BYTE0x%04x %s: %s */%n",f.getEntryPoint().getOffset(),f.getName(),err);}
            }
        }finally{decomp.dispose();}
        GzfExporter exporter=new GzfExporter();boolean exported=exporter.export(out.resolve("octominer-fw3.0.gzf").toFile(),currentProgram,null,monitor);
        Files.writeString(out.resolve("run-summary.txt"),"Ghidra="+ghidra.framework.Application.getApplicationVersion()+"\nLanguage="+currentProgram.getLanguageID()+"\nFunction entries="+total+"\nDecompiled="+ok+"\nFailed="+fail+"\nGZF exported="+exported+"\nCode address unit="+currentProgram.getAddressFactory().getDefaultAddressSpace().getAddressableUnitSize()+"\n");
        println("EXPORT: functions="+total+" decompiled="+ok+" failed="+fail+" nativeProject="+exported);
    }
}
