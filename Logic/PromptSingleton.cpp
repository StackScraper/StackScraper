//
// Created by Michin on 23.04.2024.
//

#include "PromptSingleton.hpp"

#include <utility>

std::string getMatch(std::string &text, std::vector<std::string> dict) {
    bool nEqual = false;
    int len = dict.size();
    for (int i = 0; i < len; i++) {
        int size = (text.size()>dict[i].size() ? dict[i].size() : text.size());
        nEqual = false;
        for(int j = 0; j < size; j++)
        {
            if(text[j] != dict[i][j])
            {
                nEqual = true;
                break;
            }
        }
        if(!nEqual)
        {
            return dict[i];
        }
    }
    return text;
}

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

void PromptSingleton::getPrompt() {
    std::getline(std::cin, prompt);
}

void PromptSingleton::getPromptAuto(std::vector<std::string> dict) {
    std::getline(std::cin, prompt);
    std::string t1 = this->retValues();
    std::string temp = getMatch(t1, std::move(dict));
    this->setValues(temp);
}
