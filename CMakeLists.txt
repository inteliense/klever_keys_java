cmake_minimum_required(VERSION 3.21)
project(klever_keys)

set(CMAKE_C_STANDARD 90)
set(CMAKE_CXX_STANDARD 14)

##TODO fill in the paths below
#custom variables
set(CUSTOM_LIBRARY_PATH /opt/homebrew/opt) # /path/to/libraries/dir
set(OPENSSL_PATH /usr/local/) # /path/to/library/dir
set(BOOST_PATH /opt/homebrew/opt/boost@1.78) # /path/to/library/dir
set(JAVA_PATH /opt/homebrew/opt/openjdk@11) # /path/to/library/dir

set(JAVA_INCLUDE_PATH ${JAVA_PATH})
set(JAVA_INCLUDE_PATH2 ${JAVA_PATH})
set(JAVA_AWT_INCLUDE_PATH ${JAVA_PATH})
set(OPENSSL_LIBRARY_PATH ${OPENSSL_PATH}/lib)
set(OPENSSL_HEADERS_PATH ${OPENSSL_PATH}/include)
set(BOOST_LIBRARY_PATH ${BOOST_PATH}/lib)
set(BOOST_HEADERS_PATH ${BOOST_PATH}/include)
set(JAVA_LIBRARY_PATH ${JAVA_PATH}/libexec)
set(JAVA_HEADERS_PATH ${JAVA_PATH}/include)
set(INSTALL_PATH_LIB ${INSTALL_PARENT_DIR}/lib)
set(INSTALL_PATH_HEADERS ${INSTALL_PARENT_DIR}/include)

set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} ${CUSTOM_LIBRARY_PATH})
set(CMAKE_JAVA_COMPILE_FLAGS "-source" "1.8" "-target" "1.8")
link_directories(${OPENSSL_LIBRARY_PATH} ${BOOST_LIBRARY_PATH})
include_directories(${OPENSSL_HEADERS_PATH} ${BOOST_HEADERS_PATH} ${JAVA_HEADERS_PATH})

find_library(OpenSSL openssl
        PATHS ${OPENSSL_PATH})
find_library(Crypto crypto
        PATHS ${OPENSSL_PATH})
find_library(Boost boost
        PATHS ${BOOST_PATH})

find_package (Java REQUIRED)
find_package (JNI REQUIRED)
include (UseJava)

add_library(klever_keys SHARED cpp/HideString.h cpp/KleverKeys.h cpp/KleverKeys.cpp
        cpp/easy_encrypt/EasyEncrypt.cpp cpp/easy_encrypt/EasyEncrypt.h
        cpp/easy_encrypt/Base64.h klever_keys.c include/klever_keys.h cpp_klever_keys.cpp jni_klever_keys.c)
target_link_libraries(klever_keys ssl crypto)

set_target_properties(klever_keys PROPERTIES PREFIX "")

#TODO uncomment following line after first build
#add_jar(kleverkeys KleverKeys.java RESOURCES NAMESPACE com/inteliense/kleverkeys klever_keys.dylib)