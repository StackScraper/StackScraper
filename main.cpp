//Right now project has implemented FSM but it need
//mechanism to handle functions from specific Model classes

#include <iostream>
#include "Engine.hpp"

/**
 * Declaration of PromptSingleton - class responsible for holding information about actual
 * user input in the application
 */
PromptSingleton* PromptSingleton::instancePtr = nullptr;

/**
 * Main class of the program
 * Creates Engine and start main lop
 * @return 0 if everything executes fine
 */
int main() {

    Engine eng = Engine(); ///< Engine of the application

    bool finish = false;
    while(!finish)
    {
        eng.Run(); ///< Start engine
    }
    return 0;
}
