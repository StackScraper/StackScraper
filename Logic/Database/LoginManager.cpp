//
// Created by Michin on 26.04.2024.
//

#include "LoginManager.hpp"

bool LoginManager::login(std::string& log, std::string& pass) {
    //todo
    if(log == "admin" && pass == "admin")
    {
        return true;
    }
    return false;
}

bool LoginManager::registerNew(std::string& log, std::string& pass) {
    //todo
    return false;
}
