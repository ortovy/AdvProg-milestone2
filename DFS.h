//
// Created by omer on 19/01/2020.
//

#ifndef ADVPROG_MILESTONE2_DFS_H
#define ADVPROG_MILESTONE2_DFS_H

#include "Searcher.h"
template <typename T>
class DFS: public Searcher<T, vector<State<T>*>> {
public:
    //constructor
    DFS() {
        this->searcherName = "DFS";
    }
    //returns copy
    Searcher<T, vector<State<T>*>>* clone() {
        return new DFS<T>();
    }
    //this method uses DFS algorithm.
    vector<State<T>*> search(Searchable<T> *s) {
        // Create a stack for DFS
        stack<State<T>*> stack;

        // Push the initial state to stack
        stack.push(s->getInitialState());
        this->visited.push_back(s->getInitialState());
        State<T>* p;
        while (!stack.empty())
        {
            p = stack.top();
            stack.pop();
            this->numOfDevNodes++;
            //insert to adjList vector all the neighbours of p state
            vector<State<T>*> adjList = s->getAllPossibleStates(p);
            for (State<T>* i :adjList) {
                if (!this->contains(i)) {
                    stack.push(i);
                    i->setPrevious(p);
                    this->visited.push_back(i);
                }
            }
            if (s->isGoalState(p)) {
                return this->pathToGoal(p, s);
            }
        }
    }
};

#endif //ADVPROG_MILESTONE2_DFS_H
