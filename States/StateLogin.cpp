//
// Created by Michin on 21.04.2024.
//

#include "StateLogin.hpp"

#include "../Logic/DBmanager.hpp"
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
    TextFunctions::setCursor(32, 10);
    TextFunctions::typeWriteMessage(LoginTexts::credentials, 50);
    TextFunctions::setCursor(32, 12);
    TextFunctions::print(LoginTexts::login);
    TextFunctions::setCursor(39, 12);
    TextFunctions::changeTextColor(TextColors::LIGHTGREEN);
    prompt->getPrompt();
    TextFunctions::changeTextColor(TextColors::BEIGE);
    log = prompt->retValues();
    TextFunctions::setCursor(32, 14);
    TextFunctions::print(LoginTexts::password);
    TextFunctions::setCursor(42, 14);
    TextFunctions::changeTextColor(TextColors::LIGHTGREEN);
    prompt->getPrompt();
    TextFunctions::changeTextColor(TextColors::BEIGE);
    pass = prompt->retValues();
    if(LoginManager::login(log, pass))
    {
      //  DBmanager::setNickName(log);
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
