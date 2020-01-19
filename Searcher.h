//
// Created by omer on 15/01/2020.
//

#ifndef ADVPROG_MILESTONE2_SEARCHER_H
#define ADVPROG_MILESTONE2_SEARCHER_H

#include "Searchable.h"
#include <queue>
#include <vector>
#include "State.h"
template <typename T,typename S>
class Searcher {
protected:
    priority_queue<State<T>*> priorityQueue;
public:
    virtual S search(Searchable<T> *s) = 0;
    virtual int getNumOfDevNodes() = 0;
    bool existInPQueue(State<T>* s1) {
        priority_queue<State<T>*> helper = priorityQueue;
        while (!helper.empty()) {
            State<T> *s2 = helper.top();
            helper.pop();
            if (s1 == s2) {
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
            if (s == s2) {
                return s2;
            }
        }
    }
    void deleteState(State<T>* s) {
        priority_queue<State<T>*> helper = priorityQueue;
        while (!helper.empty()) {
            State<T> *s2 = helper.top();
            helper.pop();
            priorityQueue.pop();
            if(s2 != s) {
                priorityQueue.push(s2);
            }
        }
    }
};


#endif //ADVPROG_MILESTONE2_SEARCHER_H
