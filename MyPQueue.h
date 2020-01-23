//
// Created by omer on 20/01/2020.
//

#ifndef ADVPROG_MILESTONE2_MYPQUEUE_H
#define ADVPROG_MILESTONE2_MYPQUEUE_H

#include "State.h"
#include <queue>
using namespace std;
template <typename T>
class MyPQueue {
    priority_queue<State<T>*> priorityQueue;
public:
    void pushPQ(State<T>* s) {
        priorityQueue.push(s);
    }
    bool isEmpty() {
        return(priorityQueue.empty());
    }
    void emptyPQ() {
        while(!this->priorityQueue.empty()) {
            priorityQueue.pop();
        }
    }
    bool existInPQueue(State<T>* s1) {
        /**
        for (int i = 0; i < PQ.size(); i++) {
            if (PQ[i] == s1) {
                return true;
            }
        }
        return false;
         */
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
