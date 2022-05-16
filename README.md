# klever_keys_java

The purpose for this library is to have secure system keys and initialization vectors for various encryption methods (ex: AES). While unique IVs are standard, if you need CBC encryption with an IV or set of IVs that are obscured within the code - this is a good go to.

By using the HideString header file, the key and iv strings are hidden in the binary code, thus keeping attackers from taking and using your keys.

Use the Java application (.jar file) included to create a new class and header file with a matching reference file for your use with your applications.

Execute the jar by executing the following command in the terminal or command prompt (Windows, Linux, and macOS):

java -jar kleverkeys-generator.jar

Then follow the prompts (# of keys & ivs, class name, and path) to create the 3 files automatically.

To effectively prevent someone from getting the keys by copying the library, the class file's get function default return value is a random hex value. This will make any brute force attempts impossible.

The id strings in the get function of the class can be seen in the binary code, however, they are 32 bytes in order for them to look like a 256 bit key or other string. The get function also requires a SHA hash of the id when finding a matching key in order to verify the ID appropriately.

The cpp folder contains the C++ encryption classes, as well as the generated keys files and the HideString header. The cpp_klever_keys.cpp file bridges the C++ code into C code while the jni_klever_keys.c then wraps the C code into a java library. This library requires two consecutive builds. One build to generate the C shared library and the next to place that shared library into a jar file alongside the KleverKeys Java class. While the C and C++ code are a shared library, it is not in a standard location and is compressed within the .jar file.

Prior to building, edit the CMake variables first.

To build the C shared library create a build directory (`mkdir build`), navigate into it, and build using CMake.

```
cd build
cmake ../
cmake --build .
```

<b>You need to do the same process one more time after uncommenting the last `add_jar` line in CMakeLists.txt</b>

You can then add the generated .jar file into a module.

To use in Java:

```
import com.inteliense.kleverkeys.*;

...

String hexKey = KleverKeys.get("<THE GENERATED ID FROM REF. FILE>");

```
