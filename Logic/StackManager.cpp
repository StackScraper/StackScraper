//
// Created by jakub on 10.05.2024.
//

#include "StackManager.hpp"
#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <string>

//https://api.stackexchange.com/2.3/questions/123/answers?pagesize=3&order=desc&sort=votes&site=stackoverflow&filter=withbody
//search: https://api.stackexchange.com/2.3/similar?order=desc&sort=activity&title=how%20to%20declarate%20array%20of%20pointer&site=stackoverflow&filter=withbody

std::string StackManager::askQuestion() {
    cpr::Response r = cpr::Get(cpr::Url{finalInput});
    return r.text;
    //return  finalInput;
}
void StackManager::setQuestion(std::string newInput) {
    questionInput = regex_replace(newInput, std::regex(" "), space);
    finalInput = baseInput+apiVesion+"similar?order=desc&sort=activity&title="+questionInput+"&site=stackoverflow&filter=withbody";
}

void StackManager::getAnswer(std::string res) {
    int temp = getQuestionId(res);
    answerID=std::to_string(temp);
    answerInput = std::to_string(temp);
    answerInput = baseInput+apiVesion+"questions/"+answerID+"/answers?pagesize=3&order=desc&sort=votes&site=stackoverflow&filter=withbody";
    fillTabel(answerInput);
//std::cout << answerInput;
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
void StackManager::fillTabel(std::string input) {

    cpr::Response r = cpr::Get(cpr::Url{input});

    std::string jsonText = r.text;

    nlohmann::json data = nlohmann::json::parse(jsonText);

    if (data.contains("items") && data["items"].is_array()) {
        // Iteruj przez elementy w "items" (maksymalnie 3 pierwsze)
        for (int i = 0; i < std::min(3, (int)data["items"].size()); ++i) {
            nlohmann::json item = data["items"][i];

            // Sprawdź czy istnieje klucz "body" w bieżącym elemencie
            if (item.contains("body")) {
                // Pobierz wartość "body" jako std::string
                std::string bodyContent = item["body"].get<std::string>();
                bestAnswer[i] = bodyContent;
            } else {
                // Obsłuż sytuację braku klucza "body"
                std::cout << "Brak klucza 'body' dla elementu " << i << std::endl;
                // Możesz ustawić domyślną wartość lub inaczej obsłużyć ten przypadek
                bestAnswer[i] = "Brak zawartości";
            }
        }
    } else {
        std::cout << "Brak klucza 'items' lub 'items' nie jest tablicą" << std::endl;
    }
}
std::string StackManager::RemoveHtmlTags(const std::string& input) {
    std::regex htmlTagRegex(R"(<(?!\/?code)[^>]*>)");
    return std::regex_replace(input, htmlTagRegex, "");
}
std::string StackManager::ReturnNiceCode(std::string input) {

    int pos = input.find("&lt;");

    while (pos != std::string::npos) {
        input.replace(pos, 4, "<");
        pos = input.find("&lt;", pos + 1);
    }

    pos = input.find("&gt;");
    while (pos != std::string::npos) {
        input.replace(pos, 4, ">");
        pos = input.find("&gt;", pos + 1);
    }
    pos = input.find("&quot;");
    while (pos != std::string::npos) {
        input.replace(pos, 6, "\"");
        pos = input.find("&quot;", pos + 1);
    }
    return input;
}