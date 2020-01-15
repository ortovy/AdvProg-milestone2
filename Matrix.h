//
// Created by omer on 15/01/2020.
//

#ifndef ADVPROG_MILESTONE2_MATRIX_H
#define ADVPROG_MILESTONE2_MATRIX_H

#include "Searchable.h"

class Matrix: public Searchable<pair<int, int>> {
    pair<int, int> initialState;
    pair<int, int> goalState;
    int rows;
    int columns;
public:
    Matrix(int x, int y, int z, int w, int rows, int columns);
    pair<int, int> getInitialState();
    bool isGoalState(pair<int, int> state);
    list<pair<int, int>> getAllPossibleStates(pair<int, int> state);
};


#endif //ADVPROG_MILESTONE2_MATRIX_H
