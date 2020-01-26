//
// Created by omer on 19/01/2020.
//

#ifndef ADVPROG_MILESTONE2_BESTFS_H
#define ADVPROG_MILESTONE2_BESTFS_H

#include "Searcher.h"
template <typename T>
class BestFS: public Searcher<T, vector<State<T>*>> {
public:
    //constructor
    BestFS() {
        this->searcherName = "BestFS";
    }
    //returns copy
    Searcher<T, vector<State<T>*>>* clone() {
        return new BestFS<T>();
    }
    //this method uses BestFs algorithm to find shortest path.
    vector<State<T>*> search(Searchable<T> *s) {
        //push the initial state to the queue
        this->PQueue->pushPQ(s->getInitialState());
        while (!this->PQueue->isEmpty()) {
            State<T> *p = this->PQueue->topPQ();
            this->PQueue->popPQ(p);
            this->numOfDevNodes++;
            this->visited.push_back(p);
            if (s->isGoalState(p)) {
                return this->pathToGoal(p, s);
            }
            //insert to adjList vector all the neighbours of p state
            vector<State<T>*> adjList = s->getAllPossibleStates(p);
            for (State<T> *i : adjList) {
                //if i state is neither in the queue nor in the visited:
                if ((!this->contains(i)) && (!this->PQueue->existInPQueue(i))) {
                    i->setPrevious(p);
                    s->setStateValue(i, i->getStateCost() + i->getPrevious()->getStateCost());
                    this->PQueue->pushPQ(i);
                } else {
                    //if i state is in the queue but not in the visited:
                    if(!this->contains(i)) {
                        i->setPrevious(p);
                        s->setStateValue(i, i->getStateCost()+ i->getPrevious()->getStateCost());
                        //if the cost of i is less than the cost of i in the queue, then we will replace it
                        if (i->getStateCost() < this->PQueue->valInPQueue(i)->getStateCost()) {
                            this->PQueue->pushPQ(i);
                        }
                    }
                }
            }
        }
    }
};

#endif //ADVPROG_MILESTONE2_BESTFS_H
