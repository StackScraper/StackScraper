//
// Created by jakub on 28.05.2024.
//

#ifndef STATERESULTTAGS_HPP
#define STATERESULTTAGS_HPP
#include "StatesConf.hpp"
#include "../FSM/StateMachine.hpp"
#include "../FSM/State.hpp"
#include "../Logic/PromptSingleton.hpp"

class StateResultTags : public State<States>  {
	PromptSingleton* prompt = PromptSingleton::GetInstance();
public:
	void OnEnter() override;
	void OnUpdate() override;
	void OnExit() override;

};



#endif //STATERESULTTAGS_HPP
