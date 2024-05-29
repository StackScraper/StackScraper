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


/**
 * State from which program launches - default state
 * Description of this state will be wider, since lots of fields are similar in most of states
 */
class StateIdle : public State<States>{
    PromptSingleton* prompt = PromptSingleton::GetInstance(); ///< instance of prompt singleton
    std::vector<std::string> dict = { ///< dict used for autocompletion
            "login",
            "register",
            "about"
    };
public:
    explicit StateIdle(FiniteStateMachine<States>& fsm) ///< explicit constructor with declared FSM to be used and
                                                        ///< the name of state
    : State<States>(fsm, States::IDLE, "IDLE"){}

    void OnEnter() override; ///< overriding OnEnter virtual function
    void OnUpdate() override; ///< overriding OnUpdate virtual function
    void OnExit() override; ///< overriding OnExit virtual function
};


#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATEIDLE_HPP

