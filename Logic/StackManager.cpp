//
// Created by jakub on 10.05.2024.
//

#include "StackManager.hpp"
#include <iostream>
#include <cpr/cpr.h>
//https://api.stackexchange.com/2.3/search?pagesize=1&order=desc&sort=votes&intitle=cpp&site=stackoverflow&filter=withbody

std::string StackManager::askQuestion() {
    cpr::Response r = cpr::Get(cpr::Url{finalInput});
    return r.text;
    // return  finalInput;
}
void StackManager::setQuestion(std::string newInput) {
    questionInput = newInput;
    finalInput = baseInput+apiVesion+"search?pagesize=1&order=desc&sort=votes&intitle="+questionInput+"&site=stackoverflow&filter=withbody";
}
