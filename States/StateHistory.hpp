//
// Created by Michin on 21.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_STATEHISTORY_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_STATEHISTORY_HPP

#include "StatesConf.hpp"
#include "../FSM/StateMachine.hpp"
#include "../FSM/State.hpp"

#include <iostream>
#include <string>
#include "../Logic/PromptSingleton.hpp"

class StateHistory : public State<States> {
    PromptSingleton* prompt = PromptSingleton::getInstance();
public:
    explicit StateHistory(FiniteStateMachine<States>& fsm)
    : State<States>(fsm, States::LOGIN, "LOGIN"){}

    void onEnter() override;
    void onUpdate() override;
    void onExit() override;
};


#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATEHISTORY_HPP
