//
// Created by omer on 20/01/2020.
//

#ifndef ADVPROG_MILESTONE2_MYPQUEUE_H
#define ADVPROG_MILESTONE2_MYPQUEUE_H

#include "State.h"
#include <queue>
using namespace std;
template <typename T>
//this class creates a state priority queue
//this data struct helps us in certain algorithms.
class MyPQueue {
    priority_queue<State<T>*> priorityQueue;
public:
    //push to queue.
    void pushPQ(State<T>* s) {
        priorityQueue.push(s);
    }
    //checks if queue is clear.
    bool isEmpty() {
        return(priorityQueue.empty());
    }
    //checks if state is in queue.
    bool existInPQueue(State<T>* s1) {
        priority_queue<State<T>*> helper = priorityQueue;
        while (!helper.empty()) {
            State<T> *s2 = helper.top();
            helper.pop();
            if (s1->operator==(s2)) {
                return true;
            }
        }
        return false;
    }
    //return a the the given state that in the priority queue
    State<T>* valInPQueue(State<T> *s) {
        priority_queue<State<T>*> helper = priorityQueue;
        while (!helper.empty()) {
            State<T> *s2 = helper.top();
            helper.pop();
            if (s->operator==(s2)) {
                return s2;
            }
        }
    }
    //returns top of the priority queue.
    State<T>* topPQ(){
        priority_queue<State<T>*> helper = priorityQueue;
        double minCost = helper.top()->getStateCost();
        State<T>* minState = helper.top();
        helper.pop();
        while (!helper.empty()) {
            State<T>* holder = helper.top();
            helper.pop();
            if (holder->getStateCost() < minCost) {
                minCost = holder->getStateCost();
                minState = holder;
            }
        }
        return minState;
    }
    //pops state from the priority queue
    void popPQ(State<T>* s){
        priority_queue<State<T>*> helper = priorityQueue;
        priority_queue<State<T>*> helper2;
        while (!helper.empty()) {
            State<T>* holder = helper.top();
            helper.pop();
            if(!holder->operator==(s)) {
                helper2.push(holder);
            }
        }
        priorityQueue = helper2;

    }
    //deletes the given state from the priority queue
    void deletePQ(State<T>* s) {
        priority_queue<State<T>*> helper = priorityQueue;
        while (!helper.empty()) {
            State<T> *s2 = helper.top();
            helper.pop();
            priorityQueue.pop();
            if(s2 != s) {
                priorityQueue.push(s2);
            }
        }
        priorityQueue = helper;
    }
};

#endif //ADVPROG_MILESTONE2_MYPQUEUE_H
