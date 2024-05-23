//
// Created by Michin on 23.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_PROMPTSINGLETON_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_PROMPTSINGLETON_HPP

#include <string>
#include <iostream>
#include <vector>

class PromptSingleton{
private:
    std::string prompt;
    static PromptSingleton* instancePtr;
    PromptSingleton()= default;
public:
    PromptSingleton(const PromptSingleton& obj)
    = delete;
    static PromptSingleton* getInstance();
    void setValues(std::string& val);
    std::string retValues(){ return prompt; }
    void getPrompt();
    void getPromptAuto(std::vector<std::string> dict);
};





#endif //INC_2024__TAB_DSA__8_BRODZIAK_PROMPTSINGLETON_HPP
