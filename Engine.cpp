//
// Created by Michin on 21.04.2024.
//

#include "Engine.hpp"


void Engine::run() {
    fsm->onUpdate();
}

Engine::Engine() {
    fsm = std::make_unique<FiniteStateMachine<States>>();
    State<States>& idleState = fsm->add<StateIdle>(States::IDLE);
    State<States>& loginState = fsm->add<StateLogin>(States::LOGIN);
    State<States>& exitState = fsm->add<StateLogin>(States::EXIT);
    State<States>& favouritesState = fsm->add<StateLogin>(States::FAVOURITES);
    State<States>& historyState = fsm->add<StateLogin>(States::HISTORY);
    State<States>& menuState = fsm->add<StateLogin>(States::MENU);
    State<States>& promptState = fsm->add<StateLogin>(States::PROMPT);
    State<States>& registerState = fsm->add<StateLogin>(States::REGISTER);

    fsm->setCurrentState(States::IDLE);
}
