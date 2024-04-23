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
class State
{
public:
    // The ID of the state.
    inline T getID()
    {
        return mID;
    }
    inline const std::string& getName() const
    {
        return mName;
    }
    explicit State(FiniteStateMachine<T>& fsm, T id,
                   std::string name = "default")
            : mName(name)
            , mID(id)
            , mFsm(fsm)
    {
    }
    virtual ~State() {}
    virtual void enter()
    {
    }
    virtual void exit()
    {
    }
    virtual void update()
    {
    }
protected:
    std::string mName;
    T mID;
    FiniteStateMachine<T>& mFsm;
};

#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATE_HPP
