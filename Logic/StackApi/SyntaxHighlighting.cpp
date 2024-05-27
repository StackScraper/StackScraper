//
// Created by jakub on 20.05.2024.
//

#include "SyntaxHighlighting.hpp"
#include <string>
#include "nlohmann/json.hpp"
#include <regex>
#include "Syntax.hpp"
#include <sstream>

SyntaxHighlighting::SyntaxHighlighting() {
    for(int i = 0; i < Syntax::basicSyntax.size(); i++)
    {
        std::regex wordRegex("\\b" +
                             std::regex_replace(Syntax::basicSyntax[i], std::regex(R"([-[\]{}()*+?.,\^$|#\s:])"),
                                                R"(\$&<>)") + "\\b");

        regexes.push_back(wordRegex);
    }
}

void SyntaxHighlighting::RecognizeSyntax(std::string &in) {
    std::string sentence;
    int codePos = 0;
    std::string result;
    bool terminate = false;
    while (!terminate) {
        sentence = in.substr(codePos, in.find("<code>") - codePos);
        if (in.find("<code>") != std::string::npos) {
            codePos = in.find("<code>");
            RemoveTags(in, "<code>", "", codePos);
            result += sentence;
            sentence = in.substr(codePos, in.find("</code>") - codePos);
            if (in.find("</code>") != std::string::npos) {
                codePos = in.find("</code>");
                RemoveTags(in, "</code>", "", codePos);
                result += Hightlighting(sentence);
            } else {
                terminate = true;
            }
        } else {
            terminate = true;
        }

        if (terminate && (codePos != in.length())) {
            sentence = in.substr(codePos, in.length() - codePos);
            result += sentence;
        }
    }
    in = result;
}

std::string SyntaxHighlighting::Hightlighting(std::string &in) {



    for (size_t i = 0; i < regexes.size(); i++) {
        in = std::regex_replace(in, regexes[i], Syntax::keyWord[i]);
    }
    for (int i = 0; i < Syntax::specialCharacter.size(); i++) {
        ColorChar(in, Syntax::specialCharacter[i], Syntax::colorSpecialCharacter[i]);
    }

    ColorBracket(in);

    return in;
}

void SyntaxHighlighting::RemoveTags(std::string &input, std::string tag, std::string out, int pos) {
    pos = input.find(tag, pos + out.length());
    if (pos != std::string::npos) {
        input.replace(pos, tag.length(), out);
    }
}

void SyntaxHighlighting::ColorChar(std::string &input, std::string tag, std::string out) {

    int pos = 0;
    pos = input.find(tag, pos + out.length());
    while (pos != std::string::npos) {
        input.replace(pos, tag.length(), out);
        pos = input.find(tag, pos + out.length());

        //out=="" ? pos = input.find(tag, pos + 1) : pos = input.find(tag, pos + out.length());

    }
}
void SyntaxHighlighting::ColorBracket(std::string &in) {
    int numberOfBracket=0;
    int tempNumberOfBracket=0;
    bool gtSeven = false;

    for(int i=0;i<in.length();i++) {
        char letter = in[i];
        if(letter == '(') {
            numberOfBracket++;
            if(numberOfBracket>7) {
                gtSeven = true;
                tempNumberOfBracket++;
            } else {
                gtSeven = false;
            }
            std::string newBracket = "\033[0;3"
                                    + std::to_string(gtSeven ? tempNumberOfBracket : numberOfBracket)
                                    + "m(\033[0m";
            in.replace(i, 1, newBracket);
            i += newBracket.length() - 1;

        }else if(letter == ')') {
            std::string newBracket = "\033[0;3"
                                    + std::to_string(numberOfBracket>7 ? tempNumberOfBracket : numberOfBracket)
                                    + "m)\033[0m";
            in.replace(i, 1, newBracket);
            i += newBracket.length() - 1;
            numberOfBracket--;
            if(numberOfBracket>7) tempNumberOfBracket--;

        }

        else if(letter == '{') {
            numberOfBracket++;
            if(numberOfBracket>7) {
                gtSeven = true;
                tempNumberOfBracket++;
            } else {
                gtSeven = false;
            }
            std::string newBracket = "\033[0;3"
                                    + std::to_string(gtSeven ? tempNumberOfBracket : numberOfBracket)
                                    + "m{\033[0m";
            in.replace(i, 1, newBracket);
            i += newBracket.length() - 1;

        }else if(letter == '}') {
            std::string newBracket = "\033[0;3"
                                    + std::to_string(numberOfBracket>7 ? tempNumberOfBracket : numberOfBracket)
                                    + "m}\033[0m";
            in.replace(i, 1, newBracket);
            i += newBracket.length() - 1;
            numberOfBracket--;
            if(numberOfBracket>7) tempNumberOfBracket--;

        }
    }
}