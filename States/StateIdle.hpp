//
// Created by Michin on 21.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_STATEIDLE_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_STATEIDLE_HPP

#include <iostream>
#include "StatesConf.hpp"
#include "../FSM/StateMachine.hpp"
#include "../FSM/State.hpp"
#include "../Logic/PromptSingleton.hpp"
#include <vector>



class StateIdle : public State<States>{
    PromptSingleton* prompt = PromptSingleton::GetInstance();
    std::vector<std::string> dict = {
            "login",
            "register",
            "about"
    };
public:
    explicit StateIdle(FiniteStateMachine<States>& fsm)
    : State<States>(fsm, States::IDLE, "IDLE"){}

    void OnEnter() override;
    void OnUpdate() override;
    void OnExit() override;
};


#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATEIDLE_HPP

