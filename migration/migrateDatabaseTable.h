#ifndef MIGRATE_DATABASE_TABLE_PARAM
#define MIGRATE_DATABASE_TABLE_PARAM 1

#include"../config/connectDatabase.h"

void MigrateAllTable();
void CreateTableEmail();
void CreateTableEmailSent();
void CreateTableEmailInbox();
void CreateTableTokomediaUserAccount();
void CreateTableTokomediaShopAccount();
void CreateTableCartTokomedia();
void CreateTableOrderDetailsTokomedia();
void CreateTableTransactionTokomedia();
void CreateTableItemlistTokomedia();

void MigrateAllTable() {
    CreateTableEmail();
    CreateTableEmailSent();
    CreateTableEmailInbox();
    CreateTableTokomediaUserAccount();
    CreateTableTokomediaShopAccount();
    CreateTableCartTokomedia();
    CreateTableOrderDetailsTokomedia();
    CreateTableTransactionTokomedia();
    CreateTableItemlistTokomedia();
}

void CreateTableEmail() {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        printf("Fail\n");
        mysql_close(conn);
        return;
    }
    const char* query =
R"(CREATE TABLE email(
id int NOT NULL AUTO_INCREMENT,
name varchar(255) NOT NULL,
password varchar(255) NOT NULL,
email varchar(255) NOT NULL,
created_at datetime NOT NULL,
last_login datetime NOT NULL,
PRIMARY KEY(id)
)
)";

    int q_state = 0;
    q_state = mysql_query(conn, query);

    if(!q_state){
        printf("Create Table Email Success\n");
    }
    else{
        printf("Create Table Email Fail\n");
    }

    mysql_close(conn);
}

void CreateTableEmailSent() {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        printf("Fail\n");
        mysql_close(conn);
        return;
    }
    const char* query =
R"(CREATE TABLE email_sent(
id int NOT NULL AUTO_INCREMENT,
receiver_name varchar(255) NOT NULL,
subject varchar(255) NOT NULL,
description varchar(255) NOT NULL,
available int NOT NULL,
sent_at datetime NOT NULL,
sender_email_id int NOT NULL,
PRIMARY KEY(id)
)
)";

    int q_state = 0;
    q_state = mysql_query(conn, query);

    if(!q_state){
        printf("Create Table email_sent Success\n");
    }
    else{
        printf("Create Table email_sent Fail\n");
    }

    mysql_close(conn);
}

void CreateTableEmailInbox() {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        printf("Fail\n");
        mysql_close(conn);
        return;
    }

    const char* query =
R"(CREATE TABLE email_inbox(
id int NOT NULL AUTO_INCREMENT,
sender_name varchar(255) NOT NULL,
subject varchar(255) NOT NULL,
description varchar(255) NOT NULL,
available int NOT NULL,
read_status int NOT NULL,
sent_at datetime NOT NULL,
receiver_email_id int NOT NULL,
PRIMARY KEY(id)
)
)";

    int q_state = 0;
    q_state = mysql_query(conn, query);

    if(!q_state){
        printf("Create Table email_inbox Success\n");
    }
    else{
        printf("Create Table email_inbox Fail\n");
    }

    mysql_close(conn);
}

void CreateTableTokomediaUserAccount(){
     MYSQL *conn = ConnectDatabase();

    if(!conn){
        printf("Fail\n");
        mysql_close(conn);
        return;
    }

    const char* query =
R"(CREATE TABLE tokomedia_user_account(
id int NOT NULL AUTO_INCREMENT,
name varchar(255) NOT NULL,
email varchar(255) NOT NULL,
password varchar(255) NOT NULL,
balance int NOT NULL,
security_code varchar(255) NOT NULL,
created_at datetime NOT NULL,
last_login datetime NOT NULL,
PRIMARY KEY(id)
)
)";

    int q_state = 0;
    q_state = mysql_query(conn, query);

    if(!q_state){
        printf("Create Table tokomedia_user_account Success\n");
    }
    else{
        printf("Create Table tokomedia_user_account Fail\n");
    }

    mysql_close(conn);
}

void CreateTableTokomediaShopAccount(){
     MYSQL *conn = ConnectDatabase();

    if(!conn){
        printf("Fail\n");
        mysql_close(conn);
        return;
    }

    const char* query =
R"(CREATE TABLE tokomedia_shop_account(
id int NOT NULL AUTO_INCREMENT,
name varchar(255) NOT NULL,
email varchar(255) NOT NULL,
password varchar(255) NOT NULL,
balance int NOT NULL,
security_code varchar(255) NOT NULL,
created_at datetime NOT NULL,
last_login datetime NOT NULL,
PRIMARY KEY(id)
)
)";

    int q_state = 0;
    q_state = mysql_query(conn, query);

    if(!q_state){
        printf("Create Table tokomedia_shop_account Success\n");
    }
    else{
        printf("Create Table tokomedia_shop_account Fail\n");
    }

    mysql_close(conn);
}

void CreateTableCartTokomedia(){
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        printf("Fail\n");
        mysql_close(conn);
        return;
    }

    const char* query =
R"(CREATE TABLE cart_tokomedia(
id int NOT NULL AUTO_INCREMENT,
item_name varchar(255) NOT NULL,
price_per_unit int NOT NULL,
qty int NOT NULL,
total_price int NOT NULL,
created_at datetime NOT NULL,
item_list_id int NOT NULL,
tokomedia_user_id int NOT NULL,
tokomedia_shop_id int NOT NULL,
PRIMARY KEY(id)
)
)";

    int q_state = 0;
    q_state = mysql_query(conn, query);

    if(!q_state){
        printf("Create Table cart_tokomedia Success\n");
    }
    else{
        printf("Create Table cart_tokomedia Fail\n");
    }

    mysql_close(conn);
}

void CreateTableOrderDetailsTokomedia(){
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        printf("Fail\n");
        mysql_close(conn);
        return;
    }

    const char* query =
R"(CREATE TABLE order_details_tokomedia(
id int NOT NULL AUTO_INCREMENT,
item_name varchar(255) NOT NULL,
status int NOT NULL,
price_per_unit int NOT NULL,
qty int NOT NULL,
total_price int NOT NULL,
created_at datetime NOT NULL,
updated_at datetime NOT NULL,
item_list_id int NOT NULL,
tokomedia_shop_id int NOT NULL,
transaction_id int NOT NULL,
PRIMARY KEY(id)
)
)";

    int q_state = 0;
    q_state = mysql_query(conn, query);

    if(!q_state){
        printf("Create Table order_details_tokomedia Success\n");
    }
    else{
        printf("Create Table order_details_tokomedia Fail\n");
    }

    mysql_close(conn);
}

void CreateTableTransactionTokomedia(){
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        printf("Fail\n");
        mysql_close(conn);
        return;
    }

    const char* query =
R"(CREATE TABLE transaction_tokomedia(
id int NOT NULL AUTO_INCREMENT,
status int NOT NULL,
total_price int NOT NULL,
created_at datetime NOT NULL,
updated_at datetime NOT NULL,
tokomedia_user_id int NOT NULL,
PRIMARY KEY(id)
)
)";

    int q_state = 0;
    q_state = mysql_query(conn, query);

    if(!q_state){
        printf("Create Table transaction_tokomedia Success\n");
    }
    else{
        printf("Create Table transaction_tokomedia Fail\n");
    }

    mysql_close(conn);
}

void CreateTableItemlistTokomedia(){
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        printf("Fail\n");
        mysql_close(conn);
        return;
    }

    const char* query =
R"(CREATE TABLE itemlist_tokomedia(
id int NOT NULL AUTO_INCREMENT,
item_name varchar(255) NOT NULL,
price_per_unit int NOT NULL,
discount_per_unit int NOT NULL,
stock int NOT NULL,
created_at datetime NOT NULL,
updated_at datetime NOT NULL,
tokomedia_shop_id int NOT NULL,
PRIMARY KEY(id)
)
)";

    int q_state = 0;
    q_state = mysql_query(conn, query);

    if(!q_state){
        printf("Create Table itemlist_tokomedia Success\n");
    }
    else{
        printf("Create Table itemlist_tokomedia Fail\n");
    }

    mysql_close(conn);
}

#endif // MIGRATE_DATABASE_TABLE_PARAM
