//
// Created by omer on 19/01/2020.
//

#ifndef ADVPROG_MILESTONE2_DFS_H
#define ADVPROG_MILESTONE2_DFS_H

#import "Searcher.h"
#include "State.h"
#include "Cell.h"
#include <vector>
#include <stack>
#import <algorithm>

template <typename T>
class DFS: public Searcher<T, vector<State<T>*>> {
    vector<State<T>*> visited;
public:
    vector<State<T>*> search(Searchable<T> *s) {
        // Create a stack for DFS
        stack<State<T>*> stack;

        // Push the current source node.
        stack.push(s->getInitialState());
        visited.push_back(s->getInitialState());
        State<T>* p;
        while (!stack.empty())
        {
            // Pop a vertex from stack and print it
            p = stack.top();
            stack.pop();
            this->numOfDevNodes++;
            vector<State<T>*> adjList = s->getAllPossibleStates(p);
            // Get all adjacent vertices of the popped vertex s
            // If a adjacent has not been visited, then push it
            // to the stack.
            for (State<T>* i :adjList) {
                if (!contains(i) && s->getStateValue(i) != -1) {
                    stack.push(i);
                    i->setPrevious(p);
                    visited.push_back(i);
                }
            }
            if (s->isGoalState(p)) {
                return pathToGoal(p, s);
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
    vector<State<T>*> pathToGoal(State<T> *goallState, Searchable<T> *searchable) {
        vector<State<T>*> pathToGoal;
        pathToGoal.push_back(goallState);
        while (!(goallState == searchable->getInitialState())) {
            pathToGoal.push_back(goallState->getPrevious());
            goallState = goallState->getPrevious();
        }
        reverse(pathToGoal.begin(), pathToGoal.end());
        return pathToGoal;
    }
};


#endif //ADVPROG_MILESTONE2_DFS_H
