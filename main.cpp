#include "FileCacheManager.h"
#include "Matrix.h"
#include "Searchable.h"
#include "AStar.h"
#include "SolverAdapter.h"
#include "MyClientHandler.h"
#include "MyParallelServer.h"
int main(int argc, char *argv[]) {
    if(argc == 1) {
        cout<<"No arguments were passed"<<endl;
    } else {
        int port = stoi(argv[1]);
        FileCacheManager *cache = new FileCacheManager();
        Searcher<Cell, vector<State<Cell> *>> *n = new AStar<Cell>;
        Solver<Searchable<Cell> *, vector<State<Cell> *>> *s = new SolverAdapter<Cell, vector<State<Cell> *>>(n);
        ClientHandler *c = new MyClientHandler(cache, s);
        MyParallelServer server = MyParallelServer();
        server.open(port, c);

    }
    return 0;
}