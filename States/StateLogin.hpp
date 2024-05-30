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

/**
 * State which controls login authorization
 */
class StateLogin : public State<States>{
    PromptSingleton* prompt = PromptSingleton::GetInstance();
    std::string log;
    std::string pass;
public:
    explicit StateLogin(FiniteStateMachine<States>& fsm)
    : State<States>(fsm, States::LOGIN, "LOGIN"){}

    void OnEnter() override;
    void OnUpdate() override;
    void OnExit() override;
};


#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATELOGIN_HPP
