//
// Created by Michin on 21.04.2024.
//

#include "StateIdle.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"



void StateIdle::OnEnter(){
    State<States>::OnEnter();
    system("cls");
    TextFunctions::changeTextColor(TextColors::BEIGE);
    TextFunctions::print(IdleTexts::title);
}

void StateIdle::OnUpdate() {

    State<States>::OnUpdate();
    TextFunctions::setCursor(40, 9);
    TextFunctions::typeWriteMessage(IdleTexts::helloIns, 50);
    TextFunctions::setCursor(40, 11);
    prompt->GetPromptAuto(dict);
    if(prompt->RetValues() == "login")
    {
        mFsm.SetCurrentState(States::LOGIN);
    }
    else if(prompt->RetValues() == "register")
    {
        mFsm.SetCurrentState(States::REGISTER);
    }
    else if(prompt->RetValues() == "about")
    {
        mFsm.SetCurrentState(States::ABOUT);
    }
    else
    {
        OnEnter();
        mFsm.SetCurrentState(States::IDLE);
    }
}

void StateIdle::OnExit() {
    State<States>::OnExit();
}
