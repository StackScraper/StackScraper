cmake_minimum_required(VERSION 3.27)
project(2024__TAB_DSA__8_BRODZIAK)

set(CMAKE_CXX_STANDARD 20)

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
        States/StateTags.cpp
        States/StateTags.hpp
)
