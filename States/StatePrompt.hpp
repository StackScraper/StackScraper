//
// Created by Michin on 21.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_STATEPROMPT_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_STATEPROMPT_HPP

#include "StatesConf.hpp"
#include "../FSM/StateMachine.hpp"
#include "../FSM/State.hpp"

#include <iostream>
#include <string>
#include "../Logic/PromptSingleton.hpp"
#include "../Logic/StackApi/StackManager.hpp"

/**
 * Takes keywords from user, which will be used later in the stack scraping
 */
class StatePrompt : public State<States> {
    PromptSingleton* prompt = PromptSingleton::GetInstance();
    StackManager sm = StackManager();
    std::vector<std::string> dict = {
            "return"
    };
public:
    explicit StatePrompt(FiniteStateMachine<States>& fsm)
    : State<States>(fsm, States::PROMPT, "PROMPT"){}

    void OnEnter() override;
    void OnUpdate() override;
    void OnExit() override;
};


#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATEPROMPT_HPP
