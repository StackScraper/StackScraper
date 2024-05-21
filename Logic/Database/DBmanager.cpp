//
// Created by lucja on 11.05.2024.
//

#include "DBmanager.hpp"
#include <unistd.h>
#include <string>
#include <fstream>

std::string DBmanager::nickName = "placeholder";


static int callback(void *NotUsed, int argc, char **argv, char **azColName) {

    for(int i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
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
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

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
    return 0;
}

int DBmanager::createPhraseTable() {
    return 0;
}

int DBmanager::createTagTable() {
    return 0;
}

int DBmanager::queryUser()
{
    return 0;
}

int DBmanager::insertData()
{
    /* Create SQL statement */

    const char* sql = queryHelper.insertUser("Michal","Pipka").c_str();


    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 0;
    } else {
        fprintf(stdout, "Records created successfully\n");
        return 1;
    }
}

int DBmanager::selectData()
{
    /* Create SQL statement */
    const char* sql = queryHelper.getUsers().c_str();

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 0;
    } else {
        fprintf(stdout, "Operation done successfully\n");
        return 1;
    }
}

int DBmanager::updateData()
{
    /* Create merged SQL statement */
    const char* sql = queryHelper.updateUserPass(1,"cipka").c_str();

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 0;
    } else {
        fprintf(stdout, "Operation done successfully\n");
        return 1;
    }
}

int DBmanager::deleteData() {
    /* Create merged SQL statement */
    const char* sql = queryHelper.deleteUser(2).c_str();

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 0;
    } else {
        fprintf(stdout, "Operation done successfully\n");
        return 1;
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

void DBmanager::setNickName(std::string& nick) {
    DBmanager::nickName = nick;
}

bool DBmanager::registerMember(std::string &log, std::string &email, std::string &pass) {
    return false;
}

std::vector<std::string> DBmanager::getTags() {
    std::vector<std::string> tags;
    // logic to do
    return tags;
}

std::vector<std::string> DBmanager::getMembers() {
    std::vector<std::string> members;
    // logic to do
    return members;
}

std::vector<std::string> DBmanager::getFavourites() {
    std::vector<std::string> favs;
    // logic to do
    return favs;
}

std::vector<std::string> DBmanager::getHistory() {
    std::vector<std::string> history;
    // logic to do
    return history;
}
