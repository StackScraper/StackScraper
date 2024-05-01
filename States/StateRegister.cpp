//
// Created by Michin on 21.04.2024.
//

#include "StateRegister.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"
#include "../Logic/LoginManager.hpp"
using namespace TextFunctions;

void StateRegister::onEnter() {
    State::onEnter();
    system("cls");
    print(RegisterTexts::title);
}

void StateRegister::onUpdate() {
    State::onUpdate();
    typeWriteMessage(RegisterTexts::credentials, 50);
    print(RegisterTexts::login);
    std::cin>>log;
    print(RegisterTexts::password);
    std::cin>>pass;
    print(RegisterTexts::email);
    std::cin>>email;
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
