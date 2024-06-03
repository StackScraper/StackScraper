//
// Created by jakub on 10.05.2024.
//

#ifndef STACKMANAGER_HPP
#define STACKMANAGER_HPP

#include <algorithm>
#include <iostream>
#include <regex>
#include "nlohmann/adl_serializer.hpp"
#include "../TagList/TagsList.hpp"

/**
 * Class utilizing stackoverflow api
 */
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
    std::string stringQuestionID = "";
    int questionID = 0;
    std::string title;
    static std::vector<TagsList> questionsList;



public:


    std::string bestAnswer[3] = {"","",""};
    void AskQuestion(std::string & question); ///< returns answers
    void SetQuestion(std::string newInput); ///< sets question
    void SetQuestionByTags(std::string newInput); ///< sets question with usage of tags
    void GetAnswer(std::string res); ///< gets answers
    void ChangeJsonToString(std::string&); ///< changes provided question/answer to string from json format
    void SetQuestionId(std::string); ///< sets question by provided id
    void FillTabel(std::string input); ///< fill table of questions for list tags state
    void RemoveHtmlTags(std::string& input); ///< removes html code
    void ReturnNiceCode(std::string& input); ///< utilize tabs and space to code format
    void ChangingSpecialChar(std::string &input,std::string inChar, std::string outChar); ///< color special chars
    void LookForByTags(std::string& input);
    void checkTagQuestionList(std::string& tagInput); ///< checks for list of questions based on tags
    static std::vector<TagsList> getQuestionList(); ///< returnS vector of questions
    std::string GetTitle(); ///< returns title of question
    std::string GetQuestionId(); ///< returns id of question
    void GetQuestionFromID(std::string id); ///< gets quesiton from provided id
};



#endif //STACKMANAGER_HPP
