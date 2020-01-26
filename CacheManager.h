//
// Created by omer on 12/01/2020.
//

#ifndef ADVPROG_MILESTONE2_CACHEMANAGER_H
#define ADVPROG_MILESTONE2_CACHEMANAGER_H

/*
 * this interface manages the cache data in our program
 */
#include <string>
using namespace std;
template <typename S>
class CacheManager {
public:
    //checks if the given solution exist in our cache
    virtual bool existsSolution(string problem) = 0;
    //returns the solution we have in the cache
    virtual S getSolution(string problem) = 0;
    //save the given solution in the cache with the given problem
    virtual void saveSolution(string problem, S solution) = 0;
    virtual ~CacheManager() {
    }
};

#endif //ADVPROG_MILESTONE2_CACHEMANAGER_H
