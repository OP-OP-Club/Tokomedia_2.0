#ifndef MODEL_PARAM_ITEMLIST_TOKOMEDIA
#define MODEL_PARAM_ITEMLIST_TOKOMEDIA 1

#include"modelTokomediaAccount.h"
#include"modelCartTokomedia.h"
#include"modelOrderDetailsTokomedia.h"
#include"modelTokomediaShopAccount.h"
#include"modelTransactionTokomedia.h"

struct ItemlistTokomedia {
    int id;
    char* item_name;
    int price_per_unit;
    int discount_per_unit;
    int stock;
    char* created_at;
    char* updated_at;
    int tokomedia_shop_id;

    struct ItemlistTokomedia *next;
};

struct NewItemlistTokomedia {
    char* item_name;
    int price_per_unit;
    int discount;
    int stock;
    char* created_at;
    char* updated_at;
    int tokomedia_shop_id;
};

struct UpdateItemlistTokomedia {
    int id;
    char* item_name;
    int price_per_unit;
    int discount;
    int stock;
    char* created_at;
    char* updated_at;
    int tokomedia_shop_id;
};

#endif // MODEL_PARAM_CART_TOKOMEDIA
