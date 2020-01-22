//
// Created by omer on 12/01/2020.
//

#ifndef ADVPROG_MILESTONE2_STRINGREVERSER_H
#define ADVPROG_MILESTONE2_STRINGREVERSER_H

#include "Solver.h"
#include <string>
using namespace std;
class StringReverser: public Solver <string , string>{
public:
    string solve(string s);
    string getSolverName();
};


#endif //ADVPROG_MILESTONE2_STRINGREVERSER_H
