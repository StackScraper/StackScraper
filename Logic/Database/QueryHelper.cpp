//
// Created by lucja on 21.05.2024.
//

#include "QueryHelper.hpp"

std::string QueryHelper::insertUser(std::string nick, std::string pass) {
    return std::format("INSERT INTO USER (NICKNAME,PASSWORD) VALUES ('{}', '{}' );",nick,pass );
}

std::string QueryHelper::getUsers() {
    return "SELECT * from USER";
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
