//
// Created by Michin on 23.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_PROMPTSINGLETON_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_PROMPTSINGLETON_HPP

#include <string>
#include <iostream>
#include <vector>

/**
 * Singleton class which contains prompt typed by user, so application can control what is actual prompt
 */
class PromptSingleton{
private:
    std::string prompt; ///< main prompt of the app
    static PromptSingleton* instancePtr; ///< pointer to the instance
    PromptSingleton()= default; ///< default constructor private by definition of singleton
public:
    PromptSingleton(const PromptSingleton& obj) ///< copy constructor deleted
    = delete;
    /**
     * Function to return instance of the singleton
     * @return
     */
    static PromptSingleton* GetInstance();
    /**
     * Function to change value of the prompt
     * @param val value to be set
     */
    void SetValues(std::string& val);
    /**
     * Function which returns prompt of the singleton (not an instance)
     * @return prompt string
     */
    std::string RetValues(){ return prompt; }
    /**
     * Function which gets new prompt to set directly from cin stream
     */
    void GetPrompt();
    /**
     * Function which gets new prompt to set directly from cin stream but also consist autocomplete
     * @param dict dictionary used to check for autocompletion
     */
    void GetPromptAuto(std::vector<std::string> dict);
};





#endif //INC_2024__TAB_DSA__8_BRODZIAK_PROMPTSINGLETON_HPP
