#ifndef SERVICE_EMAIL_INBOX_PARAM
#define SERVICE_EMAIL_INBOX_PARAM 1

#include"../../env.h"
#include"../../config/connectDatabase.h"
#include"../../model/Email/modelEmail.h"
#include"../../tools/cursorTools.h"

#include"serviceEmail.h"
#include"serviceEmailSent.h"

bool ServiceCreateEmailInbox(struct NewEmailInbox input);
bool ServiceUpdateEmailInbox(struct UpdateEmailInbox input);
bool ServiceDeleteEmailInbox(int id);
int ServiceGetEmailInboxSize(struct EmailInbox *head);
struct EmailInbox* ServiceGetEmailInboxByID(int id);
struct EmailInbox* ServiceGetEmailInboxByUserID(int user_id);
struct EmailInbox* ServiceGetArchivedEmailInboxByUserID(int user_id);
struct EmailInbox* ServiceGetEmailInboxAll();
struct EmailInbox* ServiceGetEmailInboxFromHeadByIndex(struct EmailInbox *head, int index);

bool ServiceCreateEmailInbox(struct NewEmailInbox input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "INSERT INTO %s (sender_name, subject, description, available, read_status, sent_at, receiver_email_id) VALUES (\'%s\', \'%s\', \'%s\', %d, %d, \'%s\', %d);", env.UserGetEmailInboxTableName(), input.sender_name, input.subject, input.description, input.available, input.read_status, input.sent_at, input.receiver_email_id);

    const char *q = query;

    getchar();

    int q_state = 0;
    q_state = mysql_query(conn, q);

    mysql_close(conn);
    if(!q_state){
        return true;
    }
    else{
        printf("FAIL\n");
        return false;
    }
}

bool ServiceUpdateEmailInbox(struct UpdateEmailInbox input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "UPDATE %s SET sender_name = \'%s\', subject = \'%s\', description = \'%s\', available = %d, read_status = %d, sent_at = \'%s\', receiver_email_id = %d WHERE id = %d;", env.UserGetEmailInboxTableName(), input.sender_name, input.subject, input.description, input.available, input.read_status, input.sent_at, input.receiver_email_id, input.id);

    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    mysql_close(conn);
    if(!q_state){
        return true;
    }
    else{
        return false;
    }
}

bool ServiceDeleteEmailInbox(int id) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "DELETE FROM %s WHERE id = %d;", env.UserGetEmailInboxTableName(), id);

    const char *q = query;

    printf("%s\n", query);


    int q_state = 0;
    q_state = mysql_query(conn, q);

    mysql_close(conn);
    if(!q_state){
        return true;
    }
    else{
        return false;
    }
}

int ServiceGetEmailInboxSize(struct EmailInbox *head){
    int counter = 0;

    while(head != NULL){
        counter++;
        head = head->next;
    }

    return counter;
}

struct EmailInbox* ServiceGetEmailInboxByID(int id) {
    MYSQL *conn = ConnectDatabase();
    struct EmailInbox *email_inbox = NULL;

    if(!conn){
        mysql_close(conn);
        return email_inbox;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE id = %d;", env.UserGetEmailInboxTableName(), id);

    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES* res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            email_inbox = (struct EmailInbox*) malloc(sizeof(struct EmailInbox));
            email_inbox->id = Atoi(row[0]);
            email_inbox->sender_name = row[1];
            email_inbox->subject = row[2];
            email_inbox->description = row[3];
            email_inbox->available = Atoi(row[4]);
            email_inbox->read_status = Atoi(row[5]);
            email_inbox->sent_at = row[6];
            email_inbox->receiver_email_id = Atoi(row[7]);
            email_inbox->next = NULL;
        }

        mysql_close(conn);
        return email_inbox;
    }
    else{
        mysql_close(conn);
        return email_inbox;
    }
}

struct EmailInbox* ServiceGetEmailInboxByUserID(int user_id) {
    MYSQL *conn = ConnectDatabase();
    struct EmailInbox *head, *tail;
    head = tail = NULL;

    if(!conn){
        mysql_close(conn);
        return head;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE receiver_email_id = %d AND available = 1 ORDER BY sent_at DESC;", env.UserGetEmailInboxTableName(), user_id);

    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES* res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct EmailInbox *temp = (struct EmailInbox*) malloc(sizeof(struct EmailInbox));
            temp->id = Atoi(row[0]);
            temp->sender_name = row[1];
            temp->subject = row[2];
            temp->description = row[3];
            temp->available = Atoi(row[4]);
            temp->read_status = Atoi(row[5]);
            temp->sent_at = row[6];
            temp->receiver_email_id = Atoi(row[7]);
            temp->next = NULL;

            if(head == NULL){
                head = tail = temp;
            }
            else{
                tail->next = temp;
                tail = tail->next;
            }
        }

        mysql_close(conn);
        return head;
    }
    else{
        mysql_close(conn);
        return head;
    }
}

struct EmailInbox* ServiceGetArchivedEmailInboxByUserID(int user_id) {
    MYSQL *conn = ConnectDatabase();
    struct EmailInbox *head, *tail;
    head = tail = NULL;

    if(!conn){
        mysql_close(conn);
        return head;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE receiver_email_id = %d AND available = 2 ORDER BY sent_at DESC;", env.UserGetEmailInboxTableName(), user_id);

    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES* res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct EmailInbox *temp = (struct EmailInbox*) malloc(sizeof(struct EmailInbox));
            temp->id = Atoi(row[0]);
            temp->sender_name = row[1];
            temp->subject = row[2];
            temp->description = row[3];
            temp->available = Atoi(row[4]);
            temp->read_status = Atoi(row[5]);
            temp->sent_at = row[6];
            temp->receiver_email_id = Atoi(row[7]);
            temp->next = NULL;

            if(head == NULL){
                head = tail = temp;
            }
            else{
                tail->next = temp;
                tail = tail->next;
            }
        }

        mysql_close(conn);
        return head;
    }
    else{
        mysql_close(conn);
        return head;
    }
}

struct EmailInbox* ServiceGetEmailInboxAll() {
    MYSQL *conn = ConnectDatabase();
    struct EmailInbox *head, *tail;
    head = tail = NULL;

    if(!conn){
        mysql_close(conn);
        return head;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s;", env.UserGetEmailInboxTableName());

    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES* res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct EmailInbox *temp = (struct EmailInbox*) malloc(sizeof(struct EmailInbox));
            temp->id = Atoi(row[0]);
            temp->sender_name = row[1];
            temp->subject = row[2];
            temp->description = row[3];
            temp->available = Atoi(row[4]);
            temp->read_status = Atoi(row[5]);
            temp->sent_at = row[6];
            temp->receiver_email_id = Atoi(row[7]);
            temp->next = NULL;

            if(head == NULL){
                head = tail = temp;
            }
            else{
                tail->next = temp;
                tail = tail->next;
            }
        }

        mysql_close(conn);
        return head;
    }
    else{
        mysql_close(conn);
        return head;
    }
}

struct EmailInbox* ServiceGetEmailInboxFromHeadByIndex(struct EmailInbox *head, int index){
   MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return head;
    }

    while(index != 0){
        head = head->next;
        index--;
    }

    return head;
}

#endif // SERVICE_EMAIL_INBOX_PARAM
