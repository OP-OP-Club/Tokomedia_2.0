#ifndef SERVICE_TOKOMEDIA_SHOP_ACCOUNT_PARAM
#define SERVICE_TOKOMEDIA_SHOP_ACCOUNT_PARAM 1

#include"../../env.h"
#include"../../config/connectDatabase.h"
#include"../../model/Email/modelEmail.h"
#include"../../model/Tokomedia/modelCartTokomedia.h"
#include"../../tools/hasherTools.h"

#include"serviceTokomediaAccount.h"
#include"serviceItemlistTokomedia.h"
#include"serviceCartTokomedia.h"
#include"serviceTransactionTokomedia.h"
#include"serviceOrderDetailsTokomedia.h"

bool ServiceCreateTokomediaShopAccount();
bool ServiceUpdateTokomediaShopAccount();
bool ServiceDeleteTokomediaShopAccount();
struct TokomediaShopAccount* ServiceGetTokomediaShopAccountByID(int id);
struct TokomediaShopAccount* ServiceGetTokomediaShopAccountByEmail(char* email);
struct TokomediaShopAccount* ServiceGetTokomediaShopAccountAll();
bool ServiceFreeTokomediaShopAccountLinkedList(struct TokomediaShopAccount *head);
struct TokomediaShopAccount* GetTokomediaShopAccountFromHeadByIndex(struct TokomediaShopAccount *head, int index);

bool ServiceCreateTokomediaShopAccount(struct NewTokomediaShopAccount input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;
    input.email = ToLower(input.email);

    input.password = sha256Hashing(input.password);

    char query[1000];

    sprintf(query, "INSERT INTO %s (name, email, password, balance, security_code, created_at, last_login) VALUES (\'%s\', \'%s\', \'%s\', %d, \'%s\', \'%s\', \'%s\');", env.UserGetTokomediaShopAccountTableName(), input.name, input.email, input.password, input.balance, input.security_code, input.created_at, input.last_login);

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

bool ServiceUpdateTokomediaShopAccount(struct UpdateTokomediaShopAccount input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;
    input.email = ToLower(input.email);

    input.password = sha256Hashing(input.password);

    char query[1000];

    sprintf(query, "UPDATE %s SET name = \'%s\', email = \'%s\', password = \'%s\', balance = %d, security_code = \'%s\', created_at = \'%s\', last_login = \'%s\' WHERE id = %d;", env.UserGetTokomediaShopAccountTableName(), input.name, input.email, input.password, input.balance, input.security_code, input.created_at, input.last_login, input.id);

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

bool ServiceDeleteTokomediaShopAccount(int id) {
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

struct TokomediaShopAccount* ServiceGetTokomediaShopAccountByID(int id) {
    MYSQL *conn = ConnectDatabase();
    struct TokomediaShopAccount* temp = NULL;

    if(!conn){
        mysql_close(conn);
        return temp;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE id = %d;", env.UserGetTokomediaShopAccountTableName(), id);
    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            temp = (struct TokomediaShopAccount*) malloc(sizeof(struct TokomediaShopAccount));
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

struct TokomediaShopAccount* ServiceGetTokomediaShopAccountByEmail(char* email){
    MYSQL *conn = ConnectDatabase();
    struct TokomediaShopAccount* temp = NULL;

    if(!conn){
        mysql_close(conn);
        return temp;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE email = \'%s\';", env.UserGetTokomediaShopAccountTableName(), email);
    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            temp = (struct TokomediaShopAccount*) malloc(sizeof(struct TokomediaShopAccount));
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

struct TokomediaShopAccount* ServiceGetTokomediaShopAccountAll() {
    MYSQL *conn = ConnectDatabase();
    struct TokomediaShopAccount *head, *tail;
    head = tail = NULL;

    if(!conn){
        mysql_close(conn);
        return head;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s;", env.UserGetTokomediaShopAccountTableName());
    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct TokomediaShopAccount *temp = (struct TokomediaShopAccount*) malloc(sizeof(struct TokomediaShopAccount));
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

bool ServiceFreeTokomediaShopAccountLinkedList(struct TokomediaShopAccount *head){
    struct TokomediaShopAccount* temp = head;

    while(temp != NULL){
        head = head->next;
        free(temp);
        temp = head;
    }

    return true;
}

struct TokomediaShopAccount* GetTokomediaShopAccountFromHeadByIndex(struct TokomediaShopAccount *head, int index){
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

#endif // SERVICE_TOKOMEDIA_SHOP_ACCOUNT_PARAM
