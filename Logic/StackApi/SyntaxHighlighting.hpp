//
// Created by jakub on 20.05.2024.
//

#ifndef SYNTAXHIGHLIGHTING_HPP
#define SYNTAXHIGHLIGHTING_HPP

#include <iostream>
#include <string>
#include <vector>
#include <regex>

/**
 * Takes control of highlighting of syntax
 */
class SyntaxHighlighting {
        std::vector<std::regex> regexes;
public:
        SyntaxHighlighting(); ///< default constructor
        void RecognizeSyntax(std::string& in); ///< finding <code> and </code> marks in questions and answers
        std::string Hightlighting(std::string &in); ///< highlights code
        void RemoveTags(std::string &input,std::string tag, std::string out, int pos); ///< deleting html tags
        void ColorChar(std::string &input,std::string tag, std::string out); ///< coloring special chars
        void ColorBracket(std::string &in); ///< provides brackets coloring
};



#endif //SYNTAXHIGHLIGHTING_HPP
