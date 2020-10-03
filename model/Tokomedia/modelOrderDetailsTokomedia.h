#ifndef MODEL_PARAM_ORDER_DETAILS_TOKOMEDIA
#define MODEL_PARAM_ORDER_DETAILS_TOKOMEDIA 1

#include"modelTokomediaAccount.h"
#include"modelCartTokomedia.h"
#include"modelItemlistTokomedia.h"
#include"modelTokomediaShopAccount.h"
#include"modelTransactionTokomedia.h"

struct OrderDetailsTokomedia {
    int id;
    char* item_name;
    int status;
    int price_per_unit;
    int qty;
    int total_price;
    char* created_at;
    char* updated_at;
    int item_list_id;
    int tokomedia_shop_id;
    int transaction_id;

    struct OrderDetailsTokomedia *next;
};

struct NewOrderDetailsTokomedia {
    char* item_name;
    int price_per_unit;
    int qty;
    int total_price;
    char* created_at;
    char* updated_at;
    int item_list_id;
    int tokomedia_shop_id;
    int transaction_id;
};

struct UpdateOrderDetailsTokomedia {
    int id;
    char* item_name;
    int price_per_unit;
    int qty;
    int total_price;
    char* created_at;
    char* updated_at;
    int item_list_id;
    int tokomedia_shop_id;
    int transaction_id;
};

#endif // MODEL_PARAM_CART_TOKOMEDIA
