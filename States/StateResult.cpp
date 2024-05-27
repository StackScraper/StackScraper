//
// Created by Michin on 24.04.2024.
//

#include "StateResult.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"
#include <vector>



void StateResult::OnEnter() {
    State::OnEnter();
    TextFunctions::changeTextColor(TextColors::BEIGE);
    system("cls");
    TextFunctions::print(ResultTexts::title);
}

void StateResult::OnUpdate() {
    State::OnUpdate();
    TextFunctions::setCursor(32, 10);
    TextFunctions::typeWriteMessage(ResultTexts::questionText, 30);
    TextFunctions::setCursor(50, 10);
    TextFunctions::changeTextColor(TextColors::BEIGE);
    question = prompt->RetValues();
    TextFunctions::print(question);
    sm.SetQuestion(prompt->RetValues());
    sm.AskQuestion(question);
    std::string jSonQ = question;
    sm.ChangeJsonToString(question);
    TextFunctions::changeTextColor(TextColors::WHITE);
    sm.RemoveHtmlTags(question);
    sm.ReturnNiceCode(question);
    sh.RecognizeSyntax(question);
    TextFunctions::print(question);
    sm.GetAnswer(jSonQ);
    TextFunctions::print(ResultTexts::firstAnswer);
    answer = sm.bestAnswer[0];
    sm.RemoveHtmlTags(answer);
    sm.ReturnNiceCode(answer);
    sh.RecognizeSyntax(answer);
    TextFunctions::print(answer);
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
    TextFunctions::changeTextColor(TextColors::BEIGE);
}
