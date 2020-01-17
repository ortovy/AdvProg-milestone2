//
// Created by omer on 15/01/2020.
//

#ifndef ADVPROG_MILESTONE2_SEARCHABLE_H
#define ADVPROG_MILESTONE2_SEARCHABLE_H

#include "State.h"
#include <vector>
using namespace std;
template <typename T>
class Searchable {
public:
    virtual State<T>* getInitialState() = 0;
    virtual bool isGoalState(State<T> *state) = 0;
    virtual vector<State<T>*> getAllPossibleStates(State<T> *state) = 0;
};


#endif //ADVPROG_MILESTONE2_SEARCHABLE_H
