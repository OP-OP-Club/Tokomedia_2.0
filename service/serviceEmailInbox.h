#ifndef SERVICE_EMAIL_INBOX_PARAM
#define SERVICE_EMAIL_INBOX_PARAM 1

#include"../env.h"
#include"../config/connectDatabase.h"
#include"../model/modelEmail.h"
#include"../tools/cursorTools.h"

#include"serviceEmail.h"
//#include"serviceEmailSent.h"

bool ServiceCreateEmailInbox(struct NewEmailInbox input);
bool ServiceUpdateEmailInbox(struct UpdateEmailInbox input);
//bool ServiceDeleteEmailInbox(int id);
//vector<struct EmailInbox> ServiceGetEmailInboxByID(int id);
//vector<struct EmailInbox> ServiceGetArchivedEmailInboxByUserID(int user_id);
//vector<struct EmailInbox> ServiceGetArchivedEmailInboxByUserID(int user_id);
//vector<struct EmailInbox> ServiceGetEmailInboxAll();

bool ServiceCreateEmailInbox(struct NewEmailInbox input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "INSERT INTO %s (sender_name, subject, description, available, read_status, sent_at, receiver_email_id) VALUES (\'%s\', \'%s\', \'%s\', %d, %d, \'%s\', %d);", env.UserGetEmailInboxTableName(), input.sender_name, input.subject, input.description, input.available, input.read_status, input.sent_at, input.receiver_email_id);

    const char *q = query;

    getchar();

    int q_state = 0;
    q_state = mysql_query(conn, q);

    mysql_close(conn);
    if(!q_state){
        return true;
    }
    else{
        printf("FAIL\n");
        return false;
    }
}

bool ServiceUpdateEmailInbox(struct UpdateEmailInbox input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[1000];

    sprintf(query, "UPDATE %s SET sender_name = \'%s\', subject = \'%s\', description = \'%s\', available = %d, read_status = %d, sent_at = \'%s\', receiver_email_id = %d) WHERE id = %d;", env.UserGetEmailInboxTableName(), input.sender_name, input.subject, input.description, input.available, input.read_status, input.sent_at, input.receiver_email_id, input.id);

    const char *q = query;

    printf("%s\n", query);

    int q_state = 0;
    q_state = mysql_query(conn, q);

    mysql_close(conn);
    if(!q_state){
        return true;
    }
    else{
        return false;
    }
}

//bool ServiceDeleteEmailInbox(int id) {
//    MYSQL *conn = ConnectDatabase();
//
//    if(!conn){
//        mysql_close(conn);
//        return false;
//    }
//
//    Environment env;
//    stringstream ss;
//
//    ss << "DELETE FROM " << env.UserGetEmailInboxTableName() << " WHERE id = " << id << ";";
//
//    string query = ss.str();
//    const char *q = query.c_str();
//
//    int q_state = 0;
//    q_state = mysql_query(conn, q);
//
//    mysql_close(conn);
//    if(!q_state){
//        return true;
//    }
//    else{
//        return false;
//    }
//}

//vector<struct EmailInbox> ServiceGetEmailInboxByID(int id) {
//    MYSQL *conn = ConnectDatabase();
//    vector<struct EmailInbox> email_inbox;
//
//    if(!conn){
//        mysql_close(conn);
//        return email_inbox;
//    }
//
//    Environment env;
//    stringstream ss;
//
//    ss << "SELECT * FROM " << env.UserGetEmailInboxTableName() << " WHERE id = " << id << ";";
//
//    string query = ss.str();
//    const char *q = query.c_str();
//
//    int q_state = 0;
//    q_state = mysql_query(conn, q);
//
//    if(!q_state){
//        MYSQL_RES* res = mysql_store_result(conn);
//        MYSQL_ROW row;
//
//        while(row = mysql_fetch_row(res)){
//            struct EmailInbox temp;
//            temp.id = atoi(row[0]);
//            temp.sender_name = row[1];
//            temp.subject = row[2];
//            temp.description = row[3];
//            temp.available = atoi(row[4]);
//            temp.read_status = atoi(row[5]);
//            temp.sent_at = row[6];
//            temp.receiver_email_id = atoi(row[7]);
//
//            email_inbox.push_back(temp);
//        }
//
//        mysql_close(conn);
//        return email_inbox;
//    }
//    else{
//        mysql_close(conn);
//        return email_inbox;
//    }
//}
//
//vector<struct EmailInbox> ServiceGetEmailInboxByUserID(int user_id) {
//    MYSQL *conn = ConnectDatabase();
//    vector<struct EmailInbox> email_inbox;
//
//    if(!conn){
//        mysql_close(conn);
//        return email_inbox;
//    }
//
//    Environment env;
//    stringstream ss;
//
//    ss << "SELECT * FROM " << env.UserGetEmailInboxTableName() << " WHERE receiver_email_id = " << user_id << " AND available = '1' ORDER BY sent_at DESC;";
//    string query = ss.str();
//    const char *q = query.c_str();
//
//    int q_state = 0;
//    q_state = mysql_query(conn, q);
//
//    if(!q_state){
//        MYSQL_RES* res = mysql_store_result(conn);
//        MYSQL_ROW row;
//
//        while(row = mysql_fetch_row(res)){
//            struct EmailInbox temp;
//            temp.id = atoi(row[0]);
//            temp.sender_name = row[1];
//            temp.subject = row[2];
//            temp.description = row[3];
//            temp.available = atoi(row[4]);
//            temp.read_status = atoi(row[5]);
//            temp.sent_at = row[6];
//            temp.receiver_email_id = atoi(row[7]);
//
//            email_inbox.push_back(temp);
//        }
//
//        mysql_close(conn);
//        return email_inbox;
//    }
//    else{
//        mysql_close(conn);
//        return email_inbox;
//    }
//}
//
//vector<struct EmailInbox> ServiceGetArchivedEmailInboxByUserID(int user_id) {
//    MYSQL *conn = ConnectDatabase();
//    vector<struct EmailInbox> email_inbox;
//
//    if(!conn){
//        mysql_close(conn);
//        return email_inbox;
//    }
//
//    Environment env;
//    stringstream ss;
//
//    ss << "SELECT * FROM " << env.UserGetEmailInboxTableName() << " WHERE receiver_email_id = " << user_id << " AND available = '2' ORDER BY sent_at DESC;";
//    string query = ss.str();
//    const char *q = query.c_str();
//
//    int q_state = 0;
//    q_state = mysql_query(conn, q);
//
//    if(!q_state){
//        MYSQL_RES* res = mysql_store_result(conn);
//        MYSQL_ROW row;
//
//        while(row = mysql_fetch_row(res)){
//            struct EmailInbox temp;
//            temp.id = atoi(row[0]);
//            temp.sender_name = row[1];
//            temp.subject = row[2];
//            temp.description = row[3];
//            temp.available = atoi(row[4]);
//            temp.read_status = atoi(row[5]);
//            temp.sent_at = row[6];
//            temp.receiver_email_id = atoi(row[7]);
//
//            email_inbox.push_back(temp);
//        }
//
//        mysql_close(conn);
//        return email_inbox;
//    }
//    else{
//        mysql_close(conn);
//        return email_inbox;
//    }
//}
//
//vector<struct EmailInbox> ServiceGetEmailInboxAll() {
//    MYSQL *conn = ConnectDatabase();
//    vector<struct EmailInbox> email_inbox;
//
//    if(!conn){
//        mysql_close(conn);
//        return email_inbox;
//    }
//
//    Environment env;
//    stringstream ss;
//
//    ss << "SELECT * FROM " << env.UserGetEmailInboxTableName() << ";";
//    string query = ss.str();
//    const char *q = query.c_str();
//
//    int q_state = 0;
//    q_state = mysql_query(conn, q);
//
//    if(!q_state){
//        MYSQL_RES* res = mysql_store_result(conn);
//        MYSQL_ROW row;
//
//        while(row = mysql_fetch_row(res)){
//            struct EmailInbox temp;
//            temp.id = atoi(row[0]);
//            temp.sender_name = row[1];
//            temp.subject = row[2];
//            temp.description = row[3];
//            temp.available = atoi(row[4]);
//            temp.read_status = atoi(row[5]);
//            temp.sent_at = row[6];
//            temp.receiver_email_id = atoi(row[7]);
//
//            email_inbox.push_back(temp);
//        }
//
//        mysql_close(conn);
//        return email_inbox;
//    }
//    else{
//        mysql_close(conn);
//        return email_inbox;
//    }
//}

#endif // SERVICE_EMAIL_INBOX_PARAM
