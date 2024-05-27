//
// Created by lucja on 21.05.2024.
//

#include "QueryHelper.hpp"

std::string QueryHelper::createUserTable() {
    return "CREATE TABLE USER("  \
       " ID INTEGER PRIMARY KEY AUTOINCREMENT," \
       "NICKNAME           TEXT    NOT NULL," \
       "PASSWORD           TEXT    NOT NULL);" \
    ;
}

std::string QueryHelper::createAdminTable() {
    return "CREATE TABLE ADMIN("  \
       "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
       "USERID INTEGER," \
       "FOREIGN KEY (USERID) REFERENCES USER(ID));" \
    ;
}

std::string QueryHelper::createPhraseTable() {
    return "CREATE TABLE PHRASE("  \
       "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
       "USERID INTEGER," \
       "BODY TEXT NOT NULL," \
       "RESPONSE TEXT NOT NULL,"\
       "FAVOURITE INTEGER DEFAULT 0,"\
       "FOREIGN KEY (USERID) REFERENCES USER(ID));" \
    ;
}

std::string QueryHelper::createTagTable() {
    return "CREATE TABLE TAG("  \
       "ID INTEGER PRIMARY KEY AUTOINCREMENT," \
       "BODY TEXT NOT NULL" \
       ");" \
    ;
}

std::string QueryHelper::createPhraseTagTable() {
    return "CREATE TABLE PHRASETAG("  \
       "PHRASEID INTEGER," \
       "TAGID INTEGER," \
       "PRIMARY KEY (PHRASEID, TAGID)," \
       "FOREIGN KEY (PHRASEID) REFERENCES PHRASE(ID)," \
       "FOREIGN KEY (TAGID) REFERENCES TAG(ID));" \
    ;
}

std::string QueryHelper::insertUser(std::string nick, std::string pass) {
    return std::format("INSERT INTO USER (NICKNAME,PASSWORD) VALUES ('{}', '{}' );",nick,pass );
}

std::string QueryHelper::getUsers() {
    return "SELECT * from USER;";
}

std::string QueryHelper::deleteUser(int id) {
    return std::format("DELETE from USER where ID={}; ",id);
}

std::string QueryHelper::updateUserPass(int id, std::string pass)
{
    return std::format("UPDATE USER set PASSWORD = '{}' where ID={}; ",pass,id );
}

std::string QueryHelper::insertAdmin(int userId) {
    return std::format("INSERT INTO ADMIN (USERID) VALUES ({});",userId );
}

std::string QueryHelper::getAdmins() {
    return "SELECT * from ADMIN";
}

std::string QueryHelper::deleteAdmin(int adminId) {
    return std::format("DELETE from ADMIN where ID={}; ",adminId);
}

std::string QueryHelper::loginUser(std::string &log, std::string &pass) {
    return std::format("SELECT * from USER where NICKNAME='{}' AND PASSWORD='{}' ;",log,pass);
}

std::string QueryHelper::insertPhrase(int &id, std::string &body, std::string &response) {
    return std::format("INSERT INTO PHRASE (USERID,BODY,RESPONSE) VALUES ({}, '{}','{}');",id,body,response );
}

std::string QueryHelper::getPhrases() {
    return "SELECT * from PHRASE";
}

std::string QueryHelper::deletePhrase(int id) {
    return std::format("DELETE from PHRASE where ID={}; ",id);
}

std::string QueryHelper::insertTag(std::string body) {
   return std::format( "INSERT INTO TAG (BODY) VALUES ('{}');",body);
}

std::string QueryHelper::getTags() {
    return "SELECT * from TAG";
}

std::string QueryHelper::deleteTag(int id) {
    return std::format("DELETE from TAG where ID={}; ",id);
}

std::string QueryHelper::insertFavourite(int phraseId) {
    return std::format("UPDATE PHRASE set FAVOURITE=1 where ID={}; ",phraseId );
}

std::string QueryHelper::getFavourites(int userId) {
    return std::format("SELECT * FROM PHRASE WHERE FAVOURITE=1 AND USERID={};",userId);
}

std::string QueryHelper::deleteFavourite(int phraseId) {
    return std::format("UPDATE PHRASE set FAVOURITE=0 where ID={}; ",phraseId );
}

std::string QueryHelper::connectTagToPhrase(int phraseId, int tagId) {
    return std::format( "INSERT INTO PHRASETAG (PHRASEID,TAGID) VALUES ({},{});",phraseId,tagId);
}

std::string QueryHelper::getPhrasesWithTag() {
    return "SELECT p.Id AS PhraseId,p.Body AS PhraseBody,p.Response AS PhraseResponse, t.Body AS TagBody FROM PHRASE p JOIN "\
    "PHRASETAG pt ON p.id = pt.PhraseId JOIN Tag t ON pt.TagId = t.ID";
}
