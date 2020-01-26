//
// Created by omer on 15/01/2020.
//

#ifndef ADVPROG_MILESTONE2_SEARCHER_H
#define ADVPROG_MILESTONE2_SEARCHER_H

#include "Searchable.h"
#include <queue>
#include <vector>
#include <stack>
#include "State.h"
#include "MyPQueue.h"
#include <algorithm>
#include <iostream>
#include <list>
#include <tgmath.h>
template <typename T,typename S>
/*
 * searcher interface is an interface defines every search algorithm
 * that searches paths in graphs.
 * BFS DFS BESTFS ASTAR are searchers
 */
class Searcher {
protected:
    int numOfDevNodes = 0;
    double totalCost = 0;
    string searcherName;
    vector<State<T>*> visited;
    MyPQueue<T> *PQueue = new MyPQueue<T>();
public:
    virtual S search(Searchable<T> *s) = 0;
    virtual Searcher* clone() = 0;
    virtual string getSearcherName() {
        return this->searcherName;
    }
    //returns the number of developed nodes opened in a search.
    virtual int getNumOfDevNodes() {
        return this->numOfDevNodes;
    }
    //returns the weight of the path found in the algorithm
    virtual double getTotalCost() {
        return this->totalCost;
    }
    //checks if visited vector contains the given state
    bool contains(State<T> *s) {
        for (State<T> *s1 : visited) {
            if (s->operator==(s1)) {
                return true;
            }
        }
        return false;
    }
    //this function returns a vector with the shortest path found by the search function.
    vector<State<T>*> pathToGoal(State<T> *goallState, Searchable<T> *searchable) {
        vector<State<T>*> pathToGoal;
        pathToGoal.push_back(goallState);
        while (!(goallState == searchable->getInitialState())) {
            pathToGoal.push_back(goallState->getPrevious());
            this->totalCost += goallState->getStateInitialCost();
            goallState = goallState->getPrevious();
        }
        reverse(pathToGoal.begin(), pathToGoal.end());
        return pathToGoal;
    }
    virtual ~Searcher() {
    }
};


#endif //ADVPROG_MILESTONE2_SEARCHER_H
