//
// Created by Michin on 24.04.2024.
//

#include "StateResult.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"
#include "../Logic/StackApi/SyntaxHighlighting.hpp"
#include <vector>



void StateResult::OnEnter() {
    State::OnEnter();
    system("cls");
    TextFunctions::print(ResultTexts::title);
}

void StateResult::OnUpdate() {
    State::OnUpdate();
    TextFunctions::setCursor(32, 10);
    TextFunctions::typeWriteMessage(ResultTexts::questionText, 30);
    TextFunctions::setCursor(50, 10);
    TextFunctions::changeTextColor(TextColors::CYAN);
    question = prompt->RetValues();
    TextFunctions::print(question);

    sm.SetQuestion(prompt->RetValues());
    std::string JsonQuestion = sm.AskQuestion();

    std::string question = sm.ChangeJsonToString(JsonQuestion);
    //TextFunctions::typeWriteMessage(question, 30);

    std::cout << "Question:"<< std::endl;

    TextFunctions::changeTextColor(TextColors::WHITE);

    std::string questionWithoutHtml = sm.RemoveHtmlTags(question);
    std::string finalQuestion = sm.ReturnNiceCode(questionWithoutHtml);
    SyntaxHighlighting sh = SyntaxHighlighting();
    sh.RecognizeSyntax(finalQuestion);
    std::cout << finalQuestion;


    sm.GetAnswer(JsonQuestion);
    std::cout << "Answer 1:" << std::endl;

    const std::string tescik = sm.bestAnswer[0];
    std::string withOutHtmlTags = sm.RemoveHtmlTags(tescik);
    std::string finalAnswer = sm.ReturnNiceCode(withOutHtmlTags);


    sh.RecognizeSyntax(finalAnswer);
    std::cout << finalAnswer;
    prompt->GetPromptAuto(dict);
    if(prompt->RetValues() == "return")
    {
        mFsm.SetCurrentState(States::MENU);
    }
    else {
        mFsm.SetCurrentState(States::PROMPT);
    }
}

void StateResult::OnExit() {
    State::OnExit();
    TextFunctions::changeTextColor(TextColors::CYAN);

}
