#ifndef MODEL_PARAM_CART_TOKOMEDIA
#define MODEL_PARAM_CART_TOKOMEDIA 1

#include"modelTokomediaAccount.h"
#include"modelItemlistTokomedia.h"
#include"modelOrderDetailsTokomedia.h"
#include"modelTokomediaShopAccount.h"
#include"modelTransactionTokomedia.h"

struct CartTokomedia {
    int id;
    char* item_name;
    int price_per_unit;
    int qty;
    int total_price;
    char* created_at;
    int itemlist_id;
    int tokomedia_user_id;
    int tokomedia_shop_id;

    struct CartTokomedia *next;
};

struct NewCartTokomedia {
    char* item_name;
    int price_per_unit;
    int qty;
    int total_price;
    char* created_at;
    int itemlist_id;
    int tokomedia_user_id;
    int tokomedia_shop_id;
};

struct UpdateCartTokomedia {
    int id;
    char* item_name;
    int price_per_unit;
    int qty;
    int total_price;
    char* created_at;
    int itemlist_id;
    int tokomedia_user_id;
    int tokomedia_shop_id;
};

#endif // MODEL_PARAM_CART_TOKOMEDIA
