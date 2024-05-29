//
// Created by jakub on 28.05.2024.
//

#ifndef STATERESULTTAGS_HPP
#define STATERESULTTAGS_HPP
#include "StatesConf.hpp"
#include "../FSM/StateMachine.hpp"
#include "../FSM/State.hpp"
#include "../Logic/PromptSingleton.hpp"
#include "../Logic/StackApi/StackManager.hpp"
#include "../Logic/StackApi/SyntaxHighlighting.hpp"

/**
 * Prints result question and answers chosen in StateListTags by user
 */
class StateResultTags : public State<States>  {
	PromptSingleton* prompt = PromptSingleton::GetInstance();
	std::string question;
	std::string answer;
	StackManager sm = StackManager();
	SyntaxHighlighting sh = SyntaxHighlighting();
	std::vector<std::string> dict = {
		"tags",
		"return"
};
public:
	explicit StateResultTags(FiniteStateMachine<States>& fsm)
	: State<States>(fsm, States::RESULTTAGS, "RESULTTAGS"){}

	void OnEnter() override;
	void OnUpdate() override;
	void OnExit() override;

	void QuestionManage();

};



#endif //STATERESULTTAGS_HPP
