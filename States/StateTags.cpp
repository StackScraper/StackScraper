//
// Created by Michin on 23.04.2024.
//

#include "StateTags.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"

void StateTags::OnEnter() {
    State::OnEnter();
    system("cls");
    TextFunctions::print(TagsTexts::title);
    std::vector<std::string> _tags;// = DBmanager::getTags();
    for (auto tag: _tags) {
        tags += tag;
    }
}

void StateTags::OnUpdate() {
    State::OnUpdate();
    TextFunctions::setCursor(32, 10);
    TextFunctions::typeWriteMessage(TagsTexts::returnText, 30);
    TextFunctions::setCursor(4, 12);
    TextFunctions::typeWriteMessage(TagsTexts::tagText, 30);
    TextFunctions::setCursor(4 + TagsTexts::tagText.length() +1, 13);
    TextFunctions::print(tags);
   // TextFunctions::setCursor(4 + TagsTexts::tagText.length() +1, 13+DBmanager::getTags().size());
    prompt->GetPrompt();
    if (TextFunctions::toLower(prompt->RetValues()) == "return")
    {
        mFsm.SetCurrentState(States::MENU);
    }
    else
    {
        mFsm.SetCurrentState(States::RESULTTAGS);
    }
}

void StateTags::OnExit() {
    State::OnExit();
}
