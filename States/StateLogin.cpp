//
// Created by Michin on 21.04.2024.
//

#include "StateLogin.hpp"

void StateLogin::enter() {
    State::enter();
    printf("Welcome in login!");
}

void StateLogin::update() {
    State::update();
}

void StateLogin::exit() {
    State::exit();
}
