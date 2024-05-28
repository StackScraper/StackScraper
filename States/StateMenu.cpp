//
// Created by Michin on 21.04.2024.
//

#include "StateMenu.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"
using namespace TextFunctions;

void StateMenu::OnEnter() {
    State::OnEnter();
    system("cls");
    print(MenuTexts::title);
}

void StateMenu::OnUpdate() {

    State::OnUpdate();
    TextFunctions::setCursor(32, 10);
    typeWriteMessage(MenuTexts::helloText, 1);
    TextFunctions::setCursor(32+ MenuTexts::helloText.length(), 10);
    TextFunctions::changeTextColor(TextColors::PINK);
    TextFunctions::print(MenuTexts::favText);
    TextFunctions::setCursor(32, 12);
    TextFunctions::changeTextColor(TextColors::LIGHTGREEN);
    prompt->GetPromptAuto(dict);
    TextFunctions::changeTextColor(TextColors::BEIGE);
    if(prompt->RetValues() == "question")
    {
        mFsm.SetCurrentState(States::PROMPT);
    }
    else if(prompt->RetValues() == "history")
    {
        mFsm.SetCurrentState(States::HISTORY);
    }
    else if(prompt->RetValues() == "tags")
    {
        mFsm.SetCurrentState(States::TAGS);
    }
    else if (prompt->RetValues() == "favourites")
    {
        mFsm.SetCurrentState(States::FAVOURITES);
    }
    else
    {
        OnEnter();
        mFsm.SetCurrentState(States::MENU);
    }
}

void StateMenu::OnExit() {
    State::OnExit();
}
