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

/**
 * Prints the list of the questions, fills the canva
 */
void StateListTags::OnUpdate() {
	State::OnUpdate();

	TextFunctions::setCursor(10, 10);
	TextFunctions::print(ListState::tagText);

	TextFunctions::changeTextColor(TextColors::WHITE);

	ManageList();
	prompt->GetPromptAuto(dict);
	if (TextFunctions::toLower(prompt->RetValues()) == "return")
	{
		mFsm.SetCurrentState(States::IDLE);
	}
	else
	{
		 mFsm.SetCurrentState(States::RESULTTAGS);
	}
}

void StateListTags::OnExit() {
	State::OnExit();
}

void StateListTags::ManageList() {
	sm.SetQuestionByTags(prompt->RetValues());
	sm.AskQuestion(question);
	std::string jSonTemp = question;
	sm.checkTagQuestionList(question);
	questionsList = sm.getQuestionList();
	std::string temp;
	if(!questionsList.empty()) {
		for(int i = 0; i < questionsList.size(); i++) {
			temp = std::to_string(i+1) + ". " + questionsList[i];
			TextFunctions::print( temp);
		}
	}
}
