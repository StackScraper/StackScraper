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

/**
 * Predefinition of State class
 * @tparam T template class for which state is created
 */
template <typename T>
class State;

/**
 * Template class of state machine
 * @tparam T template class for which state machine is created
 */
template <typename T>
class FiniteStateMachine
{
protected:
    std::map<T, std::unique_ptr<State<T>>> mStates; ///< map of states
    State<T>* mCurrentState; ///< pointer to current state
public:
    ///Default constructor
    FiniteStateMachine()
            : mCurrentState(nullptr)
    {}
    /**
     * Function which adds new state to the map
     * @tparam S template class, should be chosen accordingly to whole state machine
     * @param id id of the freshly added state
     * @return pointer on the new state
     */
    template <class S>
    State<T>& Add(T id)
    {
        static_assert(not std::is_same<State<T>, S>());
        mStates[id] = std::make_unique<S>(*this);
        return *mStates[id];
    }
    /**
     * Function for returning interesting state
     * @param stateID identification of desired state
     * @return desired state
     */
    State<T>& GetState(T stateID)
    {
        return *mStates[stateID];
    }
    /**
     * Function for returning current state
     * @return current state
     */
    State<T>& GetCurrentState()
    {
        return *mCurrentState;
    }

    /**
     * Function for returning current state
     * @return current state
     */
    const State<T>& GetCurrentState() const
    {
        return *mCurrentState;
    }

    /**
     * Function for changing state as desired
     * @param stateID id of desired state
     */
    void SetCurrentState(T stateID)
    {
        State<T>* state = &GetState(stateID);
        SetCurrentState(state);
    }
    /**
     * Function called to change state
     */
    void OnUpdate()
    {
        if (mCurrentState != nullptr)
        {
            mCurrentState->OnUpdate();
        }
    }
protected:
    /**
     * Protected function which is used by public setCurrentState to change state for existing instead of
     * creating multiple instances of same state
     * @param state
     */
    void SetCurrentState(State<T>* state)
    {
        if (mCurrentState == state)
        {
            return;
        }
        if (mCurrentState != nullptr)
        {
            mCurrentState->OnExit();
        }
        mCurrentState = state;
        if (mCurrentState != nullptr)
        {
            mCurrentState->OnEnter();
        }
    }
};


#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATEMACHINE_HPP
