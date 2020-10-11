#ifndef SERVICE_PARAM_ITEMLIST_TOKOMEDIA
#define SERVICE_PARAM_ITEMLIST_TOKOMEDIA 1

#include"../../env.h"
#include"../../config/connectDatabase.h"
#include"../../model/Email/modelEmail.h"
#include"../../model/Tokomedia/modelCartTokomedia.h"
#include"../../tools/hasherTools.h"

#include"serviceTokomediaShopAccount.h"
#include"serviceTokomediaAccount.h"
#include"serviceTransactionTokomedia.h"
#include"serviceOrderDetailsTokomedia.h"

bool ServiceCreateItemlistTokomedia(struct NewItemlistTokomedia input);
bool ServiceUpdateItemlistTokomedia(struct UpdateItemlistTokomedia input);
bool ServiceDeleteItemlistTokomedia(int id);
int ServiceGetItemlistTokomediaSize(struct ItemlistTokomedia *head);
struct ItemlistTokomedia* ServiceGetItemlistTokomediaByID(int id);
struct ItemlistTokomedia* ServiceGetItemlistTokomediaByTokomediaShopID(int shop_id);
struct ItemlistTokomedia* ServiceGetItemlistTokomediaByEmail(char* email);
struct ItemlistTokomedia* ServiceGetItemlistTokomediaAll();
bool ServiceFreeItemlistTokomediaLinkedList(struct ItemlistTokomedia *head);
struct ItemlistTokomedia* ServiceGetItemlistTokomediaFromHeadByIndex(struct ItemlistTokomedia *head, int index);
struct ItemlistTokomedia* ServiceGetItemlistTokomediaPagination(int limit, int page, int order_by);
struct ItemlistTokomedia* ServiceGetItemlistTokomediaPaginationByTokomediaShopID(int limit, int page, int order_by, int shop_id);

bool ServiceCreateItemlistTokomedia(struct NewItemlistTokomedia input){
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "INSERT INTO %s (item_name, price_per_unit, discount_per_unit, stock, created_at, updated_at, tokomedia_shop_id) VALUES (\'%s\', %d, %d, %d, \'%s\', \'%s\', %d);", env.UserGetItemlistTokomediaTableName(), input.item_name, input.price_per_unit, input.discount_per_unit, input.stock, input.created_at, input.updated_at, input.tokomedia_shop_id);

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

bool ServiceUpdateItemlistTokomedia(struct UpdateItemlistTokomedia input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "UPDATE %s SET item_name = \'%s\', price_per_unit = %d, discount_per_unit = %d, stock = %d, created_at = \'%s\', updated_at = \'%s\', tokomedia_shop_id = %d WHERE id = %d;", env.UserGetItemlistTokomediaTableName(), input.item_name, input.price_per_unit, input.discount_per_unit, input.stock, input.created_at, input.updated_at, input.tokomedia_shop_id, input.id);

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

bool ServiceDeleteItemlistTokomedia(int id){
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "DELETE FROM %s WHERE id = %d;", env.UserGetItemlistTokomediaTableName(), id);

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

int ServiceGetItemlistTokomediaSize(struct ItemlistTokomedia *head){
    int counter = 0;

    while(head != NULL){
        counter++;
        head = head->next;
    }

    return counter;
}

struct ItemlistTokomedia* ServiceGetItemlistTokomediaByID(int id){
    MYSQL *conn = ConnectDatabase();
    struct ItemlistTokomedia* temp = NULL;

    if(!conn){
        mysql_close(conn);
        return temp;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE id = %d;", env.UserGetItemlistTokomediaTableName(), id);
    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            temp = (struct ItemlistTokomedia*) malloc(sizeof(struct ItemlistTokomedia));
            temp->id = Atoi(row[0]);
            temp->item_name = row[1];
            temp->price_per_unit = Atoi(row[2]);
            temp->discount_per_unit = Atoi(row[3]);
            temp->stock = Atoi(row[4]);
            temp->created_at = row[5];
            temp->updated_at = row[6];
            temp->tokomedia_shop_id = Atoi(row[7]);
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

struct ItemlistTokomedia* ServiceGetItemlistTokomediaByTokomediaShopID(int shop_id){
    MYSQL *conn = ConnectDatabase();
    struct ItemlistTokomedia *head, *tail;
    head = tail = NULL;

    if(!conn){
        mysql_close(conn);
        return head;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE tokomedia_shop_id = %d;", env.UserGetItemlistTokomediaTableName(), shop_id);
    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct ItemlistTokomedia *temp = (struct ItemlistTokomedia*) malloc(sizeof(struct ItemlistTokomedia));
            temp->id = Atoi(row[0]);
            temp->item_name = row[1];
            temp->price_per_unit = Atoi(row[2]);
            temp->discount_per_unit = Atoi(row[3]);
            temp->stock = Atoi(row[4]);
            temp->created_at = row[5];
            temp->updated_at = row[6];
            temp->tokomedia_shop_id = Atoi(row[7]);
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

struct ItemlistTokomedia* ServiceGetItemlistTokomediaByEmail(char* email){
    MYSQL *conn = ConnectDatabase();
    struct ItemlistTokomedia* temp = NULL;

    if(!conn){
        mysql_close(conn);
        return temp;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s WHERE email = \'%s\';", env.UserGetItemlistTokomediaTableName(), email);
    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            temp = (struct ItemlistTokomedia*) malloc(sizeof(struct ItemlistTokomedia));
            temp->id = Atoi(row[0]);
            temp->item_name = row[1];
            temp->price_per_unit = Atoi(row[2]);
            temp->discount_per_unit = Atoi(row[3]);
            temp->stock = Atoi(row[4]);
            temp->created_at = row[5];
            temp->updated_at = row[6];
            temp->tokomedia_shop_id = Atoi(row[7]);
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

struct ItemlistTokomedia* ServiceGetItemlistTokomediaAll(){
    MYSQL *conn = ConnectDatabase();
    struct ItemlistTokomedia *head, *tail;
    head = tail = NULL;

    if(!conn){
        mysql_close(conn);
        return head;
    }

    Environment env;

    char query[1000];

    sprintf(query, "SELECT * FROM %s;", env.UserGetItemlistTokomediaTableName());
    const char *q = query;

    int q_state = 0;
    q_state = mysql_query(conn, q);

    if(!q_state){
        MYSQL_RES *res = mysql_store_result(conn);
        MYSQL_ROW row;

        while(row = mysql_fetch_row(res)){
            struct ItemlistTokomedia *temp = (struct ItemlistTokomedia*) malloc(sizeof(struct ItemlistTokomedia));
            temp->id = Atoi(row[0]);
            temp->item_name = row[1];
            temp->price_per_unit = Atoi(row[2]);
            temp->discount_per_unit = Atoi(row[3]);
            temp->stock = Atoi(row[4]);
            temp->created_at = row[5];
            temp->updated_at = row[6];
            temp->tokomedia_shop_id = Atoi(row[7]);
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

bool ServiceFreeItemlistTokomediaLinkedList(struct ItemlistTokomedia *head){
    struct ItemlistTokomedia* temp = head;

    while(temp != NULL){
        head = head->next;
        free(temp);
        temp = head;
    }

    return true;
}

struct ItemlistTokomedia* ServiceGetItemlistTokomediaFromHeadByIndex(struct ItemlistTokomedia *head, int index){
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

struct ItemlistTokomedia* ServiceGetItemlistTokomediaPagination(int limit, int page, int order_by){
    MYSQL *conn = ConnectDatabase();
    struct ItemlistTokomedia *head, *tail;
    head = tail = NULL;

    if(!conn){
        mysql_close(conn);
        return head;
    }

    Environment env;

    int offset = (page - 1) * limit;

    char query[1000];
    char temp[1000];
    sprintf(temp, "SELECT id, item_name, (price_per_unit - discount_per_unit) as new_price, discount_per_unit, stock, created_at, updated_at, tokomedia_shop_id FROM %s", env.UserGetItemlistTokomediaTableName());

    if(order_by == 1){
        sprintf(temp, "%s ORDER BY item_name ASC", temp);
    }
    else if(order_by == 2){
        sprintf(temp, "%s ORDER BY item_name DESC", temp);
    }
    else if(order_by == 3){
        sprintf(temp, "%s ORDER BY new_price ASC", temp);
    }
    else if(order_by == 4){
        sprintf(temp, "%s ORDER BY new_price DESC", temp);
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
            struct ItemlistTokomedia *temp = (struct ItemlistTokomedia*) malloc(sizeof(struct ItemlistTokomedia));
            temp->id = Atoi(row[0]);
            temp->item_name = row[1];
            temp->price_per_unit = Atoi(row[2]);
            temp->discount_per_unit = Atoi(row[3]);
            temp->stock = Atoi(row[4]);
            temp->created_at = row[5];
            temp->updated_at = row[6];
            temp->tokomedia_shop_id = Atoi(row[7]);
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

struct ItemlistTokomedia* ServiceGetItemlistTokomediaPaginationByTokomediaShopID(int limit, int page, int order_by, int shop_id){
    MYSQL *conn = ConnectDatabase();
    struct ItemlistTokomedia *head, *tail;
    head = tail = NULL;

    if(!conn){
        mysql_close(conn);
        return head;
    }

    Environment env;

    int offset = (page - 1) * limit;

    char query[1000];
    char temp[1000];
    sprintf(temp, "SELECT id, item_name, (price_per_unit - discount_per_unit) as new_price, discount_per_unit, stock, created_at, updated_at, tokomedia_shop_id FROM %s WHERE tokomedia_shop_id = %d", env.UserGetItemlistTokomediaTableName(), shop_id);

    if(order_by == 1){
        sprintf(temp, "%s ORDER BY item_name ASC", temp);
    }
    else if(order_by == 2){
        sprintf(temp, "%s ORDER BY item_name DESC", temp);
    }
    else if(order_by == 3){
        sprintf(temp, "%s ORDER BY new_price ASC", temp);
    }
    else if(order_by == 4){
        sprintf(temp, "%s ORDER BY new_price DESC", temp);
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
            struct ItemlistTokomedia *temp = (struct ItemlistTokomedia*) malloc(sizeof(struct ItemlistTokomedia));
            temp->id = Atoi(row[0]);
            temp->item_name = row[1];
            temp->price_per_unit = Atoi(row[2]);
            temp->discount_per_unit = Atoi(row[3]);
            temp->stock = Atoi(row[4]);
            temp->created_at = row[5];
            temp->updated_at = row[6];
            temp->tokomedia_shop_id = Atoi(row[7]);
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

#endif // SERVICE_PARAM_ITEMLIST_TOKOMEDIA
