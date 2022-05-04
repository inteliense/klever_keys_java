//
// Created by ryanfitzgerald on 5/3/22.
//

#include <jni.h>

#include "include/klever_keys.h"

static const char *JNIT_CLASS = "com/inteliense/kleverkeys/KleverKeys";

static jstring c_get_key(JNIEnv *env, jobject obj, jstring id) {

    const char *input_str;
    const char *output_str;

    input_str  = (*env)->GetStringUTFChars(env, id, 0);
    output_str = get_key((const char*) input_str);
    (*env)->ReleaseStringUTFChars(env, id, input_str);

    return (*env)->NewStringUTF(env, output_str);

}

static JNINativeMethod funcs[] = {
        { "c_get_key", "(Ljava/lang/String;)Ljava/lang/String;", (void *)&c_get_key }
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved)
{
    JNIEnv *env;
    jclass  cls;
    jint    res;

    (void)reserved;

    if ((*vm)->GetEnv(vm, (void **)&env, JNI_VERSION_1_8) != JNI_OK)
        return -1;

    cls = (*env)->FindClass(env, JNIT_CLASS);
    if (cls == NULL)
        return -1;

    res = (*env)->RegisterNatives(env, cls, funcs, sizeof(funcs)/sizeof(*funcs));
    if (res != 0)
        return -1;

    return JNI_VERSION_1_8;

}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved)
{
    JNIEnv *env;
    jclass  cls;

    (void)reserved;

    if ((*vm)->GetEnv(vm, (void **)&env, JNI_VERSION_1_8) != JNI_OK)
        return;

    cls = (*env)->FindClass(env, JNIT_CLASS);
    if (cls == NULL)
        return;

    (*env)->UnregisterNatives(env, cls);

}
