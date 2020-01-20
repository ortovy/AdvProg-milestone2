//
// Created by omer on 15/01/2020.
//

#ifndef ADVPROG_MILESTONE2_SEARCHER_H
#define ADVPROG_MILESTONE2_SEARCHER_H

#include "Searchable.h"
#include <queue>
#include <vector>
#include "State.h"
#include "MyPQueue.h"
template <typename T,typename S>
class Searcher {
protected:
    MyPQueue<T> *PQueue = new MyPQueue<T>();
    int numOfDevNodes = 0;
public:
    virtual S search(Searchable<T> *s) = 0;
    virtual int getNumOfDevNodes() {
        return this->numOfDevNodes;
    }
};


#endif //ADVPROG_MILESTONE2_SEARCHER_H
