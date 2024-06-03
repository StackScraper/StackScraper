//
// Created by jakub on 29.05.2024.
//

#include "TagsList.hpp"

#include <iostream>
#include <string>

/**
 * @return id of the tag
 */
int TagsList::GetID(){
	return id;
}
/**
 *
 * @return title of the question
 */
std::string TagsList::GetTitle(){
	return title;
}
/**
 * constructor
 * @param _id id of the question
 * @param _title title of the question
 */
TagsList::TagsList(int _id, std::string& _title){
	id=_id;
	title=_title;
}