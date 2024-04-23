//
// Created by Michin on 21.04.2024.
//

#include "StateIdle.hpp"
#include "../Texts/AllTexts.hpp"

void StateIdle::enter(){
    State<States>::enter();
    system("cls");
    std::cout<<IdleTexts::title<<std::endl;
}

void StateIdle::update() {
    State<States>::update();
    std::cout<<IdleTexts::helloIns<<std::endl;
    std::cin>>prompt;
    if(prompt == "login")
    {
        printf("login switch");
        mFsm.setCurrentState(States::LOGIN);
    }
    else if(prompt == "register")
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

void StateIdle::exit() {

}
