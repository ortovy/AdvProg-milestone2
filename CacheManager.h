//
// Created by omer on 12/01/2020.
//

#ifndef ADVPROG_MILESTONE2_CACHEMANAGER_H
#define ADVPROG_MILESTONE2_CACHEMANAGER_H


#include <string>
using namespace std;
template <typename S>
class CacheManager {
public:
    virtual bool existsInCache(string problem) = 0;
    virtual S getSolution(string problem) = 0;
    virtual void saveSolution(string problem, S solution) = 0;
};

#endif //ADVPROG_MILESTONE2_CACHEMANAGER_H
