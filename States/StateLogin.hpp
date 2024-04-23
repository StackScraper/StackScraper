//
// Created by Michin on 21.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_STATELOGIN_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_STATELOGIN_HPP

#include "StatesConf.hpp"
#include "../FSM/StateMachine.hpp"
#include "../FSM/State.hpp"

#include <iostream>
#include <string>


class StateLogin : public State<States>{
    std::string prompt;
public:
    explicit StateLogin(FiniteStateMachine<States>& fsm)
    : State<States>(fsm, States::LOGIN, "LOGIN"){}

    void enter() override;
    void update() override;
    void exit() override;
};


#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATELOGIN_HPP
