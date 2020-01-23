#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"
#include <vector>
#include "Matrix.h"
#include "Searchable.h"
#include "BFS.h"
#import "DFS.h"
#import "BestFS.h"
#include "AStar.h"
#include "SolverAdapter.h"
#include "MyClientHandler.h"
int main() {
    /**
    cout << "Hello, World!" << std::endl;
    MySerialServer s = MySerialServer();
    ClientHandler *c =  new MyTestClientHandler();
    s.open(5401, c);
     */
    FileCacheManager *cache = new FileCacheManager();
    Searcher<Cell, vector<State<Cell>*>> *n = new BestFS<Cell>;
    Solver<Searchable<Cell>*, vector<State<Cell>*>> *s = new SolverAdapter<Cell, vector<State<Cell>*>>(n);
    ClientHandler *c =  new MyClientHandler(cache, s);
    MySerialServer server = MySerialServer();
    server.open(5401, c);
    /**
    vector<double> c1 = {1,1,1};
    vector<double> c2 = {5,5,3};
    vector<double> c3 = {5,5,5};
    vector<vector<double>> m;
    m.push_back(c1);
    m.push_back(c2);
    m.push_back(c3);
    State<Cell>* init = new State<Cell> (Cell(0,0));
    State<Cell>* goal = new State<Cell> (Cell(2,2));
    Searchable<Cell> *M = new Matrix(3, 3, m, init, goal);
    Searcher<Cell, vector<State<Cell>*>> *n = new AStar<Cell>;
    vector<State<Cell>*> v = n->search(M);
    cout<<n->getNumOfDevNodes()<<endl;
     */
}