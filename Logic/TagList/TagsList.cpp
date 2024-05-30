//
// Created by jakub on 29.05.2024.
//

#include "TagsList.hpp"

#include <iostream>
#include <string>

int TagsList::GetID(){
	return id;
}
std::string TagsList::GetTitle(){
	return title;
}
TagsList::TagsList(int _id, std::string& _title){
	id=_id;
	title=_title;
}