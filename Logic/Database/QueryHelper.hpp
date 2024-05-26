//
// Created by lucja on 21.05.2024.
//

#ifndef QUERYHELPER_HPP
#define QUERYHELPER_HPP

#include<string>
#include <format>

class QueryHelper {
public:

     static std::string insertUser(std::string nick, std::string pass);
     static std::string getUsers();
     static std::string deleteUser(int id);
     static std::string updateUserPass(int id, std::string pass);

     static std::string insertAdmin(int userId);
     static std::string getAdmins();
     static std::string deleteAdmin(int adminId);

     static std::string loginUser(std::string &log, std::string &pass);

     static std::string insertPhrase(std::string &body, std::string &response);
     static std::string getPhrases();
     static std::string deletePhrase(int id);

     static std::string insertTag(std::string body);
     static std::string getTags();
     static std::string deleteTag(int id);

     static std::string insertFavourite(int phraseId);
     static std::string getFavourites();
     static std::string deleteFavourite(int favId);

     static std::string connectTagToPhrase(int phraseId,int tagId);
};


#endif //QUERYHELPER_HPP
