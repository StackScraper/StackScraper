//
// Created by Michin on 24.04.2024.
//

#include "StateResult.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"

void StateResult::onEnter() {
    State::onEnter();
    system("cls");
    TextFunctions::print(ResultTexts::title);
}

void StateResult::onUpdate() {
    State::onUpdate();
    TextFunctions::setCursor(32, 10);
    TextFunctions::typeWriteMessage(ResultTexts::questionText, 30);
    TextFunctions::setCursor(50, 10);
    TextFunctions::changeTextColor(TextColors::CYAN);
    question = prompt->retValues();
    TextFunctions::print(question);
    answer = ApiManager::getAnswer(question);
    sm.setQuestion(prompt->retValues());
    std::string JsonQuestion = sm.askQuestion();

    std::string question = sm.changeJsonToString(JsonQuestion);
    // TextFunctions::typeWriteMessage(question, 30);

    std::cout << "Question:"<< std::endl;

    std::cout << question << std::endl;

    sm.getAnswer(JsonQuestion);

    std::cout << "Answer 1:" << std::endl;

    std::string tescik = sm.bestAnswer[0];

    std::cout << tescik;
    prompt->getPrompt();
    mFsm.setCurrentState(States::MENU);
}

void StateResult::onExit() {
    State::onExit();
}
