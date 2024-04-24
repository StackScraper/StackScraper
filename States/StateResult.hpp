//
// Created by Michin on 24.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_STATERESULT_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_STATERESULT_HPP


#include "StatesConf.hpp"
#include "../FSM/StateMachine.hpp"
#include "../FSM/State.hpp"

#include <iostream>
#include <string>
#include "../Logic/PromptSingleton.hpp"

class StateResult : public State<States> {
    PromptSingleton* prompt = PromptSingleton::getInstance();
public:
    explicit StateResult(FiniteStateMachine<States>& fsm)
            : State<States>(fsm, States::REGISTER, "REGISTER"){}

    void onEnter() override;
    void onUpdate() override;
    void onExit() override;
};


#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATERESULT_HPP
