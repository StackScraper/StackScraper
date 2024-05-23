//
// Created by jakub on 20.05.2024.
//

#ifndef SYNTAXHIGHLIGHTING_HPP
#define SYNTAXHIGHLIGHTING_HPP

#include <iostream>
#include <string>
#include <vector>

class SyntaxHighlighting {

        std::string syntax;
        bool startOfCode = false;
        std::vector<std::string>input;

public:
        std::vector<std::string> RecognizeSyntax(std::string in);
        std::string Hightlighting(std::string &in,std::vector<std::string>&basic_strings, std::vector<std::string>&keyWord,
                                std::vector<std::string>&specialCharacter, std::vector<std::string>&colorSpecialCharacter);
        void SplitWithWhiteSpaces(const std::string& str);
        void RemoveTags(std::string &input,std::string tag, std::string out);

};



#endif //SYNTAXHIGHLIGHTING_HPP
