//
// Created by Michin on 21.04.2024.
//

#include "Engine.hpp"

/**
 * Function which executes first onUpdate of state
 */
void Engine::Run() {
    fsm->OnUpdate();
}

/**
 * Function which inits state machine and all of it's states
 * Sets first state to IDLE
 */
Engine::Engine() {
    fsm = std::make_unique<FiniteStateMachine<States>>();
    State<States>& idleState = fsm->Add<StateIdle>(States::IDLE);
    State<States>& loginState = fsm->Add<StateLogin>(States::LOGIN);
    State<States>& exitState = fsm->Add<StateExit>(States::EXIT);
    State<States>& favouritesState = fsm->Add<StateFavourites>(States::FAVOURITES);
    State<States>& historyState = fsm->Add<StateHistory>(States::HISTORY);
    State<States>& menuState = fsm->Add<StateMenu>(States::MENU);
    State<States>& promptState = fsm->Add<StatePrompt>(States::PROMPT);
    State<States>& registerState = fsm->Add<StateRegister>(States::REGISTER);
    State<States>& resultState = fsm->Add<StateResult>(States::RESULT);
    State<States>& tagsState = fsm->Add<StateTags>(States::TAGS);
    State<States>& aboutState = fsm->Add<StateAbout>(States::ABOUT);
    State<States>& listTagsState = fsm->Add<StateListTags>(States::LISTTAGS);
    State<States>& resultTagsState = fsm->Add<StateResultTags>(States::RESULTTAGS);

    fsm->SetCurrentState(States::TAGS);

}
