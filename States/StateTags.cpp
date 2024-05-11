//
// Created by Michin on 23.04.2024.
//

#include "StateTags.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"

void StateTags::onEnter() {
    State::onEnter();
    system("cls");
    TextFunctions::print(TagsTexts::title);
}

void StateTags::onUpdate() {
    State::onUpdate();
    TextFunctions::setCursor(32, 10);
    TextFunctions::typeWriteMessage(TagsTexts::returnText, 30);
    TextFunctions::setCursor(4, 12);
    TextFunctions::typeWriteMessage(TagsTexts::tagText, 30);
    TextFunctions::setCursor(4 + TagsTexts::tagText.length() +1, 13);
    prompt->getPrompt();
    if (TextFunctions::toLower(prompt->retValues()) == "return")
    {
        mFsm.setCurrentState(States::MENU);
    }
    else
    {
        onEnter();
    }
}

void StateTags::onExit() {
    State::onExit();
}
