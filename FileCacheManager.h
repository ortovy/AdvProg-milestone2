//
// Created by omer on 12/01/2020.
//

#ifndef ADVPROG_MILESTONE2_FILECACHEMANAGER_H
#define ADVPROG_MILESTONE2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <string>
#include <list>
#include <fstream>
#include <unordered_map>
using namespace std;
class FileCacheManager: public CacheManager<string>{
private:
    int capacity = 5;
    //chace will save 5 problems and their solutions, saves the last 5 that been in use
    //unordered_map<string, string> cache;
    unordered_map<string, pair<string , list<string>:: iterator>> cache;
    //saves all the problems that we have solution for them
    unordered_map<string, string> existSolution;
    list<string> lru;
public:
    bool existsSolution(string problem);
    string getSolution(string problem);
    void saveSolution(string problem, string solution);
    void lruOrder(typename unordered_map<string, pair<string, list<string>:: iterator>>::iterator& it);
    string fromFile(string key);
    void toFile(string solution, string fileName);
};



#endif //ADVPROG_MILESTONE2_FILECACHEMANAGER_H
