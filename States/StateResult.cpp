//
// Created by Michin on 24.04.2024.
//

#include "StateResult.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"
#include "../Logic/SyntaxHighlighting.hpp"

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
    //TextFunctions::typeWriteMessage(question, 30);

    std::cout << "Question:"<< std::endl;

    std::string questionWithoutHtml = sm.RemoveHtmlTags(question);
    std::string finalQuestion = sm.ReturnNiceCode(questionWithoutHtml);
    SyntaxHighlighting sh = SyntaxHighlighting();
    std::string test = sh.RecognizeSyntax(finalQuestion);
    std::cout << test;


    sm.getAnswer(JsonQuestion);
    std::cout << "Answer 1:" << std::endl;

    const std::string tescik = sm.bestAnswer[0];
    std::string withOutHtmlTags = sm.RemoveHtmlTags(tescik);
    std::string finalAnswer = sm.ReturnNiceCode(withOutHtmlTags);
    std::string test2 = sh.RecognizeSyntax(finalAnswer);
    std::cout << test2;
    std::cout << test2;
    prompt->getPrompt();
    mFsm.setCurrentState(States::MENU);
}

void StateResult::onExit() {
    State::onExit();
}
