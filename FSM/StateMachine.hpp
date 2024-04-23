//
// Created by Michin on 21.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_STATEMACHINE_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_STATEMACHINE_HPP

#include "State.hpp"

#include <memory>
#include <map>
#include <string>
#include <cassert>
#include <utility>

template <typename T>
class State;

template <typename T>
class FiniteStateMachine
{
protected:
    std::map<T, std::unique_ptr<State<T>>> mStates;
    State<T>* mCurrentState;
public:
    FiniteStateMachine()
            : mCurrentState(nullptr)
    {
    }
    template <class S>
    State<T>& add(T id)
    {
        static_assert(not std::is_same<State<T>, S>());
        mStates[id] = std::make_unique<S>(*this);
        return *mStates[id];
    }
    State<T>& getState(T stateID)
    {
        return *mStates[stateID];
    }
    State<T>& getCurrentState()
    {
        return *mCurrentState;
    }
    const State<T>& getCurrentState() const
    {
        return *mCurrentState;
    }

    void setCurrentState(T stateID)
    {
        State<T>* state = &getState(stateID);
        setCurrentState(state);
    }
    void update()
    {
        if (mCurrentState != nullptr)
        {
            mCurrentState->update();
        }
    }
protected:
    void setCurrentState(State<T>* state)
    {
        if (mCurrentState == state)
        {
            return;
        }
        if (mCurrentState != nullptr)
        {
            mCurrentState->exit();
        }
        mCurrentState = state;
        if (mCurrentState != nullptr)
        {
            mCurrentState->enter();
        }
    }
};


#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATEMACHINE_HPP
