//
// Created by lucja on 11.05.2024.
//

#include "DBmanager.hpp"
#include <string>
#include <fstream>
#include <iostream>

std::string DBmanager::nickName = "Michal";

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

static int callbackString(void *data, int argc, char **argv, char **azColName) {
    std::vector<std::string>& targetVector = *static_cast<std::vector<std::string>*>(data);

    for (int i = 0; i < argc; i++) {
        if (argv[i]) {
            targetVector.push_back(argv[i]);
        }
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
    this->createFavPhrasesTable();
    this->createSearchedPhrasesTable();
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

    /* Create SQL statement */
    const char* sql = "CREATE TABLE ADMIN("  \
       "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
       "USERID INTEGER," \
       "FOREIGN KEY (USERID) REFERENCES USER(ID));" \
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

    return 0;
}

int DBmanager::createPhraseTable() {
    /* Create SQL statement */
    const char* sql = "CREATE TABLE PHRASE("  \
       "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
       "BODY TEXT NOT NULL," \
       "RESPONSE TEXT NOT NULL"\
       ");" \
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

int DBmanager::createTagTable() {
    /* Create SQL statement */
    const char* sql = "CREATE TABLE TAG("  \
       "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
       "BODY TEXT NOT NULL" \
       ");" \
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

int DBmanager::createFavPhrasesTable()
{
    /* Create SQL statement */
    const char* sql = "CREATE TABLE FAVORITEPHRASES("  \
       "USERID INTEGER," \
       "PHRASEID INTEGER," \
       "PRIMARY KEY (USERID, PHRASEID)," \
       "FOREIGN KEY (USERID) REFERENCES USER(ID)," \
       "FOREIGN KEY (PHRASEID) REFERENCES PHRASE(ID));" \
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

int DBmanager::createSearchedPhrasesTable()
{
    /* Create SQL statement */
    const char* sql = "CREATE TABLE SEARCHEDPHRASES("  \
       "USERID INTEGER," \
       "PHRASEID INTEGER," \
       "PRIMARY KEY (USERID, PHRASEID)," \
       "FOREIGN KEY (USERID) REFERENCES USER(ID)," \
       "FOREIGN KEY (PHRASEID) REFERENCES PHRASE(ID));" \
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

 bool DBmanager::insertUser(std::string& nickname, std::string& password)
{
    const char* sql = queryHelper.insertUser(nickname,password).c_str();

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

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
    const char* sql = queryHelper.getUsers().c_str();

    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        return {{"SQL ERROR",zErrMsg}};
    } else {
        return receivedData;
    }
}

bool DBmanager::updateUserPassword(int id, std::string &password)
{
    const char* sql = queryHelper.updateUserPass(id,password).c_str();

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
    const char* sql = queryHelper.deleteUser(id).c_str();

    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        return false;
    } else {
        return true;
    }
}

bool DBmanager::insertAdmin(int Id) {
    const char* sql = queryHelper.insertAdmin(Id).c_str();

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

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
    const char* sql = queryHelper.getAdmins().c_str();

    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        return {{"SQL ERROR",zErrMsg}};
    } else {
        return receivedData;
    }
}

bool DBmanager::deleteAdmin(int adminId) {
    const char* sql = queryHelper.deleteAdmin(adminId).c_str();

    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK ) {
        return false;
    } else {
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

void DBmanager::setNickName(std::string& nick) {
    DBmanager::nickName = nick;
}

bool DBmanager::registerMember(std::string &log, std::string &email, std::string &pass) {
    return false;
}

bool DBmanager::loginUser(const std::string &log, const std::string &pass) {

/*   std::string sql= ("SELECT * FROM user WHERE nickname = '" + log + "' AND password = '" + pass);
    rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, &zErrMsg);

    if( rc != SQLITE_OK || rc!= SQLITE_ROW ) {
        return false;
    } else {
        return true;
    }*/ // something wonk
    return true;

}
bool DBmanager::insrtFavoritePhrases(std::string nickname, int phraseId) {
    const char* sql = ("INSERT INTO FAVORITEPHRASES (USERID, PHRASEID) VALUES ((select ID from user WHERE nickname = '"+nickname+"'), '"+std::to_string(phraseId)+"')").c_str();

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return false;
    } else {
        fprintf(stdout, "Records created successfully\n");
        return true;
    }
}

bool DBmanager::insertTag(std::string body) {
    std::string sql= ("INSERT INTO TAG (BODY) VALUES ('"+body+"')");

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return false;
    } else {
        fprintf(stdout, "Records created successfully\n");
        return true;
    }
}

std::vector<std::string> DBmanager::getTags() {
    std::vector<std::string> tags = {};
    std::string sql = ("SELECT BODY FROM TAG");
    rc = sqlite3_exec(db, sql.c_str(), callbackString, &tags, &zErrMsg);
    return tags;
}

std::vector<std::string> DBmanager::getMembers() {
    std::vector<std::string> members = {};
    // logic to do
    return members;
}

std::vector<std::string> DBmanager::getFavourites() {
    std::vector<std::string> favs ={};
    std::string sql = ("SELECT PHRASEID FROM FAVORITEPHRASES WHERE USERID IN (SELECT ID FROM user WHERE NICKNAME = '"+nickName+"')");
    rc = sqlite3_exec(db, sql.c_str(), callbackString, &favs, &zErrMsg);

    return favs;
}

std::vector<std::string> DBmanager::getHistory() {
    std::vector<std::string> history = {};
    // logic to do
    return history;
}

