//
// Created by Michin on 21.04.2024.
//

#include "StatePrompt.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"

void StatePrompt::onEnter() {
    State::onEnter();
    system("cls");
    TextFunctions::print(PromptTexts::title);
}

void StatePrompt::onUpdate() {
    State::onUpdate();
    TextFunctions::setCursor(10, 10);
    TextFunctions::typeWriteMessage(PromptTexts::promptText, 30);
    prompt->getPrompt();
    if (prompt->retValues() == "answered question")
    {
        mFsm.setCurrentState(States::RESULT);
    }
    else if(prompt->retValues() == "return")
    {
        mFsm.setCurrentState(States::MENU);
    }
    else
    {
        onEnter();
    }
}

void StatePrompt::onExit() {
    State::onExit();
}
