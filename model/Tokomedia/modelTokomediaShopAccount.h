#ifndef MODEL_PARAM_TOKOMEDIA_SHOP_ACCOUNT
#define MODEL_PARAM_TOKOMEDIA_SHOP_ACCOUNT 1

#include"modelTokomediaAccount.h"
#include"modelCartTokomedia.h"
#include"modelItemlistTokomedia.h"
#include"modelOrderDetailsTokomedia.h"
#include"modelTransactionTokomedia.h"

struct TokomediaShopAccount {
    int id;
    char* name;
    char* email;
    char* password;
    int balance;
    char* security_code;
    char* created_at;
    char* last_login;

    struct TokomediaShopAccount *next;
};

struct NewTokomediaShopAccount {
    char* name;
    char* email;
    char* password;
    int balance;
    char* security_code;
    char* created_at;
    char* last_login;
};

struct UpdateTokomediaShopAccount {
    int id;
    char* name;
    char* email;
    char* password;
    int balance;
    char* security_code;
    char* created_at;
    char* last_login;
};

#endif // MODEL_PARAM_CART_TOKOMEDIA
