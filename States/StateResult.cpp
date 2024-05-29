//
// Created by Michin on 24.04.2024.
//

#include "StateResult.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"
#include "../Logic/Database/DBmanager.hpp"

void StateResult::OnEnter() {
    State::OnEnter();
    TextFunctions::changeTextColor(TextColors::BEIGE);
    system("cls");
    TextFunctions::print(ResultTexts::title);
}

void StateResult::OnUpdate() {
    ///prepare canva
    State::OnUpdate();
    TextFunctions::setCursor(32, 10);
    TextFunctions::typeWriteMessage(ResultTexts::questionText, 30);
    TextFunctions::setCursor(50, 10);
    TextFunctions::changeTextColor(TextColors::BEIGE);
    question = prompt->RetValues();
    TextFunctions::print(question);
    ///find questions, answers and print them
    QuestionManage();
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

/**
 * Provides stack scraping and formatting
 */
void StateResult::QuestionManage() {
    sm.SetQuestion(prompt->RetValues());
    sm.AskQuestion(question);
    std::string jSonTemp = question;
    ///parse json to string
    sm.ChangeJsonToString(question);
    TextFunctions::print(ResultTexts::questionText);
    TextFunctions::changeTextColor(TextColors::WHITE);
    ///remove html tags
    sm.RemoveHtmlTags(question);
    ///return string with spaces, tabs and with some attributes changed
    sm.ReturnNiceCode(question);
    ///color syntax
    sh.RecognizeSyntax(question);
    TextFunctions::print(question);
    sm.GetAnswer(jSonTemp);
    DBmanager db = DBmanager();
    std::string body = sm.GetTitle();
    std::string response = sm.GetQuestionId();
    if(body != "Not found")db.insertPhrase(body,response);
    /**
     * Do the same as above, but for answers
     */
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
