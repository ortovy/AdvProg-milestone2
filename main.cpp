#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include <vector>
#include "Matrix.h"
#include "Searchable.h"
#include "BFS.h"
#import "DFS.h"
#import "BestFS.h"
#include "AStar.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
   // MySerialServer s = MySerialServer();
    //ClientHandler *c =  new MyTestClientHandler();
    //s.open(5400, c);
    vector<double > c1 = {1,1,1};
    vector<double > c2 = {5,5,3};
    vector<double > c3 = {5,5,5};
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
}