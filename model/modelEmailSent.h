#ifndef MODEL_PARAM_EMAIL_SENT
#define MODEL_PARAM_EMAIL_SENT 1
#include"modelEmail.h"
#include"modelEmailInbox.h"

struct EmailSent {
    int id;
    char* receiver_name;
    char* subject;
    char* description;
    int available;
    char* sent_at;
    int sender_email_id;
    struct EmailSent *next;
};

struct NewEmailSent {
    char* receiver_name;
    char* subject;
    char* description;
    int available;
    char* sent_at;
    int sender_email_id;
};

struct UpdateEmailSent {
    int id;
    char* receiver_name;
    char* subject;
    char* description;
    int available;
    char* sent_at;
    int sender_email_id;
};

#endif // MODEL_PARAM
