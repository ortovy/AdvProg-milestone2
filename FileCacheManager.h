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
#include <iostream>
using namespace std;
class FileCacheManager: public CacheManager<string>{
private:
    hash<string> hasher;
public:
    bool existsSolution(string problem);
    string getSolution(string problem);
    void saveSolution(string problem, string solution);
    void toFile(string solution, string fileName);
};



#endif //ADVPROG_MILESTONE2_FILECACHEMANAGER_H
