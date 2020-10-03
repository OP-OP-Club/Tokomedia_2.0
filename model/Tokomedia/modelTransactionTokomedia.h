#ifndef MODEL_PARAM_TRANSACTION_TOKOMEDIA
#define MODEL_PARAM_TRANSACTION_TOKOMEDIA 1

#include"modelTokomediaAccount.h"
#include"modelCartTokomedia.h"
#include"modelItemlistTokomedia.h"
#include"modelOrderDetailsTokomedia.h"
#include"modelTokomediaShopAccount.h"

struct TransactionTokomedia {
    int id;
    int status;
    int total_price;
    char* created_at;
    char* updated_at;
    int tokomedia_user_id;

    struct TransactionTokomedia *next;
};

struct NewTransactionTokomedia {
    int status;
    int total_price;
    char* created_at;
    char* updated_at;
    int tokomedia_user_id;
};

struct UpdateTransactionTokomedia {
    int id;
    int status;
    int total_price;
    char* created_at;
    char* updated_at;
    int tokomedia_user_id;
};

#endif // MODEL_PARAM_CART_TOKOMEDIA
