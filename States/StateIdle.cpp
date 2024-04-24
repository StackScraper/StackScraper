//
// Created by Michin on 21.04.2024.
//

#include "StateIdle.hpp"
#include "../Texts/AllTexts.hpp"

void StateIdle::onEnter(){
    State<States>::onEnter();
    system("cls");
    std::cout<<IdleTexts::title<<std::endl;
}

void StateIdle::onUpdate() {
    State<States>::onUpdate();
    std::cout<<IdleTexts::helloIns<<std::endl;
    std::string temp;
    std::cin>>temp;
    prompt->setValues(temp);
    if(prompt->retValues() == "login")
    {
        printf("login switch");
        mFsm.setCurrentState(States::LOGIN);
    }
    else if(prompt->retValues() == "register")
    {
        printf("register switch");
        mFsm.setCurrentState(States::REGISTER);
    }
    else
    {
        printf("type normal thing!");
        mFsm.setCurrentState(States::IDLE);
    }
}

void StateIdle::onExit() {
    State<States>::onExit();
}
