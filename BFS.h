//
// Created by omer on 17/01/2020.
//

#ifndef ADVPROG_MILESTONE2_BFS_H
#define ADVPROG_MILESTONE2_BFS_H
#include "Searcher.h"

template <typename T>
class BFS: public Searcher<T, vector<State<T>*>> {
public:
    //constructor
    BFS() {
        this->searcherName = "BFS";
    }
    //returns copy
    Searcher<T, vector<State<T>*>>* clone() {
        return new BFS<T>();
    }
    //this method uses BFS algorithm.
    vector<State<T>*> search(Searchable<T> *s) {
        // Create a queue for BFS
        list<State<T>*> queue;

        // Mark the current node as visited and enqueue it
        this->visited.push_back(s->getInitialState());
        queue.push_back(s->getInitialState());
        while(!queue.empty())
        {
            // Dequeue a vertex from the queue
            State<T>* p  = queue.front();
            queue.pop_front();
            this->numOfDevNodes++;
            //insert to adjList vector all the neighbours of p state
            vector<State<T>*> adjList = s->getAllPossibleStates(p);
            for(State<T>* i :adjList) {
                if (!this->contains(i)) {
                    this->visited.push_back(i);
                    queue.push_back(i);
                    i->setPrevious(p);
                }
                if (s->isGoalState(i)) {
                    return this->pathToGoal(i, s);
                }
            }
        }
    }
};


#endif //ADVPROG_MILESTONE2_BFS_H
