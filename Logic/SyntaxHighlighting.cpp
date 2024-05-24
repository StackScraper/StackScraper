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

void SyntaxHighlighting::RecognizeSyntax(std::string& in) {

 int pos;
 int posI;
 int beginCode = 0;
 int endCode = 0;



      if (in.find("<code>") != std::string::npos) {
       pos = in.find("<code>");
       beginCode = pos;
       startOfCode=true;
       RemoveTags(in,"<code>","", pos);
      }

      if (in.find("</code>") != std::string::npos) {
       pos = in.find("</code>");
       endCode = pos;
       startOfCode=false;
       RemoveTags(in,"</code>","", pos);
      }

      posI = pos;
      // posI++;

      pos = beginCode;
      in = Hightlighting(in, pos, posI, beginCode, endCode);
       pos = posI;





}

std::string SyntaxHighlighting::Hightlighting(std::string &in, int pos, int posI, int beginCode, int endCode) {


 for (size_t i = 0; i < Syntax::basicSyntax.size(); i++) {
      std::regex wordRegex("\\b" + std::regex_replace(Syntax::basicSyntax[i], std::regex(R"([-[\]{}()*+?.,\^$|#\s:])"), R"(\$&<>)") + "\\b");
      // in.replace(pos, posI, std::regex_replace(in.substr(pos, posI), wordRegex, Syntax::keyWord[i]));
      //in = std::regex_replace(in, wordRegex, Syntax::keyWord[i]);
  //    pos = beginCode;
  // posI = pos;

   // while(!std::isspace(in[posI]))
   //  posI++;

     in = std::regex_replace(in, wordRegex, Syntax::keyWord[i]);
 }
 for(int i=0; i<Syntax::specialCharacter.size();i++) {
     ColorChar(in, Syntax::specialCharacter[i],Syntax::colorSpecialCharacter[i],pos, beginCode, endCode);

   }
   return in;
}

void SyntaxHighlighting::RemoveTags(std::string &input,std::string tag,std::string out, int pos) {

 while (pos != std::string::npos) {
  input.replace(pos, tag.length(), out);
  //out=="" ? pos = input.find(tag, pos + 1) : pos = input.find(tag, pos + out.length());
  pos = input.find(tag, pos + out.length());

 }
}

void SyntaxHighlighting::ColorChar(std::string &input,std::string tag,std::string out,int pos, int begin, int end) {

 while (pos != std::string::npos) {
  input.replace(pos, tag.length(), out);
   pos = input.find(tag, pos + out.length());

  //out=="" ? pos = input.find(tag, pos + 1) : pos = input.find(tag, pos + out.length());

 }
}