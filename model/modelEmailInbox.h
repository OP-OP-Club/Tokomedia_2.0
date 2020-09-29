#ifndef MODEL_PARAM_EMAIL_INBOX
#define MODEL_PARAM_EMAIL_INBOX 1
#include"modelEmail.h"
#include"modelEmailSent.h"

struct EmailInbox {
    int id;
    char* sender_name;
    char* subject;
    char* description;
    int available;
    int read_status;
    char* sent_at;
    int receiver_email_id;
    struct EmailInbox *next;
};

struct NewEmailInbox {
    char* sender_name;
    char* subject;
    char* description;
    int available;
    int read_status;
    char* sent_at;
    int receiver_email_id;
};

struct UpdateEmailInbox {
    int id;
    char* sender_name;
    char* subject;
    char* description;
    int available;
    int read_status;
    char* sent_at;
    int receiver_email_id;
};

#endif // MODEL_PARAM
