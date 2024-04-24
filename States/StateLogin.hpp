//
// Created by Michin on 21.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_STATELOGIN_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_STATELOGIN_HPP

#include "StatesConf.hpp"
#include "../FSM/StateMachine.hpp"
#include "../FSM/State.hpp"
#include "../Logic/PromptSingleton.hpp"
#include <iostream>
#include <string>


class StateLogin : public State<States>{
    PromptSingleton* prompt = PromptSingleton::getInstance();
public:
    explicit StateLogin(FiniteStateMachine<States>& fsm)
    : State<States>(fsm, States::LOGIN, "LOGIN"){}

    void onEnter() override;
    void onUpdate() override;
    void onExit() override;
};


#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATELOGIN_HPP
