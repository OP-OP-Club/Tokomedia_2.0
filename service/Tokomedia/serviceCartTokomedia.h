#ifndef SERVICE_PARAM_CART_TOKOMEDIA
#define SERVICE_PARAM_CART_TOKOMEDIA 1

#include"../../env.h"
#include"../../config/connectDatabase.h"
#include"../../model/Email/modelEmail.h"
#include"../../model/Tokomedia/modelCartTokomedia.h"
#include"../../tools/hasherTools.h"

#include"serviceTokomediaShopAccount.h"
#include"serviceTokomediaAccount.h"
#include"serviceItemlistTokomedia.h"
#include"serviceTransactionTokomedia.h"
#include"serviceOrderDetailsTokomedia.h"

bool ServiceCreateCartTokomedia(struct NewCartTokomedia input);
bool ServiceUpdateCartTokomedia(struct UpdateCartTokomedia input);
bool ServiceDeleteCartTokomedia(int id);
int ServiceGetCartTokomediaSize(struct CartTokomedia *head);
struct CartTokomedia* ServiceGetCartTokomediaByID(int id);
struct CartTokomedia* ServiceGetCartTokomediaByTokomediaUserID(int id);
//struct CartTokomedia* ServiceGetCartTokomediaAll();
bool ServiceFreeCartTokomediaLinkedList(struct CartTokomedia *head);
struct CartTokomedia* ServiceGetCartTokomediaFromHeadByIndex(struct CartTokomedia *head, int index);
struct CartTokomedia* ServiceGetCartTokomediaPaginationByUserID(int limit, int page, int order_by, int user_id);

bool ServiceCreateCartTokomedia(struct NewCartTokomedia input){
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "INSERT INTO %s (item_name, price_per_unit, qty, total_price, created_at, itemlist_id, tokomedia_user_id,tokomedia_shop_id) VALUES (\'%s\', %d, %d, %d, \'%s\', %d, %d, %d);", env.UserGetCartTokomediaTableName(), input.item_name, input.price_per_unit, input.qty, input.total_price, input.created_at, input.itemlist_id, input.tokomedia_user_id, input.tokomedia_shop_id);

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

bool ServiceUpdateCartTokomedia(struct UpdateCartTokomedia input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "UPDATE %s SET item_name = \'%s\', price_per_unit = %d, qty = %d, total_price = %d, created_at = \'%s\', itemlist_id = %d, tokomedia_user_id = %d,tokomedia_shop_id = %d WHERE id = %d;", env.UserGetCartTokomediaTableName(), input.item_name, input.price_per_unit, input.qty, input.total_price, input.created_at, input.itemlist_id, input.tokomedia_user_id, input.tokomedia_shop_id, input.id);

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

bool ServiceDeleteCartTokomedia(int id){
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "DELETE FROM %s WHERE id = %d;", env.UserGetCartTokomediaTableName(), id);

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

int ServiceGetCartTokomediaSize(struct CartTokomedia *head){
    int counter = 0;

    while(head != NULL){
        counter++;
        head = head->next;
    }

    return counter;
}

struct CartTokomedia* ServiceGetCartTokomediaByID(int id){
    MYSQL *conn = ConnectDatabase();
    struct CartTokomedia* temp = NULL;

    if(!conn){
        mysql_close(conn);
        return temp;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE id = %d;", env.UserGetCartTokomediaTableName(), id);
    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            temp = (struct CartTokomedia*) malloc(sizeof(struct CartTokomedia));
            temp->id = Atoi(row[0]);
            temp->item_name = row[1];
            temp->price_per_unit = Atoi(row[2]);
            temp->qty = Atoi(row[3]);
            temp->total_price = Atoi(row[4]);
            temp->created_at = row[5];
            temp->itemlist_id = Atoi(row[6]);
            temp->tokomedia_user_id = Atoi(row[7]);
            temp->tokomedia_shop_id = Atoi(row[8]);
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

struct CartTokomedia* ServiceGetCartTokomediaByTokomediaUserID(int id){
    MYSQL *conn = ConnectDatabase();
    struct CartTokomedia *head, *tail;
    head = tail = NULL;

    if(!conn){
        mysql_close(conn);
        return head;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE tokomedia_user_id = %d;", env.UserGetCartTokomediaTableName(), id);
    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct CartTokomedia *temp = (struct CartTokomedia*) malloc(sizeof(struct CartTokomedia));
            temp->id = Atoi(row[0]);
            temp->item_name = row[1];
            temp->price_per_unit = Atoi(row[2]);
            temp->qty = Atoi(row[3]);
            temp->total_price = Atoi(row[4]);
            temp->created_at = row[5];
            temp->itemlist_id = Atoi(row[6]);
            temp->tokomedia_user_id = Atoi(row[7]);
            temp->tokomedia_shop_id = Atoi(row[8]);
            temp->next = NULL;

            struct ItemlistTokomedia *UpdatedItemList = ServiceGetItemlistTokomediaByID(temp->itemlist_id);
            if(UpdatedItemList == NULL){

            }
            else if((UpdatedItemList->price_per_unit - UpdatedItemList->discount_per_unit) != temp->price_per_unit){
                int new_price_per_unit = UpdatedItemList->price_per_unit - UpdatedItemList->discount_per_unit;
                struct UpdateCartTokomedia tempUpdate;
                tempUpdate.id = temp->id;
                tempUpdate.item_name = temp->item_name;
                temp->price_per_unit = tempUpdate.price_per_unit = new_price_per_unit;
                tempUpdate.qty = temp->qty;
                temp->total_price = tempUpdate.total_price = temp->qty * (new_price_per_unit);
                tempUpdate.created_at = temp->created_at;
                tempUpdate.itemlist_id = temp->itemlist_id;
                tempUpdate.tokomedia_user_id = temp->tokomedia_user_id;
                tempUpdate.tokomedia_shop_id = temp->tokomedia_shop_id;

                ServiceUpdateCartTokomedia(tempUpdate);


            }

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

//struct CartTokomedia* ServiceGetCartTokomediaAll(){
//    MYSQL *conn = ConnectDatabase();
//    struct CartTokomedia *head, *tail;
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
//            struct CartTokomedia *temp = (struct CartTokomedia*) malloc(sizeof(struct CartTokomedia));
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

bool ServiceFreeCartTokomediaLinkedList(struct CartTokomedia *head){
    struct CartTokomedia* temp = head;

    while(temp != NULL){
        head = head->next;
        free(temp);
        temp = head;
    }

    return true;
}

struct CartTokomedia* ServiceGetCartTokomediaFromHeadByIndex(struct CartTokomedia *head, int index){
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

struct CartTokomedia* ServiceGetCartTokomediaPaginationByUserID(int limit, int page, int order_by, int user_id){
    MYSQL *conn = ConnectDatabase();
    struct CartTokomedia *head, *tail;
    head = tail = NULL;

    if(!conn){
        mysql_close(conn);
        return head;
    }

    Environment env;

    int offset = (page - 1) * limit;

    char query[1000];
    char temp[1000];
    sprintf(temp, "SELECT id, item_name, price_per_unit, qty, total_price, created_at, itemlist_id, tokomedia_user_id, tokomedia_shop_id FROM %s WHERE tokomedia_user_id = %d", env.UserGetCartTokomediaTableName(), user_id);

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
        sprintf(temp, "%s ORDER BY created_at ASC", temp);
    }
    else if(order_by == 6){
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
            struct CartTokomedia *temp = (struct CartTokomedia*) malloc(sizeof(struct CartTokomedia));
            temp->id = Atoi(row[0]);
            temp->item_name = row[1];
            temp->price_per_unit = Atoi(row[2]);
            temp->qty = Atoi(row[3]);
            temp->total_price = Atoi(row[4]);
            temp->created_at = row[5];
            temp->itemlist_id = Atoi(row[6]);
            temp->tokomedia_user_id = Atoi(row[7]);
            temp->tokomedia_shop_id = Atoi(row[8]);
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

#endif // SERVICE_PARAM_CART_TOKOMEDIA
