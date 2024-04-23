//
// Created by Michin on 21.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_STATEIDLE_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_STATEIDLE_HPP

#include "StatesConf.hpp"
#include "../FSM/StateMachine.hpp"
#include "../FSM/State.hpp"

#include <iostream>


class StateIdle : public State<States>{
    std::string prompt;
public:
    explicit StateIdle(FiniteStateMachine<States>& fsm)
    : State<States>(fsm, States::IDLE, "IDLE"){}

    void enter() override;
    void update() override;
    void exit() override;
};


#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATEIDLE_HPP

