#ifndef START_PROGRAM_PARAM
#define START_PROGRAM_PARAM 1


#include"../config/connectDatabase.h"
#include"../migration/migrateDatabaseTable.h"
#include"../service/serviceEmail.h"
#include"../tools/hasherTools.h"

void StartProject(){

//    Environment env;
//
//    char query[1000];
//
//    char* test = "testtt";
//
//    sprintf(query, "asdasad : %s\n", env.UserGetEmailTableName());
//
//    printf("%s\n", query);
//
//    const char *q = query;
//
//    printf("%s\n", query);
//    getchar();
//    getchar();

    MYSQL *conn = ConnectDatabase();

    if(conn){
        printf("Success\n");
    }
    else{
        printf("Fail\n");
    }

    mysql_close(conn);

    struct UpdateEmailInbox inbox;

    inbox.id = 1;
    inbox.available = 1;
    inbox.description = "abcdegh";
    inbox.read_status = 2;
    inbox.receiver_email_id = 5;
    inbox.sender_name = "name";
    inbox.sent_at = GetTimeNow();
    inbox.subject = "a subject";

    Environment env;

    if(ServiceUpdateEmailInbox(inbox)){
        printf("AAAAA\n");
    }

//    struct Email *head = ServiceGetEmailAll();
//
//    struct Email *temp = head;
//
//    while(temp != NULL){
//        printf("%d %s %s %s %s %s\n", temp->id, temp->name, temp->email, temp->password, temp->created_at, temp->last_login);
//        temp = temp->next;
//    }
//
//    if(ServiceFreeEmailLinkedList(head)){
//        printf("Free\n");
//    }
//    else{
//        printf("Fail to Free\n");
//    }

//    struct Email *test = ServiceGetEmailByID(2);
//
//    if(test != NULL){
//        printf("%d %s %s %s %s %s\n", test->id, test->name, test->email, test->password, test->created_at, test->last_login);
//    }
//    else{
//        printf("Fail to fetch\n");
//    }

//    char *asd = "email@gmail.com";
//    struct Email *test = ServiceGetEmailByEmail(asd);
//
//    if(test != NULL){
//        printf("%d %s %s %s %s %s\n", test->id, test->name, test->email, test->password, test->created_at, test->last_login);
//    }
//    else{
//        printf("Fail to fetch\n");
//    }


//    struct NewEmail input;
////    input.id = 1;
//    input.name = "dummy 2";
//    input.password = "12345";
//    input.last_login = "2020-09-29 21:10:00";
//    input.created_at = "2020-09-29 20:39:00";
//    input.email = "SAGREdgsdf@gmail.com";
//
//    if(ServiceCreateEmail(input)){
//        printf("created\n");
//    }
//    else{
//        printf("fail to create\n");
//    }

//    char *word = "testing";
//    char *temp = sha256Hashing(word);
//
//    printf("%s\n", temp);

//    char *testing = "12345678901234567890123456789012345";
//    char *desc = descriptionConvert(testing, 15);
//
//    printf("%s\n", desc);

//    printf("%s\n", GetTimeNow());
//    printf("%s\n", GetTimeZero());
}

#endif // START_PROGRAM_PARAM
