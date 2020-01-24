//
// Created by omer on 23/01/2020.
//

#ifndef ADVPROG_MILESTONE2_MYPARALLELSERVER_H
#define ADVPROG_MILESTONE2_MYPARALLELSERVER_H

#include "ServerI.h"
#include "ClientHandler.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <vector>
using namespace std;
class MyParallelServer: public ServerI{
private:
    bool stopp= false;
    int socketfd;

public:
    void open(int port, ClientHandler *c);
    void stop();
    void acceptClients(int socketfd, sockaddr_in address, ClientHandler *c);
};


#endif //ADVPROG_MILESTONE2_MYPARALLELSERVER_H
