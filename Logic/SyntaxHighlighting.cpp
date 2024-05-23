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

std::vector<std::string> SyntaxHighlighting::RecognizeSyntax(std::string in) {
  input.clear();
  SplitWithWhiteSpaces(in);

   for(int i=0;i<input.size();i++) {
      if (input[i].find("<code>") != std::string::npos) {
       startOfCode=true;
       RemoveTags(input[i],"<code>","");
      }

    if (input[i].find("</code>") != std::string::npos) {
        startOfCode=false;
        RemoveTags(input[i],"</code>","");
    }
      if(startOfCode) {
         input[i] = Hightlighting(input[i], Syntax::basicSyntax, Syntax::keyWord,
                      Syntax::specialCharacter, Syntax::colorSpecialCharacter);
      }
   }
    return input;
}

std::string SyntaxHighlighting::Hightlighting(std::string &in,std::vector<std::string>&basic_strings, std::vector<std::string>&keyWord,
                          std::vector<std::string>&specialCharacter, std::vector<std::string>&colorSpecialCharacter) {


 for (size_t i = 0; i < Syntax::basicSyntax.size(); i++) {
      std::regex wordRegex("\\b" + std::regex_replace(Syntax::basicSyntax[i], std::regex(R"([-[\]{}()*+?.,\^$|#\s:])"), R"(\$&<>)") + "\\b");
      in = std::regex_replace(in, wordRegex, keyWord[i]);
 }
 for(int i=0; i<specialCharacter.size();i++) {
     RemoveTags(in, specialCharacter[i],colorSpecialCharacter[i]);

   }
   return in;
}

void SyntaxHighlighting::SplitWithWhiteSpaces(const std::string& str) {

 std::string current;

 for (char ch : str) {
  if (std::isspace(ch)) {
   if (!current.empty()) {
    input.push_back(current);
    current.clear();
   }
   input.push_back(std::string(1, ch));
  } else {
   current += ch;
  }
 }

 if (!current.empty()) {
  input.push_back(current);
 }
}
void SyntaxHighlighting::RemoveTags(std::string &input,std::string tag,std::string out) {

 int pos = input.find(tag);
 while (pos != std::string::npos) {
  input.replace(pos, tag.length(), out);
  //out=="" ? pos = input.find(tag, pos + 1) : pos = input.find(tag, pos + out.length());
  pos = input.find(tag, pos + out.length());

 }
}