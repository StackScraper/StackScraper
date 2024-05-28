//
// Created by jakub on 10.05.2024.
//

#ifndef STACKMANAGER_HPP
#define STACKMANAGER_HPP

#include <algorithm>
#include <iostream>
#include <regex>
#include "nlohmann/adl_serializer.hpp"

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



    std::string bestAnswer[3] = {"","",""};
    void AskQuestion(std::string & question);
    void SetQuestion(std::string newInput);
    void SetQuestionByTags(std::string newInput);
    void GetAnswer(std::string res);
    void ChangeJsonToString(std::string&);
    int GetQuestionId(std::string);
    std::string GetQuestionTitle(std::string input);
    void FillTabel(std::string input);
    void RemoveHtmlTags(std::string& input);
    void ReturnNiceCode(std::string& input);
    void ChangingSpecialChar(std::string &input,std::string inChar, std::string outChar);
    void LookForByTags(std::string& input);
};



#endif //STACKMANAGER_HPP
