//
// Created by jakub on 20.05.2024.
//

#include "SyntaxHighlighting.hpp"
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include <regex>


std::string SyntaxHighlighting::RecognizeSyntax(std::string in) {
    basicSyntax = {"for","while","do",
                    "if", "else","int",
                    "string","::","std",
                    "double","float","bool",
                    "main","switch","case",
                    "char","cin","getline",
                    "cout","return","long",
                    "short", "cerr", "<<",
                    ">>","include","using",
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
                    "sizeof","finally", "AND",
                    "OR","&&","||",
                    "false","true",
                    //PYTHONE
                    "False","None","True",
                    "and", "as", "assert",
                    "def", "del", "await",
                    "async", "elif", "except",
                    "global","from", "import",
                    "in", "is", "lambda",
                    "not", "!", "raise",
                    "with", "pass","yield",
                    //C KEYWORD
                    "auto", "default","inline",
                    "signed", "malloc", "printf",
                    "free",
                    //JAVA KEYWORD
                    "abstract", "boolen", "implements",
                    "interface", "native", "package",
                    "super",
                    //PHP KEYWORD
                    "array","clone","declare",
                    "echo", "elseif","foreach",
                    "empty", "endfor", "endif",
                    "endforeach", "endswitch","isset",
                    "unset","var","use",
                    "xor",
                    //JS KEYWORD
                    "let","function","export",
                   //HTML TAGS
                    "div","<",">",
                    "area", "blockquote", "body",
                    "html", "head", "button",
                    "dl","dt","h1",
                    "h2","h3","h4",
                    "h5", "h6","nav",
                    "script","strong","style",
                    "td","table","sup",
                    "ul","ol","li",
                    "p","b","s",
                    "i","br","td",
                    "a","img","tr",
                    //others
                    "print","namespace"
    };
    // std::cout << "\033[1;31mbold red text\033[0m\n";
    keyWord = {//CPP KEYWORD
                "\033[0;32mfor\033[0m","\033[0;32mwhile\033[0m","\033[0;32mdo\033[0m",
                "\033[0;34mif\033[0m", "\033[0;34melse\033[0m","\033[0;33mint\033[0m",
                "\033[0;33mstring\033[0m","\033[0;31m::\033[0m","\033[0;35mstd\033[0m",
                "\033[0;33mdouble\033[0m","\033[0;33mfloat\033[0m","\033[0;33mbool\033[0m",
                "\033[0;34mmain\033[0m","\033[0;36mswitch\033[0m", "\033[0;33mcase\033[0m",
                "\033[0;33mchar\033[0m","\033[0;31mcin\033[0m","\033[0;31mgetline\033[0m",
                "\033[0;31mcout\033[0m","\033[0;31mreturn\033[0m", "\033[0;33mlong\033[0m",
                 "\033[0;33mshort\033[0m","\033[0;31mcerr\033[0m","\033[0;32m<<\033[0m",
                "\033[0;32m>>\033[0m","\033[0;33minclude\033[0m", "\033[0;32musing\033[0m",
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
                "\033[0;33msizeof\033[0m","\033[0;33mfinally\033[0m","\033[0;32mAND\033[0m",
                "\033[0;32mOR\033[0m", "\033[0;32m&&\033[0m", "\033[0;32m||\033[0m",
                "\033[0;31mfalse\033[0m","\033[0;32mtrue\033[0m",
                //PYTHONE KEYWORD
                "\033[0;31mfalse\033[0m","\033[0;33mNone\033[0m","\033[0;32mtrue\033[0m",
                "\033[0;32mand\033[0m","\033[0;33mAs\033[0m", "\033[0;33mAssert\033[0m",
                "\033[0;33mdef\033[0m","\033[0;31mdel\033[0m","\033[0;35mawit\033[0m",
                "\033[0;35masync\033[0m","\033[0;34melif\033[0m","\033[0;31mexcept\033[0m",
                "\033[0;36mglobal\033[0m","\033[0;35mfrom\033[0m","\033[0;35mimport\033[0m",
                "\033[0;35min\033[0m","\033[0;35mis\033[0m","\033[0;36mlambdal\033[0m",
                "\033[0;31mnot\033[0m","\033[0;31m!\033[0m","\033[0;36mraise\033[0m",
                "\033[0;36mwith\033[0m","\033[0;35mpass\033[0m","\033[0;36myield\033[0m",
                //C KEYWORD
                "\033[0;33mauto\033[0m","\033[0;34mdefault\033[0m","\033[0;34minline\033[0m",
                "\033[0;33msigned\033[0m", "\033[0;31mmalloc\033[0m","\033[0;31mprintf\033[0m",
                "\033[0;32mfree\033[0m",
                //JAVA KEYWORD
                "\033[0;33mabstract\033[0m", "\033[0;33mboolen\033[0m", "\033[0;36mimplements\033[0m",
                "\033[0;33mnative\033[0m","\033[0;35mnative\033[0m", "\033[0;35mpackage\033[0m",
                "\033[0;32msuper\033[0m",
                //PHP KEYWORD
                "\033[0;33marray\033[0m","\033[0;35mclone\033[0m","\033[0;35mdeclare\033[0m",
                "\033[0;32mecho\033[0m","\033[0;34melseif\033[0m","\033[0;32mforeach\033[0m",
                "\033[0;36mempty\033[0m", "\033[0;32mendfor\033[0m","\033[0;34mendif\033[0m",
                "\033[0;32mendforeach\033[0m", "\033[0;36mendswitch\033[0m","\033[0;33misset\033[0m",
                "\033[0;33munset\033[0m","\033[0;36mvar\033[0m\n","\033[0;31muse\033[0m",
                "\033[0;33mxor\033[0m",
                //JS KEYWORD
                "\033[0;36mlet\033[0m","\033[0;32mfunction\033[0m","\033[0;32mexport\033[0m",
                //HTML TAGS
                "\033[0;36mdiv\033[0m","\033[0;32m<\033[0m","\033[0;32m>\033[0m",
                "\033[0;35marea\033[0m", "\033[0;36mblockquote\033[0m","\033[0;31mbody\033[0m",
                "\033[0;31mhtml\033[0m","\033[0;31mhead\033[0m", "\033[0;32mbutton\033[0m",
                "\033[0;32mdl\033[0m","\033[0;32mdt\033[0m","\033[0;34mh1\033[0m",
                "\033[0;34mh2\033[0m","\033[0;34mh3\033[0m","\033[0;34mh4\033[0m",
                "\033[0;34mh5\033[0m","\033[0;34mh6\033[0m","\033[0;32mnav\033[0m",
                "\033[0;33mscript\033[0m","\033[0;31mstrong\033[0m", "\033[0;32mstyle\033[0m",
                "\033[0;32mtd\033[0m","\033[0;32mtable\033[0m","\033[0;32msup\033[0m",
                "\033[0;33mul\033[0m","\033[0;33mol\033[0m","\033[0;33mli\033[0m",
                "\033[0;33mp\033[0m","\033[0;31mb\033[0m","\033[0;33ms\033[0m",
                "\033[0;35mi\033[0m","\033[0;35mbr\033[0m","\033[0;31mtd\033[0m",
                "\033[0;34ma\033[0m","\033[0;32mimg\033[0m","\033[0;31mtr\033[0m",
                //others
                "\033[0;31mprint\033[0m","\033[0;32mnamespace\033[0m"

    };
   std::vector<std::string>specialCharacter = {
       "<",">","\"",
    "\'","*","&",
    "|" , "$",":",
    "->"

   };
 std::vector<std::string>colorSpecialCharacter = {
  "\033[0;32m<\033[0m", "\033[0;32m>\033[0m", "\033[0;32m\"\033[0m",
  "\033[0;31m\'\033[0m","\033[0;34m*\033[0m","\033[0;34m&\033[0m",
  "\033[0;33m|\033[0m","\033[0;34m$\033[0m","\033[0;32m:\033[0m",
  "\033[0;32m->\033[0m"
 };

    in = Hightlighting(in, basicSyntax, keyWord, specialCharacter, colorSpecialCharacter);

    return in;
}
int SyntaxHighlighting::IsInCodeSection(std::string in) {
      int pos = in.find("<code>");
      return pos;
}
std::string SyntaxHighlighting::Hightlighting(std::string in,std::vector<std::string>&basic_strings, std::vector<std::string>&keyWord,
                          std::vector<std::string>&specialCharacter, std::vector<std::string>&colorSpecialCharacter) {

 for (size_t i = 0; i < basicSyntax.size(); i++) {
      std::regex wordRegex("\\b" + std::regex_replace(basicSyntax[i], std::regex(R"([-[\]{}()*+?.,\^$|#\s:])"), R"(\$&<>)") + "\\b");
      in = std::regex_replace(in, wordRegex, keyWord[i]);
 }
 for(int i=0; i<specialCharacter.size();i++) {
      int posOfSecialWord = in.find(specialCharacter[i]);
      while (posOfSecialWord != std::string::npos) {
           in.replace(posOfSecialWord, specialCharacter[i].length(), colorSpecialCharacter[i]);
           posOfSecialWord = in.find(specialCharacter[i], posOfSecialWord + colorSpecialCharacter[i].length());
      }

   }
   return in;
}