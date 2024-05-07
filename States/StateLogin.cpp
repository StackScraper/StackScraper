//
// Created by Michin on 21.04.2024.
//

#include "StateLogin.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"
#include "../Logic/LoginManager.hpp"

void StateLogin::onEnter() {
    State::onEnter();
    system("cls");
    TextFunctions::print(LoginTexts::title);
}

void StateLogin::onUpdate() {
    State::onUpdate();
    TextFunctions::typeWriteMessage(LoginTexts::credentials, 50);
    TextFunctions::print(LoginTexts::login);
    prompt->getPrompt();
    log = prompt->retValues();
    TextFunctions::print(LoginTexts::password);
    prompt->getPrompt();
    pass = prompt->retValues();
    if(LoginManager::login(log, pass))
    {
        mFsm.setCurrentState(States::MENU);
    }
    else
    {
        mFsm.setCurrentState(States::IDLE);
    }
}

void StateLogin::onExit() {
    State::onExit();
}
