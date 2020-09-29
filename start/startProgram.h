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

    struct NewEmail input;
//    input.id = 1;
    input.name = "dummy 2";
    input.password = "12345";
    input.last_login = "2020-09-29 21:10:00";
    input.created_at = "2020-09-29 20:39:00";
    input.email = "SAGREdgsdf@gmail.com";

    if(ServiceCreateEmail(input)){
        printf("created\n");
    }
    else{
        printf("fail to create\n");
    }

//    char *word = "testing";
//    char *temp = sha256Hashing(word);
//
//    printf("%s\n", temp);


}

#endif // START_PROGRAM_PARAM
