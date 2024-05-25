//
// Created by jakub on 20.05.2024.
//

#include "SyntaxHighlighting.hpp"
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include <regex>
#include <cctype>
#include "Syntax.hpp"

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
    for (size_t i = 0; i < Syntax::basicSyntax.size(); i++) {
        std::regex wordRegex("\\b" +
                             std::regex_replace(Syntax::basicSyntax[i], std::regex(R"([-[\]{}()*+?.,\^$|#\s:])"),
                                                R"(\$&<>)") + "\\b");
        in = std::regex_replace(in, wordRegex, Syntax::keyWord[i]);
    }
    for (int i = 0; i < Syntax::specialCharacter.size(); i++) {
        ColorChar(in, Syntax::specialCharacter[i], Syntax::colorSpecialCharacter[i]);
    }
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