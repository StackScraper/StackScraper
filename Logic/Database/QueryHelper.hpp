//
// Created by lucja on 21.05.2024.
//

#ifndef QUERYHELPER_HPP
#define QUERYHELPER_HPP

#include<string>
#include <format>

class QueryHelper {
public:
     static std::string createUserTable();
     static std::string createAdminTable();
     static std::string createPhraseTable();
     static std::string createTagTable();
     static std::string createPhraseTagTable();

     static std::string insertUser(std::string nick, std::string pass);
     static std::string getUsers();
     static std::string deleteUser(int id);
     static std::string updateUserPass(int id, std::string pass);

     static std::string insertAdmin(int userId);
     static std::string getAdmins();
     static std::string deleteAdmin(int adminId);

     static std::string loginUser(std::string &log, std::string &pass);

     static std::string insertPhrase(int &id,std::string &body, std::string &response);
     static std::string getPhrases();
     static std::string getPhrase(int phraseId);
     static std::string deletePhrase(int id);

     static std::string insertTag(std::string body);
     static std::string getTags();
     static std::string deleteTag(int id);

     static std::string insertFavourite(int phraseId);
     static std::string getFavourites(int userId);
     static std::string deleteFavourite(int phraseId);

     static std::string connectTagToPhrase(int phraseId,int tagId);
     static std::string getPhrasesWithTag();
};


#endif //QUERYHELPER_HPP
