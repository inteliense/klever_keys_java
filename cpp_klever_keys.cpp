//
// Created by ryanfitzgerald on 5/3/22.
//
#include "cpp/KleverKeys.h"

extern "C" void get_key_c(const char* input, char* output) {

    std::string result = KleverKeys::get(input);
    strcpy(output, result.c_str());

}
