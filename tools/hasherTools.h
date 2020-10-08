#ifndef HASHER_TOOLS_PARAM
#define HASHER_TOOLS_PARAM 1
#include"sha256.h"
#include"../env.h"

#include "cursorTools.h"
#include "timeTools.h"
#include "descriptionConverter.h"
#include "generator.h"
#include<string>

char* sha256Hashing(char* word);
bool HasherCompare(char* pass, char* hashedPassword);
char* ToLower(char* word);

char* sha256Hashing(char* word){
    srand(time(0));
    char arr[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    int index = rand() % 52;

    Environment env;
    SHA256 sha256;

    char temp_string[500];
    sprintf(temp_string, "%c%s%s", arr[index], word, env.UserGetSalt());

    char *before_hashed = temp_string;

    return strdup(sha256(before_hashed).c_str());
}

bool HasherCompare(char* pass, char* hashedPassword){
    SHA256 sha256;
    char arr[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    Environment env;

    bool flag = false;
    for(int i = 0; i < 53; i++){
        char temp_pass[500];
        sprintf(temp_pass, "%c%s%s", arr[i], pass, env.UserGetSalt());
        std::string s(temp_pass);

        char* temp = strdup(sha256(s).c_str());

        if(strcmp(temp, hashedPassword) == 0){
            flag = true;
            break;
        }
    }

    return flag;
}

char* ToLower(char* word) {
    char temp_string[500];
    strcpy(temp_string, word);

    int temp_string_len = strlen(temp_string);
    for(int i = 0; i < temp_string_len; i++){
        if(temp_string[i] >= 'A' && temp_string[i] <= 'Z'){
            temp_string[i] += 32;
        }
    }

    char *return_word = temp_string;
    return strdup(return_word);
}

#endif // TOOLS_PARAM

