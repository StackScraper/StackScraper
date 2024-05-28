//
// Created by jakub on 28.05.2024.
//

#include "StateListTags.hpp"
#include "../Logic/TextFormatter.hpp"
#include "../Texts/AllTexts.hpp"

void StateListTags::OnEnter() {
	State::OnEnter();
	system("cls");
	TextFunctions::print(ListState::title);
}

void StateListTags::OnUpdate() {
	State::OnUpdate();
	TextFunctions::setCursor(42, 10);
	TextFunctions::typeWriteMessage(ListState::tagText, 30);
	TextFunctions::changeTextColor(TextColors::WHITE);
	TextFunctions::setCursor(42 + ListState::tagText.length(), 10);
	
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

void StateListTags::OnExit() {
	State::OnExit();
}
