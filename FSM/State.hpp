//
// Created by Michin on 21.04.2024.
//

#ifndef INC_2024__TAB_DSA__8_BRODZIAK_STATE_HPP
#define INC_2024__TAB_DSA__8_BRODZIAK_STATE_HPP

/**
 * Pre-definition of FSM class
 */
#include "StateMachine.hpp"

#include <string>
#include <utility>
template <typename T>
class FiniteStateMachine;

/**
 * Template class of one state of FSM
 * @tparam T template class which State is created for
 */
template <typename T>
class State
{
public:
    /// The ID of the state.
    inline T getID()
    {
        return mID;
    }
    /// The name of the state
    inline const std::string& getName() const
    {
        return mName;
    }
    /// Default constructor
    explicit State(FiniteStateMachine<T>& fsm, T id,
                   std::string name = "default")
            : mName(name)
            , mID(id)
            , mFsm(fsm)
    {
    }
    /// Virtual destructor
    virtual ~State() {}
    /**
     * Virtual function to describe behaviour of state on enter time
     */
    virtual void onEnter()
    {
    }
    /**
     * Virtual function to describe behaviour of state on exit time
     */
    virtual void onExit()
    {
    }
    /**
     * Virtual function to describe behaviour of state on update time
     * on update - in the middle of the state flow
     */
    virtual void onUpdate()
    {
    }
protected:
    std::string mName; ///< name of the state
    T mID; ///< id of the state
    FiniteStateMachine<T>& mFsm; ///< state machine that state is created for
};

#endif //INC_2024__TAB_DSA__8_BRODZIAK_STATE_HPP
