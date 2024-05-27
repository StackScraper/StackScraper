//
// Created by jakub on 10.05.2024.
//

#include "StackManager.hpp"
#include <iostream>
#include "cpr/cpr.h"
#include "nlohmann/json.hpp"
#include <string>

//SEARCH: https://api.stackexchange.com/2.3/search/advanced?order=desc&sort=relevance&q=how%20to%20declare%20array%20of%20string%20in%20cpp&site=stackoverflow&filter=withbody
std::string StackManager::askQuestion() {
    cpr::Response r = cpr::Get(cpr::Url{finalInput});
    return r.text;
    //return  finalInput;
}
void StackManager::setQuestion(std::string newInput) {
    questionInput = regex_replace(newInput, std::regex(" "), space);
    finalInput = baseInput+apiVesion+"search/advanced?order=desc&sort=relevance&q="+questionInput+"&site=stackoverflow&filter=withbody";
}
void StackManager::setQuestionByTags(std::string newInput) {
    questionInput = regex_replace(newInput, std::regex(" "), space);
    finalInput = baseInput+apiVesion+"search?pagesize=1&order=desc&sort=votes&intitle=="+questionInput+"&site=stackoverflow&filter=withbody";
}
void StackManager::getAnswer(std::string res) {
    int temp = getQuestionId(res);
    answerID=std::to_string(temp);
    answerInput = std::to_string(temp);
    answerInput = baseInput+apiVesion+"questions/"+answerID+"/answers?pagesize=3&order=desc&sort=votes&site=stackoverflow&filter=withbody";
    fillTabel(answerInput);

}

std::string StackManager::changeJsonToString(std::string input) {

    nlohmann::json data = nlohmann::json::parse(input);
    if (data.contains("items") && data["items"].is_array()) {
        nlohmann::json item = data["items"][0];
        if (item.contains("body")) {
            std::string body = item["body"];
            return body;
        } else {
            return "Can not find similar problem";
        }
    } else {
        return "Can not find similar problem";
    }

}

int StackManager::getQuestionId(std::string input) {
    nlohmann::json data = nlohmann::json::parse(input);
    if (data.contains("items") && data["items"].is_array()) {
        nlohmann::json item = data["items"][0];
        if (item.contains("question_id")) {
            int body = item["question_id"];
            return body;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}
void StackManager::fillTabel(std::string input) {
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
std::string StackManager::RemoveHtmlTags(const std::string& input) {
    std::regex htmlTagRegex(R"(<(?!\/?code)[^>]*>)");
    return std::regex_replace(input, htmlTagRegex, "");
}
void StackManager::ChangingSpecialChar(std::string &input,std::string inChar, std::string outChar) {
    int pos = input.find(inChar);
    while (pos != std::string::npos) {
        input.replace(pos, inChar.length(), outChar);
        pos = input.find(inChar, pos + 1);
    }
}
std::string StackManager::ReturnNiceCode(std::string input) {
    ChangingSpecialChar(input, "&lt;", "<");
    ChangingSpecialChar(input, "&gt;", ">");
    ChangingSpecialChar(input, "&quot;", "\"");
    ChangingSpecialChar(input, "&amp;", "&");
    return input;
}
