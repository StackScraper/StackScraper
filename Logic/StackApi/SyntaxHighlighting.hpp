//
// Created by jakub on 20.05.2024.
//

#ifndef SYNTAXHIGHLIGHTING_HPP
#define SYNTAXHIGHLIGHTING_HPP

#include <iostream>
#include <string>
#include <vector>
#include <regex>
class SyntaxHighlighting {

        std::string syntax;
        bool startOfCode = false;

public:
        void RecognizeSyntax(std::string& in);
        std::string Hightlighting(std::string &in, std::vector<std::regex>& regexes);
        void SplitWithWhiteSpaces(const std::string& str);
        void RemoveTags(std::string &input,std::string tag, std::string out, int pos);
        void ColorChar(std::string &input,std::string tag, std::string out);

};



#endif //SYNTAXHIGHLIGHTING_HPP
