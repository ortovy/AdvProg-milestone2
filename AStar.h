//
// Created by omer on 21/01/2020.
//

#ifndef ADVPROG_MILESTONE2_ASTAR_H
#define ADVPROG_MILESTONE2_ASTAR_H

#include <tgmath.h>
#import "Searcher.h"
#include "Cell.h"
template <typename T>
class AStar:  public Searcher<T, vector<State<T>*>> {
    vector<State<T>*> visited;
public:
    vector<State<T>*> search(Searchable<T> *s) {
        this->PQueue->pushPQ(s->getInitialState());
        State<T> *initial = s->getInitialState();
        initial->setStateCost(initial->getStateCost()+ heuristicDis(initial, s));
        while (!this->PQueue->isEmpty()) {
            State<T> *p = this->PQueue->topPQ();
            this->PQueue->popPQ(p);
            double nH = heuristicDis(p, s);
            this->numOfDevNodes++;
            visited.push_back(p);
            if (p == s->getGoalState()) {
                return pathToGoal(p, s);
            }
            vector<State<T>*> adjList = s->getAllPossibleStates(p);
            for (State<T> *i : adjList) {
                if ((!contains(i)) && (!this->PQueue->existInPQueue(i))) {
                    i->setPrevious(p);
                    i->setStateCost(i->getStateCost() + i->getPrevious()->getStateCost() + heuristicDis(i, s) - nH);
                    this->PQueue->pushPQ(i);
                } else {
                    if (!contains(i)) {
                        i->setPrevious(p);
                        s->setStateValue(i, i->getStateCost()+ i->getPrevious()->getStateCost() + heuristicDis(i, s) - nH);
                        if (s->getStateValue(i) < s->getStateValue(this->PQueue->valInPQueue(i))) {
                            this->PQueue->pushPQ(i);
                        }
                    }
                }
            }
        }
    }
    double heuristicDis(State<Cell> *state, Searchable<Cell> *searchable) {
        double heuristicDis;
        int row1 = searchable->getGoalState()->getStateObj().getRow();
        int column1 = searchable->getGoalState()->getStateObj().getColumn();
        int row2 = state->getStateObj().getRow();
        int column2 = state->getStateObj().getColumn();
        heuristicDis = sqrt(pow(column2 - column1, 2) + pow(row2 - row2, 2));
        return heuristicDis;
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

};


#endif //ADVPROG_MILESTONE2_ASTAR_H
