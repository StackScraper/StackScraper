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

public:
        void RecognizeSyntax(std::string& in);
        std::string Hightlighting(std::string &in, int pos, int posI, int beginCode, int endCode);
        void SplitWithWhiteSpaces(const std::string& str);
        void RemoveTags(std::string &input,std::string tag, std::string out, int pos);
        void ColorChar(std::string &input,std::string tag, std::string out, int pos, int begin, int end);

};



#endif //SYNTAXHIGHLIGHTING_HPP
