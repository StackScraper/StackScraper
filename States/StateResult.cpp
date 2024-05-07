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
    TextFunctions::setCursor(10, 10);
    TextFunctions::typeWriteMessage(ResultTexts::answerSubtitle, 30);
    TextFunctions::typeWriteMessage(ResultTexts::answer, 30);
}

void StateResult::onExit() {
    State::onExit();
}
