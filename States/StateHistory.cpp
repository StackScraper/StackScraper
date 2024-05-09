//
// Created by Michin on 21.04.2024.
//

#include "StateHistory.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"

void StateHistory::onExit() {
    State::onExit();
}

void StateHistory::onUpdate() {
    State::onUpdate();
    TextFunctions::setCursor(10, 10);
    TextFunctions::typeWriteMessage(HistoryTexts::returnText, 30);
    TextFunctions::typeWriteMessage(HistoryTexts::historyTheme, 30);
    prompt->getPrompt();
    if( TextFunctions::toLower(prompt->retValues()) == "return")
    {
        mFsm.setCurrentState(States::MENU);
    }

}

void StateHistory::onEnter() {
    State::onEnter();
    system("cls");
    TextFunctions::print(HistoryTexts::title);
}
