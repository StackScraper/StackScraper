//
// Created by lucja on 11.05.2024.
//

#ifndef DBMANAGER_H
#define DBMANAGER_H

#include<string>
#include<vector>

class DBmanager {
    // static std::string nickName;
public:
    static bool registerMember(std::string& log, std::string& email, std::string& pass);
    // static std::string getNickName();
    // static void setNickName(std::string& nick);
    static std::vector<std::string> getTags();
    static std::vector<std::string> getMembers();
    static std::vector<std::string> getFavourites();
    static std::vector<std::string> getHistory();
};



#endif //DBMANAGER_H
