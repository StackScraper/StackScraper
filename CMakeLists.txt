cmake_minimum_required(VERSION 3.22)
project(2024__TAB_DSA__8_BRODZIAK)

set(CMAKE_CXX_STANDARD 20)

set(DEFAULT_BUILD_TYPE "Release")
if(EXISTS "${CMAKE_SOURCE_DIR}/.git")
    set(DEFAULT_BUILD_TYPE "Debug")
endif()
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

add_executable(2024__TAB_DSA__8_BRODZIAK main.cpp
        Engine.cpp
        Engine.hpp
        FSM/StateMachine.cpp
        FSM/StateMachine.hpp
        FSM/State.cpp
        FSM/State.hpp
        States/StateIdle.cpp
        States/StateIdle.hpp
        States/StateLogin.cpp
        States/StateLogin.hpp
        States/StateRegister.cpp
        States/StateRegister.hpp
        States/StateMenu.cpp
        States/StateMenu.hpp
        States/StatePrompt.cpp
        States/StatePrompt.hpp
        States/StatesConf.hpp
        States/StateFavourites.cpp
        States/StateFavourites.hpp
        States/StateHistory.cpp
        States/StateHistory.hpp
        States/StateExit.cpp
        States/StateExit.hpp
        Texts/AllTexts.hpp
        States/StatesWrapper.hpp
        Logic/PromptSingleton.cpp
        Logic/PromptSingleton.hpp
        Logic/StackManager.cpp
        Logic/StackManager.hpp
        States/StateTags.cpp
        States/StateTags.hpp
        States/StateResult.cpp
        States/StateResult.hpp
        Globals.hpp
        Logic/TextFormatter.hpp
        Logic/LoginManager.cpp
        Logic/LoginManager.hpp
        States/StateAbout.cpp
        States/StateAbout.hpp
)

if(WIN32) # Install dlls in the same directory as the executable on Windows
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 3020c34ae2b732121f37433e61599c34535e68a8) # Replace with your desired git commit from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

target_link_libraries(2024__TAB_DSA__8_BRODZIAK PRIVATE cpr::cpr)
