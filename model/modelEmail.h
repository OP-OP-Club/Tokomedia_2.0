#ifndef MODEL_PARAM_EMAIL
#define MODEL_PARAM_EMAIL 1

#include"modelEmailInbox.h"
#include"modelEmailSent.h"

struct Email {
    int id;
    char* name;
    char* password;
    char* email;
    char* created_at;
    char* last_login;
    struct Email *next;
};

struct NewEmail {
    char* name;
    char* password;
    char* email;
    char* created_at;
    char* last_login;
};

struct UpdateEmail {
    int id;
    char* name;
    char* password;
    char* email;
    char* created_at;
    char* last_login;
};

#endif // MODEL_PARAM
