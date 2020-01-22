//
// Created by omer on 21/01/2020.
//

#include "MyClientHandler.h"
#include <sys/socket.h>
#include <unistd.h>
#include "Cell.h"
#include "State.h"
#include <string>
MyClientHandler::MyClientHandler(CacheManager<string> *cache, Solver<Searchable<Cell>*, vector<State<Cell>*>> *s) {
    this->cache = cache;
    this->solver = s;
}
void MyClientHandler::handleClient(int clientSocket) {
    char buffer[1024] = {0};
    vector<string> linesFromClient;
    int valread = read(clientSocket , buffer, 1024);
    while (strnlen(buffer, "end")) {
        linesFromClient.push_back(buffer);
        memset(buffer,'\0',strlen(buffer));
        valread = read(clientSocket, buffer, 1024);
    }
    //create the exit state
    string temp = linesFromClient.back();
    double i = splitByComma(temp)[0];
    double j = splitByComma(temp)[1];
    State<Cell>* goal = new State<Cell> (Cell(i,j));

    //create the exit state
    temp = linesFromClient.back();
    i = splitByComma(temp)[0];
    j = splitByComma(temp)[1];
    State<Cell>* init = new State<Cell> (Cell(i, j));

    // create the  matrix
    vector<vector<double>> matrix;
    int numOfRows = linesFromClient.size();
    int numOfColumns;
    for (int i = 0; i < numOfRows; i++) {
        string rowStr = linesFromClient[i];
        vector<double> lineValues = splitByComma(rowStr);
        matrix.push_back(lineValues);
    }
    numOfColumns = matrix[0].size();
    Searchable<Cell> *M = new Matrix(numOfRows, numOfColumns, matrix, init, goal);
    string problem = solver->getSolverName() + M->toString();
    if (cache->existsSolution(problem)) {
        string solution = cache->getSolution(problem);
        send(clientSocket, solution.c_str(), solution.length(), 0);
    } else {
        vector<State<Cell>*> solverSolution = solver->solve(M);
        string solution = solutionToString(solverSolution);
        cache->saveSolution(problem, solution);
        send(clientSocket, solution.c_str(), solution.length(), 0);
    }
    close(clientSocket);
}

vector<double> MyClientHandler:: splitByComma(string line) {
    string delimiter = ",";
    int pos = 0;
    vector<double> values;
    string token;
    while ((pos = line.find(delimiter)) != std::string::npos) {
        token = line.substr(0, pos);
        values.push_back(stoi(token));
        line.erase(0, pos + delimiter.length());
    }
    return values;
}
string MyClientHandler::solutionToString(vector<State<Cell>*> solution) {
    string solutionStr;
    int i1 = solution[0]->getStateObj().getRow();
    int j1 = solution[0]->getStateObj().getColumn();
    for (int k = 1; k < solution.size(); k++) {
        int i2 = solution[k]->getStateObj().getRow();
        int j2 = solution[k]->getStateObj().getRow();
        if (i1 < i2) {
            solutionStr += "Down ";
        } else if (i1 > i2) {
            solutionStr += "Up ";
        } else if (j1 < j2) {
            solutionStr += "Right ";
        } else if (j1 > j2) {
            solutionStr += "Left ";
        }
        solutionStr+= "(" + to_string(solution[k]->getStateCost()) + ") ,";
        i1 = i2;
        j1 = j2;
    }
    return solutionStr.substr(0, solution.size()-1);;
}