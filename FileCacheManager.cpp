//
// Created by omer on 12/01/2020.
//

#include "FileCacheManager.h"
bool FileCacheManager:: existsSolution(string problem){
    fstream fromFile;
    string solution;
    string fileName = to_string(hasher(problem));
    fromFile.open(fileName, ios::in|ios::binary);
    if (!fromFile) {
        return false;
    }
    fromFile.close();
    return true;
}
string FileCacheManager:: getSolution(string problem){
    fstream fromFile;
    string solution;
    string fileName = to_string(hasher(problem));
    fromFile.open(fileName, ios::in|ios::binary);
    if (!fromFile) {
        throw ("failed to open file");
    }
    fromFile.read((char*)& solution, sizeof(solution));
    fromFile.close();
    return solution;
}
void FileCacheManager:: saveSolution(string problem, string solution){
    fstream toFile;
    string fileName = to_string(hasher(problem));
    toFile.open(fileName, ios::out|ios::binary);
    if (!toFile) {
        throw ("failed to open file");
    }
    toFile.write((char*)&solution, sizeof(solution));
    toFile.close();
    return;
}