//
// Created by Michin on 24.04.2024.
//

#include "StateResult.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"
#include "../Logic/StackApi/SyntaxHighlighting.hpp"

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
    QuestionManage();
    prompt->getPromptAuto(dict);
    if (prompt->retValues() == "return") {
        mFsm.setCurrentState(States::MENU);
    } else {
        mFsm.setCurrentState(States::PROMPT);
    }
}

void StateResult::onExit() {
    State::onExit();
    TextFunctions::changeTextColor(TextColors::CYAN);
}

void StateResult::QuestionManage() {
    sm.setQuestion(prompt->retValues());
    std::string JsonQuestion = sm.askQuestion();
    std::string question = sm.changeJsonToString(JsonQuestion);
    std::cout << "Question:"<<std::endl;
    TextFunctions::changeTextColor(TextColors::WHITE);
    std::string questionWithoutHtml = sm.RemoveHtmlTags(question);
    std::string finalQuestion = sm.ReturnNiceCode(questionWithoutHtml);
    SyntaxHighlighting sh = SyntaxHighlighting();
    sh.RecognizeSyntax(finalQuestion);
    TextFunctions::typeWriteMessage(finalQuestion, 5);
    sm.getAnswer(JsonQuestion);
    for (int i = 0; i < 3; i++) {
        if (sm.bestAnswer[i] != "") {
            std::cout << "Answer: " << i + 1 << std::endl;
            std::string withOutHtmlTags = sm.RemoveHtmlTags(sm.bestAnswer[i]);
            std::string finalAnswer = sm.ReturnNiceCode(withOutHtmlTags);
            sh.RecognizeSyntax(finalAnswer);
            TextFunctions::typeWriteMessage(finalAnswer, 2);
            std::cout << std::endl;
        }
    }
}
