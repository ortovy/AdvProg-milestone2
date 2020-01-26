//
// Created by omer on 21/01/2020.
//

#include "MyClientHandler.h"
#include <sys/socket.h>
#include <unistd.h>
#include "Cell.h"
#include "State.h"
#include <string>
//constructor
MyClientHandler::MyClientHandler(CacheManager<string> *cache1, Solver<Searchable<Cell>*, vector<State<Cell>*>> *s) {
    this->cache = cache1;
    this->solver = s;
}
//returns copy
ClientHandler * MyClientHandler::clone() {
    auto solverClone = this->solver->clone();
    MyClientHandler *clone = new MyClientHandler(cache, solverClone);
    return clone;
}
//defines how to handle client requests
void MyClientHandler::handleClient(int clientSocket) {
    char buffer[1024] = {0};
    vector<string> linesFromClient;
    string temp1;
    int valread = read(clientSocket , buffer, 1024);
    while (strcmp(buffer, "end\n") && valread > 0) {
        temp1+= buffer;
        memset(buffer,'\0',strlen(buffer));
        valread = read(clientSocket, buffer, 1024);
    }
    string temp2;
    for (unsigned int i =0; i<temp1.size();i++) {
        if (temp1[i] == '\n') {
            linesFromClient.push_back(temp2);
            temp2="";
        } else {
            temp2+=temp1[i];
        }
    }
    //create the exit state
    string temp = linesFromClient.back();
    linesFromClient.pop_back();
    double i1 = splitByComma(temp)[0];
    double j1 = splitByComma(temp)[1];
    State<Cell>* goal = new State<Cell> (Cell(i1,j1));

    //create the initial state
    temp = linesFromClient.back();
    linesFromClient.pop_back();
    i1 = splitByComma(temp)[0];
    j1 = splitByComma(temp)[1];
    State<Cell>* init = new State<Cell> (Cell(i1, j1));

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
    string problem = this->solver->getSolverName() + M->toString();
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
//returns a vector of comma-separated strings
vector<double> MyClientHandler:: splitByComma(string line) {
    string delimiter = ",";
    unsigned int pos = 0;
    vector<double> values;
    string token;
    while ((pos = line.find(delimiter)) != std::string::npos) {
        token = line.substr(0, pos);
        values.push_back(stoi(token));
        line.erase(0, pos + delimiter.length());
    }
    if(line != "") {
        values.push_back(stoi(line));
    }
    return values;
}
//gets vector of states(the solution) and returns a string of instructions (up, down ...)
string MyClientHandler::solutionToString(vector<State<Cell>*> solution) {
    string solutionStr;
    int i1 = solution[0]->getStateObj().getRow();
    int j1 = solution[0]->getStateObj().getColumn();
    int tempCost =(int) solution[0]->getStateInitialCost();
    for (unsigned int k = 1; k < solution.size(); k++) {
        int i2 = solution[k]->getStateObj().getRow();
        int j2 = solution[k]->getStateObj().getColumn();
        if (i1 < i2) {
            solutionStr += "Down ";
        } else if (i1 > i2) {
            solutionStr += "Up ";
        } else if (j1 < j2) {
            solutionStr += "Right ";
        } else if (j1 > j2) {
            solutionStr += "Left ";
        }
        tempCost += (int)solution[k]->getStateInitialCost();
        solutionStr+= "(" + to_string(tempCost) + ") ,";
        i1 = i2;
        j1 = j2;
    }
    solutionStr = solutionStr.erase(solutionStr.length() - 1, 1);
    return solutionStr;
}
