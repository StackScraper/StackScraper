//
// Created by lucja on 11.05.2024.
//

#include "DBmanager.hpp"
#include <string>
#include <fstream>
#include <iostream>

std::string DBmanager::nickName = "admin";
int DBmanager::id = 1;

std::vector<std::pair<std::string,std::string>> receivedData;


static int callback(void *NotUsed, int argc, char **argv, char **azColName) {

    for(int i = 0; i<argc; i++) {
        std::string key = azColName[i];
        std::string value = argv[i] ? argv[i] : "NULL";
        std::pair<std::string,std::string> pair = {key,value};
        receivedData.push_back(pair);
    }

    return 0;
}

typedef int (*sqlite3_callback)(
   void*,    /* Data provided in the 4th argument of sqlite3_exec() */
   int,      /* The number of columns in row */
   char**,   /* An array of strings representing fields in the row */
   char**    /* An array of strings representing column names */
);



int DBmanager::openDatabase()
{
    rc = sqlite3_open("test.db", &db); // TODO ss.db
    return rc? 0:1;
}

int DBmanager::createDatabase()
{
    this->createUserTable();
    this->createAdminTable();
    this->createPhraseTable();
    this->createTagTable();
    this->createPhraseTagTable();

    std::string admin = "admin";
    this->insertUser(admin,admin);
    this->insertAdmin(1);
    return 1;
}

int DBmanager::closeDatabase()
{
    sqlite3_close(db);
    return 1;
}

int DBmanager::createUserTable()
{
    /* Create SQL statement */
    const char* sql = "CREATE TABLE USER("  \
       " ID INTEGER PRIMARY KEY AUTOINCREMENT," \
       "NICKNAME           TEXT    NOT NULL," \
       "PASSWORD           TEXT    NOT NULL);" \
    ;

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, nullptr, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 0;
    } else {
        fprintf(stdout, "Table created successfully\n");
        return 1;
    }
}

int DBmanager::createAdminTable() {

    /* Create SQL statement */
    const char* sql = "CREATE TABLE ADMIN("  \
       "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
       "USERID INTEGER," \
       "FOREIGN KEY (USERID) REFERENCES USER(ID));" \
    ;

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, nullptr, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 0;
    } else {
        fprintf(stdout, "Table created successfully\n");
        return 1;
    }

}

int DBmanager::createPhraseTable() {
    /* Create SQL statement */
    const char* sql = "CREATE TABLE PHRASE("  \
       "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
       "USERID INTEGER," \
       "BODY TEXT NOT NULL," \
       "RESPONSE TEXT NOT NULL,"\
       "FAVOURITE INTEGER DEFAULT 0,"\
       "FOREIGN KEY (USERID) REFERENCES USER(ID));" \
    ;

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, nullptr, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 0;
    } else {
        fprintf(stdout, "Table created successfully\n");
        return 1;
    }
}

int DBmanager::createTagTable() {
    /* Create SQL statement */
    const char* sql = "CREATE TABLE TAG("  \
       "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
       "BODY TEXT NOT NULL" \
       ");" \
    ;

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, nullptr, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 0;
    } else {
        fprintf(stdout, "Table created successfully\n");
        return 1;
    }

}

int DBmanager::createPhraseTagTable()
{
    /* Create SQL statement */
    const char* sql = "CREATE TABLE PHRASETAG("  \
       "PHRASEID INTEGER," \
       "TAGID INTEGER," \
       "PRIMARY KEY (PHRASEID, TAGID)," \
       "FOREIGN KEY (PHRASEID) REFERENCES PHRASE(ID)," \
       "FOREIGN KEY (TAGID) REFERENCES TAG(ID));" \
    ;

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, nullptr, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 0;
    } else {
        fprintf(stdout, "Table created successfully\n");
        return 1;
    }
}

 bool DBmanager::insertUser(std::string& nickname, std::string& password)
{
    const char* sql = QueryHelper::insertUser(nickname,password).c_str();

    rc = sqlite3_exec(db, sql, callback, nullptr, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return false;
    } else {
        fprintf(stdout, "Records created successfully\n");
        return true;
    }
}

 std::vector<std::pair<std::string,std::string>> DBmanager::getUsers()
{
    receivedData = {};
    const char* sql = QueryHelper::getUsers().c_str();

    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        return {{"SQL ERROR",zErrMsg}};
    } else {
        return receivedData;
    }
}

bool DBmanager::updateUserPassword(int id, std::string &password)
{
    const char* sql = QueryHelper::updateUserPass(id,password).c_str();

/* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
    return false;
    } else {
     return true;
}
}


bool DBmanager::deleteUser(int id)
{
    const char* sql = QueryHelper::deleteUser(id).c_str();

    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        return false;
    } else {
        return true;
    }
}

bool DBmanager::insertAdmin(int Id) {
    const char* sql = QueryHelper::insertAdmin(Id).c_str();

    rc = sqlite3_exec(db, sql, callback, nullptr, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return false;
    } else {
        fprintf(stdout, "Records created successfully\n");
        return true;
    }


}

std::vector<std::pair<std::string, std::string>> DBmanager::getAdmins() {
    receivedData = {};
    const char* sql = QueryHelper::getAdmins().c_str();

    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        return {{"SQL ERROR",zErrMsg}};
    } else {
        return receivedData;
    }
}

bool DBmanager::deleteAdmin(int adminId) {
    const char* sql = QueryHelper::deleteAdmin(adminId).c_str();

    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        return false;
    } else {
        return true;
    }
}


bool DBmanager::loginUser(std::string &log, std::string &pass) {

    const char* sql = QueryHelper::loginUser(log,pass).c_str();

    receivedData = {};

    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    for(int i =0;i<receivedData.size();i++) {
        std::cout<<receivedData[i].first<<" "<< receivedData[i].second<<std::endl;
    }
    std::cout<<std::endl;

    if( rc != SQLITE_OK ) {
        return false;
    } else {
        if(receivedData.empty()) {
            return false;
        }
        return true;
    }

}

DBmanager::DBmanager()
{
    std::ifstream f("test.db");
    if(f.good()) {
        this->openDatabase();
    }
    else {
        this->openDatabase();
        this->createDatabase();
    }
}

DBmanager::~DBmanager()
{
    this->closeDatabase();
}
