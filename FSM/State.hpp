//
// Created by Michin on 21.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_STATE_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_STATE_HPP

#include "StateMachine.hpp"

#include <string>
#include <utility>

template <typename T>
class FiniteStateMachine;

template <typename T>
class State{
public:
    inline T getId()
    {
        return mId;
    }
    inline const std::string &getName() const
    {
        return mName;
    }
    explicit State(FiniteStateMachine<T>& fsm, T id,
                   std::string name = "IDLE")
            : mName(std::move(name))
            , mId(id)
            , mFsm(fsm)
    {}

    virtual ~State() = default;
    virtual void onEnter() = 0;
    virtual void onExit() = 0;
    virtual void onUpdate() = 0;


protected:
    std::string mName;
    T mId;
    FiniteStateMachine<T>& mFsm;
};

#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATE_HPP
