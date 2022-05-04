package com.inteliense.kleverkeys;

import java.io.*;
import java.net.URL;
import java.util.Locale;

public class KleverKeys {

    public static String get(String id) {

        return c_get_key(id);

    }

    static {
        try {
            System.load(copyFile());
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

            return ExportResource("tmpfile.dylib", "klever_keys.dylib");

        } catch (Exception ex) {
            ex.printStackTrace();
        }

        return null;

    }

    private static native String c_get_key(String id);

}