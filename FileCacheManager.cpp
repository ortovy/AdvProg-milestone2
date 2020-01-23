//
// Created by omer on 12/01/2020.
//

#include "FileCacheManager.h"
bool FileCacheManager:: existsSolution(string problem){
    string fileName = to_string(hasher(problem));
    ifstream fromFile;
    fromFile.open(fileName);
    if (fromFile) {
        fromFile.close();
        return true;
    }
    return false;
}
string FileCacheManager:: getSolution(string problem){
    string temp;
    string solution;
    ifstream fromFile;
    string fileName = to_string(hasher(problem));
    //fromFile.open(fileName, ios::in|ios::binary);
    fromFile.open(fileName);
    if (!fromFile) {
        cout<<"failed to open file"<<endl;
    }
    while(!fromFile.eof()) {
        fromFile >> temp;
        solution+=temp;
    }
    fromFile.close();
    return solution;
}
void FileCacheManager:: saveSolution(string problem, string solution){
    string fileName = to_string(hasher(problem));
    ofstream toFile;
    toFile.open(fileName);
    if (!toFile) {
        cout<<"failed to open file"<<endl;
        return;
    }
    toFile<<solution;
    toFile.close();
    return;
}