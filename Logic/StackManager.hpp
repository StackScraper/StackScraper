//
// Created by jakub on 10.05.2024.
//

#ifndef STACKMANAGER_HPP
#define STACKMANAGER_HPP

#include <algorithm>
#include <iostream>
#include <regex>
class StackManager {
    //URL TO SEARCH
    //https://api.stackexchange.com/2.3/search?order=desc&sort=activity&intitle=CPP&site=stackoverflow

    std::string space = "%20";
    std::string baseInput = "https://api.stackexchange.com/";
    std::string apiVesion = "2.3/";
    std::string questionInput = "";
    std::string finalInput = "";

public:
    std::string askQuestion();
    void setQuestion(std::string newInput);
};



#endif //STACKMANAGER_HPP
