//
// Created by jakub on 28.05.2024.
//

#include "StateResultTags.hpp"
#include "../Logic/TextFormatter.hpp"
#include "../Texts/AllTexts.hpp"

void StateResultTags::OnEnter() {
    State::OnEnter();
    TextFunctions::changeTextColor(TextColors::BEIGE);
    system("cls");
    TextFunctions::print(ResultTexts::title);
}

/**
 * Prints question with answer(s) based on specific question id
 */
void StateResultTags::OnUpdate() {
    State::OnUpdate();
    TextFunctions::setCursor(32, 10);
    TextFunctions::typeWriteMessage(ResultTexts::questionText, 30);
    TextFunctions::setCursor(50, 10);
    TextFunctions::changeTextColor(TextColors::BEIGE);
    question = prompt->RetValues();
    TextFunctions::print(question);
    QuestionManage();
    prompt->GetPromptAuto(dict);
    if(prompt->RetValues() == "return")
    {
        mFsm.SetCurrentState(States::MENU);
    }
    else {
        mFsm.SetCurrentState(States::TAGS);
    }
}

void StateResultTags::OnExit() {
    State<States>::OnExit();
}

void StateResultTags::QuestionManage() {


    int index = std::stoi(prompt->RetValues())-1;
    std::string problem = std::to_string(sm.getQuestionList()[index].GetID());
    std::cout << problem;
    sm.GetQuestionFromID("");
    sm.AskQuestion(question);
    std::string jSonTemp = question;
    sm.ChangeJsonToString(question);
    TextFunctions::print(ResultTexts::questionText);
    TextFunctions::changeTextColor(TextColors::WHITE);
    sm.RemoveHtmlTags(question);
    sm.ReturnNiceCode(question);
    sh.RecognizeSyntax(question);
    TextFunctions::print(question);
    sm.GetAnswer(jSonTemp);
    for (int i = 0; i < 3; i++) {
        if (sm.bestAnswer[i] != "") {
            std::cout << "Answer: " << i + 1 << std::endl;
            std::string ans = sm.bestAnswer[i];
            sm.RemoveHtmlTags(ans);
            sm.ReturnNiceCode(ans);
            sh.RecognizeSyntax(ans);
            TextFunctions::print(ans);
            std::cout << std::endl;
        }

        sm.bestAnswer[i] = "";
    }
}
