//
// Created by jakub on 28.05.2024.
//

#include "StateListTags.hpp"
#include "../Logic/TextFormatter.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Globals.hpp"

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

	bool changeState= false;
	while(!changeState) {
		prompt->GetPromptAuto(dict);

		if(TextFunctions::toLower(prompt->RetValues()) == "return") {
			changeState=true;
			mFsm.SetCurrentState(States::MENU);
			changeState=true;

		}else if(!ChoosingTitle(prompt->RetValues())) {
			mFsm.SetCurrentState(States::LISTTAGS);
			std::string error = "\033[0;31mYou have to choose from the list\033[0m";
			COORD position = TextFunctions::GetConsoleCursorPosition(cmd::hOutput);
			TextFunctions::print(error);

			TextFunctions::setCursor(position.X,position.Y-1);

			std::cout << "\x1b[2K";
			TextFunctions::changeTextColor(TextColors::YELLOW);
			std::cout << "Prompt: ";
			TextFunctions::changeTextColor(TextColors::WHITE);
			changeState=true;

		}
		else if (ChoosingTitle(prompt->RetValues()))
		{
			mFsm.SetCurrentState(States::RESULTTAGS);
			changeState=true;
		}
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
			temp = std::to_string(i+1) + ". " + questionsList[i].GetTitle();
			sm.ReturnNiceCode(temp);
			TextFunctions::print( temp);
		}
	}
	TextFunctions::changeTextColor(TextColors::YELLOW);
	std::cout << std::endl << "Prompt: ";
	TextFunctions::changeTextColor(TextColors::WHITE);

}

bool StateListTags::ChoosingTitle(std::string in) {

	for (int i=0; i<in.length(); i++){
		if (!isdigit(in[i])){
			return false;
		}
	}
	int questionIdx = std::stoi(in);

	if(questionIdx>0 && questionIdx<21) {
		return true;
	}
	return false;

}
