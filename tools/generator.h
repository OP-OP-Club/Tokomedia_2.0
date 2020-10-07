#ifndef GENERATOR_TOOLS_PARAM
#define GENERATOR_TOOLS_PARAM 1

#include "cursorTools.h"
#include "hasherTools.h"
#include "timeTools.h"
#include "descriptionConverter.h"

char* ToolsSecurityCodeGenerator(){
    char temp[7];

    char list_number[11] = "0123456789";

    for(int i = 0; i < 6; i++){
        temp[i] = list_number[rand() % 10];
    }

    temp[6] = '\0';

    char *result = temp;

    return strdup(result);
}

#endif // GENERATOR_TOOLS_PARAM
