// Export the saved domain file after analysis transactions have completed.
// @category Octominer
import ghidra.app.script.GhidraScript;
import ghidra.app.util.exporter.GzfExporter;
import java.nio.file.*;
public class ExportSaved extends GhidraScript {
    public void run() throws Exception {
        Path out=Paths.get(getScriptArgs()[0]);
        byte[] image=new byte[32768];
        int n=currentProgram.getMemory().getBytes(currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(0),image);
        String hash=java.util.HexFormat.of().formatHex(java.security.MessageDigest.getInstance("SHA-256").digest(image));
        if(n!=32768||!hash.equals("186930d0fe8e4caa6fa2873e151225df6c7d1a6f6c4811a82601b113f65c6ddf"))throw new Exception("Project flash bytes differ from captured image");
        Files.writeString(out.resolve("native-image-sha256.txt"),hash+"  32768bytes; Ghidra project flash memory verified against actual capture\n");
        GzfExporter exporter=new GzfExporter();
        boolean ok=exporter.export(out.resolve("octominer-fw3.0.gzf").toFile(),currentProgram.getDomainFile(),monitor);
        println("SAVED_NATIVE_EXPORT="+ok+" "+exporter.getMessageLog());
        if(!ok)throw new Exception("Native export failed");
        Path summary=out.resolve("run-summary.txt");
        String text=Files.readString(summary).replace("GZF exported=false","GZF exported=true");Files.writeString(summary,text);
    }
}
