#ifndef DISPLAY_TOKOMEDIA_PARAM
#define DISPLAY_TOKOMEDIA_PARAM 1

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

void TokomediaMainMenu();
void TokomediaUserMainMenu();
void TokomediaUserLoginMenu();
void TokomediaUserRegisterMenu();

void PrintTokomediaHeader();

//Global Variable
struct TokomediaUserAccount *tokomedia_user_login_now = NULL;

char TokomediaSymbol[15][105] = {
"0011111111000000000000000111111000000000000000000000000000000000000000000000000000000000000000000000",//1
"0100111111001111101111100111100100000001111001111000111110000000000000000000000000000000000000000000",//2
"1000100111010000011110010100100100000110111110010101000001000000000000000000000000000000000000000000",//3
"1000011100100111001101101100100111000100111(001110)0010100100000000000000000000000000000000000000000",//4
"011111110011111100(111100111111111011011110011111111111100100000000000000000000000000000000000000000",//5
"0000000011000000110000011000000000011000001100000000000011000000000000000000000000000000000000000000",//6
"2222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222",//7
};
int symbol_height = 7;

void TokomediaMainMenu(){

    char tokomedia_main_menu_option[3][50] = {
        "User",
        "Shop",
        "Return",
    };
    int tokomedia_option_available = 3;

    int option_now = symbol_height + 2;
    int option_min = 9;
    int option_max = option_min + (tokomedia_option_available - 1) * 2;

    int arrow_x_left = 18;
    int arrow_x_right = 37;

    SetCursorVisible(false);

    #ifndef ONLY_ONCE_TOKOMEDIA_SYMBOL
    #define ONLY_ONCE_TOKOMEDIA_SYMBOL
        int len_x = strlen(TokomediaSymbol[0]);

        for(int i = 0; i < 15; i++){
            for(int j = 0; j < len_x; j++){
                if(TokomediaSymbol[i][j] == '1'){
                    TokomediaSymbol[i][j] = char(STAGE4);
                }
                else if(TokomediaSymbol[i][j] == '2'){
                    TokomediaSymbol[i][j] = char(HORIZON_LINE);
                }
                else if(TokomediaSymbol[i][j] == '0'){
                    TokomediaSymbol[i][j] = ' ';
                }
            }
        }
    #endif

    PrintTokomediaHeader();


    SetCursorPosition(arrow_x_left, option_now);
    printf(">>");
    SetCursorPosition(arrow_x_right, option_now);
    printf("<<");

    int temp_opt = 0;
    for(int i = 9; i <= 9 + (tokomedia_option_available - 1) * 2; i += 2){
        SetCursorPosition(arrow_x_left + 8,i);
        printf("%s", tokomedia_main_menu_option[temp_opt]);
        temp_opt++;
    }

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
                    TokomediaUserMainMenu();
                    break;
                }
                else if(option_now == 11){
                    printf("2\n");
//                    break;
                }
                else if(option_now == 13){
                    printf("3\n");
                }
            }

        }

    }

}

void TokomediaUserMainMenu(){

    char tokomedia_user_main_menu_option[4][50] = {
        "Login",
        "Register",
        "Forgot Password",
        "Return",
    };
    int tokomedia_user_option_available = 4;

    int option_now = symbol_height + 2;
    int option_min = 9;
    int option_max = option_min + (tokomedia_user_option_available - 1) * 2;

    int arrow_x_left = 18;
    int arrow_x_right = 45;

    SetCursorVisible(false);

    PrintTokomediaHeader();

    SetCursorPosition(arrow_x_left, option_now);
    printf(">>");
    SetCursorPosition(arrow_x_right, option_now);
    printf("<<");

    int temp_opt = 0;
    for(int i = 9; i <= 9 + (tokomedia_user_option_available - 1) * 2; i += 2){
        SetCursorPosition(arrow_x_left + 8,i);
        printf("%s", tokomedia_user_main_menu_option[temp_opt]);
        temp_opt++;
    }

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
                    printf("1\n");
                    TokomediaUserLoginMenu();
                    break;
                }
                else if(option_now == 11){
                    TokomediaUserRegisterMenu();
                    break;
                }
                else if(option_now == 13){
                    printf("1\n");
                    break;
                }
                else if(option_now == 15){
                    TokomediaMainMenu();
                    break;
                }
            }

        }

    }

}

void TokomediaUserLoginMenu() {
    PrintTokomediaHeader();

    char choices[2][50] = {
        "Enter Email",
        "Enter Password",
    };
    int choices_len = 2;

    char temp[255];
    int index = 0;
    int reset_x_default_position = 17;
    int default_position_x = 17;
    int default_position_y = 10;
    int inputan = 1;

    for(int i = 0; i < choices_len; i++){
        SetCursorPosition(0, 10 + i);
        printf("%s", choices[i]);
        SetCursorPosition(default_position_x - 2, 10 + i);
        printf(":");
    }

     while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        printf("%s\n", ctime(&tempTime));


        SetCursorVisible(true);
        SetCursorPosition(default_position_x,default_position_y);
        if(kbhit()){
            temp[index] = getch();
            if(temp[index] == 13){
		    	if(index == 0){
                    continue;
				}

                if(inputan == 1){
                    temp[index] = '\0';

//                    string s(temp);
                    char *s = temp;

                    if(strcasecmp(s, "0") == 0){
                        SetCursorPosition(0,14);
                        printf("  Aborting Operation");
                        getchar();
                        TokomediaMainMenu();
                        break;
                    }
                    struct TokomediaUserAccount *head = ServiceGetTokomediaUserAccountAll();

                    int flag = 1;

                    while(head != NULL){
                        if(strcasecmp(s, head->email) == 0){
                            tokomedia_user_login_now = head;
                            flag = 0;
                            break;
                        }
                        head = head->next;
                    }

                    if(flag){
                        SetCursorPosition(0,default_position_y + 1 + choices_len);
                        printf("Email is Not Registered!!!\n");
                        printf("Press Any Key To Continue\n");
                        while(1){
                            if(kbhit()){
                                break;
                            }
                        }

                        default_position_x = reset_x_default_position;
                        index = 0;
                        SetCursorPosition(default_position_x, 10);
                        for(int i = 0; i < strlen(temp); i++) printf(" ");
                        SetCursorPosition(0, 13);
                        for(int i = 0; i < 30; i++) printf(" ");
                        SetCursorPosition(0, 14);
                        for(int i = 0; i < 30; i++) printf(" ");
                        continue;
                    }

                    inputan++;
                    default_position_y++;
                    default_position_x = reset_x_default_position;
                    index = 0;
                }
                else if(inputan == 2){
                    temp[index] = '\0';

                    char *s = temp;

                    if(HasherCompare(s, tokomedia_user_login_now->password)){
                        break;
                    }
                    else{
                        SetCursorPosition(0,13);
                        printf("Password Wrong !!!\n");
                        printf("Press Any Key To Continue\n");
                        while(1){
                            if(kbhit()){
                                break;
                            }
                        }
                        default_position_x = reset_x_default_position;
                        index = 0;
                        SetCursorPosition(default_position_x, 11);
                        for(int i = 0; i < strlen(temp); i++) printf(" ");
                        SetCursorPosition(0, 13);
                        for(int i = 0; i < 30; i++) printf(" ");
                        SetCursorPosition(0, 14);
                        for(int i = 0; i < 30; i++) printf(" ");
                        continue;
                    }

                }
                continue;
			}
			if(temp[index] == 32){
                if(inputan == 1){
                    continue;
                }
				SetCursorPosition(default_position_x, default_position_y);
				if(inputan == 2){
                    printf("*");
				}
				else{
                    printf(" ");
				}
				index++;
                default_position_x++;
				continue;
			}
			if(temp[index] == 8){
				if(index == 0){
                    continue;
				}
				default_position_x--;
				SetCursorPosition(default_position_x, default_position_y);
				printf(" ");
				index--;
				continue;
			}
			if(((temp[index] >= 'A' && temp[index] <= 'Z') || (temp[index] >= 'a' && temp[index] <= 'z') || (temp[index] >= '0' && temp[index] <= '9') || temp[index] == '@' || temp[index] == '.') == 0){
				continue;
			}

            SetCursorPosition(default_position_x, default_position_y);
            if(inputan == 2){
                printf("*");
            }
            else{
                printf("%c", temp[index]);
            }
		    index++;
            default_position_x++;
        }

        Sleep(50);
    }

    SetCursorPosition(0,default_position_y + 1 + choices_len);
    printf("Success Login\nPress Any Key To Continue\n");

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        printf("%s\n", ctime(&tempTime));


        if(kbhit()){
            struct UpdateTokomediaUserAccount update_user;
            update_user.id = tokomedia_user_login_now->id;
            update_user.name = tokomedia_user_login_now->name;
            update_user.password = tokomedia_user_login_now->password;
            update_user.email = tokomedia_user_login_now->email;
            update_user.created_at = tokomedia_user_login_now->created_at;
            update_user.last_login = GetTimeNow();
            update_user.balance = tokomedia_user_login_now->balance;
            update_user.security_code = tokomedia_user_login_now->security_code;

            ServiceUpdateTokomediaUserAccount(update_user);
            getchar();

//            EmailInboxDashboard();
            break;
        }
    }

}

void TokomediaUserRegisterMenu(){
    PrintTokomediaHeader();

    char choices[3][50] = {
        "Enter Email",
        "Enter Name",
        "Enter Password",
    };
    int choices_len = 3;

    struct NewTokomediaUserAccount new_user;
    char temp[255];
    int index = 0;
    int reset_x_default_position = 17;
    int default_position_x = 17;
    int default_position_y = 10;
    int inputan = 1;

    for(int i = 0; i < choices_len; i++){
        SetCursorPosition(0, 10 + i);
        printf("%s", choices[i]);
        SetCursorPosition(default_position_x - 2, 10 + i);
        printf(":");
    }

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        printf("%s\n", ctime(&tempTime));


        SetCursorVisible(true);
        SetCursorPosition(default_position_x,default_position_y);
        if(kbhit()){
            temp[index] = getch();
            if(temp[index] == KEY_ENTER){
		    	if(index == 0){
                    continue;
				}

                if(inputan == 1){
                    temp[index] = '\0';

                    char *s = strdup(temp);

                    new_user.email = s;

                    if(strcasecmp(new_user.email,"0") == 0){
                        SetCursorPosition(0,13);
                        printf("Aborting Operation");
                        getchar();
                        TokomediaMainMenu();
                        break;
                    }

                    struct Email *head = ServiceGetEmailAll();

                    int flag = 1;
                    while(head != NULL){
                        if(strcasecmp(new_user.email, head->email) == 0){
                            flag = 0;
                            break;
                        }
                        head = head->next;
                    }

                    if(flag){
                        SetCursorPosition(0,default_position_y + 1 + choices_len);
                        printf("Email Doesn't Exists\n");
                        printf("Press Enter To Continue");
                        getchar();
                        TokomediaUserRegisterMenu();
                    }

                    struct TokomediaUserAccount *head_2 = ServiceGetTokomediaUserAccountAll();

                    while(head_2 != NULL){
                        if(strcasecmp(new_user.email, head_2->email) == 0){
                            SetCursorPosition(0,default_position_y + 1 + choices_len);
                            printf("Email Registered!\n");
                            printf("Press Enter To Continue");
                            getchar();
                            TokomediaUserRegisterMenu();
                        }
                        head_2 = head_2->next;
                    }

                    inputan++;
                    default_position_y++;
                    default_position_x = reset_x_default_position;
                    index = 0;
                }
                else if(inputan == 2){
                    temp[index] = '\0';

                    char *s = strdup(temp);

                    new_user.name = s;

                    if(strcasecmp(new_user.name, "0") == 0){
                        SetCursorPosition(0,13);
                        printf("Aborting Operation");
                        getchar();
                        TokomediaMainMenu();
                        break;
                    }

                    inputan++;
                    default_position_y++;
                    default_position_x = reset_x_default_position;
                    index = 0;
                }
                else if(inputan == 3){
                    temp[index] = '\0';

                    char *s = strdup(temp);

                    new_user.password = s;

                    break;
                }
                continue;
			}
			if(temp[index] == 32){
                if(inputan == 1){
                    continue;
                }
				SetCursorPosition(default_position_x, default_position_y);
				if(inputan == 3){
                    printf("*");
				}
				else{
				    printf(" ");
				}
				index++;
                default_position_x++;
				continue;
			}
			if(temp[index] == 8){
				if(index == 0){
                    continue;
				}
				default_position_x--;
				SetCursorPosition(default_position_x, default_position_y);
				printf(" ");
				index--;
				continue;
			}
			if(((temp[index] >= 'A' && temp[index] <= 'Z') || (temp[index] >= 'a' && temp[index] <= 'z') || (temp[index] >= '0' && temp[index] <= '9') || temp[index] == '@' || temp[index] == '.') == 0){
				continue;
			}

            SetCursorPosition(default_position_x, default_position_y);
            if(inputan == 3){
                printf("*");
            }
            else{
                printf("%c", temp[index]);
            }
		    index++;
            default_position_x++;
        }

        Sleep(50);
    }

    new_user.balance = 0;
    new_user.created_at = GetTimeNow();
    new_user.last_login = GetTimeZero();
    new_user.security_code = "";

    bool flag = ServiceCreateTokomediaUserAccount(new_user);

    SetCursorPosition(0,default_position_y + 1 + choices_len);
    if(flag){
        printf("Success\n");
    }
    else{
        printf("Fail\n");
    }
    printf("Press Any Key To Continue\n");

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        printf("%s", ctime(&tempTime));

        if(kbhit()){
            getchar();
            TokomediaMainMenu();
        }
    }

}

void PrintTokomediaHeader(){
    system("@cls||clear");

    for(int i = 0; i < symbol_height; i++){
        printf("%s\n", TokomediaSymbol[i]);
    }

    SetCursorPosition(0, symbol_height + 1);
    for(int i = 0; i < strlen(TokomediaSymbol[0]);i++){
        printf("%c", char(HORIZON_LINE));
    }
}

#endif // DISPLAY_TOKOMEDIA_PARAM
