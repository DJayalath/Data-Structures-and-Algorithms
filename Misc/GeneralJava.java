package Misc;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;

public class GeneralJava {
    public static void main(String[] args) throws Exception {

        // 1. Get file ready with File class
        // 2. Setup stream
        // 3. Read or write
        // 4. Close stream

        // File output
        File f = new File("out.txt");
        OutputStream out = new FileOutputStream(f);
        String str = "hello there";
        out.write(str.getBytes());
        out.close();

        // File input
        File fin = new File("input.txt");
        InputStream in = new FileInputStream(fin);
        byte b[] = new byte[1024];
        int length = in.read(b);
        in.close();
    }
}