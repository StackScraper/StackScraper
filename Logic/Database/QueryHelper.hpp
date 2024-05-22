//
// Created by lucja on 21.05.2024.
//

#ifndef QUERYHELPER_HPP
#define QUERYHELPER_HPP

#include<string>
#include <format>

class QueryHelper {
public:
     std::string insertUser(std::string nick, std::string pass);
     std::string getUsers();
     std::string deleteUser(int id);
     std::string updateUserPass(int id, std::string pass);

     std::string insertAdmin(int userId);
     std::string getAdmins();
     std::string deleteAdmin(int adminId);
};



#endif //QUERYHELPER_HPP
