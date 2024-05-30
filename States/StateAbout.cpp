//
// Created by Michin on 01.05.2024.
//

#include "StateAbout.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"



void StateAbout::OnEnter() {
    State::OnEnter();
    system("cls");
    TextFunctions::print(AboutTexts::title);
}

/**
 * Implements virtual OnUpdate, in which provides app description
 */
void StateAbout::OnUpdate() {
    State::OnUpdate();
    TextFunctions::setCursor(42, 10);
    TextFunctions::typeWriteMessage(AboutTexts::aboutText, 1);
    TextFunctions::changeTextColor(TextColors::PINK);
    TextFunctions::setCursor(42 + AboutTexts::aboutText.length(), 10);
    TextFunctions::typeWriteMessage(AboutTexts::appText, 1);
    TextFunctions::changeTextColor(TextColors::BEIGE);
    TextFunctions::setCursor(32, 12);
    TextFunctions::typeWriteMessage(AboutTexts::description, 1);
    TextFunctions::setCursor(32, 14);
    TextFunctions::typeWriteMessage(AboutTexts::returnText, 1);
    TextFunctions::setCursor(32, 16);
    prompt->GetPromptAuto(dict);
    if (TextFunctions::toLower(prompt->RetValues()) == "return")
    {
        mFsm.SetCurrentState(States::IDLE);
    }
    else
    {
        OnEnter();
    }
}

void StateAbout::OnExit() {
    State::OnExit();
}
