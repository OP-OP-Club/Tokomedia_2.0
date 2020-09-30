#ifndef DESCRIPTION_CONVERTER_TOOLS_PARAM
#define DESCRIPTION_CONVERTER_TOOLS_PARAM 1

#include "cursorTools.h"
#include "timeTools.h"
#include "hasherTools.h"

char* descriptionConvert(char* desc, int max_len);
int Atoi(char* num);

char* descriptionConvert(char* desc, int max_len){

    char converted_description[2000] = {0};

    char before_convert[2000];
    sprintf(before_convert, "%s", desc);

    int index = 0;
    int desc_len = strlen(before_convert);
    int counter = 0;
    for(int i = 0; i < desc_len; i++){
        if(counter == max_len){
            if(before_convert[i] == '\n'){
                converted_description[index] = '\n';
                counter = 0;
            }
            else{
                converted_description[index] = '\n';
                index++;
                converted_description[index] += before_convert[i];
                counter = 1;
            }
        }
        else if(before_convert[i] == '\n'){
            converted_description[index] = '\n';
            counter = 0;
        }
        else{
            converted_description[index] = before_convert[i];
            counter++;
        }
        index++;
    }

    converted_description[index] = '\0';
    char *final_convert_desc = converted_description;

    return final_convert_desc;
}

int Atoi(char* num){
    char temp[100];
    sprintf(temp, "%s", num);

    int id = 0;
    int expo = 1;

    int temp_len = strlen(temp);
    for(int i = temp_len - 1; i >= 0; i--){
        id = (temp[i] - '0') * expo;
        expo *= 10;
    }

    return id;
}

#endif // DESCRIPTION_CONVERTER_TOOLS_PARAM
