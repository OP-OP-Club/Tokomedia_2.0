#ifndef ENVIRONMENT_PARAM
#define ENVIRONMENT_PARAM 1

class Environment{
    public :
        char* UserGetIPAddress();
        char* UserGetUsername();
        char* UserGetPassword();
        char* UserGetDatabaseName();
        char* UserGetEmailTableName();
        char* UserGetEmailInboxTableName();
        char* UserGetEmailSentTableName();
        char* UserGetTokomediaUserAccountTableName();
        char* UserGetTokomediaShopAccountTableName();
        char* UserGetIPAddressLive();
        char* UserGetUsernameLive();
        char* UserGetPasswordLive();
        char* UserGetDatabaseNameLive();
        char* UserGetDatabaseTestingType();

        char* UserGetSalt();

    private :
        char* salt = "saltThisThlngs";

        char* ip_address = "localhost";
        char* username = "root";
        char* password = "";
        char* database_name = "tokomedia_sql";
        char* email_table_name = "email";
        char* email_inbox_table_name = "email_inbox";
        char* email_sent_table_name = "email_sent";
        char* tokomedia_user_account_table_name = "tokomedia_user_account";
        char* tokomedia_shop_account_table_name = "tokomedia_shop_account";

        char* ip_address_live = "sql12.freesqldatabase.com";
        char* username_live = "sql12366398";
        char* password_live = "wVYIiQLYPT";
        char* database_name_live = "sql12366398";

//        const char* ip_address_live = "fdb30.runhosting.com";
//        const char* username_live = "3585897_tokomedia";
//        const char* password_live = "Lx^:Vxir3bTPow-b";
//        const char* database_name_live = "3585897_tokomedia";

//        const char* ip_address_live = "78510.us-imm-sql2.000webhost.io:3306";
//        const char* ip_address_live = "localhost";
//        const char* username_live = "id14913304_ceotokomedia";
//        const char* username_live = "id14913304_ceotokomedia@2a02:4780:bad:c0de::13";
//        const char* password_live = " x-j7>4fy%VqZ8atk";
//        const char* database_name_live = "id14913304_tokomedia";

        char* database_testing_type = "test";
};

char* Environment::UserGetIPAddress() {
    return ip_address;
}

char* Environment::UserGetUsername() {
    return username;
}

char* Environment::UserGetPassword() {
    return password;
}

char* Environment::UserGetDatabaseName() {
    return database_name;
}

char* Environment::UserGetEmailTableName() {
    return email_table_name;
}

char* Environment::UserGetEmailInboxTableName() {
    return email_inbox_table_name;
}

char* Environment::UserGetEmailSentTableName() {
    return email_sent_table_name;
}

char* Environment::UserGetTokomediaUserAccountTableName() {
    return tokomedia_user_account_table_name;
}

char* Environment::UserGetTokomediaShopAccountTableName(){
    return tokomedia_shop_account_table_name;
}


char* Environment::UserGetIPAddressLive() {
    return ip_address_live;
}

char* Environment::UserGetUsernameLive() {
    return username_live;
}

char* Environment::UserGetPasswordLive() {
    return password_live;
}

char* Environment::UserGetDatabaseNameLive() {
    return database_name_live;
}

char* Environment::UserGetDatabaseTestingType() {
    return database_testing_type;
}

char* Environment::UserGetSalt() {
    return salt;
}

#endif // ENVIRONMENT_PARAM
