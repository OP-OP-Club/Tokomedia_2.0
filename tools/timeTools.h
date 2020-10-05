#ifndef TIME_TOOLS_PARAM
#define TIME_TOOLS_PARAM 1
#include<iostream>
#include<time.h>
#include<string>

#include "hasherTools.h"
#include "descriptionConverter.h"
#include "cursorTools.h"

char* GetTimeNow();
char* GetTimeZero();

char* GetTimeNow(){
//    time_t current_time;
//    time(&current_time);
//    return ctime(&current_time);
    time_t now = time(0);
    tm *ltm = localtime(&now);

    char temp_time[500];
    sprintf(temp_time, "%d-%02d-%02d %02d:%02d:%02d", (ltm->tm_year + 1900), (ltm->tm_mon), (ltm->tm_mday), (ltm->tm_hour), (ltm->tm_min), (ltm->tm_sec));

//    string temp = to_string(ltm->tm_year + 1900) + "-" + to_string(ltm->tm_mon) + "-" + to_string(ltm->tm_mday) + " " + to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);

    char *time_now = temp_time;
    return strdup(time_now);
}

char* GetTimeZero(){
    char *zero_time = "0000-00-00 00:00:00";
    return zero_time;
}

#endif // TIME_TOOLS_PARAM
