#ifndef DISPLAY_PARAM_EMAIL
#define DISPLAY_PARAM_EMAIL 1

#include "../tools/cursorTools.h"

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

// Email Display Function
void EmailMainMenu();
void EmailLoginMenu();
void EmailRegisterMenu();
void EmailInboxDashboard();
void EmailInboxDescription(struct EmailInbox *input);
void EmailInboxArchive();
void EmailSentDashboard();
void EmailSentDescription(struct EmailSent *input);
void EmailSentArchive();
void EmailWriteMail();

// Misc
void PrintHeader();

// Global Variable
struct Email *login_now = NULL;
int inbox_dashboard_page_now = 1;
int archived_email_inbox_page_now = 1;
int sent_dashboard_page_now = 1;
int archived_email_sent_page_now = 1;

char gmailSymbol[15][105] = {
"0011111111000000000000000111111000000000000000000000000000000000000000000000000000000000000000000000",//1
"0100111111001111101111100111100100000001111001111000111110000000000000000000000000000000000000000000",//2
"1000100111010000011110010100100100000110111110010101000001000000000000000000000000000000000000000000",//3
"1000011100100111001101101100100111000100111(001110)0010100100000000000000000000000000000000000000000",//4
"011111110011111100(111100111111111011011110011111111111100100000000000000000000000000000000000000000",//5
"0000000011000000110000011000000000011000001100000000000011000000000000000000000000000000000000000000",//6
"2222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222",//7
"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",//8
"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",//9
"00000000000000000000000000LOGIN000000000000000000000000000000000000000000000000000000000000000000000",// (18 19,10) (37 38,10)
"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",//11
"0000000000000000000000000REGISTER0000000000000000000000000000000000000000000000000000000000000000000",// (X,12) (X2,12)
"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",//13
"00000000000000000000000000RETURN00000000000000000000000000000000000000000000000000000000000000000000",//14
};

void EmailMainMenu(){
    system("@cls||clear");
    int option_now = 9;
    int option_max = 13;
    int option_min = 9;

    SetCursorVisible(false);

    gmailSymbol[9][18] = '>';
    gmailSymbol[9][19] = '>';
    gmailSymbol[9][37] = '<';
    gmailSymbol[9][38] = '<';

    gmailSymbol[11][18] = ' ';
    gmailSymbol[11][19] = ' ';
    gmailSymbol[11][37] = ' ';
    gmailSymbol[11][38] = ' ';

    gmailSymbol[13][18] = ' ';
    gmailSymbol[13][19] = ' ';
    gmailSymbol[13][37] = ' ';
    gmailSymbol[13][38] = ' ';

    #ifndef ONLY_ONCE
    #define ONLY_ONCE
        int len_x = strlen(gmailSymbol[0]);

        for(int i = 0; i < 15; i++){
            for(int j = 0; j < len_x; j++){
                if(gmailSymbol[i][j] == '1'){
                    gmailSymbol[i][j] = char(STAGE4);
                }
                else if(gmailSymbol[i][j] == '2'){
                    gmailSymbol[i][j] = char(HORIZON_LINE);
                }
                else if(gmailSymbol[i][j] == '0'){
                    gmailSymbol[i][j] = ' ';
                }
            }
        }
    #endif

    for(int i = 0; i < 15; i++){
        if(i == 7){
            printf("%s", GetTimeNow());
        }
        else{
            printf("%s", gmailSymbol[i]);
        }
        puts("");
    }

    while(1){

        SetCursorPosition(0,7);
            printf("%s", GetTimeNow());

        if(kbhit()){
            char c = getch();

            if(c == KEY_UP){
                if(option_now != option_min){
                    gmailSymbol[option_now][18] = ' ';
                    gmailSymbol[option_now][19] = ' ';
                    gmailSymbol[option_now][37] = ' ';
                    gmailSymbol[option_now][38] = ' ';
                    option_now -= 2;
                    gmailSymbol[option_now][18] = '>';
                    gmailSymbol[option_now][19] = '>';
                    gmailSymbol[option_now][37] = '<';
                    gmailSymbol[option_now][38] = '<';
                }

                SetCursorPosition(0,8);
                for(int i = 8; i < 15; i++){
                    printf("%s\n", gmailSymbol[i]);
                }
            }
            else if(c == KEY_DOWN){
                if(option_now != option_max){
                    gmailSymbol[option_now][18] = ' ';
                    gmailSymbol[option_now][19] = ' ';
                    gmailSymbol[option_now][37] = ' ';
                    gmailSymbol[option_now][38] = ' ';
                    option_now += 2;
                    gmailSymbol[option_now][18] = '>';
                    gmailSymbol[option_now][19] = '>';
                    gmailSymbol[option_now][37] = '<';
                    gmailSymbol[option_now][38] = '<';
                }

                SetCursorPosition(0,8);
                for(int i = 8; i < 15; i++){
                    printf("%s\n", gmailSymbol[i]);
                }
            }
            else if(c == KEY_ENTER){
                if(option_now == 9){
                    EmailLoginMenu();
                    break;
                }
                else if(option_now == 11){
                    EmailRegisterMenu();
                    break;
                }
            }

        }

    }

}

void EmailLoginMenu() {
    PrintHeader();

    char temp[255];
    int index = 0;
    int reset_x_default_position = 17;
    int default_position_x = 17;
    int default_position_y = 10;
    int inputan = 1;

    SetCursorPosition(0,10);
    printf("Enter Email    : ");
    SetCursorPosition(0,11);
    printf("Enter Password : ");

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
                        EmailMainMenu();
                        break;
                    }
                    struct Email *head = ServiceGetEmailAll();

                    int flag = 1;

                    while(head != NULL){
                        if(strcasecmp(s, head->email) == 0){
                            login_now = head;
                            flag = 0;
                            break;
                        }
                        head = head->next;
                    }

                    if(flag){
                        SetCursorPosition(0,13);
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

                    if(HasherCompare(s, login_now->password)){
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

    SetCursorPosition(0,13);
    printf("Success Login\nPress Any Key To Continue\n");

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        printf("%s\n", ctime(&tempTime));


        if(kbhit()){
            struct UpdateEmail update_email;
            update_email.id = login_now->id;
            update_email.name = login_now->name;
            update_email.password = login_now->password;
            update_email.email = login_now->email;
            update_email.created_at = login_now->created_at;
            update_email.last_login = GetTimeNow();

            ServiceUpdateEmail(update_email);
            getchar();
            EmailInboxDashboard();
            break;
        }
    }

}

void EmailRegisterMenu(){
    PrintHeader();

    struct NewEmail new_email;
    char temp[255];
    int index = 0;
    int reset_x_default_position = 17;
    int default_position_x = 17;
    int default_position_y = 10;
    int inputan = 1;

    SetCursorPosition(0,10);
    printf("Enter Email    : ");
    SetCursorPosition(0,11);
    printf("Enter Name     : ");
    SetCursorPosition(0,12);
    printf("Enter Password : ");

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

                    new_email.email = s;

                    if(strcasecmp(new_email.email,"0") == 0){
                        SetCursorPosition(0,13);
                        printf("Aborting Operation");
                        getchar();
                        EmailMainMenu();
                        break;
                    }

                    struct Email *head = ServiceGetEmailAll();

                    while(head != NULL){
                        if(strcasecmp(new_email.email, head->email) == 0){
                                SetCursorPosition(0,13);
                                printf("Email Exists\n");
                                printf("Press Enter To Continue");
                                getchar();
                                EmailRegisterMenu();
                        }
                        head = head->next;
                    }

                    inputan++;
                    default_position_y++;
                    default_position_x = reset_x_default_position;
                    index = 0;
                }
                else if(inputan == 2){
                    temp[index] = '\0';

                    char *s = strdup(temp);

                    new_email.name = s;

                    if(strcasecmp(new_email.name, "0") == 0){
                        SetCursorPosition(0,13);
                        printf("Aborting Operation");
                        getchar();
                        EmailMainMenu();
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

                    new_email.password = s;

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

    new_email.created_at = GetTimeNow();
    new_email.last_login = GetTimeZero();

    bool flag = ServiceCreateEmail(new_email);

    SetCursorPosition(0,13);
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
            EmailMainMenu();
        }
    }

}

void EmailInboxDashboard() {
    PrintHeader();

    SetCursorPosition(0,8);
    printf("Welcome, %s\n", login_now->name);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    struct EmailInbox *email_inbox_head = ServiceGetEmailInboxByUserID(login_now->id);

    int size_email_inbox = ServiceGetEmailInboxSize(email_inbox_head);

    char email_count_text[50];

    sprintf(email_count_text, "%d Email(s) In Your Inbox", size_email_inbox);

    int count_temp_pos = 58;
    SetCursorPosition(count_temp_pos, 8);
    printf("%s", email_count_text);

    int max_pagination_page;
    if(size_email_inbox % 15 == 0){
        max_pagination_page = size_email_inbox / 15;
    }
    else{
        max_pagination_page = size_email_inbox / 15 + 1;
    }

    SetCursorPosition(8,10);
    printf("Sender");
    SetCursorPosition(28,10);
    printf("Subject");
    SetCursorPosition(80,10);
    printf("Sent At");

    SetCursorPosition(0, 11);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    int inbox_y = 12;
    int temp_y = inbox_y;

    int item_counter_on_page;
    if(max_pagination_page == 0){
        item_counter_on_page = 0;
    }
    else if(inbox_dashboard_page_now != max_pagination_page){
        item_counter_on_page = 15;
    }
    else{
        item_counter_on_page = size_email_inbox - (inbox_dashboard_page_now - 1) * 15;
    }

    for(int i = inbox_y + (inbox_dashboard_page_now - 1) * 15; i < temp_y + (inbox_dashboard_page_now - 1) * 15 + item_counter_on_page; i++){
        SetCursorPosition(5,inbox_y);
        struct EmailInbox *index_n = ServiceGetEmailInboxFromHeadByIndex(email_inbox_head, (i - temp_y));
        if(index_n->read_status == 2){
            printf("%c ", char(254));
        }
        else{
            printf("  ");
        }

        SetCursorPosition(8,inbox_y);
        if(strlen(index_n->sender_name) > 22){
            for(int i = 0; i < 22; i++){
                printf("%c", index_n->sender_name[i]);
            }
        }
        else{
                printf("%s", index_n->sender_name);
        }
        SetCursorPosition(28,inbox_y);
        if(strlen(index_n->subject) > 45){
            for(int i = 0; i < 45; i++){
                printf("%c", index_n->subject[i]);
            }
            printf("...");
        }
        else{
                printf("%s", index_n->subject);
        }
        SetCursorPosition(80,inbox_y);
        printf("%s", index_n->sent_at);

        inbox_y++;
    }

    SetCursorPosition(0, inbox_y + 1);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));
    SetCursorPosition(27, inbox_y + 2);
    printf("%d/%d", inbox_dashboard_page_now, max_pagination_page);

    int selected_email_inbox;
    int range_min, range_max;
    int flag = 0;
    if(size_email_inbox > 0){
        selected_email_inbox = (inbox_dashboard_page_now - 1) * 15 + 1;
        SetCursorPosition(2, temp_y);
        printf(">>");

        range_min = (inbox_dashboard_page_now - 1) * 15 + 1;
        if(inbox_dashboard_page_now != max_pagination_page){
            range_max = range_min + 14;
        }
        else{
            range_max = size_email_inbox;
        }
        flag = 1;
    }
    else{
        selected_email_inbox = 0;
        SetCursorPosition(5, temp_y);
        printf("  ");
        printf("Inbox Empty");
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
                    struct EmailInbox *email_inbox_selected = ServiceGetEmailInboxFromHeadByIndex(email_inbox_head, (selected_email_inbox - 1));
                    EmailInboxDescription(email_inbox_selected);
                }
                else if(c == KEY_UP){
                    if(selected_email_inbox == range_min){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    printf("  ");
                    temp_y--;
                    selected_email_inbox--;
                    SetCursorPosition(2, temp_y);
                    printf(">>");
                }
                else if(c == KEY_DOWN){
                    if(selected_email_inbox == range_max){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    printf("  ");
                    temp_y++;
                    selected_email_inbox++;
                    SetCursorPosition(2, temp_y);
                    printf(">>");
                }
                else if(c == KEY_LEFT){
                    if(inbox_dashboard_page_now == 1){
                        continue;
                    }
                    inbox_dashboard_page_now--;
                    EmailInboxDashboard();
                }
                else if(c == KEY_RIGHT){
                    if(inbox_dashboard_page_now == max_pagination_page){
                        continue;
                    }
                    inbox_dashboard_page_now++;
                    EmailInboxDashboard();
                }
                else if(c == 'A' || c == 'a'){
                    EmailInboxArchive();
                }
                else if(c == 'D' || c == 'd'){
                    struct EmailInbox *email_inbox_selected = ServiceGetEmailInboxFromHeadByIndex(email_inbox_head, (selected_email_inbox - 1));
                    struct UpdateEmailInbox update_email_inbox;
                    update_email_inbox.id = email_inbox_selected->id;
                    update_email_inbox.sender_name = email_inbox_selected->sender_name;
                    update_email_inbox.subject = email_inbox_selected->subject;
                    update_email_inbox.description = email_inbox_selected->description;
                    update_email_inbox.available = 2;
                    update_email_inbox.read_status = email_inbox_selected->read_status;
                    update_email_inbox.sent_at = email_inbox_selected->sent_at;
                    update_email_inbox.receiver_email_id = email_inbox_selected->receiver_email_id;
                    ServiceUpdateEmailInbox(update_email_inbox);
                    EmailInboxDashboard();
                }
                else if(c == 'S' || c == 's'){
                    EmailSentDashboard();
                }
                else if(c == 'W' || c == 'w'){
                    EmailWriteMail();
                }
                else if(c == '0' || c == KEY_BACKSPACE){
                    system("@cls||clear");
                    printf("Logging Out . . . .\n");
                    printf("Press Enter To Continue\n");
                    getchar();
                    inbox_dashboard_page_now = 1;
                    archived_email_inbox_page_now = 1;
                    EmailMainMenu();
                }
            }
            else{
                if(c == 'A' || c == 'a'){
                    EmailInboxArchive();
                }
                else if(c == '0' || c == KEY_BACKSPACE){
                    system("@cls||clear");
                    printf("Logging Out . . . .\n");
                    printf("Press Enter To Continue\n");
                    getchar();
                    inbox_dashboard_page_now = 1;
                    archived_email_inbox_page_now = 1;
                    EmailMainMenu();
                }
                else if(c == 'W' || c == 'w'){
                    EmailWriteMail();
                }
                else if(c == 'S' || c == 's'){
                    EmailSentDashboard();
                }
            }
        }
    }


}

void EmailInboxDescription(struct EmailInbox *input) {
    PrintHeader();

    struct UpdateEmailInbox update_email_inbox;
    update_email_inbox.id = input->id;
    update_email_inbox.description = input->description;
    update_email_inbox.receiver_email_id = input->receiver_email_id;
    update_email_inbox.sender_name = input->sender_name;
    update_email_inbox.sent_at = input->sent_at;
    update_email_inbox.subject = input->subject;
    update_email_inbox.available = input->available;
    update_email_inbox.read_status = 1;

    ServiceUpdateEmailInbox(update_email_inbox);

    SetCursorPosition(0,8);
    printf("Sender : %s at %s\n", input->sender_name, input->sent_at);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));
    printf("\nSubject : %s\n\n", input->subject);
    printf("%s\n", descriptionConvert(input->description, 99));
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        printf("%s", ctime(&tempTime));

        if(kbhit()){
            char c = getch();

            if(c == KEY_BACKSPACE || c == '0'){
                EmailInboxDashboard();
                break;
            }
        }
    }
}

void EmailInboxArchive() {
    PrintHeader();

    struct EmailInbox *archived_email = ServiceGetArchivedEmailInboxByUserID(login_now->id);

    int archived_count = ServiceGetEmailInboxSize(archived_email);

    SetCursorPosition(0,8);
    printf("You have %d Archived Email(s)\n", archived_count);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    SetCursorPosition(8,10);
    printf("Sender");
    SetCursorPosition(28,10);
    printf("Subject");
    SetCursorPosition(80,10);
    printf("Sent At");

    SetCursorPosition(0, 11);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    int inbox_y = 12;
    int temp_y = inbox_y;

    int max_pagination_page;
    if(archived_count % 15 == 0){
        max_pagination_page = archived_count / 15;
    }
    else{
        max_pagination_page = archived_count / 15 + 1;
    }

    int item_counter_on_page;
    if(max_pagination_page == 0){
        item_counter_on_page = 0;
    }
    else if(archived_email_inbox_page_now != max_pagination_page){
        item_counter_on_page = 15;
    }
    else{
        item_counter_on_page = archived_count - (archived_email_inbox_page_now - 1) * 15;
    }

    for(int i = inbox_y + (archived_email_inbox_page_now - 1) * 15; i < temp_y + (archived_email_inbox_page_now - 1) * 15 + item_counter_on_page; i++){
        struct EmailInbox *index_n = ServiceGetEmailInboxFromHeadByIndex(archived_email, (i - temp_y));

        SetCursorPosition(8,inbox_y);
        if(strlen(index_n->sender_name) > 22){
            for(int i = 0; i < 22; i++){
                printf("%c", index_n->sender_name[i]);
            }
        }
        else{
            printf("%s", index_n->sender_name);
        }
        SetCursorPosition(28,inbox_y);
        if(strlen(index_n->subject) > 45){
            for(int i = 0; i < 22; i++){
                printf("%c", index_n->subject[i]);
            }
            printf("...");
        }
        else{
            printf("%s", index_n->subject);
        }
        SetCursorPosition(80,inbox_y);
        printf("%s", index_n->sent_at);

        inbox_y++;
    }

    SetCursorPosition(0, inbox_y + 1);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));
    SetCursorPosition(27, inbox_y + 2);
    cout << archived_email_inbox_page_now << "/" << max_pagination_page;

    int selected_archived_email;
    int range_min, range_max;
    int flag = 0;
    if(archived_count > 0){
        selected_archived_email = (archived_email_inbox_page_now - 1) * 15 + 1;
        SetCursorPosition(2, temp_y);
        printf(">>");

        range_min = (archived_email_inbox_page_now - 1) * 15 + 1;
        if(archived_email_inbox_page_now != max_pagination_page){
            range_max = range_min + 14;
        }
        else{
            range_max = archived_count;
        }
        flag = 1;
    }
    else{
        selected_archived_email = 0;
        SetCursorPosition(5, temp_y);
        printf("Archived Empty");
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
                if(c == 'R' || c == 'r'){
                    struct EmailInbox *index_n = ServiceGetEmailInboxFromHeadByIndex(archived_email, (selected_archived_email- 1));
                    struct UpdateEmailInbox update_email_inbox;
                    update_email_inbox.id = index_n->id;
                    update_email_inbox.sender_name = index_n->sender_name;
                    update_email_inbox.subject = index_n->subject;
                    update_email_inbox.description = index_n->description;
                    update_email_inbox.available = 1;
                    update_email_inbox.read_status = index_n->read_status;
                    update_email_inbox.sent_at = index_n->sent_at;
                    update_email_inbox.receiver_email_id = index_n->receiver_email_id;
                    ServiceUpdateEmailInbox(update_email_inbox);
                    EmailInboxArchive();
                }
                else if(c == 'D' || c == 'd'){
                    struct EmailInbox *index_n = ServiceGetEmailInboxFromHeadByIndex(archived_email, (selected_archived_email- 1));
                    ServiceDeleteEmailInbox(index_n->id);
                    EmailInboxArchive();
                }
                else if(c == KEY_UP){
                    if(selected_archived_email == range_min){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    printf("  ");
                    temp_y--;
                    selected_archived_email--;
                    SetCursorPosition(2, temp_y);
                    printf(">>");
                }
                else if(c == KEY_DOWN){
                    if(selected_archived_email == range_max){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    printf("  ");
                    temp_y++;
                    selected_archived_email++;
                    SetCursorPosition(2, temp_y);
                    printf(">>");
                }
                else if(c == KEY_LEFT){
                    if(inbox_dashboard_page_now == 1){
                        continue;
                    }
                    inbox_dashboard_page_now--;
                    EmailInboxDashboard();
                }
                else if(c == KEY_RIGHT){
                    if(inbox_dashboard_page_now == max_pagination_page){
                        continue;
                    }
                    inbox_dashboard_page_now++;
                    EmailInboxDashboard();
                }
                else if(c == '0' || c == KEY_BACKSPACE){
                    EmailInboxDashboard();
                    break;
                }
            }
            else{
                if(c == '0' || c == KEY_BACKSPACE){
                    EmailInboxDashboard();
                    break;
                }
            }
        }

    }


}

void EmailSentDashboard() {
    PrintHeader();

    struct EmailSent* email_sent = ServiceGetEmailSentByUserID(login_now->id);

    int email_sent_counter = ServiceGetEmailSentSize(email_sent);

    SetCursorPosition(0,8);
    printf("You Have Sent %d Email(s)\n", email_sent_counter);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    int max_pagination_page;
    if(email_sent_counter % 15 == 0){
        max_pagination_page = email_sent_counter / 15;
    }
    else{
        max_pagination_page = email_sent_counter / 15 + 1;
    }

    SetCursorPosition(8,10);
    printf("Receiver");
    SetCursorPosition(28,10);
    printf("Subject");
    SetCursorPosition(80,10);
    printf("Sent At");

    SetCursorPosition(0, 11);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    int inbox_y = 12;
    int temp_y = inbox_y;

    int item_counter_on_page;
    if(max_pagination_page == 0){
        item_counter_on_page = 0;
    }
    else if(sent_dashboard_page_now != max_pagination_page){
        item_counter_on_page = 15;
    }
    else{
        item_counter_on_page = email_sent_counter - (sent_dashboard_page_now - 1) * 15;
    }

    for(int i = inbox_y + (sent_dashboard_page_now - 1) * 15; i < temp_y + (sent_dashboard_page_now - 1) * 15  + item_counter_on_page; i++){
        struct EmailSent *index_n = ServiceGetEmailSentFromHeadByIndex(email_sent, (i - temp_y));

        SetCursorPosition(8,inbox_y);
        if(strlen(index_n->receiver_name) > 22){
            for(int i = 0; i < 22; i++){
                printf("%c", index_n->receiver_name[i]);
            }
        }
        else{
            printf("%s", index_n->receiver_name);
        }
        SetCursorPosition(28,inbox_y);
        if(strlen(index_n->subject) > 45){
            for(int i = 0; i < 45; i++){
                printf("%c", index_n->subject[i]);
            }
            printf("...");
        }
        else{
            printf("%s", index_n->subject);
        }
        SetCursorPosition(80,inbox_y);
        printf("%s", index_n->sent_at);

        inbox_y++;
    }

    SetCursorPosition(0, inbox_y + 1);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));
    SetCursorPosition(27, inbox_y + 2);
    printf("%d//%d", sent_dashboard_page_now, max_pagination_page);

    int selected_email_sent;
    int range_min, range_max;
    int flag = 0;
    if(email_sent_counter > 0){
        selected_email_sent = (sent_dashboard_page_now - 1) * 15 + 1;
        SetCursorPosition(2, temp_y);
        printf(">>");

        range_min = (sent_dashboard_page_now - 1) * 15 + 1;
        if(sent_dashboard_page_now != max_pagination_page){
            range_max = range_min + 14;
        }
        else{
            range_max = email_sent_counter;
        }
        flag = 1;
    }
    else{
        selected_email_sent = 0;
        SetCursorPosition(5, temp_y);
        printf("Nothing Sent Empty");
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
                    struct EmailSent *index_n = ServiceGetEmailSentFromHeadByIndex(email_sent, (selected_email_sent - 1));
                    EmailSentDescription(index_n);
                }
                else if(c == KEY_UP){
                    if(selected_email_sent == range_min){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    printf("  ");
                    temp_y--;
                    selected_email_sent--;
                    SetCursorPosition(2, temp_y);
                    printf(">>");
                }
                else if(c == KEY_DOWN){
                    if(selected_email_sent == range_max){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    printf("  ");
                    temp_y++;
                    selected_email_sent++;
                    SetCursorPosition(2, temp_y);
                    printf(">>");
                }
                else if(c == KEY_LEFT){
                    if(sent_dashboard_page_now == 1){
                        continue;
                    }
                    sent_dashboard_page_now--;
                    EmailSentDashboard();
                }
                else if(c == KEY_RIGHT){
                    if(sent_dashboard_page_now == max_pagination_page){
                        continue;
                    }
                    sent_dashboard_page_now++;
                    EmailSentDashboard();
                }
                else if(c == 'A' || c == 'a'){
                    EmailSentArchive();
                }
                else if(c == 'D' || c == 'd'){
                    struct EmailSent *index_n = ServiceGetEmailSentFromHeadByIndex(email_sent, (selected_email_sent - 1));
                    struct UpdateEmailSent update_email_sent;
                    update_email_sent.id = index_n->id;
                    update_email_sent.receiver_name = index_n->receiver_name;
                    update_email_sent.subject = index_n->subject;
                    update_email_sent.description = index_n->description;
                    update_email_sent.available = 2;
                    update_email_sent.sent_at = index_n->sent_at;
                    update_email_sent.sender_email_id = index_n->sender_email_id;
                    ServiceUpdateEmailSent(update_email_sent);
                    EmailSentDashboard();
                }
                else if(c == '0' || c == KEY_BACKSPACE){
                    inbox_dashboard_page_now = 1;
                    archived_email_inbox_page_now = 1;
                    sent_dashboard_page_now = 1;
                    archived_email_sent_page_now = 1;
                    EmailInboxDashboard();
                }
            }
            else{
                if(c == 'A' || c == 'a'){
                    EmailSentArchive();
                }
                else if(c == '0' || c == KEY_BACKSPACE){
                    inbox_dashboard_page_now = 1;
                    archived_email_inbox_page_now = 1;
                    sent_dashboard_page_now = 1;
                    archived_email_sent_page_now = 1;
                    EmailInboxDashboard();
                }
            }
        }
    }
}

void EmailSentDescription(struct EmailSent *input){
    PrintHeader();

    SetCursorPosition(0,8);
    printf("Receiver : %s at %s\n", input->receiver_name, input->sent_at);
    for(int i = 0; i < 100; i++) cout << char(HORIZON_LINE);
    printf("\nSubject : %s\n\n", input->subject);
    printf("%s\n", descriptionConvert(input->description,99));
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        printf("%s", ctime(&tempTime));

        if(kbhit()){
            char c = getch();

            if(c == KEY_BACKSPACE || c == '0'){
                EmailSentDashboard();
                break;
            }
        }
    }

}

void EmailSentArchive() {
    PrintHeader();

    struct EmailSent *email_sent_archive = ServiceGetArchivedEmailSentByUserID(login_now->id);
    int email_archived_counter = ServiceGetEmailSentSize(email_sent_archive);

    SetCursorPosition(0,8);
    cout << "You Have " << email_archived_counter << " Archived Email(s)\n";
    printf("You Have %d Archived Email(s)\n", email_archived_counter);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    int max_pagination_page;
    if(email_archived_counter % 15 == 0){
        max_pagination_page = email_archived_counter / 15;
    }
    else{
        max_pagination_page = email_archived_counter / 15 + 1;
    }

    SetCursorPosition(8,10);
    printf("Receiver");
    SetCursorPosition(28,10);
    printf("Subject");
    SetCursorPosition(80,10);
    printf("Sent At");

    SetCursorPosition(0, 11);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));

    int inbox_y = 12;
    int temp_y = inbox_y;

    int item_counter_on_page;
    if(max_pagination_page == 0){
        item_counter_on_page = 0;
    }
    else if(archived_email_sent_page_now != max_pagination_page){
        item_counter_on_page = 15;
    }
    else{
        item_counter_on_page = email_archived_counter - (archived_email_sent_page_now - 1) * 15;
    }

    for(int i = inbox_y + (archived_email_sent_page_now - 1); i < temp_y + (archived_email_sent_page_now - 1) + item_counter_on_page; i++){
        struct EmailSent *index_n = ServiceGetEmailSentFromHeadByIndex(email_sent_archive, (i - temp_y));

        SetCursorPosition(8,inbox_y);
        if(strlen(index_n->receiver_name) > 22){
            for(int i = 0; i < 22; i++){
                printf("%c", index_n->receiver_name[i]);
            }
        }
        else{
            printf("%s", index_n->receiver_name);
        }
        SetCursorPosition(28,inbox_y);
        if(strlen(index_n->subject) > 45){
            for(int i = 0; i < 45; i++){
                printf("%c", index_n->subject[i]);
            }
        }
        else{
            printf("%s", index_n->subject);
        }
        SetCursorPosition(80,inbox_y);
        printf("%s", index_n->sent_at);

        inbox_y++;
    }

    SetCursorPosition(0, inbox_y + 1);
    for(int i = 0; i < 100; i++) printf("%c", char(HORIZON_LINE));
    SetCursorPosition(27, inbox_y + 2);
    printf("%d/%d", archived_email_inbox_page_now, max_pagination_page);

    int selected_email_sent;
    int range_min, range_max;
    int flag = 0;

    if(email_archived_counter > 0){
        selected_email_sent = (archived_email_sent_page_now - 1) * 15 + 1;
        SetCursorPosition(2, temp_y);
        printf(">>");

        range_min = (archived_email_sent_page_now - 1) * 15 + 1;
        if(archived_email_sent_page_now != max_pagination_page){
            range_max = range_min + 14;
        }
        else{
            range_max = email_archived_counter;
        }
        flag = 1;
    }
    else{
        selected_email_sent = 0;
        SetCursorPosition(5, temp_y);
        printf("Archived Empty");
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
                if(c == KEY_UP){
                    if(selected_email_sent == range_min){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    printf("  ");
                    temp_y--;
                    selected_email_sent--;
                    SetCursorPosition(2, temp_y);
                    printf(">>");
                }
                else if(c == KEY_DOWN){
                    if(selected_email_sent == range_max){
                        continue;
                    }
                    SetCursorPosition(2, temp_y);
                    printf("  ");
                    temp_y++;
                    selected_email_sent++;
                    SetCursorPosition(2, temp_y);
                    printf(">>");
                }
                else if(c == KEY_LEFT){
                    if(archived_email_sent_page_now == 1){
                        continue;
                    }
                    archived_email_sent_page_now--;
                    EmailSentArchive();
                }
                else if(c == KEY_RIGHT){
                    if(archived_email_sent_page_now == max_pagination_page){
                        continue;
                    }
                    archived_email_sent_page_now++;
                    EmailSentArchive();
                }
                else if(c == 'R' || c == 'r'){
                    struct EmailSent *index_n = ServiceGetEmailSentFromHeadByIndex(email_sent_archive, (selected_email_sent - 1));

                    struct UpdateEmailSent update_email_sent;
                    update_email_sent.id = index_n->id;
                    update_email_sent.receiver_name = index_n->receiver_name;
                    update_email_sent.subject = index_n->subject;
                    update_email_sent.description = index_n->description;
                    update_email_sent.available = 1;
                    update_email_sent.sent_at = index_n->sent_at;
                    update_email_sent.sender_email_id = index_n->sender_email_id;
                    ServiceUpdateEmailSent(update_email_sent);
                    EmailSentArchive();
                }
                else if(c == 'D' || c == 'd'){
                    struct EmailSent *index_n = ServiceGetEmailSentFromHeadByIndex(email_sent_archive, (selected_email_sent - 1));
                    ServiceDeleteEmailSent(index_n->id);
                    EmailSentArchive();
                }
                else if(c == '0' || c == KEY_BACKSPACE){
                    inbox_dashboard_page_now = 1;
                    archived_email_inbox_page_now = 1;
                    sent_dashboard_page_now = 1;
                    archived_email_sent_page_now = 1;
                    EmailSentDashboard();
                }
            }
            else{
                if(c == '0' || c == KEY_BACKSPACE){
                    inbox_dashboard_page_now = 1;
                    archived_email_inbox_page_now = 1;
                    archived_email_sent_page_now = 1;
                    sent_dashboard_page_now = 1;
                    EmailSentDashboard();
                }
            }
        }
    }

}

void EmailWriteMail(){
    PrintHeader();


    char temp[255];
    int index = 0;
    int reset_x_default_position = 20;
    int default_position_x = 20;
    int default_position_y = 10;
    int inputan = 1;

    char* email_list;
    struct NewEmailSent emails_sent;
    struct NewEmailInbox emails_inbox;

    SetCursorPosition(0,9);
    printf("Send Mail to Multiple Users by writing ',' between email. Email that is not registered will not be send");
    SetCursorPosition(0,10);
    printf("Enter Email       : ");
    SetCursorPosition(0,11);
    printf("Enter Subject     : ");
    SetCursorPosition(0,12);
    printf("Enter Description : ");

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        printf("%s", ctime(&tempTime));

        SetCursorVisible(true);
        SetCursorPosition(default_position_x,default_position_y);
        if(kbhit()){
            temp[index] = getch();
            if(temp[index] == 27){
                EmailInboxDashboard();
            }
            if(temp[index] == KEY_ENTER){
                if(index == 0){
                    continue;
				}

                if(inputan == 1){
                    temp[index] = '\0';

                    char *s = strdup(temp);

                    email_list = s;

                    struct Email *AllEmail = ServiceGetEmailAll();

                    int flag = 1;
                    while(AllEmail != NULL){
                        if(strcasecmp(AllEmail->email, email_list) == 0){
                            emails_sent.sender_email_id = login_now->id;
                            emails_sent.available = 1;
                            emails_sent.receiver_name = AllEmail->name;

                            emails_inbox.sender_name = login_now->name;
                            emails_inbox.receiver_email_id = AllEmail->id;
                            emails_inbox.available = 1;
                            emails_inbox.read_status = 2;
                            flag = 0;
                            break;
                        }
                        AllEmail = AllEmail->next;
                    }

                    if(flag){
                        SetCursorPosition(0,14);
                        printf("Not A Valid Email\n");
                        printf("Aborting Operation\n");
                        default_position_x = reset_x_default_position;
                        index = 0;
                        getchar();
                        EmailWriteMail();
                    }
                    else{
                        inputan++;
                        default_position_y++;
                        default_position_x = reset_x_default_position;
                        index = 0;
                    }
                }
                else if(inputan == 2){
                    temp[index] = '\0';

                    char *s = strdup(temp);

                    if(strcasecmp(s, "0") == 0){
                        SetCursorPosition(0,13);
                        printf("Aborting Operation");
                        getchar();
                        EmailInboxDashboard();
                        break;
                    }

                    emails_sent.subject = s;
                    emails_inbox.subject = s;

                    inputan++;
                    default_position_y++;
                    default_position_x = reset_x_default_position;
                    index = 0;
                }
                else if(inputan == 3){
                    temp[index] = '\0';

                    char *s = strdup(temp);

                    emails_sent.description = s;
                    emails_inbox.description = s;

                    break;
                }
                continue;
            }
            if(temp[index] == 32){
                if(inputan == 1){
                    continue;
                }
				SetCursorPosition(default_position_x, default_position_y);

				printf(" ");

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
			if(((temp[index] >= 'A' && temp[index] <= 'Z') || (temp[index] >= 'a' && temp[index] <= 'z') || (temp[index] >= '0' && temp[index] <= '9') || temp[index] == '@' || temp[index] == '.' || temp[index] == ',' || temp[index] == '!' || temp[index] == '#' || temp[index] == '$' || temp[index] == '%'|| temp[index] == '^'|| temp[index] == '&' || temp[index] == '*' || temp[index] == '(' || temp[index] == ')' || temp[index] == '-' || temp[index] == '+' || temp[index] == '`' || temp[index] == '=' || temp[index] == '_') == 0 ){
				continue;
			}

            SetCursorPosition(default_position_x, default_position_y);

            printf("%c", temp[index]);

		    index++;
            default_position_x++;
        }
        Sleep(50);
    }

    char* time_now = GetTimeNow();
    emails_inbox.sent_at = time_now;
    emails_sent.sent_at = time_now;

    ServiceCreateEmailInbox(emails_inbox);
    ServiceCreateEmailSent(emails_sent);

    SetCursorPosition(0,14);
    printf("Emails Successfully Sent");

    while(1){
        SetCursorVisible(false);
        SetCursorPosition(0,7);
        time_t tempTime;
        time(&tempTime);
        printf("%s", ctime(&tempTime));

        if(kbhit()){
            EmailInboxDashboard();
        }
    }


}

void PrintHeader(){
    system("@cls||clear");

    for(int i = 0; i < 7; i++){
        printf("%s\n", gmailSymbol[i]);
    }
}

#endif // DISPLAY_PARAM
