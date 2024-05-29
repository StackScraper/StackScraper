//
// Created by Michin on 21.04.2024.
//

#include "StateHistory.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"

void StateHistory::OnExit() {
    State::OnExit();
}

void StateHistory::OnUpdate() {
    State::OnUpdate();
    TextFunctions::setCursor(32, 10);
    TextFunctions::typeWriteMessage(HistoryTexts::returnText, 1);
    TextFunctions::setCursor(4, 12);
    TextFunctions::typeWriteMessage(HistoryTexts::historyTheme, 1);
    TextFunctions::setCursor(0, 14);
    this->trimmedData = {};
    this->ManageData();
    for(int i=0;i<trimmedData.size();i++) {
        if(i%2==0){    TextFunctions::changeTextColor(TextColors::WHITE);}
        else {    TextFunctions::changeTextColor(TextColors::BEIGE);}
        TextFunctions::print(trimmedData[i]);
    }
    TextFunctions::changeTextColor(TextColors::LIGHTGREEN);
    prompt->GetPromptAuto(dict);
    TextFunctions::changeTextColor(TextColors::BEIGE);

    int phraseId = CheckFav(prompt->RetValues());

    if(phraseId>0 && phraseId <= trimmedData.size()) {
        db.insertFavourite(phraseId);
        TextFunctions::print(HistoryTexts::successText);
        prompt->GetPrompt();
        OnEnter();
    }
    else if( TextFunctions::toLower(prompt->RetValues()) == "return")
    {
        mFsm.SetCurrentState(States::MENU);
    }
    else {
        system("cls");
        TextFunctions::print(HistoryTexts::title);
    }
}

void StateHistory::ManageData() {
    DBmanager db = DBmanager();

    const std::vector<std::pair<std::string,std::string>> data = db.getPhrases();
    std::string tmp;
    for(int i = 0;i<data.size();i++) {
        if(data[i].first == "ID") {
            tmp = data[i].second + ". ";
        }
        if(data[i].first == "BODY") {
            tmp+=  data[i].second;
            if(tmp[tmp.size()-1]!='\n') {
                tmp+='\n';
            }
            this->trimmedData.push_back(tmp);
        }
    }
}

int StateHistory::CheckFav(std::string prompt) {
    std::string num;
    if(prompt[0]=='f' && prompt.size()>1) {
        for(int i =1;i<prompt.size();i++) {
            if(isdigit(prompt[i])) {
                num+=prompt[i];
            }
            else {
                return -1;
            }
        }
    }
    else {
        return -1;
    }
    return std::stoi(num);
}

void StateHistory::OnEnter() {
    State::OnEnter();
    TextFunctions::changeTextColor(TextColors::BEIGE);
    system("cls");
    TextFunctions::print(HistoryTexts::title);
}
