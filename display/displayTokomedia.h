#ifndef DISPLAY_TOKOMEDIA_PARAM
#define DISPLAY_TOKOMEDIA_PARAM 1

#include "../service/Tokomedia/serviceCartTokomedia.h"

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
void TokomediaUserDashboard();
void TokomediaUserCart();
void TokomediaUserTransactionPage();
void TokomediaUserOrderDetailsPage(int transaction_id);
void TokomediaUserForgotPassword();
void TokomediaUserForgotPasswordSendEmail();
void TokomediaUserForgotPasswordReset();

void TokomediaShopMainMenu();
void TokomediaShopLoginMenu();
void TokomediaShopRegisterMenu();
void TokomediaShopDashboard();
void TokomediaShopOrderDetailsPage();
void TokomediaShopForgotPassword();
void TokomediaShopForgotPasswordSendEmail();
void TokomediaShopForgotPasswordReset();

void PrintTokomediaHeader();

//Global Variable
struct TokomediaUserAccount *tokomedia_user_login_now = NULL;
struct TokomediaShopAccount *tokomedia_shop_login_now = NULL;
int tokomedia_user_itemlist_page_now = 1;
int tokomedia_user_itemlist_order_by = 0;

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
                    TokomediaShopMainMenu();
                    break;
                }
                else if(option_now == 13){
                    break;
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
                    TokomediaUserForgotPassword();
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

    char *save_pass;

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
                        save_pass = strdup(s);
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
            update_user.password = save_pass;
            update_user.email = tokomedia_user_login_now->email;
            update_user.created_at = tokomedia_user_login_now->created_at;
            update_user.last_login = GetTimeNow();
            update_user.balance = tokomedia_user_login_now->balance;
            update_user.security_code = tokomedia_user_login_now->security_code;

            ServiceUpdateTokomediaUserAccountNormal(update_user);

            TokomediaUserDashboard();
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
            TokomediaUserMainMenu();
        }
    }

}

void TokomediaUserDashboard(){
    PrintTokomediaHeader();

    SetCursorPosition(0,8);
    printf("Welcome, %s Your Balance : Rp %d\n", tokomedia_user_login_now->name, tokomedia_user_login_now->balance);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    struct ItemlistTokomedia *itemlist_tokomedia_head = ServiceGetItemlistTokomediaAll();

    int size_order_details_tokomedia = ServiceGetItemlistTokomediaSize(itemlist_tokomedia_head);

    ServiceFreeItemlistTokomediaLinkedList(itemlist_tokomedia_head);

    struct CartTokomedia *cart_tokomedia_user_head = ServiceGetCartTokomediaByTokomediaUserID(tokomedia_user_login_now->id);

    int user_cart_size = ServiceGetCartTokomediaSize(cart_tokomedia_user_head);

    ServiceFreeCartTokomediaLinkedList(cart_tokomedia_user_head);

    char email_count_text[50];

    sprintf(email_count_text, "%d Item(s) In Your Cart\n", user_cart_size);

    int count_temp_pos = 58;
    SetCursorPosition(count_temp_pos, 8);
    printf("%s", email_count_text);

    int max_pagination_page;
    if(size_order_details_tokomedia % 15 == 0){
        max_pagination_page = size_order_details_tokomedia / 15;
    }
    else{
        max_pagination_page = size_order_details_tokomedia / 15 + 1;
    }

    SetCursorPosition(8,10);
    printf("Item Name");
    SetCursorPosition(28,10);
    printf("Price");
    SetCursorPosition(50,10);
    printf("Stock");
    SetCursorPosition(80,10);
    printf("Shop");

    SetCursorPosition(0, 11);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    int cart_tokomedia_y = 12;
    int temp_y = cart_tokomedia_y;

    int item_counter_on_page;
    if(max_pagination_page == 0){
        item_counter_on_page = 0;
    }
    else if(tokomedia_user_itemlist_page_now != max_pagination_page){
        item_counter_on_page = 15;
    }
    else{
        item_counter_on_page = size_order_details_tokomedia - (tokomedia_user_itemlist_page_now - 1) * 15;
    }

    struct ItemlistTokomedia *cart_tokomedia_pagination = ServiceGetItemlistTokomediaPagination(15, tokomedia_user_itemlist_page_now, tokomedia_user_itemlist_order_by);
    struct ItemlistTokomedia *head_dummy = cart_tokomedia_pagination;

    while(head_dummy != NULL){
        SetCursorPosition(5,cart_tokomedia_y);

        SetCursorPosition(8,cart_tokomedia_y);
        if(strlen(head_dummy->item_name) > 22){
            for(int i = 0; i < 22; i++){
                printf("%c", head_dummy->item_name[i]);
            }
        }
        else{
                printf("%s", head_dummy->item_name);
        }
        SetCursorPosition(28, cart_tokomedia_y);
        printf("%d", head_dummy->price_per_unit);
        SetCursorPosition(50, cart_tokomedia_y);
        printf("%d", head_dummy->stock);
        SetCursorPosition(80, cart_tokomedia_y);

        struct TokomediaShopAccount *shop_acc = ServiceGetTokomediaShopAccountByID(head_dummy->tokomedia_shop_id);

        printf("%s", shop_acc->name);

        ServiceFreeTokomediaShopAccountLinkedList(shop_acc);

        head_dummy = head_dummy->next;
        cart_tokomedia_y++;
    }

    SetCursorPosition(0, cart_tokomedia_y + 1);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));
    SetCursorPosition(27, cart_tokomedia_y + 2);
    printf("%d/%d", tokomedia_user_itemlist_page_now, max_pagination_page);

    int selected_cart_tokomedia;
    int range_min, range_max;
    int flag = 0;

    head_dummy = cart_tokomedia_pagination;
    size_order_details_tokomedia = ServiceGetItemlistTokomediaSize(head_dummy);

    if(size_order_details_tokomedia > 0){
        selected_cart_tokomedia = 1;
        SetCursorPosition(2, temp_y);
        printf(">>");

        range_min = 1;
        if(tokomedia_user_itemlist_page_now != max_pagination_page){
            range_max = range_min + 14;
        }
        else{
            range_max = size_order_details_tokomedia;
        }
        flag = 1;
    }
    else{
        selected_cart_tokomedia = 0;
        SetCursorPosition(5, temp_y);
        printf("  ");
        printf("Itemlist Empty");
    }

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        printf("%s", ctime(&tempTime));

        if(kbhit()){
            char c = getch();

            if(flag){
                if(c == KEY_ENTER){
                    struct ItemlistTokomedia *itemlist_tokomedia_selected = ServiceGetItemlistTokomediaFromHeadByIndex(cart_tokomedia_pagination, (selected_cart_tokomedia - 1));
//                    EmailInboxDescription(email_inbox_selected);
                }
                else if(c == KEY_UP){
                    if(selected_cart_tokomedia == range_min){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    printf("  ");
                    temp_y--;
                    selected_cart_tokomedia--;
                    SetCursorPosition(2, temp_y);
                    printf(">>");
                }
                else if(c == KEY_DOWN){
                    if(selected_cart_tokomedia == range_max){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    printf("  ");
                    temp_y++;
                    selected_cart_tokomedia++;
                    SetCursorPosition(2, temp_y);
                    printf(">>");
                }
                else if(c == KEY_LEFT){
                    if(tokomedia_user_itemlist_page_now == 1){
                        continue;
                    }
                    tokomedia_user_itemlist_page_now--;
                    TokomediaUserDashboard();
                }
                else if(c == KEY_RIGHT){
                    if(tokomedia_user_itemlist_page_now == max_pagination_page){
                        continue;
                    }
                    tokomedia_user_itemlist_page_now++;
                    TokomediaUserDashboard();
                }
                else if(c == '0'){
                    tokomedia_user_itemlist_order_by = 0;
                    TokomediaUserDashboard();
                }
                else if(c == '1'){
                    tokomedia_user_itemlist_order_by = 1;
                    TokomediaUserDashboard();
                }
                else if(c == '2'){
                    tokomedia_user_itemlist_order_by = 2;
                    TokomediaUserDashboard();
                }
                else if(c == '3'){
                    tokomedia_user_itemlist_order_by = 3;
                    TokomediaUserDashboard();
                }
                else if(c == '4'){
                    tokomedia_user_itemlist_order_by = 4;
                    TokomediaUserDashboard();
                }
                else if(c == '5'){
                    tokomedia_user_itemlist_order_by = 5;
                    TokomediaUserDashboard();
                }
                else if(c == '6'){
                    tokomedia_user_itemlist_order_by = 6;
                    TokomediaUserDashboard();
                }
                else if(c == 'B' || c == 'b'){
                    cart_tokomedia_y += 3;
                    SetCursorPosition(0, cart_tokomedia_y);

                    struct ItemlistTokomedia *itemlist_tokomedia_selected = ServiceGetItemlistTokomediaFromHeadByIndex(cart_tokomedia_pagination, (selected_cart_tokomedia - 1));

                    if(itemlist_tokomedia_selected->stock <= 0){
                        printf("No Stock Available\nPress Enter To Continue\n");
                        getchar();
                        TokomediaUserDashboard();
                    }


                    printf("Item Quantity : ");
                    int qty;
                    scanf("%d", &qty);
                    getchar();

                    if(itemlist_tokomedia_selected->stock < qty){
                        printf("Order Quantity Exceeded\nPress Enter To Continue\n");
                        getchar();
                        TokomediaUserDashboard();
                    }

                    struct UpdateItemlistTokomedia temp_update_itemlist_tokomedia;
                    temp_update_itemlist_tokomedia.id = itemlist_tokomedia_selected->id;
                    temp_update_itemlist_tokomedia.item_name = itemlist_tokomedia_selected->item_name;
                    temp_update_itemlist_tokomedia.price_per_unit = itemlist_tokomedia_selected->price_per_unit + itemlist_tokomedia_selected->discount_per_unit;
                    temp_update_itemlist_tokomedia.discount_per_unit = itemlist_tokomedia_selected->discount_per_unit;
                    temp_update_itemlist_tokomedia.stock = itemlist_tokomedia_selected->stock - qty;
                    temp_update_itemlist_tokomedia.created_at = itemlist_tokomedia_selected->created_at;
                    temp_update_itemlist_tokomedia.updated_at = GetTimeNow();
                    temp_update_itemlist_tokomedia.tokomedia_shop_id = itemlist_tokomedia_selected->tokomedia_shop_id;

                    ServiceUpdateItemlistTokomedia(temp_update_itemlist_tokomedia);

                    struct NewCartTokomedia new_user_cart;
                    new_user_cart.item_name = itemlist_tokomedia_selected->item_name;
                    new_user_cart.price_per_unit = itemlist_tokomedia_selected->price_per_unit;
                    new_user_cart.qty = qty;
                    new_user_cart.total_price = qty * new_user_cart.price_per_unit;
                    new_user_cart.created_at = GetTimeNow();
                    new_user_cart.itemlist_id = itemlist_tokomedia_selected->id;
                    new_user_cart.tokomedia_user_id = tokomedia_user_login_now->id;
                    new_user_cart.tokomedia_shop_id = itemlist_tokomedia_selected->tokomedia_shop_id;

                    ServiceCreateCartTokomedia(new_user_cart);

                    printf("Successfully Added");
                    getchar();
                    TokomediaUserDashboard();
                }
                else if(c == 'C' || c == 'c'){
                    TokomediaUserCart();
                }
                else if(c == 'T' || c == 't'){
                    TokomediaUserTransactionPage();
                }
                else if(c == KEY_BACKSPACE){
                    system("@cls||clear");
                    printf("Logging Out . . . .\n");
                    printf("Press Enter To Continue\n");
                    getchar();

                    tokomedia_user_itemlist_page_now = 1;
                    tokomedia_user_itemlist_order_by = 0;
                    TokomediaUserMainMenu();
                }
            }
            else{
                if(c == 'C' || c == 'c'){
                    TokomediaUserCart();
                }
                else if(c == 'T' || c == 't'){
                    TokomediaUserTransactionPage();
                }
                else if(c == KEY_BACKSPACE){
                    system("@cls||clear");
                    printf("Logging Out . . . .\n");
                    printf("Press Enter To Continue\n");
                    getchar();
                    tokomedia_user_itemlist_page_now = 1;
                    tokomedia_user_itemlist_order_by = 0;
                    TokomediaUserMainMenu();
                }
            }
        }
    }
}

void TokomediaUserCart(){
    PrintTokomediaHeader();

    SetCursorPosition(0,8);
    printf("Welcome, %s Your Balance : Rp %d\n", tokomedia_user_login_now->name, tokomedia_user_login_now->balance);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    struct CartTokomedia *cart_tokomedia_head = ServiceGetCartTokomediaByTokomediaUserID(tokomedia_user_login_now->id);

    int size_order_details_tokomedia = ServiceGetCartTokomediaSize(cart_tokomedia_head);

    ServiceFreeCartTokomediaLinkedList(cart_tokomedia_head);

    char email_count_text[50];

    sprintf(email_count_text, "%d Item(s) In Your Cart\n", size_order_details_tokomedia);

    int count_temp_pos = 58;
    SetCursorPosition(count_temp_pos, 8);
    printf("%s", email_count_text);

    int max_pagination_page;
    if(size_order_details_tokomedia % 15 == 0){
        max_pagination_page = size_order_details_tokomedia / 15;
    }
    else{
        max_pagination_page = size_order_details_tokomedia / 15 + 1;
    }

    SetCursorPosition(8,10);
    printf("Item Name");
    SetCursorPosition(28,10);
    printf("@Price");
    SetCursorPosition(40,10);
    printf("Qty");
    SetCursorPosition(45,10);
    printf("Total Price");
    SetCursorPosition(57,10);
    printf("Created At");
    SetCursorPosition(80,10);
    printf("Shop");

    SetCursorPosition(0, 11);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    int cart_tokomedia_y = 12;
    int temp_y = cart_tokomedia_y;

    int item_counter_on_page;
    if(max_pagination_page == 0){
        item_counter_on_page = 0;
    }
    else if(tokomedia_user_itemlist_page_now != max_pagination_page){
        item_counter_on_page = 15;
    }
    else{
        item_counter_on_page = size_order_details_tokomedia - (tokomedia_user_itemlist_page_now - 1) * 15;
    }

    struct CartTokomedia *cart_tokomedia_pagination = ServiceGetCartTokomediaPaginationByUserID(15, tokomedia_user_itemlist_page_now, tokomedia_user_itemlist_order_by, tokomedia_user_login_now->id);
    struct CartTokomedia *head_dummy = cart_tokomedia_pagination;

    while(head_dummy != NULL){
        SetCursorPosition(5,cart_tokomedia_y);

        SetCursorPosition(8,cart_tokomedia_y);
        if(strlen(head_dummy->item_name) > 22){
            for(int i = 0; i < 22; i++){
                printf("%c", head_dummy->item_name[i]);
            }
        }
        else{
            printf("%s", head_dummy->item_name);
        }
        SetCursorPosition(28, cart_tokomedia_y);
        printf("%d", head_dummy->price_per_unit);
        SetCursorPosition(40, cart_tokomedia_y);
        printf("%d", head_dummy->qty);
        SetCursorPosition(45, cart_tokomedia_y);
        printf("%d", head_dummy->total_price);
        SetCursorPosition(57, cart_tokomedia_y);
        printf("%s", head_dummy->created_at);
        SetCursorPosition(80, cart_tokomedia_y);

        struct TokomediaShopAccount *shop_acc = ServiceGetTokomediaShopAccountByID(head_dummy->tokomedia_shop_id);

        printf("%s", shop_acc->name);

        ServiceFreeTokomediaShopAccountLinkedList(shop_acc);

        head_dummy = head_dummy->next;
        cart_tokomedia_y++;
    }

    SetCursorPosition(0, cart_tokomedia_y + 1);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));
    SetCursorPosition(27, cart_tokomedia_y + 2);
    printf("%d/%d", tokomedia_user_itemlist_page_now, max_pagination_page);

    int selected_cart_tokomedia;
    int range_min, range_max;
    int flag = 0;

    head_dummy = cart_tokomedia_pagination;
    size_order_details_tokomedia = ServiceGetCartTokomediaSize(head_dummy);

    if(size_order_details_tokomedia > 0){
        selected_cart_tokomedia = 1;
        SetCursorPosition(2, temp_y);
        printf(">>");

        range_min = 1;
        if(tokomedia_user_itemlist_page_now != max_pagination_page){
            range_max = range_min + 14;
        }
        else{
            range_max = size_order_details_tokomedia;
        }
        flag = 1;
    }
    else{
        selected_cart_tokomedia = 0;
        SetCursorPosition(5, temp_y);
        printf("  ");
        printf("Cart Empty");
    }

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        printf("%s", ctime(&tempTime));

        if(kbhit()){
            char c = getch();

            if(flag){
                if(c == KEY_ENTER){
//                    struct ItemlistTokomedia *itemlist_tokomedia_selected = ServiceGetItemlistTokomediaFromHeadByIndex(cart_tokomedia_pagination, (selected_cart_tokomedia - 1));
//                    EmailInboxDescription(email_inbox_selected);
                }
                else if(c == KEY_UP){
                    if(selected_cart_tokomedia == range_min){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    printf("  ");
                    temp_y--;
                    selected_cart_tokomedia--;
                    SetCursorPosition(2, temp_y);
                    printf(">>");
                }
                else if(c == KEY_DOWN){
                    if(selected_cart_tokomedia == range_max){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    printf("  ");
                    temp_y++;
                    selected_cart_tokomedia++;
                    SetCursorPosition(2, temp_y);
                    printf(">>");
                }
                else if(c == KEY_LEFT){
                    if(tokomedia_user_itemlist_page_now == 1){
                        continue;
                    }
                    tokomedia_user_itemlist_page_now--;
                    TokomediaUserCart();
                }
                else if(c == KEY_RIGHT){
                    if(tokomedia_user_itemlist_page_now == max_pagination_page){
                        continue;
                    }
                    tokomedia_user_itemlist_page_now++;
                    TokomediaUserCart();
                }
                else if(c == '0'){
                    tokomedia_user_itemlist_order_by = 0;
                    TokomediaUserCart();
                }
                else if(c == '1'){
                    tokomedia_user_itemlist_order_by = 1;
                    TokomediaUserCart();
                }
                else if(c == '2'){
                    tokomedia_user_itemlist_order_by = 2;
                    TokomediaUserCart();
                }
                else if(c == '3'){
                    tokomedia_user_itemlist_order_by = 3;
                    TokomediaUserCart();
                }
                else if(c == '4'){
                    tokomedia_user_itemlist_order_by = 4;
                    TokomediaUserCart();
                }
                else if(c == '5'){
                    tokomedia_user_itemlist_order_by = 5;
                    TokomediaUserCart();
                }
                else if(c == '6'){
                    tokomedia_user_itemlist_order_by = 6;
                    TokomediaUserCart();
                }
                else if(c == 'T' || c == 't'){
                    cart_tokomedia_y += 4;

                    SetCursorPosition(0, cart_tokomedia_y);
                    printf("Convert Cart(s) into transaction : >>  Yes        No ");
                          //12345678901234567890123456789012345678901234567890123
                    int temp_opt = 1;
                    while(1){
                        if(kbhit()){
                            char temp_c = getch();
                            if(temp_c == KEY_ENTER){
                                break;
                            }
                            else if(temp_c == KEY_LEFT){
                                if(temp_opt == 2){
                                    SetCursorPosition(46, cart_tokomedia_y);
                                    printf("  ");
                                    SetCursorPosition(35, cart_tokomedia_y);
                                    printf(">>");
                                    temp_opt = 1;
                                }
                            }
                            else if(temp_c == KEY_RIGHT){
                                if(temp_opt == 1){
                                    SetCursorPosition(35, cart_tokomedia_y);
                                    printf("  ");
                                    SetCursorPosition(46, cart_tokomedia_y);
                                    printf(">>");
                                    temp_opt = 2;
                                }
                            }
                        }
                    }

                    if(temp_opt == 1){
                        struct CartTokomedia *full_head = ServiceGetCartTokomediaByTokomediaUserID(tokomedia_user_login_now->id);

                        struct CartTokomedia *dummy_head = full_head;

                        int total_price = 0;

                        while(dummy_head != NULL){
                            total_price += dummy_head->total_price;
                            dummy_head = dummy_head->next;
                        }

                        struct NewTransactionTokomedia  new_trans;
                        new_trans.status = 2;
                        new_trans.total_price = total_price;
                        new_trans.created_at = GetTimeNow();
                        new_trans.updated_at = GetTimeZero();
                        new_trans.tokomedia_user_id = tokomedia_user_login_now->id;

                        int last_id = ServiceCreateTransactionTokomedia(new_trans);

                        while(full_head != NULL){
                            struct NewOrderDetailsTokomedia new_order;

                            new_order.item_name = full_head->item_name;
                            new_order.status = 2;
                            new_order.price_per_unit = full_head->price_per_unit;
                            new_order.qty = full_head->qty;
                            new_order.total_price = full_head->total_price;
                            new_order.created_at = GetTimeNow();
                            new_order.updated_at = GetTimeZero();
                            new_order.itemlist_id = full_head->itemlist_id;
                            new_order.tokomedia_shop_id = full_head->tokomedia_shop_id;
                            new_order.transaction_id = last_id;

                            ServiceCreateOrderDetailsTokomedia(new_order);

                            ServiceDeleteCartTokomedia(full_head->id);
                            full_head = full_head->next;
                        }

                        char word[500];
                        sprintf(word, "Your Transaction Successfully Created With Transaction ID : %d", last_id);
                        char *dupkey = word;

                        char *desc_hold = strdup(dupkey);

                        struct NewEmailInbox new_inbox;
                        new_inbox.sender_name = "Tokomedia Service";
                        new_inbox.subject = "Transaction Created";
                        new_inbox.description = desc_hold;
                        new_inbox.available = 1;
                        new_inbox.read_status = 2;
                        new_inbox.sent_at = GetTimeNow();
                        new_inbox.receiver_email_id = tokomedia_user_login_now->id;

                        ServiceCreateEmailInbox(new_inbox);

                        SetCursorPosition(0, cart_tokomedia_y + 2);
                        printf("Success\nPress Enter To Continue");
                        getchar();
                        TokomediaUserCart();
                    }
                    else{
                        TokomediaUserCart();
                    }
                }
                else if(c == KEY_BACKSPACE){
                    TokomediaUserDashboard();
                }
            }
            else{
                if(c == 'C' || c == 'c'){
//                    EmailInboxArchive();
                }
                else if(c == KEY_BACKSPACE){
                    TokomediaUserDashboard();
                }
            }
        }
    }
}

void TokomediaUserTransactionPage(){

    PrintTokomediaHeader();

    SetCursorPosition(0,8);
    printf("Welcome, %s Your Balance : Rp %d\n", tokomedia_user_login_now->name, tokomedia_user_login_now->balance);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    struct TransactionTokomedia *transaction_tokomedia_head = ServiceGetTransactionTokomediaByTokomediaUserID(tokomedia_user_login_now->id);

    int size_transaction_tokomedia = ServiceGetTransactionTokomediaSize(transaction_tokomedia_head);

    ServiceFreeTransactionTokomediaLinkedList(transaction_tokomedia_head);

    char email_count_text[50];

    sprintf(email_count_text, "%d Transaction(s) In Your List\n", size_transaction_tokomedia);

    int count_temp_pos = 58;
    SetCursorPosition(count_temp_pos, 8);
    printf("%s", email_count_text);

    int max_pagination_page;
    if(size_transaction_tokomedia % 15 == 0){
        max_pagination_page = size_transaction_tokomedia / 15;
    }
    else{
        max_pagination_page = size_transaction_tokomedia / 15 + 1;
    }

    SetCursorPosition(8,10);
    printf("ID");
    SetCursorPosition(28,10);
    printf("Status");
    SetCursorPosition(50,10);
    printf("Total Price");
    SetCursorPosition(80,10);
    printf("Created At");

    SetCursorPosition(0, 11);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    int cart_tokomedia_y = 12;
    int temp_y = cart_tokomedia_y;

    int item_counter_on_page;
    if(max_pagination_page == 0){
        item_counter_on_page = 0;
    }
    else if(tokomedia_user_itemlist_page_now != max_pagination_page){
        item_counter_on_page = 15;
    }
    else{
        item_counter_on_page = size_transaction_tokomedia - (tokomedia_user_itemlist_page_now - 1) * 15;
    }

    struct TransactionTokomedia *transaction_tokomedia_pagination = ServiceGetTransactionTokomediaPaginationByUserID(15, tokomedia_user_itemlist_page_now, tokomedia_user_itemlist_order_by, tokomedia_user_login_now->id);
    struct TransactionTokomedia *head_dummy = transaction_tokomedia_pagination;

    while(head_dummy != NULL){
        SetCursorPosition(5,cart_tokomedia_y);

        SetCursorPosition(8,cart_tokomedia_y);
        printf("%d", head_dummy->id);
        SetCursorPosition(28, cart_tokomedia_y);
        if(head_dummy->status == 1){
            printf("Paid");
        }
        else{
            printf("Pending");
        }
        SetCursorPosition(50, cart_tokomedia_y);
        printf("%d", head_dummy->total_price);
        SetCursorPosition(80, cart_tokomedia_y);
        printf("%s", head_dummy->created_at);

        head_dummy = head_dummy->next;
        cart_tokomedia_y++;
    }

    SetCursorPosition(0, cart_tokomedia_y + 1);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));
    SetCursorPosition(27, cart_tokomedia_y + 2);
    printf("%d/%d", tokomedia_user_itemlist_page_now, max_pagination_page);

    int selected_cart_tokomedia;
    int range_min, range_max;
    int flag = 0;

    head_dummy = transaction_tokomedia_pagination;
    size_transaction_tokomedia = ServiceGetTransactionTokomediaSize(head_dummy);

    if(size_transaction_tokomedia > 0){
        selected_cart_tokomedia = 1;
        SetCursorPosition(2, temp_y);
        printf(">>");

        range_min = 1;
        if(tokomedia_user_itemlist_page_now != max_pagination_page){
            range_max = range_min + 14;
        }
        else{
            range_max = size_transaction_tokomedia;
        }
        flag = 1;
    }
    else{
        selected_cart_tokomedia = 0;
        SetCursorPosition(5, temp_y);
        printf("  ");
        printf("Transaction Empty");
    }

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        printf("%s", ctime(&tempTime));

        if(kbhit()){
            char c = getch();

            if(flag){
                if(c == KEY_ENTER){
                    struct TransactionTokomedia *selected_head = ServiceGetTransactionTokomediaFromHeadByIndex(transaction_tokomedia_pagination, (selected_cart_tokomedia - 1));

                    TokomediaUserOrderDetailsPage(selected_head->id);
                }
                else if(c == KEY_UP){
                    if(selected_cart_tokomedia == range_min){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    printf("  ");
                    temp_y--;
                    selected_cart_tokomedia--;
                    SetCursorPosition(2, temp_y);
                    printf(">>");
                }
                else if(c == KEY_DOWN){
                    if(selected_cart_tokomedia == range_max){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    printf("  ");
                    temp_y++;
                    selected_cart_tokomedia++;
                    SetCursorPosition(2, temp_y);
                    printf(">>");
                }
                else if(c == KEY_LEFT){
                    if(tokomedia_user_itemlist_page_now == 1){
                        continue;
                    }
                    tokomedia_user_itemlist_page_now--;
                    TokomediaUserTransactionPage();
                }
                else if(c == KEY_RIGHT){
                    if(tokomedia_user_itemlist_page_now == max_pagination_page){
                        continue;
                    }
                    tokomedia_user_itemlist_page_now++;
                    TokomediaUserTransactionPage();
                }
                else if(c == '0'){
                    tokomedia_user_itemlist_order_by = 0;
                    TokomediaUserTransactionPage();
                }
                else if(c == '1'){
                    tokomedia_user_itemlist_order_by = 1;
                    TokomediaUserTransactionPage();
                }
                else if(c == '2'){
                    tokomedia_user_itemlist_order_by = 2;
                    TokomediaUserTransactionPage();
                }
                else if(c == '3'){
                    tokomedia_user_itemlist_order_by = 3;
                    TokomediaUserTransactionPage();
                }
                else if(c == '4'){
                    tokomedia_user_itemlist_order_by = 4;
                    TokomediaUserTransactionPage();
                }
                else if(c == '5'){
                    tokomedia_user_itemlist_order_by = 5;
                    TokomediaUserTransactionPage();
                }
                else if(c == '6'){
                    tokomedia_user_itemlist_order_by = 6;
                    TokomediaUserTransactionPage();
                }
                else if(c == 'P' || c == 'p'){
                    cart_tokomedia_y += 4;

                    struct TransactionTokomedia *full_head = ServiceGetTransactionTokomediaFromHeadByIndex(transaction_tokomedia_pagination, (selected_cart_tokomedia - 1));


                    if(full_head->status == 1){
                        SetCursorPosition(0, cart_tokomedia_y + 2);
                        printf("Already Paid!!!\nPress Enter To Continue");
                        getchar();
                        ServiceFreeTransactionTokomediaLinkedList(full_head);
                        TokomediaUserTransactionPage();
                    }

                    if(full_head->total_price > tokomedia_user_login_now->balance){
                        SetCursorPosition(0, cart_tokomedia_y + 2);
                        printf("Balance Not Enough!!!\nPress Enter To Continue");
                        getchar();
                        ServiceFreeTransactionTokomediaLinkedList(full_head);
                        TokomediaUserTransactionPage();
                    }

                    SetCursorPosition(0, cart_tokomedia_y);
                    printf("Pay For Transaction %d :      Yes         No ", full_head->id);
                          //12345678901234567890123456789012345678901234567890123
                    SetCursorPosition(26, cart_tokomedia_y);
                    printf(">>");
                    int temp_opt = 1;
                    while(1){
                        if(kbhit()){
                            char temp_c = getch();
                            if(temp_c == KEY_ENTER){
                                break;
                            }
                            else if(temp_c == KEY_LEFT){
                                if(temp_opt == 2){
                                    SetCursorPosition(35, cart_tokomedia_y);
                                    printf("  ");
                                    SetCursorPosition(26, cart_tokomedia_y);
                                    printf(">>");
                                    temp_opt = 1;
                                }
                            }
                            else if(temp_c == KEY_RIGHT){
                                if(temp_opt == 1){
                                    SetCursorPosition(26, cart_tokomedia_y);
                                    printf("  ");
                                    SetCursorPosition(35, cart_tokomedia_y);
                                    printf(">>");
                                    temp_opt = 2;
                                }
                            }
                        }
                    }

                    if(temp_opt == 1){
                        int total_price = 0;

                        struct UpdateTransactionTokomedia  update_trans;
                        update_trans.id = full_head->id;
                        update_trans.status = 1;
                        update_trans.total_price = full_head->total_price;
                        update_trans.created_at = full_head->created_at;
                        update_trans.updated_at = GetTimeNow();
                        update_trans.tokomedia_user_id = tokomedia_user_login_now->id;

                        ServiceUpdateTransactionTokomedia(update_trans);

                        struct OrderDetailsTokomedia *list_order_details = ServiceGetOrderDetailsTokomediaByTransactionID(full_head->id);

                        while(list_order_details != NULL){
                            struct UpdateOrderDetailsTokomedia update_order;
                            update_order.id = list_order_details->id;
                            update_order.item_name = list_order_details->item_name;
                            update_order.status = 1;
                            update_order.price_per_unit = list_order_details->price_per_unit;
                            update_order.qty = list_order_details->qty;
                            update_order.total_price = list_order_details->total_price;
                            update_order.created_at = list_order_details->created_at;
                            update_order.updated_at = GetTimeNow();
                            update_order.itemlist_id = list_order_details->itemlist_id;
                            update_order.tokomedia_shop_id = list_order_details->tokomedia_shop_id;
                            update_order.transaction_id = full_head->id;

                            ServiceUpdateOrderDetailsTokomedia(update_order);

                            struct TokomediaShopAccount *temp_shop = ServiceGetTokomediaShopAccountByID(list_order_details->tokomedia_shop_id);

                            temp_shop->balance += list_order_details->total_price;

                            struct UpdateTokomediaShopAccount update_shop;
                            update_shop.id = temp_shop->id;
                            update_shop.name = temp_shop->name;
                            update_shop.email = temp_shop->email;
                            update_shop.password = temp_shop->password;
                            update_shop.balance = temp_shop->balance;
                            update_shop.security_code = temp_shop->security_code;
                            update_shop.created_at = temp_shop->created_at;
                            update_shop.last_login = temp_shop->last_login;

                            ServiceFreeTokomediaShopAccountLinkedList(temp_shop);
                            ServiceUpdateTokomediaShopAccountNoPassword(update_shop);

                            list_order_details = list_order_details->next;
                        }

                        tokomedia_user_login_now->balance -= full_head->total_price;

                        struct UpdateTokomediaUserAccount update_user_acc;
                        update_user_acc.id = tokomedia_user_login_now->id;
                        update_user_acc.name = tokomedia_user_login_now->name;
                        update_user_acc.email = tokomedia_user_login_now->email;
                        update_user_acc.password = tokomedia_user_login_now->password;
                        update_user_acc.balance = tokomedia_user_login_now->balance;
                        update_user_acc.security_code = tokomedia_user_login_now->security_code;
                        update_user_acc.created_at = tokomedia_user_login_now->created_at;
                        update_user_acc.last_login = tokomedia_user_login_now->last_login;

                        ServiceUpdateTokomediaUserAccountNoPassword(update_user_acc);


                        char word[500];
                        sprintf(word, "Your Transaction Successfully Paid With Transaction ID : %d\nPrice : Rp.%d", full_head->id, full_head->total_price);
                        char *dupkey = word;

                        char *desc_hold = strdup(dupkey);

                        struct NewEmailInbox new_inbox;
                        new_inbox.sender_name = "Tokomedia Service";
                        new_inbox.subject = "Transaction Paid";
                        new_inbox.description = desc_hold;
                        new_inbox.available = 1;
                        new_inbox.read_status = 2;
                        new_inbox.sent_at = GetTimeNow();
                        new_inbox.receiver_email_id = tokomedia_user_login_now->id;

                        ServiceCreateEmailInbox(new_inbox);

                        SetCursorPosition(0, cart_tokomedia_y + 2);
                        printf("Success\nPress Enter To Continue");
                        getchar();
                        TokomediaUserTransactionPage();
                    }
                    else{
                        TokomediaUserTransactionPage();
                    }
                }
                else if(c == KEY_BACKSPACE){
                    TokomediaUserDashboard();
                }
            }
            else{
                if(c == KEY_BACKSPACE){
                    TokomediaUserDashboard();
                }
            }
        }
    }
}

void TokomediaUserOrderDetailsPage(int transaction_id){

    PrintTokomediaHeader();

    SetCursorPosition(0,8);
    printf("Welcome, %s Your Balance : Rp %d\n", tokomedia_user_login_now->name, tokomedia_user_login_now->balance);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    struct OrderDetailsTokomedia *order_details_tokomedia_head = ServiceGetOrderDetailsTokomediaByTransactionID(transaction_id);

    int size_order_details_tokomedia = ServiceGetOrderDetailsTokomediaSize(order_details_tokomedia_head);

    ServiceFreeOrderDetailsTokomediaLinkedList(order_details_tokomedia_head);

    char email_count_text[50];

    sprintf(email_count_text, "Transaction ID: %d\n", transaction_id);

    int count_temp_pos = 58;
    SetCursorPosition(count_temp_pos, 8);
    printf("%s", email_count_text);

    int max_pagination_page;
    if(size_order_details_tokomedia % 15 == 0){
        max_pagination_page = size_order_details_tokomedia / 15;
    }
    else{
        max_pagination_page = size_order_details_tokomedia / 15 + 1;
    }

    SetCursorPosition(8,10);
    printf("Item Name");
    SetCursorPosition(24,10);
    printf("Status");
    SetCursorPosition(36,10);
    printf("@Price");
    SetCursorPosition(45,10);
    printf("Qty");
    SetCursorPosition(50,10);
    printf("Total Price");
    SetCursorPosition(65,10);
    printf("Created At");
    SetCursorPosition(90,10);
    printf("Shop");

    SetCursorPosition(0, 11);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    int cart_tokomedia_y = 12;
    int temp_y = cart_tokomedia_y;

    int item_counter_on_page;
    if(max_pagination_page == 0){
        item_counter_on_page = 0;
    }
    else if(tokomedia_user_itemlist_page_now != max_pagination_page){
        item_counter_on_page = 15;
    }
    else{
        item_counter_on_page = size_order_details_tokomedia - (tokomedia_user_itemlist_page_now - 1) * 15;
    }

    struct OrderDetailsTokomedia *order_details_tokomedia_pagination = ServiceGetOrderDetailsTokomediaPaginationByTransactionID(15, tokomedia_user_itemlist_page_now, tokomedia_user_itemlist_order_by, transaction_id);
    struct OrderDetailsTokomedia *head_dummy = order_details_tokomedia_pagination;

    while(head_dummy != NULL){
        SetCursorPosition(8,cart_tokomedia_y);
        printf("%s", head_dummy->item_name);
        SetCursorPosition(24, cart_tokomedia_y);
        if(head_dummy->status == 1){
            printf("Paid");
        }
        else{
            printf("Pending");
        }
        SetCursorPosition(36, cart_tokomedia_y);
        printf("%d", head_dummy->price_per_unit);
        SetCursorPosition(45, cart_tokomedia_y);
        printf("%d", head_dummy->qty);
        SetCursorPosition(50, cart_tokomedia_y);
        printf("%d", head_dummy->total_price);
        SetCursorPosition(65, cart_tokomedia_y);
        printf("%s", head_dummy->created_at);
        SetCursorPosition(90, cart_tokomedia_y);

        struct TokomediaShopAccount *shop_acc = ServiceGetTokomediaShopAccountByID(head_dummy->tokomedia_shop_id);
        printf("%s", shop_acc->name);
        ServiceFreeTokomediaShopAccountLinkedList(shop_acc);

        head_dummy = head_dummy->next;
        cart_tokomedia_y++;
    }

    SetCursorPosition(0, cart_tokomedia_y + 1);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));
    SetCursorPosition(27, cart_tokomedia_y + 2);
    printf("%d/%d", tokomedia_user_itemlist_page_now, max_pagination_page);

    int selected_cart_tokomedia;
    int range_min, range_max;
    int flag = 0;

    head_dummy = order_details_tokomedia_pagination;
    size_order_details_tokomedia = ServiceGetOrderDetailsTokomediaSize(head_dummy);

    if(size_order_details_tokomedia > 0){
        selected_cart_tokomedia = 1;
        SetCursorPosition(2, temp_y);
        printf(">>");

        range_min = 1;
        if(tokomedia_user_itemlist_page_now != max_pagination_page){
            range_max = range_min + 14;
        }
        else{
            range_max = size_order_details_tokomedia;
        }
        flag = 1;
    }
    else{
        selected_cart_tokomedia = 0;
        SetCursorPosition(5, temp_y);
        printf("  ");
        printf("OrderDetails Empty");
    }

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        printf("%s", ctime(&tempTime));

        if(kbhit()){
            char c = getch();

            if(flag){
                if(c == KEY_ENTER){

                }
                else if(c == KEY_UP){
                    if(selected_cart_tokomedia == range_min){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    printf("  ");
                    temp_y--;
                    selected_cart_tokomedia--;
                    SetCursorPosition(2, temp_y);
                    printf(">>");
                }
                else if(c == KEY_DOWN){
                    if(selected_cart_tokomedia == range_max){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    printf("  ");
                    temp_y++;
                    selected_cart_tokomedia++;
                    SetCursorPosition(2, temp_y);
                    printf(">>");
                }
                else if(c == KEY_LEFT){
                    if(tokomedia_user_itemlist_page_now == 1){
                        continue;
                    }
                    tokomedia_user_itemlist_page_now--;
                    TokomediaUserOrderDetailsPage(transaction_id);
                }
                else if(c == KEY_RIGHT){
                    if(tokomedia_user_itemlist_page_now == max_pagination_page){
                        continue;
                    }
                    tokomedia_user_itemlist_page_now++;
                    TokomediaUserOrderDetailsPage(transaction_id);
                }
                else if(c == '0'){
                    tokomedia_user_itemlist_order_by = 0;
                    TokomediaUserOrderDetailsPage(transaction_id);
                }
                else if(c == '1'){
                    tokomedia_user_itemlist_order_by = 1;
                    TokomediaUserOrderDetailsPage(transaction_id);
                }
                else if(c == '2'){
                    tokomedia_user_itemlist_order_by = 2;
                    TokomediaUserOrderDetailsPage(transaction_id);
                }
                else if(c == '3'){
                    tokomedia_user_itemlist_order_by = 3;
                    TokomediaUserOrderDetailsPage(transaction_id);
                }
                else if(c == '4'){
                    tokomedia_user_itemlist_order_by = 4;
                    TokomediaUserOrderDetailsPage(transaction_id);
                }
                else if(c == '5'){
                    tokomedia_user_itemlist_order_by = 5;
                    TokomediaUserOrderDetailsPage(transaction_id);
                }
                else if(c == '6'){
                    tokomedia_user_itemlist_order_by = 6;
                    TokomediaUserOrderDetailsPage(transaction_id);
                }
                else if(c == '7'){
                    tokomedia_user_itemlist_order_by = 7;
                    TokomediaUserOrderDetailsPage(transaction_id);
                }
                else if(c == '8'){
                    tokomedia_user_itemlist_order_by = 8;
                    TokomediaUserOrderDetailsPage(transaction_id);
                }
                else if(c == '9'){
                    tokomedia_user_itemlist_order_by = 9;
                    TokomediaUserOrderDetailsPage(transaction_id);
                }
                else if(c == '-'){
                    tokomedia_user_itemlist_order_by = 10;
                    TokomediaUserOrderDetailsPage(transaction_id);
                }
                else if(c == KEY_BACKSPACE){
                    TokomediaUserTransactionPage();
                }
            }
            else{
                if(c == KEY_BACKSPACE){
                    TokomediaUserTransactionPage();
                }
            }
        }
    }
}

void TokomediaUserForgotPassword(){
    char tokomedia_user_main_menu_option[3][50] = {
        "Send Email",
        "Reset Pass",
        "Return",
    };
    int tokomedia_user_option_available = 3;

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
                    TokomediaUserForgotPasswordSendEmail();
                    break;
                }
                else if(option_now == 11){
                    TokomediaUserForgotPasswordReset();
                    break;
                }
                else if(option_now == 13){
                    TokomediaUserMainMenu();
                    break;
                }
            }

        }

    }

}

void TokomediaUserForgotPasswordSendEmail() {
    PrintTokomediaHeader();

    char choices[1][50] = {
        "Enter Email",
    };
    int choices_len = 1;

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
                    break;
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
                printf("%c", temp[index]);
		    index++;
            default_position_x++;
        }

        Sleep(50);
    }

    SetCursorPosition(0,default_position_y + 1 + choices_len);
    printf("Check Your Email Inbox For Your Security Code\nPress Any Key To Continue\n");

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        printf("%s\n", ctime(&tempTime));


        if(kbhit()){
            char *random_code = ToolsSecurityCodeGenerator();

            struct UpdateTokomediaUserAccount update_user;
            update_user.id = tokomedia_user_login_now->id;
            update_user.name = tokomedia_user_login_now->name;
            update_user.password = tokomedia_user_login_now->password;
            update_user.email = tokomedia_user_login_now->email;
            update_user.created_at = tokomedia_user_login_now->created_at;
            update_user.last_login = tokomedia_user_login_now->last_login;
            update_user.balance = tokomedia_user_login_now->balance;
            update_user.security_code = random_code;

            ServiceUpdateTokomediaUserAccountNoPassword(update_user);

            struct Email *get_mail = ServiceGetEmailByEmail(tokomedia_user_login_now->email);

            char desc[500];
            sprintf(desc, "Your Tokomedia User Secret Key : %s", random_code);

            char *key = desc;
            char *dupkey = strdup(key);

            struct NewEmailInbox new_inbox;
            new_inbox.sender_name = "Tokomedia Service";
            new_inbox.subject = "Reset Password Secret Key";
            new_inbox.description = dupkey;
            new_inbox.available = 1;
            new_inbox.read_status = 2;
            new_inbox.sent_at = GetTimeNow();
            new_inbox.receiver_email_id = get_mail->id;

            ServiceCreateEmailInbox(new_inbox);

            TokomediaUserForgotPassword();
            break;
        }
    }

}

void TokomediaUserForgotPasswordReset() {
    PrintTokomediaHeader();

    char choices[3][50] = {
        "Enter Email",
        "Enter Security Code",
        "Enter New Password"
    };
    int choices_len = 3;

    char temp[255];
    int index = 0;
    int reset_x_default_position = 25;
    int default_position_x = 25;
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

                    if(strcasecmp(s, tokomedia_user_login_now->security_code) == 0){
                        inputan++;
                        default_position_y++;
                        default_position_x = reset_x_default_position;
                        index = 0;
                        continue;
                    }
                    else{
                        SetCursorPosition(0,13);
                        printf("Security Code Wrong !!!\n");
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
                else if(inputan == 3){
                    temp[index] = '\0';

                    char *s = strdup(temp);

                    struct UpdateTokomediaUserAccount update_user;
                    update_user.id = tokomedia_user_login_now->id;
                    update_user.name = tokomedia_user_login_now->name;
                    update_user.email = tokomedia_user_login_now->email;
                    update_user.password = s;
                    update_user.balance = tokomedia_user_login_now->balance;
                    update_user.security_code = "";
                    update_user.created_at = tokomedia_user_login_now->created_at;
                    update_user.last_login = tokomedia_user_login_now->last_login;

                    ServiceUpdateTokomediaUserAccountNormal(update_user);
                    break;
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
            if(inputan == 2 || inputan == 3){
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
    printf("Password Reset Successful\nPress Any Key To Continue\n");

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        printf("%s\n", ctime(&tempTime));


        if(kbhit()){
            getchar();
            TokomediaUserForgotPassword();
            break;
        }
    }

}


void TokomediaShopMainMenu(){

    char tokomedia_shop_main_menu_option[4][50] = {
        "Login",
        "Register",
        "Forgot Password",
        "Return",
    };
    int tokomedia_shop_option_available = 4;

    int option_now = symbol_height + 2;
    int option_min = 9;
    int option_max = option_min + (tokomedia_shop_option_available - 1) * 2;

    int arrow_x_left = 18;
    int arrow_x_right = 45;

    SetCursorVisible(false);

    PrintTokomediaHeader();

    SetCursorPosition(arrow_x_left, option_now);
    printf(">>");
    SetCursorPosition(arrow_x_right, option_now);
    printf("<<");

    int temp_opt = 0;
    for(int i = 9; i <= 9 + (tokomedia_shop_option_available - 1) * 2; i += 2){
        SetCursorPosition(arrow_x_left + 8,i);
        printf("%s", tokomedia_shop_main_menu_option[temp_opt]);
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
                    TokomediaShopLoginMenu();
                    break;
                }
                else if(option_now == 11){
                    TokomediaShopRegisterMenu();
                    break;
                }
                else if(option_now == 13){
                    TokomediaShopForgotPassword();
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

void TokomediaShopRegisterMenu(){
    PrintTokomediaHeader();

    char choices[3][50] = {
        "Enter Email",
        "Enter Name",
        "Enter Password",
    };
    int choices_len = 3;

    struct NewTokomediaShopAccount new_shop;
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

                    new_shop.email = s;

                    if(strcasecmp(new_shop.email,"0") == 0){
                        SetCursorPosition(0,13);
                        printf("Aborting Operation");
                        getchar();
                        TokomediaMainMenu();
                        break;
                    }

                    struct Email *head = ServiceGetEmailAll();

                    int flag = 1;
                    while(head != NULL){
                        if(strcasecmp(new_shop.email, head->email) == 0){
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
                        TokomediaShopRegisterMenu();
                    }

                    struct TokomediaShopAccount *head_2 = ServiceGetTokomediaShopAccountAll();

                    while(head_2 != NULL){
                        if(strcasecmp(new_shop.email, head_2->email) == 0){
                            SetCursorPosition(0,default_position_y + 1 + choices_len);
                            printf("Email Registered!\n");
                            printf("Press Enter To Continue");
                            getchar();
                            TokomediaShopRegisterMenu();
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

                    new_shop.name = s;

                    if(strcasecmp(new_shop.name, "0") == 0){
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

                    new_shop.password = s;

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

    new_shop.balance = 0;
    new_shop.created_at = GetTimeNow();
    new_shop.last_login = GetTimeZero();
    new_shop.security_code = "";

    bool flag = ServiceCreateTokomediaShopAccount(new_shop);

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
            TokomediaShopMainMenu();
        }
    }

}

void TokomediaShopLoginMenu() {
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

//    char *save_pass;

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
                    struct TokomediaShopAccount *head = ServiceGetTokomediaShopAccountAll();

                    int flag = 1;

                    while(head != NULL){
                        if(strcasecmp(s, head->email) == 0){
                            tokomedia_shop_login_now = head;
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

                    if(HasherCompare(s, tokomedia_shop_login_now->password)){
//                        save_pass = strdup(s);
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
            struct UpdateTokomediaShopAccount update_shop;
            update_shop.id = tokomedia_shop_login_now->id;
            update_shop.name = tokomedia_shop_login_now->name;
            update_shop.password = tokomedia_shop_login_now->password;
            update_shop.email = tokomedia_shop_login_now->email;
            update_shop.created_at = tokomedia_shop_login_now->created_at;
            update_shop.last_login = GetTimeNow();
            update_shop.balance = tokomedia_shop_login_now->balance;
            update_shop.security_code = tokomedia_shop_login_now->security_code;

            ServiceUpdateTokomediaShopAccountNoPassword(update_shop);

            TokomediaShopDashboard();
            break;
        }
    }

}

void TokomediaShopDashboard(){
    PrintTokomediaHeader();

    SetCursorPosition(0,8);
    printf("Welcome, %s Your Balance : Rp %d\n", tokomedia_shop_login_now->name, tokomedia_shop_login_now->balance);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    struct ItemlistTokomedia *itemlist_tokomedia_head = ServiceGetItemlistTokomediaByTokomediaShopID(tokomedia_shop_login_now->id);

    int size_itemlist_tokomedia = ServiceGetItemlistTokomediaSize(itemlist_tokomedia_head);

    ServiceFreeItemlistTokomediaLinkedList(itemlist_tokomedia_head);

    char email_count_text[50];

    sprintf(email_count_text, "You Have %d Itemlist(s)\n", size_itemlist_tokomedia);

    int count_temp_pos = 58;
    SetCursorPosition(count_temp_pos, 8);
    printf("%s", email_count_text);

    int max_pagination_page;
    if(size_itemlist_tokomedia % 15 == 0){
        max_pagination_page = size_itemlist_tokomedia / 15;
    }
    else{
        max_pagination_page = size_itemlist_tokomedia / 15 + 1;
    }

    SetCursorPosition(8,10);
    printf("Item Name");
    SetCursorPosition(28,10);
    printf("@Price");
    SetCursorPosition(50,10);
    printf("@Discount");
    SetCursorPosition(70,10);
    printf("Stock");

    SetCursorPosition(0, 11);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    int cart_tokomedia_y = 12;
    int temp_y = cart_tokomedia_y;

    int item_counter_on_page;
    if(max_pagination_page == 0){
        item_counter_on_page = 0;
    }
    else if(tokomedia_user_itemlist_page_now != max_pagination_page){
        item_counter_on_page = 15;
    }
    else{
        item_counter_on_page = size_itemlist_tokomedia - (tokomedia_user_itemlist_page_now - 1) * 15;
    }

    struct ItemlistTokomedia *itemlist_tokomedia_pagination = ServiceGetItemlistTokomediaPaginationByTokomediaShopID(15, tokomedia_user_itemlist_page_now, tokomedia_user_itemlist_order_by, tokomedia_shop_login_now->id);
    struct ItemlistTokomedia *head_dummy = itemlist_tokomedia_pagination;

    while(head_dummy != NULL){
        SetCursorPosition(5,cart_tokomedia_y);

        SetCursorPosition(8,cart_tokomedia_y);
        if(strlen(head_dummy->item_name) > 22){
            for(int i = 0; i < 22; i++){
                printf("%c", head_dummy->item_name[i]);
            }
        }
        else{
                printf("%s", head_dummy->item_name);
        }
        SetCursorPosition(28, cart_tokomedia_y);
        printf("%d", head_dummy->price_per_unit + head_dummy->discount_per_unit);
        SetCursorPosition(50, cart_tokomedia_y);
        printf("%d", head_dummy->discount_per_unit);
        SetCursorPosition(70, cart_tokomedia_y);
        printf("%d", head_dummy->stock);

        head_dummy = head_dummy->next;
        cart_tokomedia_y++;
    }

    SetCursorPosition(0, cart_tokomedia_y + 1);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));
    SetCursorPosition(27, cart_tokomedia_y + 2);
    printf("%d/%d", tokomedia_user_itemlist_page_now, max_pagination_page);

    int selected_cart_tokomedia;
    int range_min, range_max;
    int flag = 0;

    head_dummy = itemlist_tokomedia_pagination;
    size_itemlist_tokomedia = ServiceGetItemlistTokomediaSize(head_dummy);

    if(size_itemlist_tokomedia > 0){
        selected_cart_tokomedia = 1;
        SetCursorPosition(2, temp_y);
        printf(">>");

        range_min = 1;
        if(tokomedia_user_itemlist_page_now != max_pagination_page){
            range_max = range_min + 14;
        }
        else{
            range_max = size_itemlist_tokomedia;
        }
        flag = 1;
    }
    else{
        selected_cart_tokomedia = 0;
        SetCursorPosition(5, temp_y);
        printf("  ");
        printf("Product Empty");
    }

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        printf("%s", ctime(&tempTime));

        if(kbhit()){
            char c = getch();

            if(flag){
                if(c == KEY_ENTER){

                }
                else if(c == KEY_UP){
                    if(selected_cart_tokomedia == range_min){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    printf("  ");
                    temp_y--;
                    selected_cart_tokomedia--;
                    SetCursorPosition(2, temp_y);
                    printf(">>");
                }
                else if(c == KEY_DOWN){
                    if(selected_cart_tokomedia == range_max){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    printf("  ");
                    temp_y++;
                    selected_cart_tokomedia++;
                    SetCursorPosition(2, temp_y);
                    printf(">>");
                }
                else if(c == KEY_LEFT){
                    if(tokomedia_user_itemlist_page_now == 1){
                        continue;
                    }
                    tokomedia_user_itemlist_page_now--;
                    TokomediaShopDashboard();
                }
                else if(c == KEY_RIGHT){
                    if(tokomedia_user_itemlist_page_now == max_pagination_page){
                        continue;
                    }
                    tokomedia_user_itemlist_page_now++;
                    TokomediaShopDashboard();
                }
                else if(c == '0'){
                    tokomedia_user_itemlist_order_by = 0;
                    TokomediaShopDashboard();
                }
                else if(c == '1'){
                    tokomedia_user_itemlist_order_by = 1;
                    TokomediaShopDashboard();
                }
                else if(c == '2'){
                    tokomedia_user_itemlist_order_by = 2;
                    TokomediaShopDashboard();
                }
                else if(c == '3'){
                    tokomedia_user_itemlist_order_by = 3;
                    TokomediaShopDashboard();
                }
                else if(c == '4'){
                    tokomedia_user_itemlist_order_by = 4;
                    TokomediaShopDashboard();
                }
                else if(c == '5'){
                    tokomedia_user_itemlist_order_by = 5;
                    TokomediaShopDashboard();
                }
                else if(c == '6'){
                    tokomedia_user_itemlist_order_by = 6;
                    TokomediaShopDashboard();
                }
                else if(c == 'C' || c == 'c'){
                    SetCursorVisible(true);
                    cart_tokomedia_y += 3;

                    SetCursorPosition(0, cart_tokomedia_y);
                    printf("Item Name         : ");
                    SetCursorPosition(0, cart_tokomedia_y + 1);
                    printf("Price Per Unit    : ");
                    SetCursorPosition(0, cart_tokomedia_y + 2);
                    printf("Discount Per Unit : ");
                    SetCursorPosition(0, cart_tokomedia_y + 3);
                    printf("Stock             : ");

                    char name_item[500];
                    int pa,da,sa;

                    SetCursorPosition(20, cart_tokomedia_y);
                    scanf("%[^\n]", &name_item);
                    cart_tokomedia_y++;
                    SetCursorPosition(20, cart_tokomedia_y);
                    scanf("%d", &pa);
                    cart_tokomedia_y++;
                    SetCursorPosition(20, cart_tokomedia_y);
                    scanf("%d", &da);
                    cart_tokomedia_y++;
                    SetCursorPosition(20, cart_tokomedia_y);
                    scanf("%d", &sa);
                    cart_tokomedia_y++;
                    getchar();

                    if((pa <= da) || sa < 0){
                        printf("Aborting Operation\nPress Enter To Continue");
                        getchar();
                        TokomediaShopDashboard();
                    }
                    else{
                        char *temp = name_item;
                        struct NewItemlistTokomedia new_item;
                        new_item.item_name = temp;
                        new_item.price_per_unit = pa;
                        new_item.discount_per_unit = da;
                        new_item.stock = sa;
                        new_item.created_at = GetTimeNow();
                        new_item.updated_at = GetTimeZero();
                        new_item.tokomedia_shop_id = tokomedia_shop_login_now->id;

                        ServiceCreateItemlistTokomedia(new_item);

                        printf("Success\nPress Enter To Continue");
                        getchar();
                        TokomediaShopDashboard();
                    }
                }
                else if(c == 'A' || c == 'a'){
                    cart_tokomedia_y += 3;
                    SetCursorPosition(0, cart_tokomedia_y);
                    char word[100] = "Add Stock : ";
                    int word_len = strlen(word);
                    printf("%s", word);

                    int print_stock = 0;
                    while(1){
                        SetCursorVisible(false);
                        SetCursorPosition(0,7);
                        time_t tempTime;
                        time(&tempTime);
                        printf("%s", ctime(&tempTime));

                        SetCursorPosition(word_len, cart_tokomedia_y);
                        printf("%d              ", print_stock);
                        if(kbhit()){
                            char tempG = getch();

                            if(tempG == KEY_ENTER){
                                break;
                            }
                            else if(tempG == KEY_UP){
                                print_stock++;
                            }
                            else if(tempG == KEY_DOWN){
                                if(print_stock > 0){
                                    print_stock--;
                                }
                            }
                            else if(tempG == KEY_LEFT){
                                if(print_stock >= 10){
                                    print_stock -= 10;
                                }
                                else if(print_stock >= 0 && print_stock <= 9){
                                    print_stock = 0;
                                }
                            }
                            else if(tempG == KEY_RIGHT){
                                print_stock += 10;
                            }
                        }
                        Sleep(50);
                    }

                    cart_tokomedia_y++;
                    SetCursorPosition(0, cart_tokomedia_y);
                    if(print_stock == 0){
                        printf("Aborting Operation\nPress Any Enter To Continue\n");
                        getchar();
                        TokomediaShopDashboard();
                    }
                    else{
                        struct ItemlistTokomedia *selected_head = ServiceGetItemlistTokomediaFromHeadByIndex(itemlist_tokomedia_pagination, (selected_cart_tokomedia - 1));

                        struct UpdateItemlistTokomedia update_item;
                        update_item.id = selected_head->id;
                        update_item.item_name = selected_head->item_name;
                        update_item.price_per_unit = selected_head->price_per_unit;
                        update_item.discount_per_unit = selected_head->discount_per_unit;
                        update_item.stock = selected_head->stock + print_stock;
                        update_item.created_at = selected_head->created_at;
                        update_item.updated_at = GetTimeNow();
                        update_item.tokomedia_shop_id = selected_head->tokomedia_shop_id;

                        ServiceUpdateItemlistTokomedia(update_item);

                        printf("Success\nPress Any Enter To Continue\n");
                        getchar();
                        TokomediaShopDashboard();
                    }
                }
                else if(c == 'E' || c == 'e'){
                    SetCursorVisible(true);
                    cart_tokomedia_y += 3;
                    SetCursorPosition(0, cart_tokomedia_y);
                    printf("Price Per Unit    : ");
                    SetCursorPosition(0, cart_tokomedia_y + 1);
                    printf("Discount Per Unit : ");
                    int p,d;
                    SetCursorPosition(20, cart_tokomedia_y);
                    scanf("%d", &p);
                    cart_tokomedia_y++;
                    SetCursorPosition(20, cart_tokomedia_y);
                    scanf("%d", &d);
                    getchar();

                    cart_tokomedia_y++;
                    SetCursorPosition(0, cart_tokomedia_y);
                    if(p <= d){
                        printf("Aborting Operation\nPress Enter To Continue");
                        getchar();
                        TokomediaShopDashboard();
                    }
                    else{
                        struct ItemlistTokomedia *selected_head = ServiceGetItemlistTokomediaFromHeadByIndex(itemlist_tokomedia_pagination, (selected_cart_tokomedia - 1));

                        struct UpdateItemlistTokomedia update_item;
                        update_item.id = selected_head->id;
                        update_item.item_name = selected_head->item_name;
                        update_item.price_per_unit = p;
                        update_item.discount_per_unit = d;
                        update_item.stock = selected_head->stock;
                        update_item.created_at = selected_head->created_at;
                        update_item.updated_at = GetTimeNow();
                        update_item.tokomedia_shop_id = selected_head->tokomedia_shop_id;

                        ServiceUpdateItemlistTokomedia(update_item);

                        struct CartTokomedia *list_cart = ServiceGetCartTokomediaByItemlistID(selected_head->id);

                        while(list_cart != NULL){

                            struct UpdateCartTokomedia update_cart;
                            update_cart.id = list_cart->id;
                            update_cart.item_name = list_cart->item_name;
                            update_cart.price_per_unit = selected_head->price_per_unit - selected_head->discount_per_unit;
                            update_cart.qty = list_cart->qty;
                            update_cart.total_price = list_cart->qty * update_cart.price_per_unit;
                            update_cart.created_at = list_cart->created_at;
                            update_cart.itemlist_id = list_cart->itemlist_id;
                            update_cart.tokomedia_user_id = list_cart->tokomedia_user_id;
                            update_cart.tokomedia_shop_id = list_cart->tokomedia_shop_id;

                            ServiceUpdateCartTokomedia(update_cart);

                            list_cart = list_cart->next;
                        }

                        printf("Success\nPress Enter To Continue");
                        getchar();
                        TokomediaShopDashboard();
                    }
                }
                else if(c == 'D' || c == 'd'){
                    struct ItemlistTokomedia *selected_head = ServiceGetItemlistTokomediaFromHeadByIndex(itemlist_tokomedia_pagination, (selected_cart_tokomedia - 1));

                    ServiceDeleteItemlistTokomedia(selected_head->id);

                    SetCursorPosition(0, cart_tokomedia_y + 3);

                    struct CartTokomedia *cart_list = ServiceGetCartTokomediaByItemlistID(selected_head->id);

                    while(cart_list != NULL){
                        ServiceDeleteCartTokomedia(cart_list->id);
                    }

                    printf("Success\nPress Any Enter To Continue\n");
                    getchar();
                    TokomediaShopDashboard();
                }
                else if(c == 'O'|| c == 'o'){
                    TokomediaShopOrderDetailsPage();
                    break;
                }
                else if(c == KEY_BACKSPACE){
                    system("@cls||clear");
                    printf("Logging Out . . . .\n");
                    printf("Press Enter To Continue\n");
                    getchar();

                    tokomedia_user_itemlist_page_now = 1;
                    tokomedia_user_itemlist_order_by = 0;
                    TokomediaShopMainMenu();
                }
            }
            else{
                if(c == KEY_BACKSPACE){
                    system("@cls||clear");
                    printf("Logging Out . . . .\n");
                    printf("Press Enter To Continue\n");
                    getchar();
                    tokomedia_user_itemlist_page_now = 1;
                    tokomedia_user_itemlist_order_by = 0;
                    TokomediaShopMainMenu();
                }
                else if(c == 'O'|| c == 'o'){
                    TokomediaShopOrderDetailsPage();
                    break;
                }
                else if(c == 'C' || c == 'c'){
                    SetCursorVisible(true);
                    cart_tokomedia_y += 3;

                    SetCursorPosition(0, cart_tokomedia_y);
                    printf("Item Name         : ");
                    SetCursorPosition(0, cart_tokomedia_y + 1);
                    printf("Price Per Unit    : ");
                    SetCursorPosition(0, cart_tokomedia_y + 2);
                    printf("Discount Per Unit : ");
                    SetCursorPosition(0, cart_tokomedia_y + 3);
                    printf("Stock             : ");

                    char name_item[500];
                    int pa,da,sa;

                    SetCursorPosition(20, cart_tokomedia_y);
                    scanf("%[^\n]", &name_item);
                    cart_tokomedia_y++;
                    SetCursorPosition(20, cart_tokomedia_y);
                    scanf("%d", &pa);
                    cart_tokomedia_y++;
                    SetCursorPosition(20, cart_tokomedia_y);
                    scanf("%d", &da);
                    cart_tokomedia_y++;
                    SetCursorPosition(20, cart_tokomedia_y);
                    scanf("%d", &sa);
                    cart_tokomedia_y++;
                    getchar();

                    if((pa <= da) || sa < 0){
                        printf("Aborting Operation\nPress Enter To Continue");
                        getchar();
                        TokomediaShopDashboard();
                    }
                    else{
                        char *temp = name_item;
                        struct NewItemlistTokomedia new_item;
                        new_item.item_name = temp;
                        new_item.price_per_unit = pa;
                        new_item.discount_per_unit = da;
                        new_item.stock = sa;
                        new_item.created_at = GetTimeNow();
                        new_item.updated_at = GetTimeZero();
                        new_item.tokomedia_shop_id = tokomedia_shop_login_now->id;

                        ServiceCreateItemlistTokomedia(new_item);

                        printf("Success\nPress Enter To Continue");
                        getchar();
                        TokomediaShopDashboard();
                    }
                }
            }
        }
    }
}

void TokomediaShopOrderDetailsPage(){

    PrintTokomediaHeader();

    SetCursorPosition(0,8);
    printf("Welcome, %s Your Balance : Rp %d\n", tokomedia_shop_login_now->name, tokomedia_shop_login_now->balance);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    struct OrderDetailsTokomedia *order_details_tokomedia_head = ServiceGetOrderDetailsTokomediaByTokomediaShopID(tokomedia_shop_login_now->id);

    int size_order_details_tokomedia = ServiceGetOrderDetailsTokomediaSize(order_details_tokomedia_head);

    ServiceFreeOrderDetailsTokomediaLinkedList(order_details_tokomedia_head);

    char email_count_text[50];

    sprintf(email_count_text, "%d Order Detail(s) in Your List", size_order_details_tokomedia);

    int count_temp_pos = 58;
    SetCursorPosition(count_temp_pos, 8);
    printf("%s", email_count_text);

    int max_pagination_page;
    if(size_order_details_tokomedia % 15 == 0){
        max_pagination_page = size_order_details_tokomedia / 15;
    }
    else{
        max_pagination_page = size_order_details_tokomedia / 15 + 1;
    }

    SetCursorPosition(8,10);
    printf("Item Name");
    SetCursorPosition(24,10);
    printf("Status");
    SetCursorPosition(36,10);
    printf("@Price");
    SetCursorPosition(50,10);
    printf("Qty");
    SetCursorPosition(60,10);
    printf("Total Price");
    SetCursorPosition(80,10);
    printf("Created At");

    SetCursorPosition(0, 11);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    int cart_tokomedia_y = 12;
    int temp_y = cart_tokomedia_y;

    int item_counter_on_page;
    if(max_pagination_page == 0){
        item_counter_on_page = 0;
    }
    else if(tokomedia_user_itemlist_page_now != max_pagination_page){
        item_counter_on_page = 15;
    }
    else{
        item_counter_on_page = size_order_details_tokomedia - (tokomedia_user_itemlist_page_now - 1) * 15;
    }

    struct OrderDetailsTokomedia *order_details_tokomedia_pagination = ServiceGetOrderDetailsTokomediaPaginationByTokomediaShopID(15, tokomedia_user_itemlist_page_now, tokomedia_user_itemlist_order_by, tokomedia_shop_login_now->id);
    struct OrderDetailsTokomedia *head_dummy = order_details_tokomedia_pagination;

    while(head_dummy != NULL){
        SetCursorPosition(8,cart_tokomedia_y);
        printf("%s", head_dummy->item_name);
        SetCursorPosition(24, cart_tokomedia_y);
        if(head_dummy->status == 1){
            printf("Paid");
        }
        else{
            printf("Pending");
        }
        SetCursorPosition(36, cart_tokomedia_y);
        printf("%d", head_dummy->price_per_unit);
        SetCursorPosition(50, cart_tokomedia_y);
        printf("%d", head_dummy->qty);
        SetCursorPosition(60, cart_tokomedia_y);
        printf("%d", head_dummy->total_price);
        SetCursorPosition(80, cart_tokomedia_y);
        printf("%s", head_dummy->created_at);

        head_dummy = head_dummy->next;
        cart_tokomedia_y++;
    }

    SetCursorPosition(0, cart_tokomedia_y + 1);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));
    SetCursorPosition(27, cart_tokomedia_y + 2);
    printf("%d/%d", tokomedia_user_itemlist_page_now, max_pagination_page);

    int selected_cart_tokomedia;
    int range_min, range_max;
    int flag = 0;

    head_dummy = order_details_tokomedia_pagination;
    size_order_details_tokomedia = ServiceGetOrderDetailsTokomediaSize(head_dummy);

    if(size_order_details_tokomedia > 0){
        selected_cart_tokomedia = 1;
        SetCursorPosition(2, temp_y);
        printf(">>");

        range_min = 1;
        if(tokomedia_user_itemlist_page_now != max_pagination_page){
            range_max = range_min + 14;
        }
        else{
            range_max = size_order_details_tokomedia;
        }
        flag = 1;
    }
    else{
        selected_cart_tokomedia = 0;
        SetCursorPosition(5, temp_y);
        printf("  ");
        printf("OrderDetails Empty");
    }

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        printf("%s", ctime(&tempTime));

        if(kbhit()){
            char c = getch();

            if(flag){
                if(c == KEY_ENTER){

                }
                else if(c == KEY_UP){
                    if(selected_cart_tokomedia == range_min){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    printf("  ");
                    temp_y--;
                    selected_cart_tokomedia--;
                    SetCursorPosition(2, temp_y);
                    printf(">>");
                }
                else if(c == KEY_DOWN){
                    if(selected_cart_tokomedia == range_max){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    printf("  ");
                    temp_y++;
                    selected_cart_tokomedia++;
                    SetCursorPosition(2, temp_y);
                    printf(">>");
                }
                else if(c == KEY_LEFT){
                    if(tokomedia_user_itemlist_page_now == 1){
                        continue;
                    }
                    tokomedia_user_itemlist_page_now--;
                    TokomediaShopOrderDetailsPage();
                }
                else if(c == KEY_RIGHT){
                    if(tokomedia_user_itemlist_page_now == max_pagination_page){
                        continue;
                    }
                    tokomedia_user_itemlist_page_now++;
                    TokomediaShopOrderDetailsPage();
                }
                else if(c == '0'){
                    tokomedia_user_itemlist_order_by = 0;
                    TokomediaShopOrderDetailsPage();
                }
                else if(c == '1'){
                    tokomedia_user_itemlist_order_by = 1;
                    TokomediaShopOrderDetailsPage();
                }
                else if(c == '2'){
                    tokomedia_user_itemlist_order_by = 2;
                    TokomediaShopOrderDetailsPage();
                }
                else if(c == '3'){
                    tokomedia_user_itemlist_order_by = 3;
                    TokomediaShopOrderDetailsPage();
                }
                else if(c == '4'){
                    tokomedia_user_itemlist_order_by = 4;
                    TokomediaShopOrderDetailsPage();
                }
                else if(c == '5'){
                    tokomedia_user_itemlist_order_by = 5;
                    TokomediaShopOrderDetailsPage();
                }
                else if(c == '6'){
                    tokomedia_user_itemlist_order_by = 6;
                    TokomediaShopOrderDetailsPage();
                }
                else if(c == '7'){
                    tokomedia_user_itemlist_order_by = 7;
                    TokomediaShopOrderDetailsPage();
                }
                else if(c == '8'){
                    tokomedia_user_itemlist_order_by = 8;
                    TokomediaShopOrderDetailsPage();
                }
                else if(c == '9'){
                    tokomedia_user_itemlist_order_by = 9;
                    TokomediaShopOrderDetailsPage();
                }
                else if(c == '-'){
                    tokomedia_user_itemlist_order_by = 10;
                    TokomediaShopOrderDetailsPage();
                }
                else if(c == KEY_BACKSPACE){
                    TokomediaShopDashboard();
                }
            }
            else{
                if(c == KEY_BACKSPACE){
                    TokomediaShopDashboard();
                }
            }
        }
    }
}

void TokomediaShopForgotPassword(){
    char tokomedia_user_main_menu_option[3][50] = {
        "Send Email",
        "Reset Pass",
        "Return",
    };
    int tokomedia_user_option_available = 3;

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
                    TokomediaShopForgotPasswordSendEmail();
                    break;
                }
                else if(option_now == 11){
                    TokomediaShopForgotPasswordReset();
                    break;
                }
                else if(option_now == 13){
                    TokomediaShopMainMenu();
                    break;
                }
            }

        }

    }

}

void TokomediaShopForgotPasswordSendEmail() {
    PrintTokomediaHeader();

    char choices[1][50] = {
        "Enter Email",
    };
    int choices_len = 1;

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
                        printf("Aborting Operation");
                        getchar();
                        TokomediaMainMenu();
                        break;
                    }
                    struct TokomediaShopAccount *head = ServiceGetTokomediaShopAccountAll();

                    int flag = 1;

                    while(head != NULL){
                        if(strcasecmp(s, head->email) == 0){
                            tokomedia_shop_login_now = head;
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
                    break;
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
            printf("%c", temp[index]);
		    index++;
            default_position_x++;
        }

        Sleep(50);
    }

    SetCursorPosition(0,default_position_y + 1 + choices_len);
    printf("Check Your Email Inbox For Your Security Code\nPress Any Key To Continue\n");

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        printf("%s\n", ctime(&tempTime));


        if(kbhit()){
            char *random_code = ToolsSecurityCodeGenerator();

            struct UpdateTokomediaShopAccount update_shop;
            update_shop.id = tokomedia_shop_login_now->id;
            update_shop.name = tokomedia_shop_login_now->name;
            update_shop.password = tokomedia_shop_login_now->password;
            update_shop.email = tokomedia_shop_login_now->email;
            update_shop.created_at = tokomedia_shop_login_now->created_at;
            update_shop.last_login = tokomedia_shop_login_now->last_login;
            update_shop.balance = tokomedia_shop_login_now->balance;
            update_shop.security_code = random_code;

            ServiceUpdateTokomediaShopAccountNoPassword(update_shop);

            struct Email *get_mail = ServiceGetEmailByEmail(tokomedia_shop_login_now->email);

            char desc[500];
            sprintf(desc, "Your Tokomedia Shop Secret Key : %s", random_code);

            char *key = desc;
            char *dupkey = strdup(key);

            struct NewEmailInbox new_inbox;
            new_inbox.sender_name = "Tokomedia Service";
            new_inbox.subject = "Reset Password Secret Key";
            new_inbox.description = dupkey;
            new_inbox.available = 1;
            new_inbox.read_status = 2;
            new_inbox.sent_at = GetTimeNow();
            new_inbox.receiver_email_id = get_mail->id;

            ServiceCreateEmailInbox(new_inbox);

            TokomediaShopForgotPassword();
            break;
        }
    }

}

void TokomediaShopForgotPasswordReset() {
    PrintTokomediaHeader();

    char choices[3][50] = {
        "Enter Email",
        "Enter Security Code",
        "Enter New Password"
    };
    int choices_len = 3;

    char temp[255];
    int index = 0;
    int reset_x_default_position = 25;
    int default_position_x = 25;
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
                        printf("Aborting Operation");
                        getchar();
                        TokomediaMainMenu();
                        break;
                    }
                    struct TokomediaShopAccount *head = ServiceGetTokomediaShopAccountAll();

                    int flag = 1;

                    while(head != NULL){
                        if(strcasecmp(s, head->email) == 0){
                            tokomedia_shop_login_now = head;
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

                    if(strcasecmp(s, tokomedia_shop_login_now->security_code) == 0){
                        inputan++;
                        default_position_y++;
                        default_position_x = reset_x_default_position;
                        index = 0;
                        continue;
                    }
                    else{
                        SetCursorPosition(0,13);
                        printf("Security Code Wrong !!!\n");
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
                else if(inputan == 3){
                    temp[index] = '\0';

                    char *s = strdup(temp);

                    struct UpdateTokomediaShopAccount update_shop;
                    update_shop.id = tokomedia_shop_login_now->id;
                    update_shop.name = tokomedia_shop_login_now->name;
                    update_shop.email = tokomedia_shop_login_now->email;
                    update_shop.password = s;
                    update_shop.balance = tokomedia_shop_login_now->balance;
                    update_shop.security_code = "";
                    update_shop.created_at = tokomedia_shop_login_now->created_at;
                    update_shop.last_login = tokomedia_shop_login_now->last_login;

                    ServiceUpdateTokomediaShopAccountNormal(update_shop);
                    break;
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
            if(inputan == 2 || inputan == 3){
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
    printf("Password Reset Successful\nPress Any Key To Continue\n");

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        printf("%s\n", ctime(&tempTime));


        if(kbhit()){
            getchar();
            TokomediaShopForgotPassword();
            break;
        }
    }

}



void PrintTokomediaHeader(){
    system("@cls||clear");

    for(int i = 0; i < symbol_height; i++){
        printf("%s\n", TokomediaSymbol[i]);
    }

//    SetCursorPosition(0, symbol_height + 1);
//    for(int i = 0; i < strlen(TokomediaSymbol[0]);i++){
//        printf("%c", char(HORIZON_LINE));
//    }
}

#endif // DISPLAY_TOKOMEDIA_PARAM
