//
// Created by jakub on 20.05.2024.
//

#include "SyntaxHighlighting.hpp"
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>


std::string SyntaxHighlighting::RecognizeSyntax(std::string in) {
    basicSyntax = {"for","while","do",
                    "if", "else","int",
                    "string","::","std",
                    "double","float","bool",
                    "main","switch","case",
                    "char","cin","getline",
                    "cout","return","long",
                    "short", "cerr", "<<",
                    ">>","#include","using namespace",
                    "NULL","nullptr","class",
                    "void","private","public",
                    "*","&","\"",
                    "=","const","static",
                    "delete", "new", "break",
                    "continue","protected","enum",
                    "\'","typedef","try",
                    "catch","throw","template",
                    "operator","this","friend",
                    "volatile","extern","struct",
                    "sizeof","finally"};
    // std::cout << "\033[1;31mbold red text\033[0m\n";
    keyWord = {"\033[0;32mfor\033[0m","\033[0;32mwhile\033[0m","\033[0;32mdo\033[0m",
                "\033[0;34mif\033[0m", "\033[0;34melse\033[0m","\033[0;33mint\033[0m",
                "\033[0;33mstring\033[0m","\033[0;31m::\033[0m","\033[0;35mstd\033[0m",
                "\033[0;33mdouble\033[0m","\033[0;33mfloat\033[0m","\033[0;33mbool\033[0m",
                "\033[0;34mmain\033[0m","\033[0;36mswitch\033[0m", "\033[0;33mcase\033[0m",
                "\033[0;33mchar\033[0m","\033[0;31mcin\033[0m","\033[0;31mgetline\033[0m",
                "\033[0;31mcout\033[0m","\033[0;31mreturn\033[0m", "\033[0;33mlong\033[0m",
                 "\033[0;33mshort\033[0m","\033[0;31mcerr\033[0m","\033[0;32m<<\033[0m",
                "\033[0;32m>>\033[0m","\033[0;33m#include\033[0m", "\033[0;32musing namespace\033[0m",
                "\033[0;32mNULL\033[0m","\033[0;32mnullptr\033[0m", "\033[0;33mclass\033[0m",
                 "\033[0;33mvoid\033[0m","\033[0;31mprivate\033[0m","\033[0;32mpublic\033[0m",
                "\033[0;34m*\033[0m","\033[0;34m&\033[0m","\033[0;32m\"\033[0m",
                "\033[0;33m=\033[0m","\033[0;35mconst\033[0m","\033[0;35mstatic\033[0m",
                "\033[0;31mdelete\033[0m","\033[0;36mnew\033[0m","\033[0;31mbreak\033[0m",
                "\033[0;33mcontinue\033[0m","\033[0;33mprotected\033[0m","\033[0;33menum\033[0m",
                 "\033[0;31m\'\033[0m","\033[0;32mtypedef\033[0m","\033[0;36mtry\033[0m",
                "\033[0;36mcatch\033[0m","\033[0;31mthrow\033[0m","\033[0;34mtemplate\033[0m",
                "\033[0;33moperator\033[0m","\033[0;32mthis\033[0m","\033[0;35mfriend\033[0m",
                "\033[0;33mvolatile\033[0m","\033[0;33mextern\033[0m","\033[0;33mstruct\033[0m",
                "\033[0;33msizeof\033[0m","\033[0;33mfinally\033[0m"};
    for(int i=0; i<keyWord.size();i++) {
        int posOfKeyWord = in.find(basicSyntax[i]);
        while (posOfKeyWord != std::string::npos) {
            in.replace(posOfKeyWord, basicSyntax[i].length(), keyWord[i]);
            posOfKeyWord = in.find(basicSyntax[i], posOfKeyWord + keyWord[i].length());

        }
    }
    return in;
}
