//
// Created by omer on 27/01/2020.
//

#ifndef ADVPROG_MILESTONE2_MAIN_H
#define ADVPROG_MILESTONE2_MAIN_H

#include "FileCacheManager.h"
#include "Matrix.h"
#include "Searchable.h"
#include "AStar.h"
#include "SolverAdapter.h"
#include "MyClientHandler.h"
#include "MyParallelServer.h"
#include "ServerI.h"
namespace boot {
    class Main {
    public:
        void main(int port) {
            FileCacheManager *cache = new FileCacheManager();
            Searcher<Cell, vector<State<Cell> *>> *n = new AStar<Cell>;
            Solver<Searchable<Cell> *, vector<State<Cell> *>> *s = new SolverAdapter<Cell, vector<State<Cell> *>>(n);
            ClientHandler *c = new MyClientHandler(cache, s);
            server_side::ServerI* server = new MyParallelServer();
            server->open(port, c);
        }
    };

}

#endif //ADVPROG_MILESTONE2_MAIN_H
