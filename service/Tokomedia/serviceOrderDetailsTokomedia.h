#ifndef SERVICE_PARAM_ORDER_DETAILS_TOKOMEDIA
#define SERVICE_PARAM_ORDER_DETAILS_TOKOMEDIA 1

#include"../../env.h"
#include"../../config/connectDatabase.h"
#include"../../model/Email/modelEmail.h"
#include"../../model/Tokomedia/modelOrderDetailsTokomedia.h"
#include"../../tools/hasherTools.h"

#include"serviceTokomediaShopAccount.h"
#include"serviceTokomediaAccount.h"
#include"serviceItemlistTokomedia.h"
#include"serviceTransactionTokomedia.h"
#include"serviceOrderDetailsTokomedia.h"

bool ServiceCreateOrderDetailsTokomedia(struct NewOrderDetailsTokomedia input);
bool ServiceUpdateOrderDetailsTokomedia(struct UpdateOrderDetailsTokomedia input);
bool ServiceDeleteOrderDetailsTokomedia(int id);
int ServiceGetOrderDetailsTokomediaSize(struct OrderDetailsTokomedia *head);
struct OrderDetailsTokomedia* ServiceGetOrderDetailsTokomediaByID(int id);
struct OrderDetailsTokomedia* ServiceGetOrderDetailsTokomediaByTokomediaShopID(int shop_id);
//struct OrderDetailsTokomedia* ServiceGetOrderDetailsTokomediaAll();
bool ServiceFreeOrderDetailsTokomediaLinkedList(struct OrderDetailsTokomedia *head);
struct OrderDetailsTokomedia* GetOrderDetailsTokomediaFromHeadByIndex(struct OrderDetailsTokomedia *head, int index);
struct OrderDetailsTokomedia* ServiceGetOrderDetailsTokomediaPaginationByTransactionID(int limit, int page, int order_by, int transaction_id);
struct OrderDetailsTokomedia* ServiceGetOrderDetailsTokomediaPaginationByTokomediaShopID(int limit, int page, int order_by, int shop_id);

bool ServiceCreateOrderDetailsTokomedia(struct NewOrderDetailsTokomedia input){
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "INSERT INTO %s (item_name, status, price_per_unit, qty, total_price, created_at, updated_at, itemlist_id, tokomedia_shop_id, transaction_id) VALUES (\'%s\', %d, %d, %d, %d, \'%s\', \'%s\', %d, %d, %d);", env.UserGetOrderDetailsTokomediaTableName(), input.item_name, input.status, input.price_per_unit, input.qty, input.total_price, input.created_at, input.updated_at, input.itemlist_id, input.tokomedia_shop_id, input.transaction_id);

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

bool ServiceUpdateOrderDetailsTokomedia(struct UpdateOrderDetailsTokomedia input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "UPDATE %s SET item_name = \'%s\', status = %d, price_per_unit = %d, qty = %d, total_price = %d, created_at = \'%s\', updated_at = \'%s\', itemlist_id = %d, tokomedia_shop_id = %d, transaction_id = %d WHERE id = %d;", env.UserGetOrderDetailsTokomediaTableName(), input.item_name, input.status, input.price_per_unit, input.qty, input.total_price, input.created_at, input.updated_at, input.itemlist_id, input.tokomedia_shop_id, input.transaction_id, input.id);

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

int ServiceGetOrderDetailsTokomediaSize(struct OrderDetailsTokomedia *head){
    int counter = 0;

    while(head != NULL){
        counter++;
        head = head->next;
    }

    return counter;
}

bool ServiceDeleteOrderDetailsTokomedia(int id){
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "DELETE FROM %s WHERE id = %d;", env.UserGetOrderDetailsTokomediaTableName(), id);

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

struct OrderDetailsTokomedia* ServiceGetOrderDetailsTokomediaByID(int id){
    MYSQL *conn = ConnectDatabase();
    struct OrderDetailsTokomedia* temp = NULL;

    if(!conn){
        mysql_close(conn);
        return temp;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE id = %d;", env.UserGetOrderDetailsTokomediaTableName(), id);
    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            temp = (struct OrderDetailsTokomedia*) malloc(sizeof(struct OrderDetailsTokomedia));
            temp->id = Atoi(row[0]);
            temp->item_name = row[1];
            temp->status = Atoi(row[2]);
            temp->price_per_unit = Atoi(row[3]);
            temp->qty = Atoi(row[4]);
            temp->total_price = Atoi(row[5]);
            temp->created_at = row[6];
            temp->updated_at = row[7];
            temp->itemlist_id = Atoi(row[8]);
            temp->tokomedia_shop_id = Atoi(row[9]);
            temp->transaction_id = Atoi(row[10]);
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

struct OrderDetailsTokomedia* ServiceGetOrderDetailsTokomediaByTransactionID(int transaction_id){
    MYSQL *conn = ConnectDatabase();
    struct OrderDetailsTokomedia *head, *tail;
    head = tail = NULL;

    if(!conn){
        mysql_close(conn);
        return head;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE transaction_id = %d;", env.UserGetOrderDetailsTokomediaTableName(), transaction_id);
    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct OrderDetailsTokomedia *temp = (struct OrderDetailsTokomedia*) malloc(sizeof(struct OrderDetailsTokomedia));
            temp->id = Atoi(row[0]);
            temp->item_name = row[1];
            temp->status = Atoi(row[2]);
            temp->price_per_unit = Atoi(row[3]);
            temp->qty = Atoi(row[4]);
            temp->total_price = Atoi(row[5]);
            temp->created_at = row[6];
            temp->updated_at = row[7];
            temp->itemlist_id = Atoi(row[8]);
            temp->tokomedia_shop_id = Atoi(row[9]);
            temp->transaction_id = Atoi(row[10]);
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

struct OrderDetailsTokomedia* ServiceGetOrderDetailsTokomediaByTokomediaShopID(int shop_id){
    MYSQL *conn = ConnectDatabase();
    struct OrderDetailsTokomedia *head, *tail;
    head = tail = NULL;

    if(!conn){
        mysql_close(conn);
        return head;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE tokomedia_shop_id = %d;", env.UserGetOrderDetailsTokomediaTableName(), shop_id);
    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct OrderDetailsTokomedia *temp = (struct OrderDetailsTokomedia*) malloc(sizeof(struct OrderDetailsTokomedia));
            temp->id = Atoi(row[0]);
            temp->item_name = row[1];
            temp->status = Atoi(row[2]);
            temp->price_per_unit = Atoi(row[3]);
            temp->qty = Atoi(row[4]);
            temp->total_price = Atoi(row[5]);
            temp->created_at = row[6];
            temp->updated_at = row[7];
            temp->itemlist_id = Atoi(row[8]);
            temp->tokomedia_shop_id = Atoi(row[9]);
            temp->transaction_id = Atoi(row[10]);
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

//struct OrderDetailsTokomedia* ServiceGetOrderDetailsTokomediaAll(){
//    MYSQL *conn = ConnectDatabase();
//    struct OrderDetailsTokomedia *head, *tail;
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
//            struct OrderDetailsTokomedia *temp = (struct OrderDetailsTokomedia*) malloc(sizeof(struct OrderDetailsTokomedia));
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

bool ServiceFreeOrderDetailsTokomediaLinkedList(struct OrderDetailsTokomedia *head){
    struct OrderDetailsTokomedia* temp = head;

    while(temp != NULL){
        head = head->next;
        free(temp);
        temp = head;
    }

    return true;
}

struct OrderDetailsTokomedia* GetOrderDetailsTokomediaFromHeadByIndex(struct OrderDetailsTokomedia *head, int index){
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

struct OrderDetailsTokomedia* ServiceGetOrderDetailsTokomediaPaginationByTransactionID(int limit, int page, int order_by, int transaction_id){
    MYSQL *conn = ConnectDatabase();
    struct OrderDetailsTokomedia *head, *tail;
    head = tail = NULL;

    if(!conn){
        mysql_close(conn);
        return head;
    }

    Environment env;

    int offset = (page - 1) * limit;

    char query[1000];
    char temp[1000];
    sprintf(temp, "SELECT id, item_name, status, price_per_unit, qty, total_price, created_at, updated_at, itemlist_id, tokomedia_shop_id, transaction_id FROM %s WHERE transaction_id = %d", env.UserGetOrderDetailsTokomediaTableName(), transaction_id);

    if(order_by == 1){
        sprintf(temp, "%s ORDER BY item_name ASC", temp);
    }
    else if(order_by == 2){
        sprintf(temp, "%s ORDER BY item_name DESC", temp);
    }
    else if(order_by == 3){
        sprintf(temp, "%s ORDER BY price_per_unit ASC", temp);
    }
    else if(order_by == 4){
        sprintf(temp, "%s ORDER BY price_per_unit DESC", temp);
    }
    else if(order_by == 5){
        sprintf(temp, "%s ORDER BY qty ASC", temp);
    }
    else if(order_by == 6){
        sprintf(temp, "%s ORDER BY qty DESC", temp);
    }
    else if(order_by == 7){
        sprintf(temp, "%s ORDER BY total_price ASC", temp);
    }
    else if(order_by == 8){
        sprintf(temp, "%s ORDER BY total_price DESC", temp);
    }
    else if(order_by == 9){
        sprintf(temp, "%s ORDER BY created_at ASC", temp);
    }
    else if(order_by == 10){
        sprintf(temp, "%s ORDER BY created_at DESC", temp);
    }
    else{
        sprintf(temp, "%s", temp);
    }

    sprintf(query, "%s LIMIT %d, %d;", temp, offset, limit);

    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct OrderDetailsTokomedia *temp = (struct OrderDetailsTokomedia*) malloc(sizeof(struct OrderDetailsTokomedia));
            temp->id = Atoi(row[0]);
            temp->item_name = row[1];
            temp->status = Atoi(row[2]);
            temp->price_per_unit = Atoi(row[3]);
            temp->qty = Atoi(row[4]);
            temp->total_price = Atoi(row[5]);
            temp->created_at = row[6];
            temp->updated_at = row[7];
            temp->itemlist_id = Atoi(row[8]);
            temp->tokomedia_shop_id = Atoi(row[9]);
            temp->transaction_id = Atoi(row[10]);
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

struct OrderDetailsTokomedia* ServiceGetOrderDetailsTokomediaPaginationByTokomediaShopID(int limit, int page, int order_by, int shop_id){
    MYSQL *conn = ConnectDatabase();
    struct OrderDetailsTokomedia *head, *tail;
    head = tail = NULL;

    if(!conn){
        mysql_close(conn);
        return head;
    }

    Environment env;

    int offset = (page - 1) * limit;

    char query[1000];
    char temp[1000];
    sprintf(temp, "SELECT id, item_name, status, price_per_unit, qty, total_price, created_at, updated_at, itemlist_id, tokomedia_shop_id, transaction_id FROM %s WHERE tokomedia_shop_id = %d", env.UserGetOrderDetailsTokomediaTableName(), shop_id);

    if(order_by == 1){
        sprintf(temp, "%s ORDER BY item_name ASC", temp);
    }
    else if(order_by == 2){
        sprintf(temp, "%s ORDER BY item_name DESC", temp);
    }
    else if(order_by == 3){
        sprintf(temp, "%s ORDER BY price_per_unit ASC", temp);
    }
    else if(order_by == 4){
        sprintf(temp, "%s ORDER BY price_per_unit DESC", temp);
    }
    else if(order_by == 5){
        sprintf(temp, "%s ORDER BY qty ASC", temp);
    }
    else if(order_by == 6){
        sprintf(temp, "%s ORDER BY qty DESC", temp);
    }
    else if(order_by == 7){
        sprintf(temp, "%s ORDER BY total_price ASC", temp);
    }
    else if(order_by == 8){
        sprintf(temp, "%s ORDER BY total_price DESC", temp);
    }
    else if(order_by == 9){
        sprintf(temp, "%s ORDER BY created_at ASC", temp);
    }
    else if(order_by == 10){
        sprintf(temp, "%s ORDER BY created_at DESC", temp);
    }
    else{
        sprintf(temp, "%s", temp);
    }

    sprintf(query, "%s LIMIT %d, %d;", temp, offset, limit);

    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct OrderDetailsTokomedia *temp = (struct OrderDetailsTokomedia*) malloc(sizeof(struct OrderDetailsTokomedia));
            temp->id = Atoi(row[0]);
            temp->item_name = row[1];
            temp->status = Atoi(row[2]);
            temp->price_per_unit = Atoi(row[3]);
            temp->qty = Atoi(row[4]);
            temp->total_price = Atoi(row[5]);
            temp->created_at = row[6];
            temp->updated_at = row[7];
            temp->itemlist_id = Atoi(row[8]);
            temp->tokomedia_shop_id = Atoi(row[9]);
            temp->transaction_id = Atoi(row[10]);
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

#endif // SERVICE_PARAM_ORDER_DETAILS_TOKOMEDIA
