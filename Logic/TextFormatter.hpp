//
// Created by Michin on 24.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_TEXTFORMATTER_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_TEXTFORMATTER_HPP

#include <windows.h>
#include <iostream>
#include <thread>
#include <iomanip>
#include "../Globals.hpp"
#include <algorithm>
#include <cctype>

/**
 * File which contains all text based operations and variables of the application
 */

///Viable colors of the text
namespace TextColors
{
    static int BLUE = 1;
    static int GREEN = 2;
    static int LIGHTBLUE = 3;
    static int RED = 4;
    static int PURPLE = 5;
    static int YELLOW = 6;
    static int WHITE = 7;
    static int GREY = 8;
    static int BLUEBERRY = 9;
    static int LIGHTGREEN = 10;
    static int CYAN = 11;
    static int ROSE = 12;
    static int PINK = 13;
    static int BEIGE = 14;
}

/**
 * Namespace for functions which adjust printing of texts
 */
namespace TextFunctions{

    /**
     * Functions that changes actual color of the text in the console
     * @param color color to be used
     */
    static void changeTextColor(int color)
    {
        SetConsoleTextAttribute(cmd::hOutput, color);
    }

    /**
     * Function which produces type write machine effect on the text
     * @param s text to be written
     * @param time time cycle of printing one letter
     */
    static void typeWriteMessage(std::string& s, int time)
    {
        for (const auto c : s) {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
        }
        printf("\n");
    }

    /**
     * Standard print function which includes std::endl for convenience of devs
     * @param message text to be print
     */
    static void print(std::string& message)
    {
        std::cout<<message<<std::endl;
    }

    /**
     * Function which changes position of cursor on canva (here - terminal or cmd)
     * @param x desired position on x axis
     * @param y desired position on y axis
     * @return true if operation succeded
     */
    static bool setCursor(short x, short y)
    {
        return SetConsoleCursorPosition(cmd::hOutput, {x, y});
    }
    static COORD GetConsoleCursorPosition(HANDLE hConsoleOutput)
    {
        CONSOLE_SCREEN_BUFFER_INFO cbsi;
        if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
        {
            return cbsi.dwCursorPosition;
        }
        else
        {
            // The function failed. Call GetLastError() for details.
            COORD invalid = { 0, 0 };
            return invalid;
        }
    }
    /**
     * Function which changes all letters in string to lowercase
     * @param data text to be changed
     * @return modified string
     */
    static std::string toLower(std::string data) {

         std::transform(data.begin(), data.end(), data.begin(),
    [](unsigned char c){ return std::tolower(c); });

        return data;
    }


}



#endif //INC_2024__TAB_DSA__8_BRODZIAK_TEXTFORMATTER_HPP
