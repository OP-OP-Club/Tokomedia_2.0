#ifndef SERVICE_TOKOMEDIA_ACCOUNT_PARAM
#define SERVICE_TOKOMEDIA_ACCOUNT_PARAM 1

#include"../../env.h"
#include"../../config/connectDatabase.h"
#include"../../model/Email/modelEmail.h"
#include"../../model/Tokomedia/modelCartTokomedia.h"
#include"../../tools/hasherTools.h"

#include"serviceTokomediaShopAccount.h"
#include"serviceItemlistTokomedia.h"
#include"serviceCartTokomedia.h"
#include"serviceTransactionTokomedia.h"
#include"serviceOrderDetailsTokomedia.h"

bool ServiceCreateTokomediaUserAccount(struct NewTokomediaUserAccount);
bool ServiceUpdateTokomediaUserAccount(struct UpdateTokomediaUserAccount);
bool ServiceDeleteTokomediaUserAccount(int id);
struct TokomediaUserAccount* ServiceGetTokomediaUserAccountByID(int id);
struct TokomediaUserAccount* ServiceGetTokomediaUserAccountByEmail(char* email);
struct TokomediaUserAccount* ServiceGetTokomediaUserAccountAll();
bool ServiceFreeTokomediaUserAccountLinkedList(struct TokomediaUserAccount *head);
struct TokomediaUserAccount* GetTokomediaUserAccountFromHeadByIndex(struct TokomediaUserAccount *head, int index);

bool ServiceCreateTokomediaUserAccount(struct NewTokomediaUserAccount input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;
    input.email = ToLower(input.email);

    input.password = sha256Hashing(input.password);

    char query[1000];

    sprintf(query, "INSERT INTO %s (name, email, password, balance, security_code, created_at, last_login) VALUES (\'%s\', \'%s\', \'%s\', %d, \'%s\', \'%s\', \'%s\');", env.UserGetTokomediaUserAccountTableName(), input.name, input.email, input.password, input.balance, input.security_code, input.created_at, input.last_login);

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

bool ServiceUpdateTokomediaUserAccount(struct UpdateTokomediaUserAccount input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;
    input.email = ToLower(input.email);

    input.password = sha256Hashing(input.password);

    char query[1000];

    sprintf(query, "UPDATE %s SET name = \'%s\', email = \'%s\', password = \'%s\', balance = %d, security_code = \'%s\', created_at = \'%s\', last_login = \'%s\' WHERE id = %d;", env.UserGetTokomediaUserAccountTableName(), input.name, input.email, input.password, input.balance, input.security_code, input.created_at, input.last_login, input.id);

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

bool ServiceDeleteTokomediaUserAccount(int id) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "DELETE FROM %s WHERE id = %d;", id);

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

struct TokomediaUserAccount* ServiceGetTokomediaUserAccountByID(int id) {
    MYSQL *conn = ConnectDatabase();
    struct TokomediaUserAccount* temp = NULL;

    if(!conn){
        mysql_close(conn);
        return temp;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE id = %d;", env.UserGetTokomediaUserAccountTableName(), id);
    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            temp = (struct TokomediaUserAccount*) malloc(sizeof(struct TokomediaUserAccount));
            temp->id = Atoi(row[0]);
            temp->name = row[1];
            temp->email = row[2];
            temp->password = row[3];
            temp->balance = Atoi(row[4]);
            temp->security_code = row[5];
            temp->created_at = row[6];
            temp->last_login = row[7];
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

struct TokomediaUserAccount* ServiceGetTokomediaUserAccountByEmail(char* email){
    MYSQL *conn = ConnectDatabase();
    struct TokomediaUserAccount* temp = NULL;

    if(!conn){
        mysql_close(conn);
        return temp;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE email = \'%s\';", env.UserGetTokomediaUserAccountTableName(), email);
    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            temp = (struct TokomediaUserAccount*) malloc(sizeof(struct TokomediaUserAccount));
            temp->id = Atoi(row[0]);
            temp->name = row[1];
            temp->email = row[2];
            temp->password = row[3];
            temp->balance = Atoi(row[4]);
            temp->security_code = row[5];
            temp->created_at = row[6];
            temp->last_login = row[7];
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

struct TokomediaUserAccount* ServiceGetTokomediaUserAccountAll() {
    MYSQL *conn = ConnectDatabase();
    struct TokomediaUserAccount *head, *tail;
    head = tail = NULL;

    if(!conn){
        mysql_close(conn);
        return head;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s;", env.UserGetTokomediaUserAccountTableName());
    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct TokomediaUserAccount *temp = (struct TokomediaUserAccount*) malloc(sizeof(struct TokomediaUserAccount));
            temp->id = Atoi(row[0]);
            temp->name = row[1];
            temp->email = row[2];
            temp->password = row[3];
            temp->balance = Atoi(row[4]);
            temp->security_code = row[5];
            temp->created_at = row[6];
            temp->last_login = row[7];
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

bool ServiceFreeTokomediaUserAccountLinkedList(struct TokomediaUserAccount *head){
    struct TokomediaUserAccount* temp = head;

    while(temp != NULL){
        head = head->next;
        free(temp);
        temp = head;
    }

    return true;
}

struct TokomediaUserAccount* GetTokomediaUserAccountFromHeadByIndex(struct TokomediaUserAccount *head, int index){
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

#endif // SERVICE_TOKOMEDIA_ACCOUNT_PARAM
