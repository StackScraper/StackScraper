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
    rc = sqlite3_open("ss.db", &db);
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
    const std::string sql = QueryHelper::createUserTable();

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), callback, nullptr, &zErrMsg);

    if( rc != SQLITE_OK ){
        return 0;
    } else {
        return 1;
    }
}

int DBmanager::createAdminTable() {

    /* Create SQL statement */
    const std::string sql = QueryHelper::createAdminTable();

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), callback, nullptr, &zErrMsg);

    if( rc != SQLITE_OK ){
        return 0;
    } else {
        return 1;
    }

}

int DBmanager::createPhraseTable() {
    /* Create SQL statement */
    const std::string sql = QueryHelper::createPhraseTable();

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), callback, nullptr, &zErrMsg);

    if( rc != SQLITE_OK ){
        return 0;
    } else {
        return 1;
    }
}

int DBmanager::createTagTable() {
    /* Create SQL statement */
    const std::string sql = QueryHelper::createTagTable();

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), callback, nullptr, &zErrMsg);

    if( rc != SQLITE_OK ){
        return 0;
    } else {
        return 1;
    }

}

int DBmanager::createPhraseTagTable()
{
    /* Create SQL statement */
     const std::string sql = QueryHelper::createPhraseTagTable();

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), callback, nullptr, &zErrMsg);

    if( rc != SQLITE_OK ){
        return 0;
    } else {
        return 1;
    }
}

 bool DBmanager::insertUser(std::string& nickname, std::string& password)
{
    const char* sql = QueryHelper::insertUser(nickname,password).c_str();

    rc = sqlite3_exec(db, sql, callback, nullptr, &zErrMsg);

    if( rc != SQLITE_OK ){
        return false;
    } else {
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
        return false;
    } else {
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

bool DBmanager::insertPhrase(std::string &body, std::string &response) {

    const std::string sql = QueryHelper::insertPhrase(id,body,response);

    rc = sqlite3_exec(db, sql.c_str(), callback, nullptr, &zErrMsg);

    if( rc != SQLITE_OK ){
        return false;
    } else {
        return true;
    }


}

std::vector<std::pair<std::string, std::string>> DBmanager::getPhrases() {
    receivedData = {};
    const char* sql = QueryHelper::getPhrases().c_str();

    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        return {{"SQL ERROR",zErrMsg}};
    } else {
        return receivedData;
    }
}

std::vector<std::pair<std::string, std::string>> DBmanager::getPhrase(int phraseId) {
    receivedData = {};
    const char* sql = QueryHelper::getPhrase(phraseId).c_str();

    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        return {{"SQL ERROR",zErrMsg}};
    } else {
        return receivedData;
    }
}

bool DBmanager::deletePhrase(int id) {
    const char* sql = QueryHelper::deletePhrase(id).c_str();

    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        return false;
    } else {
        return true;
    }
}

bool DBmanager::insertTag(std::string& body) {
    const std::string sql = QueryHelper::insertTag(body);

    rc = sqlite3_exec(db, sql.c_str(), callback, nullptr, &zErrMsg);

    if( rc != SQLITE_OK ){
        return false;
    } else {
        return true;
    }
}

std::vector<std::pair<std::string, std::string>> DBmanager::getTags() {
    receivedData = {};
    const char* sql = QueryHelper::getTags().c_str();

    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        return {{"SQL ERROR",zErrMsg}};
    } else {
        return receivedData;
    }
}

bool DBmanager::deleteTag(int id) {
    const char* sql = QueryHelper::deleteTag(id).c_str();

    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        return false;
    } else {
        return true;
    }
}

bool DBmanager::insertFavourite(int phraseId) {
    const std::string sql = QueryHelper::insertFavourite(phraseId);

    rc = sqlite3_exec(db, sql.c_str(), callback, nullptr, &zErrMsg);

    if( rc != SQLITE_OK ){
        return false;
    } else {
        return true;
    }

}

std::vector<std::pair<std::string, std::string>> DBmanager::getFavourites() {
    receivedData = {};
    const char* sql = QueryHelper::getFavourites(id).c_str();

    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        return {{"SQL ERROR",zErrMsg}};
    } else {
        return receivedData;
    }
}

bool DBmanager::deleteFavourite(int phraseId) {
    if(this->getPhrase(phraseId).empty()) {
        return false;
    }

    const char* sql = QueryHelper::deleteFavourite(phraseId).c_str();

    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        return false;
    } else {
        return true;
    }
}

bool DBmanager::connectTagToPhrase(int phraseId, int tagId) {
    const char* sql = QueryHelper::connectTagToPhrase(phraseId,tagId).c_str();

    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        return false;
    } else {
        return true;
    }
}

std::vector<std::pair<std::string, std::string>> DBmanager::getPhraseWithTag() {
    receivedData = {};
    const std::string sql = QueryHelper::getPhrasesWithTag();

    rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        return {{"SQL ERROR",zErrMsg}};
    } else {
        return receivedData;
    }
}

bool DBmanager::loginUser(std::string &log, std::string &pass) {

    const char* sql = QueryHelper::loginUser(log,pass).c_str();

    receivedData = {};

    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);


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
    std::ifstream f("ss.db");
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
