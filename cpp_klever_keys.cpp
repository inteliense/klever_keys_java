//
// Created by ryanfitzgerald on 5/3/22.
//
#include "cpp/KleverKeys.h"

extern "C" void get_key_c(const char* input, char* output) {

    std::string result = KleverKeys::get(input);
    printf("%s\n",result.c_str());
    //output = (char*) malloc(65);
    strcpy(output, result.c_str());
    //output[64] = '\0';
    printf("%s\n", output);

}