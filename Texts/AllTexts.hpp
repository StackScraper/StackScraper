//
// Created by Michin on 23.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_ALLTEXTS_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_ALLTEXTS_HPP

#include <string>

/**
 * File which contains namespaces of strings to use by all states of the program
 * Every state has its own namespace
 */

///namespace for Idle state
namespace IdleTexts
{
    static std::string title =   " ____    __                    __      ____                                                   \n"
                          "/\\  _`\\ /\\ \\__                /\\ \\    /\\  _`\\                                                 \n"
                          "\\ \\,\\L\\_\\ \\ ,_\\    __      ___\\ \\ \\/'\\\\ \\,\\L\\_\\    ___   _ __    __     _____      __   _ __  \n"
                          " \\/_\\__ \\\\ \\ \\/  /'__`\\   /'___\\ \\ , < \\/_\\__ \\   /'___\\/\\`'__\\/'__`\\  /\\ '__`\\  /'__`\\/\\`'__\\\n"
                          "   /\\ \\L\\ \\ \\ \\_/\\ \\L\\.\\_/\\ \\__/\\ \\ \\\\`\\ /\\ \\L\\ \\/\\ \\__/\\ \\ \\//\\ \\L\\.\\_\\ \\ \\L\\ \\/\\  __/\\ \\ \\/ \n"
                          "   \\ `\\____\\ \\__\\ \\__/.\\_\\ \\____\\\\ \\_\\ \\_\\ `\\____\\ \\____\\\\ \\_\\\\ \\__/.\\_\\\\ \\ ,__/\\ \\____\\\\ \\_\\ \n"
                          "    \\/_____/\\/__/\\/__/\\/_/\\/____/ \\/_/\\/_/\\/_____/\\/____/ \\/_/ \\/__/\\/_/ \\ \\ \\/  \\/____/ \\/_/ \n"
                          "                                                                          \\ \\_\\               \n"
                          "                                                                           \\/_/              ";

    static std::string helloIns = "Type login/register or about";
}

///namespace for Login state
namespace LoginTexts
{
    static std::string title =   " ____    __                    __      ____                                                   \n"
                          "/\\  _`\\ /\\ \\__                /\\ \\    /\\  _`\\                                                 \n"
                          "\\ \\,\\L\\_\\ \\ ,_\\    __      ___\\ \\ \\/'\\\\ \\,\\L\\_\\    ___   _ __    __     _____      __   _ __  \n"
                          " \\/_\\__ \\\\ \\ \\/  /'__`\\   /'___\\ \\ , < \\/_\\__ \\   /'___\\/\\`'__\\/'__`\\  /\\ '__`\\  /'__`\\/\\`'__\\\n"
                          "   /\\ \\L\\ \\ \\ \\_/\\ \\L\\.\\_/\\ \\__/\\ \\ \\\\`\\ /\\ \\L\\ \\/\\ \\__/\\ \\ \\//\\ \\L\\.\\_\\ \\ \\L\\ \\/\\  __/\\ \\ \\/ \n"
                          "   \\ `\\____\\ \\__\\ \\__/.\\_\\ \\____\\\\ \\_\\ \\_\\ `\\____\\ \\____\\\\ \\_\\\\ \\__/.\\_\\\\ \\ ,__/\\ \\____\\\\ \\_\\ \n"
                          "    \\/_____/\\/__/\\/__/\\/_/\\/____/ \\/_/\\/_/\\/_____/\\/____/ \\/_/ \\/__/\\/_/ \\ \\ \\/  \\/____/ \\/_/ \n"
                          "                                                                          \\ \\_\\               \n"
                          "                                                                           \\/_/              ";

    static std::string credentials = "We will ask you about credentials right now, okay?";
    static std::string login = "login:";
    static std::string password = "password:";
}

///namespace for Register state
namespace RegisterTexts
{
    static std::string title =   " ____    __                    __      ____                                                   \n"
                                 "/\\  _`\\ /\\ \\__                /\\ \\    /\\  _`\\                                                 \n"
                                 "\\ \\,\\L\\_\\ \\ ,_\\    __      ___\\ \\ \\/'\\\\ \\,\\L\\_\\    ___   _ __    __     _____      __   _ __  \n"
                                 " \\/_\\__ \\\\ \\ \\/  /'__`\\   /'___\\ \\ , < \\/_\\__ \\   /'___\\/\\`'__\\/'__`\\  /\\ '__`\\  /'__`\\/\\`'__\\\n"
                                 "   /\\ \\L\\ \\ \\ \\_/\\ \\L\\.\\_/\\ \\__/\\ \\ \\\\`\\ /\\ \\L\\ \\/\\ \\__/\\ \\ \\//\\ \\L\\.\\_\\ \\ \\L\\ \\/\\  __/\\ \\ \\/ \n"
                                 "   \\ `\\____\\ \\__\\ \\__/.\\_\\ \\____\\\\ \\_\\ \\_\\ `\\____\\ \\____\\\\ \\_\\\\ \\__/.\\_\\\\ \\ ,__/\\ \\____\\\\ \\_\\ \n"
                                 "    \\/_____/\\/__/\\/__/\\/_/\\/____/ \\/_/\\/_/\\/_____/\\/____/ \\/_/ \\/__/\\/_/ \\ \\ \\/  \\/____/ \\/_/ \n"
                                 "                                                                          \\ \\_\\               \n"
                                 "                                                                           \\/_/              ";

    static std::string credentials = "We will ask you about credentials right now, okay?";
    static std::string login = "login:";
    static std::string password = "password:";
    static std::string email="email:";
}

///namespace for Menu state
namespace MenuTexts
{
    static std::string title =   " ____    __                    __      ____                                                   \n"
                                 "/\\  _`\\ /\\ \\__                /\\ \\    /\\  _`\\                                                 \n"
                                 "\\ \\,\\L\\_\\ \\ ,_\\    __      ___\\ \\ \\/'\\\\ \\,\\L\\_\\    ___   _ __    __     _____      __   _ __  \n"
                                 " \\/_\\__ \\\\ \\ \\/  /'__`\\   /'___\\ \\ , < \\/_\\__ \\   /'___\\/\\`'__\\/'__`\\  /\\ '__`\\  /'__`\\/\\`'__\\\n"
                                 "   /\\ \\L\\ \\ \\ \\_/\\ \\L\\.\\_/\\ \\__/\\ \\ \\\\`\\ /\\ \\L\\ \\/\\ \\__/\\ \\ \\//\\ \\L\\.\\_\\ \\ \\L\\ \\/\\  __/\\ \\ \\/ \n"
                                 "   \\ `\\____\\ \\__\\ \\__/.\\_\\ \\____\\\\ \\_\\ \\_\\ `\\____\\ \\____\\\\ \\_\\\\ \\__/.\\_\\\\ \\ ,__/\\ \\____\\\\ \\_\\ \n"
                                 "    \\/_____/\\/__/\\/__/\\/_/\\/____/ \\/_/\\/_/\\/_____/\\/____/ \\/_/ \\/__/\\/_/ \\ \\ \\/  \\/____/ \\/_/ \n"
                                 "                                                                          \\ \\_\\               \n"
                                 "                                                                           \\/_/              ";
    static std::string helloText = "Hi! Choose question/history/tags/";
    static std::string favText = "favourites";
}

///namespace for Prompt state
namespace PromptTexts
{
    static std::string title = " ____    __                    __      ____                                                   \n"
        "/\\  _`\\ /\\ \\__                /\\ \\    /\\  _`\\                                                 \n"
        "\\ \\,\\L\\_\\ \\ ,_\\    __      ___\\ \\ \\/'\\\\ \\,\\L\\_\\    ___   _ __    __     _____      __   _ __  \n"
        " \\/_\\__ \\\\ \\ \\/  /'__`\\   /'___\\ \\ , < \\/_\\__ \\   /'___\\/\\`'__\\/'__`\\  /\\ '__`\\  /'__`\\/\\`'__\\\n"
        "   /\\ \\L\\ \\ \\ \\_/\\ \\L\\.\\_/\\ \\__/\\ \\ \\\\`\\ /\\ \\L\\ \\/\\ \\__/\\ \\ \\//\\ \\L\\.\\_\\ \\ \\L\\ \\/\\  __/\\ \\ \\/ \n"
        "   \\ `\\____\\ \\__\\ \\__/.\\_\\ \\____\\\\ \\_\\ \\_\\ `\\____\\ \\____\\\\ \\_\\\\ \\__/.\\_\\\\ \\ ,__/\\ \\____\\\\ \\_\\ \n"
        "    \\/_____/\\/__/\\/__/\\/_/\\/____/ \\/_/\\/_/\\/_____/\\/____/ \\/_/ \\/__/\\/_/ \\ \\ \\/  \\/____/ \\/_/ \n"
        "                                                                          \\ \\_\\               \n"
        "                                                                           \\/_/              ";
    static std::string promptText = "Write a question or type return to go back";
}

///namespace for Result state
namespace ResultTexts
{
    static std::string title = " ____    __                    __      ____                                                   \n"
        "/\\  _`\\ /\\ \\__                /\\ \\    /\\  _`\\                                                 \n"
        "\\ \\,\\L\\_\\ \\ ,_\\    __      ___\\ \\ \\/'\\\\ \\,\\L\\_\\    ___   _ __    __     _____      __   _ __  \n"
        " \\/_\\__ \\\\ \\ \\/  /'__`\\   /'___\\ \\ , < \\/_\\__ \\   /'___\\/\\`'__\\/'__`\\  /\\ '__`\\  /'__`\\/\\`'__\\\n"
        "   /\\ \\L\\ \\ \\ \\_/\\ \\L\\.\\_/\\ \\__/\\ \\ \\\\`\\ /\\ \\L\\ \\/\\ \\__/\\ \\ \\//\\ \\L\\.\\_\\ \\ \\L\\ \\/\\  __/\\ \\ \\/ \n"
        "   \\ `\\____\\ \\__\\ \\__/.\\_\\ \\____\\\\ \\_\\ \\_\\ `\\____\\ \\____\\\\ \\_\\\\ \\__/.\\_\\\\ \\ ,__/\\ \\____\\\\ \\_\\ \n"
        "    \\/_____/\\/__/\\/__/\\/_/\\/____/ \\/_/\\/_/\\/_____/\\/____/ \\/_/ \\/__/\\/_/ \\ \\ \\/  \\/____/ \\/_/ \n"
        "                                                                          \\ \\_\\               \n"
        "                                                                           \\/_/              ";
    static std::string answerSubtitle = "Most upvoted answered question: ";
    static std::string answer = "Example answered question: ";
    static std::string proceed = "Press enter to get back to menu";
    static std::string questionText = "Your question is: ";
    static std::string firstAnswer = "Answer 1: ";
}

///namespace for History state
namespace HistoryTexts
{
    static std::string title = " ____    __                    __      ____                                                   \n"
      "/\\  _`\\ /\\ \\__                /\\ \\    /\\  _`\\                                                 \n"
      "\\ \\,\\L\\_\\ \\ ,_\\    __      ___\\ \\ \\/'\\\\ \\,\\L\\_\\    ___   _ __    __     _____      __   _ __  \n"
      " \\/_\\__ \\\\ \\ \\/  /'__`\\   /'___\\ \\ , < \\/_\\__ \\   /'___\\/\\`'__\\/'__`\\  /\\ '__`\\  /'__`\\/\\`'__\\\n"
      "   /\\ \\L\\ \\ \\ \\_/\\ \\L\\.\\_/\\ \\__/\\ \\ \\\\`\\ /\\ \\L\\ \\/\\ \\__/\\ \\ \\//\\ \\L\\.\\_\\ \\ \\L\\ \\/\\  __/\\ \\ \\/ \n"
      "   \\ `\\____\\ \\__\\ \\__/.\\_\\ \\____\\\\ \\_\\ \\_\\ `\\____\\ \\____\\\\ \\_\\\\ \\__/.\\_\\\\ \\ ,__/\\ \\____\\\\ \\_\\ \n"
      "    \\/_____/\\/__/\\/__/\\/_/\\/____/ \\/_/\\/_/\\/_____/\\/____/ \\/_/ \\/__/\\/_/ \\ \\ \\/  \\/____/ \\/_/ \n"
      "                                                                          \\ \\_\\               \n"
      "                                                                           \\/_/              ";
    static std::string historyTheme = "Your recent questions:";
    static std::string returnText = "Type return to get back to menu or type f$ where $ = question index";
    static std::string successText = "Question added sucessfully";
}

///namespace for Favourites state
namespace FavouriteTexts
{
    static std::string title = " ____    __                    __      ____                                                   \n"
        "/\\  _`\\ /\\ \\__                /\\ \\    /\\  _`\\                                                 \n"
        "\\ \\,\\L\\_\\ \\ ,_\\    __      ___\\ \\ \\/'\\\\ \\,\\L\\_\\    ___   _ __    __     _____      __   _ __  \n"
        " \\/_\\__ \\\\ \\ \\/  /'__`\\   /'___\\ \\ , < \\/_\\__ \\   /'___\\/\\`'__\\/'__`\\  /\\ '__`\\  /'__`\\/\\`'__\\\n"
        "   /\\ \\L\\ \\ \\ \\_/\\ \\L\\.\\_/\\ \\__/\\ \\ \\\\`\\ /\\ \\L\\ \\/\\ \\__/\\ \\ \\//\\ \\L\\.\\_\\ \\ \\L\\ \\/\\  __/\\ \\ \\/ \n"
        "   \\ `\\____\\ \\__\\ \\__/.\\_\\ \\____\\\\ \\_\\ \\_\\ `\\____\\ \\____\\\\ \\_\\\\ \\__/.\\_\\\\ \\ ,__/\\ \\____\\\\ \\_\\ \n"
        "    \\/_____/\\/__/\\/__/\\/_/\\/____/ \\/_/\\/_/\\/_____/\\/____/ \\/_/ \\/__/\\/_/ \\ \\ \\/  \\/____/ \\/_/ \n"
        "                                                                          \\ \\_\\               \n"
        "                                                                           \\/_/              ";
    static std::string favTheme = "Your favourite questions:";
    static std::string returnText = "Type return to get back to menu or type d$ where $ = question index";
    static std::string successText = "Question deleted from favourites sucessfully";
}

///namespace for About state
namespace AboutTexts
{
    static std::string title = " ____    __                    __      ____                                                   \n"
        "/\\  _`\\ /\\ \\__                /\\ \\    /\\  _`\\                                                 \n"
        "\\ \\,\\L\\_\\ \\ ,_\\    __      ___\\ \\ \\/'\\\\ \\,\\L\\_\\    ___   _ __    __     _____      __   _ __  \n"
        " \\/_\\__ \\\\ \\ \\/  /'__`\\   /'___\\ \\ , < \\/_\\__ \\   /'___\\/\\`'__\\/'__`\\  /\\ '__`\\  /'__`\\/\\`'__\\\n"
        "   /\\ \\L\\ \\ \\ \\_/\\ \\L\\.\\_/\\ \\__/\\ \\ \\\\`\\ /\\ \\L\\ \\/\\ \\__/\\ \\ \\//\\ \\L\\.\\_\\ \\ \\L\\ \\/\\  __/\\ \\ \\/ \n"
        "   \\ `\\____\\ \\__\\ \\__/.\\_\\ \\____\\\\ \\_\\ \\_\\ `\\____\\ \\____\\\\ \\_\\\\ \\__/.\\_\\\\ \\ ,__/\\ \\____\\\\ \\_\\ \n"
        "    \\/_____/\\/__/\\/__/\\/_/\\/____/ \\/_/\\/_/\\/_____/\\/____/ \\/_/ \\/__/\\/_/ \\ \\ \\/  \\/____/ \\/_/ \n"
        "                                                                          \\ \\_\\               \n"
        "                                                                           \\/_/              ";
    static std::string aboutText = "About ";
    static std::string appText = "StackScraper";
    static std::string description = "Super CLI app to give answers about various problems!";
    static std::string returnText = "Type return to get back to menu";
}

///namespace for Tags state
namespace TagsTexts
{
    static std::string title = " ____    __                    __      ____                                                   \n"
        "/\\  _`\\ /\\ \\__                /\\ \\    /\\  _`\\                                                 \n"
        "\\ \\,\\L\\_\\ \\ ,_\\    __      ___\\ \\ \\/'\\\\ \\,\\L\\_\\    ___   _ __    __     _____      __   _ __  \n"
        " \\/_\\__ \\\\ \\ \\/  /'__`\\   /'___\\ \\ , < \\/_\\__ \\   /'___\\/\\`'__\\/'__`\\  /\\ '__`\\  /'__`\\/\\`'__\\\n"
        "   /\\ \\L\\ \\ \\ \\_/\\ \\L\\.\\_/\\ \\__/\\ \\ \\\\`\\ /\\ \\L\\ \\/\\ \\__/\\ \\ \\//\\ \\L\\.\\_\\ \\ \\L\\ \\/\\  __/\\ \\ \\/ \n"
        "   \\ `\\____\\ \\__\\ \\__/.\\_\\ \\____\\\\ \\_\\ \\_\\ `\\____\\ \\____\\\\ \\_\\\\ \\__/.\\_\\\\ \\ ,__/\\ \\____\\\\ \\_\\ \n"
        "    \\/_____/\\/__/\\/__/\\/_/\\/____/ \\/_/\\/_/\\/_____/\\/____/ \\/_/ \\/__/\\/_/ \\ \\ \\/  \\/____/ \\/_/ \n"
        "                                                                          \\ \\_\\               \n"
        "                                                                           \\/_/              ";
    static std::string tagText = "Tags: ";
    static std::string returnText = "Type return to get back to menu";
}

///namespace for List state
namespace ListState
{
    static std::string title = " ____    __                    __      ____                                                   \n"
        "/\\  _`\\ /\\ \\__                /\\ \\    /\\  _`\\                                                 \n"
        "\\ \\,\\L\\_\\ \\ ,_\\    __      ___\\ \\ \\/'\\\\ \\,\\L\\_\\    ___   _ __    __     _____      __   _ __  \n"
        " \\/_\\__ \\\\ \\ \\/  /'__`\\   /'___\\ \\ , < \\/_\\__ \\   /'___\\/\\`'__\\/'__`\\  /\\ '__`\\  /'__`\\/\\`'__\\\n"
        "   /\\ \\L\\ \\ \\ \\_/\\ \\L\\.\\_/\\ \\__/\\ \\ \\\\`\\ /\\ \\L\\ \\/\\ \\__/\\ \\ \\//\\ \\L\\.\\_\\ \\ \\L\\ \\/\\  __/\\ \\ \\/ \n"
        "   \\ `\\____\\ \\__\\ \\__/.\\_\\ \\____\\\\ \\_\\ \\_\\ `\\____\\ \\____\\\\ \\_\\\\ \\__/.\\_\\\\ \\ ,__/\\ \\____\\\\ \\_\\ \n"
        "    \\/_____/\\/__/\\/__/\\/_/\\/____/ \\/_/\\/_/\\/_____/\\/____/ \\/_/ \\/__/\\/_/ \\ \\ \\/  \\/____/ \\/_/ \n"
        "                                                                          \\ \\_\\               \n"
        "                                                                           \\/_/              ";
    static std::string tagText = "List of questions consisting of inputted tags: ";
    static std::string returnText = "Type return to get back to menu";
}

///namespace for manual
namespace Manual
{
    static std::string manual = "(01010011 01110100 01100001 01100011 01101011 01010011 01100011 01110010 01100001 01110000 01100101 01110010)\n"
                                "Manual of StackScraper \n"
                                "\n"
                                "Provided states and commands which can be used in them\n"
                                "Idle:\n"
                                " - login - go to login\n"
                                " - register - go to register\n"
                                "in both of login and register app will ask about credentials.\n"
                                "Login approval will result in transfering to main menu\n"
                                "Register approval will result in transfering to login\n"
                                "\n"
                                "Main menu:\n"
                                " - question - ask question on stack overflos\n"
                                " - tags - search for questions by tags\n"
                                " - history - check your history\n"
                                " - favourites - check your favourites questions\n"
                                "\n"
                                "Question:\n"
                                "prompt your question to ask and go to result,\n"
                                "type return to go back to menu\n"
                                "\n"
                                "Tags:\n"
                                "prompt tags to check for questions and move to list of them,\n"
                                "type return to go back to menu\n"
                                "\n"
                                "List of questions:\n"
                                "choose question from list by prompting number,\n"
                                "type return to go back to menu\n"
                                "\n"
                                "History:\n"
                                "lists your recent questions,\n"
                                "type return to go back,\n"
                                "type number of question to move to this question,\n"
                                "type f$ where $ is number of question to add it to favourites\n"
                                "\n"
                                "Favourites:\n"
                                "lists your favourites questions,\n"
                                "type return to go back,\n"
                                "type number of question to move to this question,\n"
                                "type d$ where $ is number of question to delete it from favourites\n"
                                "\n"
                                "Result:\n"
                                "you can move to result from different states,\n"
                                "from question by prompting question,\n"
                                "from list of tags, history or favourites by choosing number from list\n"
                                "it always gives back question with max 3 top rated answers\n"
                                "and possibility to type return to go back to previous state\n"
                                "\n"
                                "MOST OF THE STATES HAVE AUTOCOMPLETE SO YOU CAN TYPE\n"
                                "R INSTEAD OF RETURN TO EXECUTE DESIRED COMMAND";

    static std::string exit = "\nPress any key + enter to exit\n";
    static std::string help = "\nYou can also double check commands in the new file HELP.txt which just got created"
                              "in the exe directory\n";
}


#endif //INC_2024__TAB_DSA__8_BRODZIAK_ALLTEXTS_HPP
