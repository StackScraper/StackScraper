//
// Created by lucja on 11.05.2024.
//

#ifndef DBMANAGER_HPP
#define DBMANAGER_HPP

#include<string>
#include<vector>
#include <sqlite3.h>
#include "QueryHelper.hpp"

class DBmanager {
    static std::string nickName;
    sqlite3 *db;
    char *zErrMsg;
    int rc;
    const char* data = "Callback function called";

    QueryHelper queryHelper =  QueryHelper();

    int openDatabase();
    int createDatabase();
    int closeDatabase();

    int createUserTable();
    int createAdminTable();
    int createPhraseTable();
    int createTagTable();
    int createPhraseTagTable();
    int createFavPhrasesTable();
    int createSearchedPhrasesTable();
public:
    bool insertUser(std::string& nickname, std::string& password);
    std::vector<std::pair<std::string,std::string>> getUsers();
    bool updateUserPassword(int id,std::string& password);
    bool deleteUser(int id);
    bool loginUser(const std::string& log, const std::string& pass);
    bool insrtFavoritePhrases(std::string nickname, int phraseId);
    bool insertTag(std::string body);


    DBmanager();
    ~DBmanager();
    bool registerMember(std::string& log, std::string& email, std::string& pass);
    void setNickName(std::string& nick);
    std::vector<std::string> getTags();
    std::vector<std::string> getMembers();
    std::vector<std::string> getFavourites();
    std::vector<std::string> getHistory();
};



#endif //DBMANAGER_HPP
