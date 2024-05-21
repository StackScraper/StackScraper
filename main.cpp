//Right now project has implemented FSM but it need
//mechanism to handle functions from specific Model classes

#include <iostream>
#include "Engine.hpp"
#include "Logic/Database/DBmanager.hpp"

PromptSingleton* PromptSingleton::instancePtr = nullptr;


int main() {



    DBmanager michal = DBmanager();


    // Engine eng = Engine();
    // bool finish = false;
    // while(!finish)
    // {
    //     eng.run();
    // }
    return 0;
}
