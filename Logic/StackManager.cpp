//
// Created by jakub on 10.05.2024.
//

#include "StackManager.hpp"
#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <string>

//https://api.stackexchange.com/2.3/questions/123/answers?pagesize=3&order=desc&sort=votes&site=stackoverflow&filter=withbody

std::string StackManager::askQuestion() {
    cpr::Response r = cpr::Get(cpr::Url{finalInput});
    //return r.text;
    return  finalInput;
}
void StackManager::setQuestion(std::string newInput) {
    questionInput = regex_replace(newInput, std::regex(" "), space);
    finalInput = baseInput+apiVesion+"search?pagesize=1&order=desc&sort=votes&intitle="+questionInput+"&site=stackoverflow&filter=withbody";
}

std::string StackManager::getAnswer(std::string res) {
    answerID = getQuestionId(res);
    std::cout << answerID;
    answerInput = baseInput+apiVesion+"questions/"+answerID+"/answers?pagesize=3&order=desc&sort=votes&site=stackoverflow&filter=withbody";
    cpr::Response r = cpr::Get(cpr::Url{answerInput});
    return r.text;
}

std::string StackManager::changeJsonToString(std::string input) {

    nlohmann::json data = nlohmann::json::parse(input);


    if (data.contains("items") && data["items"].is_array()) {
        // Pobranie pierwszego elementu z tablicy "items"
        nlohmann::json item = data["items"][0];

        // Sprawdzenie czy istnieje klucz "body"
        if (item.contains("body")) {
            std::string body = item["body"]; // Pobranie wartości "body"
            return body;
        } else {
            return "Nie znaleziono klucza 'body'.";
        }
    } else {
        return "Nie znaleziono klucza 'items' lub nie jest to tablica.";
    }

}

int StackManager::getQuestionId(std::string input) {

    nlohmann::json data = nlohmann::json::parse(input);

    if (data.contains("items") && data["items"].is_array()) {
        // Pobranie pierwszego elementu z tablicy "items"
        nlohmann::json item = data["items"][0];

        // Sprawdzenie czy istnieje klucz "body"
        if (item.contains("question_id")) {
            int body = item["question_id"]; // Pobranie wartości "body"
            return body;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}
