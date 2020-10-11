#ifndef DISPLAY_MAIN_PARAM
#define DISPLAY_MAIN_PARAM 1

#include"displayTokomedia.h"
#include"displayEmail.h"

#define STAGE4 219
#define STAGE3 178
#define STAGE2 177
#define STAGE1 176
#define LARGE_DOT 254
#define CORNER1 201
#define CORNER2 187
#define CORNER3 200
#define CORNER4 188
#define HORIZON_LINE 205
#define VERTICAL_LINE 186
#define KEY_UP 72  //arrow keys
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_BACKSPACE 8

void GlobalMainMenu();

void GlobalMainMenu(){

    char tokomedia_main_menu_option[4][100] = {
        "        Gmail              ",
        "        Tokomedia          ",
        "        Banking            ",
        "        Exit               ",
    };
    int tokomedia_option_available = 4;

    int option_now = symbol_height + 2;
    int option_min = 9;
    int option_max = option_min + (tokomedia_option_available - 1) * 2;

    int arrow_x_left = 18;
    int arrow_x_right = 37;

    SetCursorVisible(false);

//    #ifndef ONLY_ONCE_TOKOMEDIA_SYMBOL
//    #define ONLY_ONCE_TOKOMEDIA_SYMBOL
//        int len_x = strlen(TokomediaSymbol[0]);
//
//        for(int i = 0; i < 15; i++){
//            for(int j = 0; j < len_x; j++){
//                if(TokomediaSymbol[i][j] == '1'){
//                    TokomediaSymbol[i][j] = char(STAGE4);
//                }
//                else if(TokomediaSymbol[i][j] == '2'){
//                    TokomediaSymbol[i][j] = char(HORIZON_LINE);
//                }
//                else if(TokomediaSymbol[i][j] == '0'){
//                    TokomediaSymbol[i][j] = ' ';
//                }
//            }
//        }
//    #endif

//    PrintTokomediaHeader();



    int temp_opt = 0;
    for(int i = 9; i <= 9 + (tokomedia_option_available - 1) * 2; i += 2){
        SetCursorPosition(arrow_x_left -2,i);
        printf("%s", tokomedia_main_menu_option[temp_opt]);
        temp_opt++;
    }

    SetCursorPosition(arrow_x_left, option_now);
    printf(">>");
    SetCursorPosition(arrow_x_right, option_now);
    printf("<<");

    while(1){

        SetCursorPosition(0,7);
        printf("%s", GetTimeNow());

        if(kbhit()){
            char c = getch();

            if(c == KEY_UP){
                if(option_now != option_min){
                    SetCursorPosition(arrow_x_left, option_now);
                    printf("  ");
                    SetCursorPosition(arrow_x_right, option_now);
                    printf("  ");

                    option_now -= 2;

                    SetCursorPosition(arrow_x_left, option_now);
                    printf(">>");
                    SetCursorPosition(arrow_x_right, option_now);
                    printf("<<");
                }
            }
            else if(c == KEY_DOWN){
                if(option_now != option_max){
                    SetCursorPosition(arrow_x_left, option_now);
                    printf("  ");
                    SetCursorPosition(arrow_x_right, option_now);
                    printf("  ");

                    option_now += 2;

                    SetCursorPosition(arrow_x_left, option_now);
                    printf(">>");
                    SetCursorPosition(arrow_x_right, option_now);
                    printf("<<");
                }
            }
            else if(c == KEY_ENTER){
                if(option_now == 9){
                    EmailMainMenu();
                    GlobalMainMenu();
                }
                else if(option_now == 11){
                    TokomediaMainMenu();
                    GlobalMainMenu();
                }
                else if(option_now == 13){
                    printf("3\n");
                }
            }

        }

    }

}


#endif // DISPLAY_MAIN_PARAM
