//
// Created by Michin on 21.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_STATEHISTORY_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_STATEHISTORY_HPP

#include "StatesConf.hpp"
#include "../FSM/StateMachine.hpp"
#include "../FSM/State.hpp"
#include "..//Logic/Database/DBmanager.hpp"

#include <iostream>
#include <string>
#include "../Logic/PromptSingleton.hpp"

class StateHistory : public State<States> {
    PromptSingleton* prompt = PromptSingleton::GetInstance();
    std::vector<std::string> dict = {
            "return"
    };
    DBmanager db;
    std::vector<std::string> trimmedData;

    void ManageData();
    int CheckFav(std::string);
public:
    explicit StateHistory(FiniteStateMachine<States>& fsm)
    : State<States>(fsm, States::HISTORY, "HISTORY"){}

    void OnEnter() override;
    void OnUpdate() override;
    void OnExit() override;
};


#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATEHISTORY_HPP
