//
// Created by Michin on 21.04.2024.
//

#include "StateRegister.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"
#include "../Logic/Database/LoginManager.hpp"
using namespace TextFunctions;

void StateRegister::onEnter() {
    State::onEnter();
    system("cls");
    print(RegisterTexts::title);
}

void StateRegister::onUpdate() {
    State::onUpdate();
    TextFunctions::setCursor(32, 10);
    typeWriteMessage(RegisterTexts::credentials, 50);
    TextFunctions::setCursor(32, 12);
    typeWriteMessage(RegisterTexts::login, 0);
    TextFunctions::setCursor(39, 12);
    TextFunctions::changeTextColor(TextColors::LIGHTGREEN);
    prompt->getPrompt();
    TextFunctions::changeTextColor(TextColors::BEIGE);
    log = prompt->retValues();
    TextFunctions::setCursor(32, 14);
    typeWriteMessage(RegisterTexts::password,0);
    TextFunctions::setCursor(42, 14);
    TextFunctions::changeTextColor(TextColors::LIGHTGREEN);
    prompt->getPrompt();
    TextFunctions::changeTextColor(TextColors::BEIGE);
    pass = prompt->retValues();
    TextFunctions::setCursor(32, 16);
    typeWriteMessage(RegisterTexts::email,0);
    TextFunctions::setCursor(39, 16);
    TextFunctions::changeTextColor(TextColors::LIGHTGREEN);
    prompt->getPrompt();
    TextFunctions::changeTextColor(TextColors::BEIGE);
    email = prompt->retValues();;
    if(LoginManager::registerNew(log, email, pass))
    {
        mFsm.setCurrentState(States::MENU);
    }
    else
    {
        mFsm.setCurrentState(States::IDLE);
    }
}

void StateRegister::onExit() {
    State::onExit();
}
