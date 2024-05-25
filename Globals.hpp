//
// Created by Michin on 24.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_GLOBALS_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_GLOBALS_HPP

#include <windows.h>

/**
 * File that holds all globals of the program
 */

///CMD - Namespace responsible for holding globals connected to shell application
namespace cmd
{
    static HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); ///< Handle to shell output
    static HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE); ///< Handle to shell input
}

#endif //INC_2024__TAB_DSA__8_BRODZIAK_GLOBALS_HPP
