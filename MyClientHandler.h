//
// Created by omer on 21/01/2020.
//

#ifndef ADVPROG_MILESTONE2_MYCLIENTHANDLER_H
#define ADVPROG_MILESTONE2_MYCLIENTHANDLER_H


#include "ClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "Searchable.h"
#include "Matrix.h"
#include <iostream>
#include <string.h>
#include "vector"
#include "Solver.h"
using namespace std;
class MyClientHandler: public ClientHandler{
    CacheManager<string> *cache;
    Solver<Searchable<Cell>*, vector<State<Cell>*>> *solver;

public:
    MyClientHandler(CacheManager<string> *cache, Solver<Searchable<Cell>*, vector<State<Cell>*>> *s);
    void handleClient(int clientSocket);
    vector<double> splitByComma(string line);
    string solutionToString(vector<State<Cell>*> solution);
};


#endif //ADVPROG_MILESTONE2_MYCLIENTHANDLER_H
