//
// Created by Michin on 21.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_STATEFAVOURITES_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_STATEFAVOURITES_HPP

#include "StatesConf.hpp"
#include "../FSM/StateMachine.hpp"
#include "../FSM/State.hpp"
#include "..//Logic/Database/DBmanager.hpp"

#include <iostream>
#include <string>
#include "../Logic/PromptSingleton.hpp"

/**
 * Provides information about questions which user added to favourites
 */
class StateFavourites : public State<States> {
    PromptSingleton* prompt = PromptSingleton::GetInstance();
    std::vector<std::string> dict = {
            "return"
    };

    DBmanager db; ///< database manager for executing queries
    std::vector<int> indexes;
    std::vector<std::pair<std::string,std::string>> data;
    std::vector<std::string> trimmedData;

    void ManageData();
    int CheckFav(std::string);
public:
    explicit StateFavourites(FiniteStateMachine<States>& fsm)
    : State<States>(fsm, States::FAVOURITES, "FAVOURITES"){}

    void OnEnter() override;
    void OnUpdate() override;
    void OnExit() override;
};


#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATEFAVOURITES_HPP
