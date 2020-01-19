//
// Created by omer on 19/01/2020.
//

#ifndef ADVPROG_MILESTONE2_BESTFS_H
#define ADVPROG_MILESTONE2_BESTFS_H

#include "Searcher.h"
#include <vector>
template <typename T>
class BestFS: public Searcher<T, vector<State<T>*>> {
    vector<State<T>*> visited;
    int numOfDevNodes = 0;
public:
    vector<State<T>*> search(Searchable<T> *s) {
        this->priorityQueue.push(s->getInitialState());
        while (!this->priorityQueue.empty()) {
            State<T> *p = this->priorityQueue.top();
            this->priorityQueue.pop();
            numOfDevNodes++;
            visited.push_back(p);
            if (s->isGoalState(p)) {
                return pathToGoal(p, s);
            }
            vector<State<T>*> adjList = s->getAllPossibleStates(p);
            for (State<T> *i : adjList) {
                if ((!contains(i)) && (!this->existInPQueue(i))) {
                    i->setPrevious(p);
                    s->setStateValue(i, s->getStateValue(i) + s->getStateValue(i->getPrevious()));
                    this->priorityQueue.push(i);
                } else {
                    if (!contains(i)) {
                        i->setPrevious(p);
                        s->setStateValue(i, s->getStateValue(i) + s->getStateValue(i->getPrevious()));
                        if (s->getStateValue(i) < s->getStateValue(this->valInPQueue(i))) {
                            this->deleteState(i);
                            this->priorityQueue.push(i);
                        }
                    }
                }
            }
        }
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
};


#endif //ADVPROG_MILESTONE2_BESTFS_H
