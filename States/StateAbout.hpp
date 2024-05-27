//
// Created by Michin on 01.05.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_STATEABOUT_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_STATEABOUT_HPP


#include "StatesConf.hpp"
#include "../FSM/StateMachine.hpp"
#include "../FSM/State.hpp"
#include "../Logic/PromptSingleton.hpp"

#include <iostream>
#include <string>
#include <vector>

class StateAbout : public State<States> {
    PromptSingleton* prompt = PromptSingleton::GetInstance();
    std::vector<std::string> dict = {
            "return"
    };
public:
    explicit StateAbout(FiniteStateMachine<States>& fsm)
            : State<States>(fsm, States::ABOUT, "ABOUT"){}

    void OnEnter() override;
    void OnUpdate() override;
    void OnExit() override;
};


#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATEABOUT_HPP
