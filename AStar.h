//
// Created by omer on 21/01/2020.
//

#ifndef ADVPROG_MILESTONE2_ASTAR_H
#define ADVPROG_MILESTONE2_ASTAR_H

#import "Searcher.h"
template <typename T>
class AStar:  public Searcher<T, vector<State<T>*>> {
public:
    //constructor
    AStar<T>() {
        this->searcherName = "AStar";
    }
    //returns copy
    Searcher<T, vector<State<T>*>>* clone() {
        return new AStar<T>();
    }
    //this function uses aStar algorithm to find shortest path.
    vector<State<T>*> search(Searchable<T> *s) {
        //push the initial state to the queue
        this->PQueue->pushPQ(s->getInitialState());
        while (!this->PQueue->isEmpty()) {
            State<T> *p = this->PQueue->topPQ();
            this->PQueue->popPQ(p);
            double  pHeuristic= heuristicDis(p, s);
            this->numOfDevNodes++;
            this->visited.push_back(p);
            if (p->operator==(s->getGoalState())) {
                return this->pathToGoal(p, s);
            }
            //insert to adjList vector all the neighbours of p state
            vector<State<T>*> adjList = s->getAllPossibleStates(p);
            for (State<T> *i : adjList) {
                //if i state is neither in the queue nor in the visited:
                if ((!this->contains(i)) && (!this->PQueue->existInPQueue(i))) {
                    i->setPrevious(p);
                    s->setStateValue(i, i->getStateCost() + i->getPrevious()->getStateCost() + heuristicDis(i, s) - pHeuristic);
                    this->PQueue->pushPQ(i);
                } else {
                    //if i state is in the queue but not in the visited:
                    if (!this->contains(i)) {
                        i->setPrevious(p);
                        s->setStateValue(i, i->getStateCost()+ i->getPrevious()->getStateCost() + heuristicDis(i, s) -pHeuristic);
                        //if the cost of i is less than the cost of i in the queue, then we will replace it
                        if (i->getStateCost() < this->PQueue->valInPQueue(i)->getStateCost()) {
                            this->PQueue->deletePQ(i);
                            this->PQueue->pushPQ(i);
                        }
                    }
                }
            }
        }
    }
    //this function calculates the heuristic distance between a node to the end goal.
    double heuristicDis(State<Cell> *state, Searchable<Cell> *searchable) {
        double heuristicDis;
        int row1 = searchable->getGoalState()->getStateObj().getRow();
        int column1 = searchable->getGoalState()->getStateObj().getColumn();
        int row2 = state->getStateObj().getRow();
        int column2 = state->getStateObj().getColumn();
        heuristicDis = sqrt(pow(column2 - column1, 2) + pow(row2 - row1, 2));
        return heuristicDis;
    }
};


#endif //ADVPROG_MILESTONE2_ASTAR_H
