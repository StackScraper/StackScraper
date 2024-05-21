//
// Created by Michin on 23.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_STATETAGS_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_STATETAGS_HPP

#include "StatesConf.hpp"
#include "../FSM/StateMachine.hpp"
#include "../FSM/State.hpp"
#include "..//Logic/Database/DBmanager.hpp"

#include <iostream>
#include <string>
#include<vector>
#include "../Logic/PromptSingleton.hpp"

class StateTags : public State<States>{
    PromptSingleton* prompt = PromptSingleton::getInstance();
    std::string tags;
public:
    explicit StateTags(FiniteStateMachine<States>& fsm)
    : State<States>(fsm, States::TAGS, "TAGS"){}

    void onEnter() override;
    void onUpdate() override;
    void onExit() override;
};


#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATETAGS_HPP
