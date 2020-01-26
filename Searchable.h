//
// Created by omer on 15/01/2020.
//

#ifndef ADVPROG_MILESTONE2_SEARCHABLE_H
#define ADVPROG_MILESTONE2_SEARCHABLE_H

/*
 * searchable is an interface that defines all the
 * data structs we can treat as a graph and search paths in them.
 * matrix is one example of a searchable.
 */
#include "State.h"
#include "State.h"
#include <vector>
#include <string>
using namespace std;
template <typename T>
class Searchable {
public:
    //gets initial starting position.
    virtual State<T>* getInitialState() = 0;
    //checks if state is the finish position.
    virtual bool isGoalState(State<T> *state) = 0;
    //returns the goal state.
    virtual State<T>* getGoalState() = 0;
    //returns given state all the nearby adjacent states.
    virtual vector<State<T>*> getAllPossibleStates(State<T> *state) = 0;
    //gets given state value.
    virtual double getStateValue(State<T> *state) = 0;
    //sets state value.
    virtual void setStateValue(State<T> *state, double val) = 0;
    //creates a string to describe this searchable object
    virtual string toString() = 0;
    virtual ~Searchable() {

    }
};

#endif //ADVPROG_MILESTONE2_SEARCHABLE_H
