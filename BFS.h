//
// Created by omer on 17/01/2020.
//

#ifndef ADVPROG_MILESTONE2_BFS_H
#define ADVPROG_MILESTONE2_BFS_H
#include "Searcher.h"
#include "Cell.h"
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

template <typename T>
class BFS: public Searcher<T, vector<State<T>*>> {
    vector<State<T>*> visited;
public:
    BFS() {
        this->searcherName = "BFS";
    }
    vector<State<T>*> search(Searchable<T> *s) {
        // Create a queue for BFS
        list<State<T>*> queue;

        // Mark the current node as visited and enqueue it
        visited.push_back(s->getInitialState());
        queue.push_back(s->getInitialState());

        // 'i' will be used to get all adjacent
        // vertices of a vertex
        while(!queue.empty())
        {
            // Dequeue a vertex from queue and print it
            State<T>* p  = queue.front();
            queue.pop_front();
            this->numOfDevNodes++;
            vector<State<T>*> adjList = s->getAllPossibleStates(p);
            // Get all adjacent vertices of the dequeued
            // vertex s. If a adjacent has not been visited,
            // then mark it visited and enqueue it
            for(State<T>* i :adjList) {
                if (!contains(i)) {
                    //if (!contains(i) && s->getStateValue(i) != -1) {
                    visited.push_back(i);
                    queue.push_back(i);
                    i->setPrevious(p);
                }
                if (s->isGoalState(i)) {
                    return pathToGoal(i, s);
                }
            }
        }
    }
    bool contains(State<T> *s) {
        for (State<T> *s1 : visited) {
            if (s->operator==(s1)) {
                return true;
            }
        }
        return false;
    }
    int getNumOfDevNodes() {
        return this->numOfDevNodes;
    }
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
};


#endif //ADVPROG_MILESTONE2_BFS_H
