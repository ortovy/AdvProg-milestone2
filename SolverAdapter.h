//
// Created by omer on 22/01/2020.
//

#ifndef ADVPROG_MILESTONE2_SOLVERADAPTER_H
#define ADVPROG_MILESTONE2_SOLVERADAPTER_H

#include "Solver.h"
#include "Searchable.h"
#include "Searcher.h"
template <typename T, typename S>
class SolverAdapter: public Solver<Searchable<T>*, S> {
    Searcher<T,S> * searcher;
public:
    SolverAdapter(Searcher<T, S> *s) {
        this->searcher = s;
    }
    S solve(Searchable<T> *problem) {
        return this->searcher->search(problem);
    }
    string getSolverName() {
        return this->searcher->getSearcherName();
    }
};



#endif //ADVPROG_MILESTONE2_SOLVERADAPTER_H
