//
// Created by omer on 15/01/2020.
//

#include "Matrix.h"
Matrix::Matrix(int x, int y, int z, int w, int rows, int columns) {
    initialState.first = x;
    initialState.second = y;
    goalState.first = z;
    goalState.second = w;
    this->rows = rows;
    this->columns = columns;
}
pair<int, int> Matrix:: getInitialState() {
    return initialState;
}
bool Matrix:: isGoalState(pair<int, int> state) {
    return (state == goalState);
}
list<pair<int, int>> Matrix:: getAllPossibleStates(pair<int, int> state) {
    list<pair<int, int>> adjList;
    adjList.push_back(make_pair(state.first-1, state.second));
    adjList.push_back(make_pair(state.first+1, state.second));
    adjList.push_back(make_pair(state.first, state.second-1));
    adjList.push_back(make_pair(state.first, state.second+1));
    for (list<pair<int,int>>::iterator it = adjList.begin(); it != adjList.end(); it++) {
        if (it->first < 0 || it->first > rows || it->second < 0 || it->second > columns) {
            adjList.remove(make_pair(it->first, it->second));
        }
    }
    return adjList;
}