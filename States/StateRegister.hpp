//
// Created by Michin on 21.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_STATEREGISTER_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_STATEREGISTER_HPP

#include "StatesConf.hpp"
#include "../FSM/StateMachine.hpp"
#include "../FSM/State.hpp"

#include <iostream>
#include <string>
#include "../Logic/PromptSingleton.hpp"

/**
 * Controls registration process
 */
class StateRegister : public State<States> {
    PromptSingleton* prompt = PromptSingleton::GetInstance();
    std::string log;
    std::string pass;
    std::string email;
public:
    explicit StateRegister(FiniteStateMachine<States>& fsm)
    : State<States>(fsm, States::REGISTER, "REGISTER"){}

    void OnEnter() override;
    void OnUpdate() override;
    void OnExit() override;
};


#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATEREGISTER_HPP
