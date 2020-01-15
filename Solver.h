//
// Created by omer on 12/01/2020.
//

#ifndef ADVPROG_MILESTONE2_SOLVER_H
#define ADVPROG_MILESTONE2_SOLVER_H

template <typename P, typename S>
class Solver {
public:
    virtual S solve(P problem) = 0;
};


#endif //ADVPROG_MILESTONE2_SOLVER_H
