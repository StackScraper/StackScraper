//
// Created by Michin on 21.04.2024.
//

#include "StateLogin.hpp"

#include "../Logic/Database/DBmanager.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"
#include "..//Logic/Database/DBmanager.hpp"

void StateLogin::OnEnter() {
    State::OnEnter();
    system("cls");
    TextFunctions::print(LoginTexts::title);
}

void StateLogin::OnUpdate() {
    State::OnUpdate();
    TextFunctions::setCursor(32, 10);
    TextFunctions::typeWriteMessage(LoginTexts::credentials, 50);
    TextFunctions::setCursor(32, 12);
    TextFunctions::print(LoginTexts::login);
    TextFunctions::setCursor(39, 12);
    TextFunctions::changeTextColor(TextColors::LIGHTGREEN);
    prompt->GetPrompt();
    TextFunctions::changeTextColor(TextColors::BEIGE);
    log = prompt->RetValues();
    TextFunctions::setCursor(32, 14);
    TextFunctions::print(LoginTexts::password);
    TextFunctions::setCursor(42, 14);
    TextFunctions::changeTextColor(TextColors::LIGHTGREEN);
    prompt->GetPrompt();
    TextFunctions::changeTextColor(TextColors::BEIGE);
    pass = prompt->RetValues();
    DBmanager db = DBmanager();
    if(db.loginUser(log,pass))
    {
        mFsm.SetCurrentState(States::MENU);

    }
    else
    {
        mFsm.SetCurrentState(States::IDLE);
    }
}

void StateLogin::OnExit() {
    State::OnExit();
}
