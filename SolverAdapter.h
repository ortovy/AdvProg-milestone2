//
// Created by omer on 22/01/2020.
//

#ifndef ADVPROG_MILESTONE2_SOLVERADAPTER_H
#define ADVPROG_MILESTONE2_SOLVERADAPTER_H

#include "Solver.h"
#include "Searchable.h"
#include "Searcher.h"
template <typename T, typename S>
//solver adapter class connects searchable objects to searcher algorithms.
class SolverAdapter: public Solver<Searchable<T>*, S> {
    Searcher<T,S>* searcher;
public:
    //constructor - gets searcher
    SolverAdapter(Searcher<T, S> *s) {
        this->searcher = s;
    }
    //in this function we solve given searchable using our already given searcher.
    S solve(Searchable<T> *problem) {
        S sol = this->searcher->search(problem);
        return sol;
    }
    //returns searcher name.
    string getSolverName() {
        return this->searcher->getSearcherName();
    }
    //returns copy
    Solver<Searchable<T>*, vector<State<T>*>>* clone() {
        Searcher<T, S>* searcherClone = this->searcher->clone();
        return new SolverAdapter(searcherClone);
    }
};



#endif //ADVPROG_MILESTONE2_SOLVERADAPTER_H
