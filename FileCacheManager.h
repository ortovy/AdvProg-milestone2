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
    unordered_map<string, string> cache;
public:
    bool existsInCache(string problem);
    string getSolution(string problem);
    void saveSolution(string problem, string solution);
};



#endif //ADVPROG_MILESTONE2_FILECACHEMANAGER_H
