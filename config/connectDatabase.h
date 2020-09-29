#ifndef DATABASE_CONFIGURATION_PARAM
#define DATABASE_CONFIGURATION_PARAM 1

#include"../env.h"

MYSQL* ConnectDatabase();

// Connecting To Xampp Localhost MYSQL
MYSQL* ConnectDatabase(){
    MYSQL *conn;
    Environment env;

    conn = mysql_init(0);

    char *ip_address;
    char *username;
    char *pass;
    char *database;
    char *database_type;

    database_type = env.UserGetDatabaseTestingType();

    if(strcasecmp(database_type, "test") == 0){
        ip_address =    env.UserGetIPAddress();
        username =      env.UserGetUsername();
        pass =          env.UserGetPassword();
        database =      env.UserGetDatabaseName();
    }
    else{
        ip_address =    env.UserGetIPAddressLive();
        username =      env.UserGetUsernameLive();
        pass =          env.UserGetPasswordLive();
        database =      env.UserGetDatabaseNameLive();
    }

    conn = mysql_real_connect(conn, ip_address, username, pass, database, 0, NULL, 0);

    return conn;
}

#endif // DATABASE_CONFIGURATION_PARAM
