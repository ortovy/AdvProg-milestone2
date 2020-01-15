//
// Created by omer on 15/01/2020.
//

#ifndef ADVPROG_MILESTONE2_SEARCHABLE_H
#define ADVPROG_MILESTONE2_SEARCHABLE_H

#include <list>
using namespace std;
template <typename T>
class Searchable {
    virtual T getInitialState() = 0;
    virtual bool isGoalState(T state) = 0;
    virtual list<T> getAllPossibleStates(pair<int, int> state) = 0;
};


#endif //ADVPROG_MILESTONE2_SEARCHABLE_H
