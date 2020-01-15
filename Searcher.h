//
// Created by omer on 15/01/2020.
//

#ifndef ADVPROG_MILESTONE2_SEARCHER_H
#define ADVPROG_MILESTONE2_SEARCHER_H

#include "Searchable.h"
template <typename T,typename S>
class Searcher {
    virtual S search(Searchable<T> s) = 0;
};


#endif //ADVPROG_MILESTONE2_SEARCHER_H
