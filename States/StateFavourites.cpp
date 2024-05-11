//
// Created by Michin on 21.04.2024.
//

#include "StateFavourites.hpp"
#include "../Texts/AllTexts.hpp"
#include "../Logic/TextFormatter.hpp"

void StateFavourites::onExit() {
    State::onExit();
    std::vector<std::string> _favs = DBmanager::getFavourites();
    for (auto fav: _favs) {
        favs += fav;
    }
}

void StateFavourites::onUpdate() {
    State::onUpdate();
    TextFunctions::setCursor(32, 10);
    TextFunctions::typeWriteMessage(FavouriteTexts::returnText, 30);
    TextFunctions::setCursor(4, 12);
    TextFunctions::typeWriteMessage(FavouriteTexts::favTheme, 30);
    TextFunctions::setCursor(4 + FavouriteTexts::favTheme.length() + 1, 13);
    TextFunctions::print(favs);
    TextFunctions::setCursor(4 + FavouriteTexts::favTheme.length() + 1, 13 + DBmanager::getFavourites().size());
    prompt->getPrompt();
    if (TextFunctions::toLower(prompt->retValues()) == "return")
    {
        mFsm.setCurrentState(States::MENU);
    }
    else
    {
        onEnter();
    }
}

void StateFavourites::onEnter() {
    State::onEnter();
    system("cls");
    TextFunctions::print(FavouriteTexts::title);
}
