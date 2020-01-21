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
using namespace std;
class MyClientHandler: public ClientHandler{
    FileCacheManager cache;
public:
    void handleClient(int clientSocket);
    vector<double> splitByComma(string line);
    string solutionToString(vector<State<Cell>*> solution);
};


#endif //ADVPROG_MILESTONE2_MYCLIENTHANDLER_H
