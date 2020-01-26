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
//this class implement ClientHandler interface and defines how to handle client requests
class MyClientHandler: public ClientHandler{
    CacheManager<string> *cache;
    Solver<Searchable<Cell>*, vector<State<Cell>*>> *solver;

public:
    MyClientHandler(CacheManager<string> *cache, Solver<Searchable<Cell>*, vector<State<Cell>*>> *s);
    void handleClient(int clientSocket);
    vector<double> splitByComma(string line);
    string solutionToString(vector<State<Cell>*> solution);
    ClientHandler* clone();

};


#endif //ADVPROG_MILESTONE2_MYCLIENTHANDLER_H
