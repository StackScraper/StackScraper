//
// Created by jakub on 10.05.2024.
//

#ifndef STACKMANAGER_HPP
#define STACKMANAGER_HPP

#include <algorithm>
#include <iostream>
#include <regex>
#include <nlohmann/adl_serializer.hpp>

class StackManager {
    //URL TO SEARCH
    //https://api.stackexchange.com/2.3/search?order=desc&sort=activity&intitle=CPP&site=stackoverflow

    //value which store answear id "accepted_answer_id": 63548573,
    //URL TO FIND ANSWEAR
    //https://api.stackexchange.com/2.3/answers/63548573?order=desc&sort=activity&site=stackoverflow&filter=withbody

    std::string space = "%20";
    std::string baseInput = "https://api.stackexchange.com/";
    std::string apiVesion = "2.3/";
    std::string questionInput = "";
    std::string finalInput = "";
    std::string answerInput = "";
    std::string answerID = "";

public:
    std::string askQuestion();
    void setQuestion(std::string newInput);
    std::string getAnswer(std::string res);
    std::string changeJsonToString(std::string);
    int getQuestionId(std::string);


};



#endif //STACKMANAGER_HPP
