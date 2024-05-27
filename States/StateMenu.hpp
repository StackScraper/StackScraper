//
// Created by Michin on 21.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_STATEMENU_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_STATEMENU_HPP

#include "StatesConf.hpp"
#include "../FSM/StateMachine.hpp"
#include "../FSM/State.hpp"
#include "../Logic/PromptSingleton.hpp"

#include <iostream>
#include <string>
#include <vector>

class StateMenu : public State<States> {
    PromptSingleton* prompt = PromptSingleton::GetInstance();
    std::vector<std::string> dict = {
            "question",
            "history",
            "tags",
            "favourites"
    };

public:
    explicit StateMenu(FiniteStateMachine<States>& fsm)
    : State<States>(fsm, States::MENU, "MENU"){}

    void OnEnter() override;
    void OnUpdate() override;
    void OnExit() override;
};


#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATEMENU_HPP
