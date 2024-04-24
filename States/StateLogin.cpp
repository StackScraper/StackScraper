//
// Created by Michin on 21.04.2024.
//

#include "StateLogin.hpp"

void StateLogin::onEnter() {
    State::onEnter();
    printf("Welcome in login!");
}

void StateLogin::onUpdate() {
    State::onUpdate();
    mFsm.setCurrentState(States::IDLE);
}

void StateLogin::onExit() {
    State::onExit();
}
