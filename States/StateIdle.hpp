//
// Created by Michin on 21.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_STATEIDLE_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_STATEIDLE_HPP

#include "StatesConf.hpp"
#include "../FSM/StateMachine.hpp"
#include "../FSM/State.hpp"

#include <iostream>
#include "../Logic/PromptSingleton.hpp"


class StateIdle : public State<States>{
    PromptSingleton* prompt = PromptSingleton::getInstance();
public:
    explicit StateIdle(FiniteStateMachine<States>& fsm)
    : State<States>(fsm, States::IDLE, "IDLE"){}

    void onEnter() override;
    void onUpdate() override;
    void onExit() override;
};


#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATEIDLE_HPP

