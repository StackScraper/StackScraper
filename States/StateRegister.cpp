//
// Created by Michin on 21.04.2024.
//

#include "StateRegister.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"
#include "..//Logic/Database/DBmanager.hpp"
using namespace TextFunctions;

void StateRegister::OnEnter() {
    State::OnEnter();
    system("cls");
    print(RegisterTexts::title);
}

void StateRegister::OnUpdate() {
    State::OnUpdate();
    TextFunctions::setCursor(32, 10);
    typeWriteMessage(RegisterTexts::credentials, 50);
    TextFunctions::setCursor(32, 12);
    typeWriteMessage(RegisterTexts::login, 0);
    TextFunctions::setCursor(39, 12);
    TextFunctions::changeTextColor(TextColors::LIGHTGREEN);
    prompt->GetPrompt();
    TextFunctions::changeTextColor(TextColors::BEIGE);
    log = prompt->RetValues();
    TextFunctions::setCursor(32, 14);
    typeWriteMessage(RegisterTexts::password,0);
    TextFunctions::setCursor(42, 14);
    TextFunctions::changeTextColor(TextColors::LIGHTGREEN);
    prompt->GetPrompt();
    TextFunctions::changeTextColor(TextColors::BEIGE);
    pass = prompt->RetValues();
    TextFunctions::setCursor(32, 16);
    typeWriteMessage(RegisterTexts::email,0);
    TextFunctions::setCursor(39, 16);
    TextFunctions::changeTextColor(TextColors::LIGHTGREEN);
    prompt->GetPrompt();
    TextFunctions::changeTextColor(TextColors::BEIGE);

    email = prompt->RetValues();
    std::cout<<"hej";
    DBmanager db = DBmanager();
    if(db.insertUser(log,pass))
    {
        mFsm.SetCurrentState(States::LOGIN);
    }
    else
    {
        mFsm.SetCurrentState(States::IDLE);
    }
}

void StateRegister::OnExit() {
    State::OnExit();
}
