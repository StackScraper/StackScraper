//
// Created by Michin on 23.04.2024.
//

#include "PromptSingleton.hpp"

#include <utility>

/**
 * Local function implemented to check for matches with dictionary in getPromptAuto
 * @param text text to be matched
 * @param dict dict to search from
 * @return
 */
std::string GetMatch(std::string &text, std::vector<std::string> dict) {
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

/**
 * Function to change current value of prompt
 * @param val value to be set
 */
void PromptSingleton::SetValues(std::string &val) {
    this->prompt = val;
}

/**
 * Returns instance of singleton
 * @return instance of singleton
 */
PromptSingleton *PromptSingleton::GetInstance() {
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

/**
 * Sets prompt from cin stream
 */
void PromptSingleton::GetPrompt() {
    std::getline(std::cin, prompt);
}

/**
 * Function which gets new prompt to set directly from cin stream but also consist autocomplete
 * @param dict dictionary used to check for autocompletion
 */
void PromptSingleton::GetPromptAuto(std::vector<std::string> dict) {
    std::getline(std::cin, prompt);
    std::string t1 = this->RetValues();
    std::string temp = GetMatch(t1, std::move(dict));
    this->SetValues(temp);
}
