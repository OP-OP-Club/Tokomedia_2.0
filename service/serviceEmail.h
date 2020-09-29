#ifndef SERVICE_PARAM_EMAIL
#define SERVICE_PARAM_EMAIL 1

//#include"serviceEmailSent.h"
//#include"serviceEmailInbox.h"
#include"../env.h"
#include"../config/connectDatabase.h"
#include"../model/modelEmail.h"
#include"../tools/hasherTools.h"
using namespace std;

bool ServiceCreateEmail();
bool ServiceUpdateEmail();
bool ServiceDeleteEmail();

bool ServiceCreateEmail(struct NewEmail input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;
    input.email = ToLower(input.email);

    input.password = sha256Hashing(input.password);

    char query[500];

    sprintf(query, "INSERT INTO %s (name, password, email, created_at, last_login) VALUES (\'%s\', \'%s\', \'%s\', \'%s\', \'%s\');", env.UserGetEmailTableName(), input.name, input.password, input.email, input.created_at, input.last_login);

    const char *q = query;

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

bool ServiceUpdateEmail(struct UpdateEmail input) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;

    char query[500];

    sprintf(query, "UPDATE %s SET name = \'%s\', password = \'%s\', email = \'%s\', created_at = \'%s\', last_login = \'%s\' WHERE id = %d;", env.UserGetEmailTableName(), input.name, input.password, input.email, input.created_at, input.last_login, input.id);

    const char *q = query;

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

bool ServiceDeleteEmail(int id) {
    MYSQL *conn = ConnectDatabase();

    if(!conn){
        mysql_close(conn);
        return false;
    }

    Environment env;
    char query[500];

    sprintf(query, "DELETE FROM %s WHERE id = %d;", env.UserGetEmailTableName(), id);
    const char *q = query;

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

//vector<struct Email> ServiceGetEmailByID(int id) {
//    MYSQL *conn = ConnectDatabase();
//    vector<struct Email> temp;
//
//    if(!conn){
//        mysql_close(conn);
//        return temp;
//    }
//
//    Environment env;
//    stringstream ss;
//
//    ss << "SELECT * FROM " << env.UserGetEmailTableName() << " WHERE id = " << id << ";";
//
//    string query = ss.str();
//    const char *q = query.c_str();
//
//    int q_state = 0;
//    q_state = mysql_query(conn, q);
//
//    if(!q_state){
//        MYSQL_RES *res = mysql_store_result(conn);
//        MYSQL_ROW row;
//
//        while(row = mysql_fetch_row(res)){
//            struct Email emailTemp;
//            emailTemp.id = atoi(row[0]);
//            emailTemp.name = row[1];
//            emailTemp.password = row[2];
//            emailTemp.email = row[3];
//            emailTemp.created_at = row[4];
//            emailTemp.last_login = row[5];
//
//            temp.push_back(emailTemp);
//        }
//
//        mysql_close(conn);
//        return temp;
//    }
//    else{
//        mysql_close(conn);
//        return temp;
//    }
//}
//
//vector<struct Email> ServiceGetEmailByEmail(string email){
//    MYSQL *conn = ConnectDatabase();
//    vector<struct Email> temp;
//
//    if(!conn){
//        mysql_close(conn);
//        return temp;
//    }
//
//    Environment env;
//    stringstream ss;
//
//    ss << "SELECT * FROM " << env.UserGetEmailTableName() << " WHERE email = '" << email << "';";
//
//    string query = ss.str();
//    const char *q = query.c_str();
//
//    int q_state = 0;
//    q_state = mysql_query(conn, q);
//
//    if(!q_state){
//        MYSQL_RES *res = mysql_store_result(conn);
//        MYSQL_ROW row;
//
//        while(row = mysql_fetch_row(res)){
//            struct Email emailTemp;
//            emailTemp.id = atoi(row[0]);
//            emailTemp.name = row[1];
//            emailTemp.password = row[2];
//            emailTemp.email = row[3];
//            emailTemp.created_at = row[4];
//            emailTemp.last_login = row[5];
//
//            temp.push_back(emailTemp);
//        }
//
//        mysql_close(conn);
//        return temp;
//    }
//    else{
//        mysql_close(conn);
//        return temp;
//    }
//}
//
//vector<struct Email> ServiceGetEmailAll() {
//    MYSQL *conn = ConnectDatabase();
//    vector<struct Email> temp;
//
//    if(!conn){
//        mysql_close(conn);
//        return temp;
//    }
//
//    Environment env;
//    stringstream ss;
//
//    ss << "SELECT * FROM " << env.UserGetEmailTableName() << ";";
//
//    string query = ss.str();
//    const char *q = query.c_str();
//
//    int q_state = 0;
//    q_state = mysql_query(conn, q);
//
//    if(!q_state){
//        MYSQL_RES *res = mysql_store_result(conn);
//        MYSQL_ROW row;
//
//        while(row = mysql_fetch_row(res)){
//            struct Email emailTemp;
//            emailTemp.id = atoi(row[0]);
//            emailTemp.name = row[1];
//            emailTemp.password = row[2];
//            emailTemp.email = row[3];
//            emailTemp.created_at = row[4];
//            emailTemp.last_login = row[5];
//
//            temp.push_back(emailTemp);
//        }
//
//        mysql_close(conn);
//        return temp;
//    }
//    else{
//        mysql_close(conn);
//        return temp;
//    }
//}

#endif // SERVICE_PARAM
