//
// Created by omer on 12/01/2020.
//

#ifndef ADVPROG_MILESTONE2_MYTESTCLIENTHANDLER_H
#define ADVPROG_MILESTONE2_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include <iostream>
#include <string.h>
using namespace std;
class MyTestClientHandler: public ClientHandler {
    StringReverser *s;
    FileCacheManager cache;
public:
    void handleClient(int clientSocket);
    ClientHandler* clone();

};

#endif //ADVPROG_MILESTONE2_MYTESTCLIENTHANDLER_H