//
// Created by jakub on 10.05.2024.
//

#include "StackManager.hpp"
#include <iostream>
#include "cpr/cpr.h"
#include "nlohmann/json.hpp"
#include <string>

//SEARCH: https://api.stackexchange.com/2.3/search/advanced?order=desc&sort=relevance&q=how%20to%20declare%20array%20of%20string%20in%20cpp&site=stackoverflow&filter=withbody
void StackManager::AskQuestion(std::string & question) {
    cpr::Response r = cpr::Get(cpr::Url{finalInput});
    question = r.text;
    //return  finalInput;
}
void StackManager::SetQuestion(std::string newInput) {
    questionInput = regex_replace(newInput, std::regex(" "), space);
    finalInput = baseInput+apiVesion+"search/advanced?order=desc&sort=relevance&q="+questionInput+"&site=stackoverflow&filter=withbody";
}
void StackManager::SetQuestionByTags(std::string newInput) {
    questionInput = regex_replace(newInput, std::regex(" "), space);
    finalInput = baseInput+apiVesion+"search?pagesize=1&order=desc&sort=votes&intitle=="+questionInput+"&site=stackoverflow&filter=withbody";
}
void StackManager::GetAnswer(std::string res) {
    // int temp = GetQuestionId(res);
    // answerID=std::to_string(temp);
    // answerInput = std::to_string(temp);
    GetQuestionInfo(res);
    answerInput = baseInput+apiVesion+"questions/"+questionID+"/answers?pagesize=3&order=desc&sort=votes&site=stackoverflow&filter=withbody";
    FillTabel(answerInput);
}

void StackManager::ChangeJsonToString(std::string & input) {

    nlohmann::json data = nlohmann::json::parse(input);
    if (data.contains("items") && data["items"].is_array()) {
        nlohmann::json item = data["items"][0];
        if (item.contains("body")) {
            std::string body = item["body"];
            input = body;
        } else {
            input = "Can not find similar problem";
        }
    } else {
        input = "Can not find similar problem";
    }

}

void StackManager::GetQuestionInfo(std::string input) {

    nlohmann::json data = nlohmann::json::parse(input);

    if (data.contains("items") && data["items"].is_array()) {
        nlohmann::json item = data["items"][0];
        if (item.contains("question_id")) {
            title = item["title"];
            questionID = item["quesiton_id"];
        } else {
            title = "Not found";
            questionID = "Not found";
        }
    } else {
        title = "Not found";
        questionID = "Not found";
    }
}
std::string StackManager::GetQuestionTitle(std::string input) {
    nlohmann::json data = nlohmann::json::parse(input);

    if (data.contains("items") && data["items"].is_array()) {
        nlohmann::json item = data["items"][0];
        if (item.contains("title")) {
            std::string body = item["title"];
            return body;
        } else {
            return "";
        }
    } else {
        return "";
    }
}
void StackManager::FillTabel(std::string input) {
    cpr::Response r = cpr::Get(cpr::Url{input});
    std::string jsonText = r.text;
    nlohmann::json data = nlohmann::json::parse(jsonText);
    if (data.contains("items") && data["items"].is_array()) {
        // Iteruj przez elementy w "items" (maksymalnie 3 pierwsze)
        for (int i = 0; i < std::min(3, (int)data["items"].size()); ++i) {
            nlohmann::json item = data["items"][i];
            if (item.contains("body")) {
                std::string bodyContent = item["body"].get<std::string>();
                bestAnswer[i] = bodyContent;
            } else {
                std::cout << "Answer not found " << std::endl;
                //bestAnswer[i] = "Brak zawartości";
            }
        }
    } else {
        std::cout << "" << std::endl;
    }
}
void StackManager::RemoveHtmlTags(std::string& input) {
    std::regex htmlTagRegex(R"(<(?!\/?code)[^>]*>)");
    input = std::regex_replace(input, htmlTagRegex, "");
}
void StackManager::ChangingSpecialChar(std::string &input,std::string inChar, std::string outChar) {
    int pos = input.find(inChar);
    while (pos != std::string::npos) {
        input.replace(pos, inChar.length(), outChar);
        pos = input.find(inChar, pos + 1);
    }
}
void StackManager::ReturnNiceCode(std::string& input) {
    ChangingSpecialChar(input, "&lt;", "<");
    ChangingSpecialChar(input, "&gt;", ">");
    ChangingSpecialChar(input, "&quot;", "\"");
    ChangingSpecialChar(input, "&amp;", "&");
}
//https://api.stackexchange.com/questions?site=stackoverflow&tagged=c++;java;&filter=withbody
void StackManager::LookForByTags(std::string &input) {
    questionInput = regex_replace(input, std::regex(" "), ";");
    finalInput = baseInput+apiVesion+"questions?site=stackoverflow&tagged="+questionInput+"&filter=withbody";
}

