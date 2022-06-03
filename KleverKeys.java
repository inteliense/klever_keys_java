package com.inteliense.kleverkeys;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.Random;

public class KleverKeys {

    public static String get(String id) {

        return c_get_key(id);

    }

    static {
        try {
            String filepath = copyFile();
            System.load(filepath);
            File f = new File(filepath);
            f.delete();

        } catch (Exception e) {
            e.printStackTrace();
            throw new UnsatisfiedLinkError("Couldn't load the klever_keys library.");
        }
    }

    private static String ExportResource(String filename, String resourcePath) throws Exception {
        InputStream stream = null;
        OutputStream resStreamOut = null;
        String jarFolder;
        try {
            stream = KleverKeys.class.getResourceAsStream(resourcePath);//note that each / is a directory down in the "jar tree" been the jar the root of the tree
            if(stream == null) {
                throw new Exception("Cannot get resource \"" + resourcePath + "\" from Jar file.");
            }

            int readBytes;
            byte[] buffer = new byte[4096];
            jarFolder = new File(com.inteliense.kleverkeys.KleverKeys.class.getProtectionDomain().getCodeSource().getLocation().toURI().getPath()).getParentFile().getPath().replace('\\', '/');
            File file = new File(jarFolder + "/" + filename);
            file.createNewFile();
            resStreamOut = new FileOutputStream(file);
            while ((readBytes = stream.read(buffer)) > 0) {
                resStreamOut.write(buffer, 0, readBytes);
            }
        } catch (Exception ex) {
            ex.printStackTrace();
            throw ex;
        }

        return jarFolder + "/" + filename;
    }

    private static String copyFile() {

        try {

            return ExportResource(generateStr() + ".so", "klever_keys.so");

        } catch (Exception ex) {
            ex.printStackTrace();
        }

        return null;

    }

    private static String generateStr() {
        int leftLimit = 48;
        int rightLimit = 122; 
        int targetStringLength = 10;
        Random random = new Random();

        String generatedString = random.ints(leftLimit, rightLimit + 1)
                .filter(i -> (i <= 57 || i >= 65) && (i <= 90 || i >= 97))
                .limit(targetStringLength)
                .collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append)
                .toString();

        return generatedString;

    }

    private static native String c_get_key(String id);

}
