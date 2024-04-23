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

    fsm->setCurrentState(States::IDLE);
}
