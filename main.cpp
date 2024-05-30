//Right now project has implemented FSM but it need
//mechanism to handle functions from specific Model classes

#include <fstream>
#include "Engine.hpp"
#include "Texts/AllTexts.hpp"
#include "Logic/TextFormatter.hpp"
/**
 * Declaration of PromptSingleton - class responsible for holding information about actual
 * user input in the application
 */
PromptSingleton* PromptSingleton::instancePtr = nullptr;

/**
 * Creating help file and printing it
 * @param argv name of parameter, it has to be --help or -h so it executes function
 */
void PrintHelp(char *argv)
{
    std::string p = argv;
    if(p == "--help" || p == "-h")
    {
        std::ofstream outfile ("HELP.txt");
        outfile << Manual::manual << std::endl;
        outfile.close();

        std::ifstream f("HELP.txt");
        if (f.is_open())
            std::cout<<f.rdbuf();
        TextFunctions::print(Manual::help);
        TextFunctions::print(Manual::exit);
        std::cin.get();
    }
}

/**
 * Main class of the program
 * Creates Engine and start main lop
 * @return 0 if everything executes fine
 */
int main(int argc, char *argv[]) {

    if(argc == 2)
        PrintHelp(argv[1]);

    Engine eng = Engine();
    bool finish = false;
    while(!finish)
    {
        eng.Run(); ///< Start engine
    }
    return 0;
}
