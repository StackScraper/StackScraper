//
// Created by Michin on 23.04.2024.
//

#include "PromptSingleton.hpp"

void PromptSingleton::setValues(std::string &val) {
    this->prompt = val;
}

PromptSingleton *PromptSingleton::getInstance() {
    if (instancePtr == nullptr)
    {
        instancePtr = new PromptSingleton();
        return instancePtr;
    }
    else
    {
        return instancePtr;
    }
}

void PromptSingleton::setNickname(std::string &s) {
    this->nick = s;
}

void PromptSingleton::getPrompt() {
    std::getline(std::cin, prompt);
}

std::string PromptSingleton::getNickname() {
    return nick;
}
