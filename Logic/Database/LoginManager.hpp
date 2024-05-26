//
// Created by Michin on 26.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_LOGINMANAGER_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_LOGINMANAGER_HPP

#include <string>

class LoginManager {
public:
    static bool login(std::string& log, std::string& pass);
    static bool registerNew(std::string& log, std::string& pass);
};


#endif //INC_2024__TAB_DSA__8_BRODZIAK_LOGINMANAGER_HPP
