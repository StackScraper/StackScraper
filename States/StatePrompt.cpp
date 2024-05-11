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
    TextFunctions::setCursor(32, 10);
    TextFunctions::typeWriteMessage(PromptTexts::promptText, 30);
    TextFunctions::setCursor(32, 12);
    TextFunctions::changeTextColor(TextColors::LIGHTGREEN);
    prompt->getPrompt();
    TextFunctions::changeTextColor(TextColors::BEIGE);
    if(prompt->retValues() == "return")
    {
        mFsm.setCurrentState(States::MENU);
    }
    else
    {
          sm.setQuestion(prompt->retValues());
          std::string test = sm.askQuestion();
          TextFunctions::typeWriteMessage(test, 30);
       // mFsm.setCurrentState(States::RESULT);
    }
}

void StatePrompt::onExit() {
    State::onExit();
}
