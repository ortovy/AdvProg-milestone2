//
// Created by omer on 15/01/2020.
//

#ifndef ADVPROG_MILESTONE2_MATRIX_H
#define ADVPROG_MILESTONE2_MATRIX_H

#include "Searchable.h"
#include "State.h"
#include "Cell.h"
#include <vector>
#include <string>
class Matrix: public Searchable<Cell> {
    int rows;
    int columns;
    vector<vector<double>> matrix;
    State<Cell>* initialState;
    State<Cell>* goalState;
public:
    Matrix(int rows, int columns, vector<vector<double>> matrix, State<Cell> *initial, State<Cell> *goal);
    State<Cell>* getInitialState();
    State<Cell>* getGoalState();
    bool isGoalState(State<Cell> *state);
    vector<State<Cell>*> getAllPossibleStates(State<Cell> *state);
    double getStateValue(State<Cell> *state);
    void setStateValue(State<Cell> *state, double val);
    string toString();
};

#endif //ADVPROG_MILESTONE2_MATRIX_H
