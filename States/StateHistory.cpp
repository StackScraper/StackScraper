//
// Created by Michin on 21.04.2024.
//

#include "StateHistory.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"



void StateHistory::OnExit() {
    State::OnExit();
    std::vector<std::string> _history = DBmanager::getHistory();
    for (auto his: _history) {
        history += his;
    }
}

void StateHistory::OnUpdate() {


    State::OnUpdate();
    TextFunctions::setCursor(32, 10);
    TextFunctions::typeWriteMessage(HistoryTexts::returnText, 30);
    TextFunctions::setCursor(4, 12);
    TextFunctions::typeWriteMessage(HistoryTexts::historyTheme, 30);
    TextFunctions::setCursor(27, 13);
    TextFunctions::print(history);
    TextFunctions::setCursor(27, 13 + DBmanager::getHistory().size());
    prompt->GetPromptAuto(dict);
    if( TextFunctions::toLower(prompt->RetValues()) == "return")
    {
        mFsm.SetCurrentState(States::MENU);
    }

}

void StateHistory::OnEnter() {
    State::OnEnter();
    system("cls");
    TextFunctions::print(HistoryTexts::title);
}
