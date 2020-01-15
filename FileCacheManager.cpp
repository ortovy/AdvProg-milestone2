//
// Created by omer on 12/01/2020.
//

#include "FileCacheManager.h"
bool FileCacheManager:: existsInCache(string problem){
    auto item = cache.find(problem);
    if(item == cache.end()) {
        return false;
    }
    return true;
}
string FileCacheManager:: getSolution(string problem){
    return cache[problem];
}
void FileCacheManager:: saveSolution(string problem, string solution){
    cache[problem] = solution;
}