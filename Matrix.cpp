//
// Created by omer on 15/01/2020.
//

#include "Matrix.h"
//this class implement Searchable interface and defines a matrix
Matrix::Matrix(int rowsNum, int columnsNum, vector<vector<double>> matrix1, State<Cell> *initial, State<Cell> *goal) {
    this->rows = rowsNum;
    this->columns = columnsNum;
    this->matrix = matrix1;
    this->initialState = initial;
    this->goalState = goal;
    this->initialState->setStateInitialCost(matrix[initialState->getStateObj().getRow()][initialState->getStateObj().getColumn()]);
    this->initialState->setStateCost(matrix[initialState->getStateObj().getRow()][initialState->getStateObj().getColumn()]);

}
//returns the starting position
State<Cell>* Matrix:: getInitialState() {
    return this->initialState;
}
//checks if certain state is the goal state.
bool Matrix:: isGoalState(State<Cell> *state) {
    return (goalState->operator==(state));
}
//return the goal state
State<Cell>* Matrix::getGoalState() {
    return goalState;
}
//this function returns every possible adj states a given state has,
//the states come in a vector of states.
vector<State<Cell>*> Matrix:: getAllPossibleStates(State<Cell> *state) {
    vector<State<Cell>*> adjList;
    //gets i,j - location on the matrix
    int row = state->getStateObj().getRow();
    int column = state->getStateObj().getColumn();
    //creates all thw "neighbors" cells
    State<Cell> *s1 = new State<Cell> (Cell(row-1, column));
    State<Cell> *s2 = new State<Cell> (Cell(row+1, column));
    State<Cell> *s3 = new State<Cell> (Cell(row, column-1));
    State<Cell> *s4 = new State<Cell> (Cell(row, column+1));
    //push them to the list
    adjList.push_back(s1);
    adjList.push_back(s2);
    adjList.push_back(s3);
    adjList.push_back(s4);

    for (int i = 0; i < 4; i++) {
        State<Cell> *checker = adjList.back();
        adjList.pop_back();
        if (checker->getStateObj().getRow() >= 0 && checker->getStateObj().getRow() <= rows-1 && checker->getStateObj().getColumn() >= 0 && checker->getStateObj().getColumn() <= columns-1 ) {
            double cost = matrix[checker->getStateObj().getRow()][checker->getStateObj().getColumn()];
            if (cost != -1) {
                adjList.insert(adjList.begin(), checker);
                checker->setStateCost(cost);
                checker->setStateInitialCost(cost);
            }
        }
    }
    return adjList;
}
//this function returns a given state value
double Matrix::getStateValue(State<Cell> *state) {
    return matrix[state->getStateObj().getRow()][state->getStateObj().getColumn()];
}
//this function sets a new value to a state.
void Matrix::setStateValue(State<Cell> *state, double val) {
    matrix[state->getStateObj().getRow()][state->getStateObj().getColumn()] = val;
    state->setStateCost(val);
}
//this function creates string describing this matrix
string Matrix::toString() {
    string matrixStr;
    matrixStr.append("#" + to_string(initialState->getStateObj().getRow()) + ","+ to_string(initialState->getStateObj().getColumn()));
    matrixStr.append("*" + to_string(goalState->getStateObj().getRow()) + "," + to_string(goalState->getStateObj().getColumn()));
    for (int i = 0; i<rows; i++) {
        matrixStr.append("&");
        for(int j = 0; j<columns; j++) {
            matrixStr.append(to_string(matrix[i][j]));
            matrixStr.append("^");
        }
    }
    return matrixStr;
}