//
// Created by omer on 12/01/2020.
//

#include "FileCacheManager.h"
bool FileCacheManager:: existsSolution(string problem){
    auto item = existSolution.find(problem);
    if(item == existSolution.end()) {
        return false;
    }
    return true;
}
string FileCacheManager:: getSolution(string problem){
    auto item = cache.find(problem);
    if(item == cache.end()) {
        return fromFile(problem);
    }
    lruOrder(item);
    return item->second.first;
}
void FileCacheManager:: saveSolution(string problem, string solution){
    //cache[problem] = solution;
    auto item = cache.find(problem);
    if(item != cache.end()) {
        lruOrder(item);
        cache[problem] = {solution, lru.begin()};
        toFile(solution, problem);
        return;
    }
    if(cache.size() == capacity) {
        cache.erase((lru.back()));
        lru.pop_back();
    }
    lru.push_front(problem);
    cache.insert({problem, {solution, lru.begin()}});
    string fileName = problem;
    toFile(solution, fileName);

}
void FileCacheManager::lruOrder(typename unordered_map<string, pair<string, list<string>:: iterator>>::iterator& it) {
    lru.erase(it->second.second);
    lru.push_front(it->first);
    it->second.second = lru.begin();
}
string FileCacheManager:: fromFile(string key) {
    string solution;
    string fileName =key;
    fstream fromFile;
    fromFile.open(fileName, ios::in|ios::binary);
    if (!fromFile) {
        throw ("failed to open file");
    }
    fromFile.read((char*)& solution, sizeof(solution));
    saveSolution(key, solution);
    fromFile.close();
    return solution;
}
void FileCacheManager:: toFile(string solution, string fileName) {
    fstream toFile;
    toFile.open(fileName, ios::out|ios::binary);
    if (!toFile) {
        throw ("failed to open file");
    }
    toFile.write((char*)&solution, sizeof(solution));
    toFile.close();
    return;
}