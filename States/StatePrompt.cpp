//
// Created by Michin on 21.04.2024.
//

#include "StatePrompt.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"
#include <nlohmann/json.hpp>


void StatePrompt::onEnter() {
    State::onEnter();
    system("cls");
    TextFunctions::print(PromptTexts::title);
}

void StatePrompt::onUpdate() {
    State::onUpdate();
    TextFunctions::setCursor(10, 10);
    TextFunctions::typeWriteMessage(PromptTexts::promptText, 30);
    prompt->getPrompt();
    sm.setQuestion(prompt->retValues());
    std::string JsonQuestion = sm.askQuestion();



    std::string question = sm.changeJsonToString(JsonQuestion);



    TextFunctions::typeWriteMessage(question, 30);

    std::string answer = sm.getAnswer();
    //answer = sm.changeJsonToString(answer);
    answer = sm.getAnswerID(JsonQuestion);



    TextFunctions::typeWriteMessage(answer, 30);
}

void StatePrompt::onExit() {
    State::onExit();
}
