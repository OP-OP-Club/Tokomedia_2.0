#ifndef SERVICE_PARAM_CART_TOKOMEDIA
#define SERVICE_PARAM_CART_TOKOMEDIA 1

#include"../../env.h"
#include"../../config/connectDatabase.h"
#include"../../model/Email/modelEmail.h"
#include"../../model/Tokomedia/modelTransactionTokomedia.h"
#include"../../tools/hasherTools.h"

#include"serviceOrderDetailsTokomedia.h"
#include"serviceTransactionTokomedia.h"
#include"serviceTokomediaShopAccount.h"
#include"serviceTokomediaAccount.h"
#include"serviceItemlistTokomedia.h"

bool ServiceCreateTransactionTokomedia(struct NewTransactionTokomedia input);
bool ServiceUpdateTransactionTokomedia(struct UpdateTransactionTokomedia input);
bool ServiceDeleteTransactionTokomedia(int id);
struct TransactionTokomedia* ServiceGetTransactionTokomediaByID(int id);
struct TransactionTokomedia* ServiceGetTransactionTokomediaByTokomediaUserID(int id);
//struct TransactionTokomedia* ServiceGetTransactionTokomediaAll();
bool ServiceFreeTransactionTokomediaLinkedList(struct TransactionTokomedia *head);
struct TransactionTokomedia* GetTransactionTokomediaFromHeadByIndex(struct TransactionTokomedia *head, int index);

bool ServiceCreateTransactionTokomedia(struct NewTransactionTokomedia input){
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "INSERT INTO %s (status, total_price, created_at, updated_at, tokomedia_user_id) VALUES (%d, %d, \'%s\', \'%s\', %d);", env.UserGetTransactionTokomediaTableName(), input.status, input.total_price, input.created_at, input.updated_at, input.tokomedia_user_id);

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

bool ServiceUpdateTransactionTokomedia(struct UpdateTransactionTokomedia input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "UPDATE %s SET status = %d, total_price = %d, created_at = \'%s\', updated_at = \'%s\', tokomedia_user_id = %d WHERE id = %d;", env.UserGetTransactionTokomediaTableName(), input.status, input.total_price, input.created_at, input.updated_at, input.tokomedia_user_id, input.id);

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

bool ServiceDeleteTransactionTokomedia(int id){
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "DELETE FROM %s WHERE id = %d;", env.UserGetTransactionTokomediaTableName(), id);

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

struct TransactionTokomedia* ServiceGetTransactionTokomediaByID(int id){
    MYSQL *conn = ConnectDatabase();
    struct TransactionTokomedia* temp = NULL;

    if(!conn){
        mysql_close(conn);
        return temp;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE id = %d;", env.UserGetTransactionTokomediaTableName(), id);
    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            temp = (struct TransactionTokomedia*) malloc(sizeof(struct TransactionTokomedia));
            temp->id = Atoi(row[0]);
            temp->status = Atoi(row[1]);
            temp->total_price = Atoi(row[2]);
            temp->created_at = row[3];
            temp->updated_at = row[4];
            temp->tokomedia_user_id = Atoi(row[5]);
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

struct TransactionTokomedia* ServiceGetTransactionTokomediaByTokomediaUserID(int id){
    MYSQL *conn = ConnectDatabase();
    struct TransactionTokomedia *head, *tail;
    head = tail = NULL;

    if(!conn){
        mysql_close(conn);
        return head;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE tokomedia_user_id = %d;", env.UserGetTransactionTokomediaTableName(), id);
    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct TransactionTokomedia *temp = (struct TransactionTokomedia*) malloc(sizeof(struct TransactionTokomedia));
            temp->id = Atoi(row[0]);
            temp->status = Atoi(row[1]);
            temp->total_price = Atoi(row[2]);
            temp->created_at = row[3];
            temp->updated_at = row[4];
            temp->tokomedia_user_id = Atoi(row[5]);
            temp->next = NULL;
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

//struct TransactionTokomedia* ServiceGetTransactionTokomediaAll(){
//    MYSQL *conn = ConnectDatabase();
//    struct TransactionTokomedia *head, *tail;
//    head = tail = NULL;
//
//    if(!conn){
//        mysql_close(conn);
//        return head;
//    }
//
//    Environment env;
//
//    char query[1000];
//
//    sprintf(query, "SELECT * FROM %s;", env.UserGetTokomediaUserAccountTableName());
//    const char *q = query;
//
//    int q_state = 0;
//    q_state = mysql_query(conn, q);
//
//    if(!q_state){
//        MYSQL_RES *res = mysql_store_result(conn);
//        MYSQL_ROW row;
//
//        while(row = mysql_fetch_row(res)){
//            struct TransactionTokomedia *temp = (struct TransactionTokomedia*) malloc(sizeof(struct TransactionTokomedia));
//            temp->id = Atoi(row[0]);
//            temp->item_name = row[1];
//            temp->price_per_unit = Atoi(row[2]);
//            temp->discount_per_unit = Atoi(row[3]);
//            temp->stock = Atoi(row[4]);
//            temp->created_at = row[5];
//            temp->updated_at = row[6];
//            temp->tokomedia_shop_id = Atoi(row[7]);
//            temp->next = NULL;
//
//            if(head == NULL){
//                head = tail = temp;
//            }
//            else{
//                tail->next = temp;
//                tail = tail->next;
//            }
//        }
//
//        mysql_close(conn);
//        return head;
//    }
//    else{
//        mysql_close(conn);
//        return head;
//    }
//}

bool ServiceFreeTransactionTokomediaLinkedList(struct TransactionTokomedia *head){
    struct TransactionTokomedia* temp = head;

    while(temp != NULL){
        head = head->next;
        free(temp);
        temp = head;
    }

    return true;
}

struct TransactionTokomedia* GetTransactionTokomediaFromHeadByIndex(struct TransactionTokomedia *head, int index){
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

#endif // SERVICE_PARAM_CART_TOKOMEDIA
