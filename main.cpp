//Right now project has implemented FSM but it need
//mechanism to handle functions from specific Model classes

#include <iostream>
#include "Engine.hpp"
#include <soci/soci.h>
#include <soci/session.h>
#include <soci/soci-backend.h>

PromptSingleton* PromptSingleton::instancePtr = nullptr;


int main() {

    Engine eng = Engine();
    bool finish = false;
    while(!finish)
    {
        eng.run();
    }
    return 0;
}
