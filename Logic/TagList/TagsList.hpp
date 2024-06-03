//
// Created by jakub on 29.05.2024.
//

#ifndef TAGSLIST_HPP
#define TAGSLIST_HPP

#include <iostream>
#include <string>

/**
 * Class which contains functions to list of questions creation
 */
class TagsList {
	int id;
	std::string title;
public:
	int GetID();
	std::string GetTitle();
	TagsList(int _id, std::string& _title);
};



#endif //TAGSLIST_HPP
