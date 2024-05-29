//
// Created by Michin on 21.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_STATEEXIT_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_STATEEXIT_HPP

#include "StatesConf.hpp"
#include "../FSM/StateMachine.hpp"
#include "../FSM/State.hpp"
#include "../Logic/PromptSingleton.hpp"

#include <iostream>
#include <string>

/**
 * Exit State of the application
 * TBD
 */
class StateExit : public State<States> {
    PromptSingleton* prompt = PromptSingleton::GetInstance();
public:
    explicit StateExit(FiniteStateMachine<States>& fsm)
    : State<States>(fsm, States::EXIT, "EXIT"){}

    void OnEnter() override;
    void OnUpdate() override;
    void OnExit() override;
};


#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATEEXIT_HPP
