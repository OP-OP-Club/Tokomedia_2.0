#ifndef MODEL_PARAM_TOKOMEDI_ACCOUNT
#define MODEL_PARAM_TOKOMEDI_ACCOUNT 1

#include"modelCartTokomedia.h"
#include"modelItemlistTokomedia.h"
#include"modelOrderDetailsTokomedia.h"
#include"modelTokomediaShopAccount.h"
#include"modelTransactionTokomedia.h"

struct TokomediaUserAccount {
    int id;
    char* name;
    char* email;
    char* password;
    int balance;
    char* security_code;
    char* created_at;
    char* last_login;

    struct TokomediaUserAccount *next;
};

struct NewTokomediaUserAccount {
    char* name;
    char* email;
    char* password;
    int balance;
    char* security_code;
    char* created_at;
    char* last_login;
};

struct UpdateTokomediaUserAccount {
    int id;
    char* name;
    char* email;
    char* password;
    int balance;
    char* security_code;
    char* created_at;
    char* last_login;
};

#endif // MODEL_PARAM_TOKOMEDI_ACCOUNT
