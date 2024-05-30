//
// Created by Michin on 21.04.2024.
//

#include "StatePrompt.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"
#include <nlohmann/json.hpp>
#include <string>



void StatePrompt::OnEnter() {
    State::OnEnter();
    system("cls");
    TextFunctions::print(PromptTexts::title);
}

/**
 * Takes desired prompt from user
 */
void StatePrompt::OnUpdate() {
    State::OnUpdate();
    TextFunctions::setCursor(10, 10);
    TextFunctions::typeWriteMessage(PromptTexts::promptText, 30);
    prompt->GetPromptAuto(dict);
    if(prompt->RetValues() == "return")
        mFsm.SetCurrentState(States::MENU);
    else
        mFsm.SetCurrentState(States::RESULT);


    // TextFunctions::typeWriteMessage(tescik, 30);
    // std::cout << "Answer 2:" << std::endl;
    //
    // tescik = sm.bestAnswer[1];
    // TextFunctions::typeWriteMessage(tescik, 30);
    // std::cout << "Answer 3:" << std::endl;
    //
    // tescik = sm.bestAnswer[2];
    // TextFunctions::typeWriteMessage(tescik, 30);

    // std::string answer = sm.getAnswer();
    // TextFunctions::typeWriteMessage(answer, 30);
    //std::string answer = sm.getAnswer();
    //answer = sm.changeJsonToString(answer);
    //int answer = sm.getAnswerID(JsonQuestion);

}

void StatePrompt::OnExit() {
    State::OnExit();
}
