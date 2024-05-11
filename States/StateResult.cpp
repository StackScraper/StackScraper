//
// Created by Michin on 24.04.2024.
//

#include "StateResult.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"

void StateResult::onEnter() {
    State::onEnter();
    system("cls");
    TextFunctions::print(ResultTexts::title);
}

void StateResult::onUpdate() {
    State::onUpdate();
    TextFunctions::setCursor(32, 10);
    TextFunctions::typeWriteMessage(ResultTexts::questionText, 30);
    TextFunctions::setCursor(50, 10);
    TextFunctions::changeTextColor(TextColors::CYAN);
    question = prompt->retValues();
    TextFunctions::print(question);
    answer = ApiManager::getAnswer(question);
    TextFunctions::changeTextColor(TextColors::BEIGE);
    TextFunctions::setCursor(10, 14);
    TextFunctions::typeWriteMessage(ResultTexts::answerSubtitle, 30);
    TextFunctions::setCursor(10, 14 + ResultTexts::answerSubtitle.length());
    std::cout<<answer;
    // TextFunctions::print(answer);
    TextFunctions::setCursor(10, 16);
    TextFunctions::typeWriteMessage(ResultTexts::answer, 30);
    TextFunctions::setCursor(10, 18);
    TextFunctions::typeWriteMessage(ResultTexts::proceed, 30);
    TextFunctions::setCursor(10, 20);
    prompt->getPrompt();
    mFsm.setCurrentState(States::MENU);
}

void StateResult::onExit() {
    State::onExit();
}
