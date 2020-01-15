//
// Created by omer on 16/01/2020.
//

#ifndef ADVPROG_MILESTONE2_BFS_H
#define ADVPROG_MILESTONE2_BFS_H

#include "Searcher.h"
#include <string>
#include <vector>
#include <algorithm>
class BFS: public Searcher<pair<int, int>, string> {
    string search(Searchable<pair<int, int>> s);
};


#endif //ADVPROG_MILESTONE2_BFS_H
