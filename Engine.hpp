//
// Created by Michin on 21.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_ENGINE_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_ENGINE_HPP

#include "States/StatesWrapper.hpp"
#include "FSM/StateMachine.hpp"
#include "Logic/PromptSingleton.hpp"


/**
 * Engine of the program
 * Responsible for handling init of StateMachine
 */
class Engine {
    std::unique_ptr<FiniteStateMachine<States>> fsm = nullptr; ///< Pointer to state machine
public:
    Engine(); ///< Default constructor
    void run(); ///< Function which executes start of state machine
};


#endif //INC_2024__TAB_DSA__8_BRODZIAK_ENGINE_HPP
