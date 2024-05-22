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
    State<States>& exitState = fsm->add<StateExit>(States::EXIT);
    State<States>& favouritesState = fsm->add<StateFavourites>(States::FAVOURITES);
    State<States>& historyState = fsm->add<StateHistory>(States::HISTORY);
    State<States>& menuState = fsm->add<StateMenu>(States::MENU);
    State<States>& promptState = fsm->add<StatePrompt>(States::PROMPT);
    State<States>& registerState = fsm->add<StateRegister>(States::REGISTER);
    State<States>& resultState = fsm->add<StateResult>(States::RESULT);
    State<States>& tagsState = fsm->add<StateTags>(States::TAGS);
    State<States>& aboutState = fsm->add<StateAbout>(States::ABOUT);

    fsm->setCurrentState(States::IDLE);
}
