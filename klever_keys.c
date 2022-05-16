//
// Created by ryanfitzgerald on 5/3/22.
//

#include "include/klever_keys.h"
#include <stdlib.h>

void get_key_c(const char*, char*);

char* get_key(const char* input) {

    char* res = (char*) malloc(65);
    get_key_c(input, res);

    return res;

}
