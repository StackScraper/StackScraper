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
    setCursor(10, 10);
    typeWriteMessage(MenuTexts::helloText, 30);
    prompt->getPrompt();
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
    else
    {
        onEnter();
        mFsm.setCurrentState(States::MENU);
    }
}

void StateMenu::onExit() {
    State::onExit();
}
