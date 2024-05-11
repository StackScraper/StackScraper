//Right now project has implemented FSM but it need
//mechanism to handle functions from specific Model classes

#include <iostream>
#include "Engine.hpp"
#include <curl/curl.h>
#include <soci/soci.h>
#include <soci/empty/soci-empty.h>

PromptSingleton* PromptSingleton::instancePtr = nullptr;


int main() {

    soci::session sql(soci::empty, "hej");

    Engine eng = Engine();
    bool finish = false;
    while(!finish)
    {
        eng.run();
    }
    return 0;
}
