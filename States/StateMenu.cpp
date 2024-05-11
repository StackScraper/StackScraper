//
// Created by Michin on 21.04.2024.
//

#include "StateMenu.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"
using namespace TextFunctions;

void StateMenu::onEnter() {
    State::onEnter();
    system("cls");
    print(MenuTexts::title);
}

void StateMenu::onUpdate() {
    State::onUpdate();
    TextFunctions::setCursor(32, 10);
    typeWriteMessage(MenuTexts::helloText, 30);
    TextFunctions::setCursor(32+ MenuTexts::helloText.length(), 10);
    TextFunctions::changeTextColor(TextColors::PINK);
    TextFunctions::print(MenuTexts::favText);
    TextFunctions::setCursor(32, 12);
    TextFunctions::changeTextColor(TextColors::LIGHTGREEN);
    prompt->getPrompt();
    TextFunctions::changeTextColor(TextColors::BEIGE);
    if(prompt->retValues() == "question")
    {
        mFsm.setCurrentState(States::PROMPT);
    }
    else if(prompt->retValues() == "history")
    {
        mFsm.setCurrentState(States::HISTORY);
    }
    else if(prompt->retValues() == "tags")
    {
        mFsm.setCurrentState(States::TAGS);
    }
    else if (prompt->retValues() == "favourites")
    {
        mFsm.setCurrentState(States::FAVOURITES);
    }
    else
    {
        onEnter();
        mFsm.setCurrentState(States::MENU);
    }
}

void StateMenu::onExit() {
    State::onExit();
}
