#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include <vector>
#include "Matrix.h"
#include "Searchable.h"
#include "BFS.h"
#import "DFS.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
   // MySerialServer s = MySerialServer();
    //ClientHandler *c =  new MyTestClientHandler();
    //s.open(5400, c);
    vector<double > c1 = {1,2,3};
    vector<double > c2 = {1,2,3};
    vector<double > c3 = {1,2,3};
    vector<vector<double>> m;
    m.push_back(c1);
    m.push_back(c2);
    m.push_back(c3);
    State<Cell>* init = new State<Cell> (Cell(0,0));
    State<Cell>* goal = new State<Cell> (Cell(2,2));
    Searchable<Cell> *M = new Matrix(3, 3, m, init, goal);
    //Searcher<Cell, vector<State<Cell>*>> *bfs = new BFS<Cell>;
    Searcher<Cell, vector<State<Cell>*>> *n = new BFS<Cell>;
    vector<State<Cell>*> v = n->search(M);
   // Searcher<Cell, vector<State<Cell>*>> *iSearcher = new BestFirstSearch<Cell, double>();
    //vector<State<Cell>*> bb = bfs->search(M);
    cout<<n->getNumOfDevNodes()<<endl;
}