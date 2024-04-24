//
// Created by Michin on 21.04.2024.
//

#include "StateRegister.hpp"

void StateRegister::onEnter() {
    State::onEnter();
}

void StateRegister::onUpdate() {
    State::onUpdate();
    mFsm.setCurrentState(States::IDLE);
}

void StateRegister::onExit() {
    State::onExit();
}
