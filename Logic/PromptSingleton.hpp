//
// Created by Michin on 23.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_PROMPTSINGLETON_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_PROMPTSINGLETON_HPP

#include <string>
#include <iostream>

class PromptSingleton{
private:
    std::string prompt;
    std::string nick;
    static PromptSingleton* instancePtr;
    PromptSingleton()= default;
public:
    PromptSingleton(const PromptSingleton& obj)
    = delete;
    static PromptSingleton* getInstance();
    void setValues(std::string& val);
    std::string retValues(){ return prompt; }
    void setNickname(std::string& s);
    void getPrompt();
    std::string getNickname();
};





#endif //INC_2024__TAB_DSA__8_BRODZIAK_PROMPTSINGLETON_HPP
