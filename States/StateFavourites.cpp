//
// Created by Michin on 21.04.2024.
//

#include "StateFavourites.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"




void StateFavourites::OnExit() {
    State::OnExit();
}

void StateFavourites::OnUpdate() {
    State::OnUpdate();
    this->trimmedData = {};
    this->indexes ={};
    this->ManageData();
    TextFunctions::setCursor(32, 10);
    TextFunctions::typeWriteMessage(FavouriteTexts::returnText, 1);
    TextFunctions::setCursor(4, 12);
    TextFunctions::changeTextColor(TextColors::PINK);
    TextFunctions::typeWriteMessage(FavouriteTexts::favTheme, 1);
    TextFunctions::changeTextColor(TextColors::BEIGE);
    TextFunctions::setCursor(4 + FavouriteTexts::favTheme.length() + 1, 13);

    TextFunctions::setCursor(0, 14);
    for(int i=0;i<trimmedData.size();i++) {
        if(i%2==0){    TextFunctions::changeTextColor(TextColors::WHITE);}
        else {    TextFunctions::changeTextColor(TextColors::BEIGE);}
        TextFunctions::print(trimmedData[i]);
    }
    TextFunctions::changeTextColor(TextColors::LIGHTGREEN);
    prompt->GetPromptAuto(dict);
    TextFunctions::changeTextColor(TextColors::BEIGE);

    int phraseId = CheckFav(prompt->RetValues());

    if(phraseId>0) {
        int index = indexes[phraseId-1];
        if(db.deleteFavourite(index)) TextFunctions::print(FavouriteTexts::successText);
        prompt->GetPrompt();
        OnEnter();
    }
    else if (TextFunctions::toLower(prompt->RetValues()) == "return")
    {
        mFsm.SetCurrentState(States::MENU);
    }
    else
    {
        OnEnter();
    }
}

void StateFavourites::ManageData() {
    DBmanager db = DBmanager();

    const std::vector<std::pair<std::string,std::string>> data = db.getFavourites();
    std::string tmp;
    int iter = 1;
    for(int i = 0;i<data.size();i++) {
        if(data[i].first == "ID") {
            tmp = std::to_string(iter) + ". ";
            iter++;
            indexes.push_back(std::stoi(data[i].second));
        }
        if(data[i].first == "BODY") {
            tmp+=  data[i].second;
            if(tmp[tmp.size()-1]!='\n') {
                tmp+='\n';
            }
            trimmedData.push_back(tmp);
        }
    }
}

int StateFavourites::CheckFav(std::string prompt) {
    std::string num;
    if(prompt[0]=='d' && prompt.size()>1) {
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
    int ret = std::stoi(num);

    if(ret > trimmedData.size()) {
        return -1;
    }

    return  ret;
}

void StateFavourites::OnEnter() {
    State::OnEnter();
    system("cls");
    TextFunctions::print(FavouriteTexts::title);
}
