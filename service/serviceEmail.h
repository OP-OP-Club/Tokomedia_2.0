#ifndef SERVICE_PARAM_EMAIL
#define SERVICE_PARAM_EMAIL 1

//#include"serviceEmailSent.h"
#include"serviceEmailInbox.h"
#include"../env.h"
#include"../config/connectDatabase.h"
#include"../model/modelEmail.h"
#include"../tools/hasherTools.h"

bool ServiceCreateEmail();
bool ServiceUpdateEmail();
bool ServiceDeleteEmail();
struct Email* ServiceGetEmailByID(int id);
struct Email* ServiceGetEmailByEmail(char* email);
struct Email* ServiceGetEmailAll();

bool ServiceCreateEmail(struct NewEmail input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;
    input.email = ToLower(input.email);

    input.password = sha256Hashing(input.password);

    char query[1000];

    sprintf(query, "INSERT INTO %s (name, password, email, created_at, last_login) VALUES (\'%s\', \'%s\', \'%s\', \'%s\', \'%s\');", env.UserGetEmailTableName(), input.name, input.password, input.email, input.created_at, input.last_login);

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

bool ServiceUpdateEmail(struct UpdateEmail input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "UPDATE %s SET name = \'%s\', password = \'%s\', email = \'%s\', created_at = \'%s\', last_login = \'%s\' WHERE id = %d;", env.UserGetEmailTableName(), input.name, input.password, input.email, input.created_at, input.last_login, input.id);

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

bool ServiceDeleteEmail(int id) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;
    char query[1000];

    sprintf(query, "DELETE FROM %s WHERE id = %d;", env.UserGetEmailTableName(), id);
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

struct Email* ServiceGetEmailByID(int id) {
    MYSQL *conn = ConnectDatabase();
    struct Email* temp = NULL;

    if(!conn){
        mysql_close(conn);
        return temp;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE id = %d;", env.UserGetEmailTableName(), id);
    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            temp = (struct Email*) malloc(sizeof(struct Email));
            temp->id = Atoi(row[0]);
            temp->name = row[1];
            temp->password = row[2];
            temp->email = row[3];
            temp->created_at = row[4];
            temp->last_login = row[5];
            temp->next = NULL;
        }

        mysql_close(conn);
        return temp;
    }
    else{
        mysql_close(conn);
        return temp;
    }
}

struct Email* ServiceGetEmailByEmail(char* email){
    MYSQL *conn = ConnectDatabase();
    struct Email* temp = NULL;

    if(!conn){
        mysql_close(conn);
        return temp;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE email = \'%s\';", env.UserGetEmailTableName(), email);
    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            temp = (struct Email*) malloc(sizeof(struct Email));
            temp->id = Atoi(row[0]);
            temp->name = row[1];
            temp->password = row[2];
            temp->email = row[3];
            temp->created_at = row[4];
            temp->last_login = row[5];
            temp->next = NULL;
        }

        mysql_close(conn);
        return temp;
    }
    else{
        mysql_close(conn);
        return temp;
    }
}

struct Email* ServiceGetEmailAll() {
    MYSQL *conn = ConnectDatabase();
    struct Email *head, *tail;
    head = tail = NULL;

    if(!conn){
        mysql_close(conn);
        return head;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s;", env.UserGetEmailTableName());
    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct Email *emailTemp = (struct Email*) malloc(sizeof(struct Email));
            emailTemp->id = Atoi(row[0]);
            emailTemp->name = row[1];
            emailTemp->password = row[2];
            emailTemp->email = row[3];
            emailTemp->created_at = row[4];
            emailTemp->last_login = row[5];
            emailTemp->next = NULL;

            if(head == NULL){
                head = tail = emailTemp;
            }
            else{
                tail->next = emailTemp;
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

bool ServiceFreeEmailLinkedList(struct Email *head){
    struct Email* temp = head;

    while(temp != NULL){
        head = head->next;
        free(temp);
        temp = head;
    }

    return true;
}

#endif // SERVICE_PARAM
