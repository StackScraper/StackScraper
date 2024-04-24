//
// Created by Michin on 21.04.2024.
//

#include "StateIdle.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"
using namespace TextFunctions;
using namespace TextColors;

void StateIdle::onEnter(){
    State<States>::onEnter();
    system("cls");
    changeTextColor(BEIGE);
    print(IdleTexts::title);
}

void StateIdle::onUpdate() {
    State<States>::onUpdate();
    setCursor(40, 7);
    typeWriteMessage(IdleTexts::helloIns, 50);
    prompt->getPrompt();
    if(prompt->retValues() == "login")
    {
        printf("login switch");
        mFsm.setCurrentState(States::LOGIN);
    }
    else if(prompt->retValues() == "register")
    {
        printf("register switch");
        mFsm.setCurrentState(States::REGISTER);
    }
    else
    {
        onEnter();
        mFsm.setCurrentState(States::IDLE);
    }
}

void StateIdle::onExit() {
    State<States>::onExit();
}
