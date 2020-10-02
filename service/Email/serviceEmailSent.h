#ifndef SERVICE_PARAM_EMAIL_SENT
#define SERVICE_PARAM_EMAIL_SENT 1

#include"../../env.h"
#include"../../config/connectDatabase.h"
#include"../../model/Email/modelEmail.h"
#include"serviceEmail.h"
#include"serviceEmailInbox.h"

bool ServiceCreateEmailSent(struct NewEmailSent input);
bool ServiceUpdateEmailSent(struct UpdateEmailSent input);
bool ServiceDeleteEmailSent(int id);
struct EmailSent* ServiceGetEmailSentByID(int id);
struct EmailSent* ServiceGetEmailSentByUserID(int user_id);
struct EmailSent* ServiceGetArchivedEmailSentByUserID(int user_id);
struct EmailSent* ServiceGetEmailSentAll();
struct EmailSent* GetEmailFromHeadByIndex(struct EmailSent *head, int index);

bool ServiceCreateEmailSent(struct NewEmailSent input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "INSERT INTO %s (receiver_name, subject, description, available, sent_at, sender_email_id) VALUES (\'%s\', \'%s\', \'%s\', %d, \'%s\', %d);", env.UserGetEmailSentTableName(), input.receiver_name, input.subject, input.description, input.available, input.sent_at, input.sender_email_id);

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

bool ServiceUpdateEmailSent(struct UpdateEmailSent input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "UPDATE %s SET receiver_name = \'%s\', subject = \'%s\', description = \'%s\', available = %d, sent_at = \'%s\', sender_email_id = %d  WHERE id = %d;", env.UserGetEmailSentTableName(), input.receiver_name, input.subject, input.description, input.available, input.sent_at, input.sender_email_id, input.id);

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

bool ServiceDeleteEmailSent(int id) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "DELETE FROM %s WHERE id = %d;", env.UserGetEmailSentTableName(), id);

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

struct EmailSent* ServiceGetEmailSentByID(int id){
    MYSQL *conn = ConnectDatabase();
    struct EmailSent *email_sent = NULL;

    if(!conn){
        mysql_close(conn);
        return email_sent;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE id = %d;", env.UserGetEmailSentTableName(), id);

    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES* res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            email_sent = (struct EmailSent*) malloc(sizeof(struct EmailSent));
            email_sent->id = Atoi(row[0]);
            email_sent->receiver_name = row[1];
            email_sent->subject = row[2];
            email_sent->description = row[3];
            email_sent->available = Atoi(row[4]);
            email_sent->sent_at = row[5];
            email_sent->sender_email_id = Atoi(row[6]);
            email_sent->next = NULL;
        }

        mysql_close(conn);
        return email_sent;
    }
    else{
        mysql_close(conn);
        return email_sent;
    }
}

struct EmailSent* ServiceGetEmailSentByUserID(int user_id){
    MYSQL *conn = ConnectDatabase();
    struct EmailSent *head, *tail;
    head = tail = NULL;

    if(!conn){
        mysql_close(conn);
        return head;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE sender_email_id = %d AND available = 1 ORDER BY sent_at DESC;", env.UserGetEmailSentTableName(), user_id);

    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES* res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct EmailSent *temp = (struct EmailSent*) malloc(sizeof(struct EmailSent));
            temp->id = Atoi(row[0]);
            temp->receiver_name = row[1];
            temp->subject = row[2];
            temp->description = row[3];
            temp->available = Atoi(row[4]);
            temp->sent_at = row[5];
            temp->sender_email_id = Atoi(row[6]);
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

struct EmailSent* ServiceGetArchivedEmailSentByUserID(int user_id){
    MYSQL *conn = ConnectDatabase();
    struct EmailSent *head, *tail;
    head = tail = NULL;

    if(!conn){
        mysql_close(conn);
        return head;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE sender_email_id = %d AND available = 2 ORDER BY sent_at DESC;", env.UserGetEmailSentTableName(), user_id);

    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES* res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct EmailSent *temp = (struct EmailSent*) malloc(sizeof(struct EmailSent));
            temp->id = Atoi(row[0]);
            temp->receiver_name = row[1];
            temp->subject = row[2];
            temp->description = row[3];
            temp->available = Atoi(row[4]);
            temp->sent_at = row[5];
            temp->sender_email_id = Atoi(row[6]);
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

struct EmailSent* ServiceGetEmailSentAll(){
    MYSQL *conn = ConnectDatabase();
    struct EmailSent *head, *tail;
    head = tail = NULL;

    if(!conn){
        mysql_close(conn);
        return head;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s;", env.UserGetEmailSentTableName());

    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES* res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct EmailSent *temp = (struct EmailSent*) malloc(sizeof(struct EmailSent));
            temp->id = Atoi(row[0]);
            temp->receiver_name = row[1];
            temp->subject = row[2];
            temp->description = row[3];
            temp->available = Atoi(row[4]);
            temp->sent_at = row[5];
            temp->sender_email_id = Atoi(row[6]);
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

struct EmailSent* GetEmailFromHeadByIndex(struct EmailSent *head, int index){
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

#endif // SERVICE_PARAM_EMAIL
