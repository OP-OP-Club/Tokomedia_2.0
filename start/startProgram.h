#ifndef START_PROGRAM_PARAM
#define START_PROGRAM_PARAM 1

#include"../config/connectDatabase.h"
#include"../migration/migrateDatabaseTable.h"

void StartProject(){

    MYSQL *conn = ConnectDatabase();

    if(conn){
        printf("Success\n");
    }
    else{
        printf("Fail\n");
    }

    mysql_close(conn);

    MigrateAllTable();
}

#endif // START_PROGRAM_PARAM
