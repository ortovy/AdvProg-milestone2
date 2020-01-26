//
// Created by omer on 12/01/2020.
//

#ifndef ADVPROG_MILESTONE2_MYSERIALSERVER_H
#define ADVPROG_MILESTONE2_MYSERIALSERVER_H


#include "ServerI.h"
#include "ClientHandler.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
using namespace std;
//this class implement Server interface and defines serial server
class MySerialServer: public ServerI{
private:
    int socketfd;
public:
    void open(int port, ClientHandler *c);
    void stop();
    void acceptClients(int socketfd, sockaddr_in address, ClientHandler *c);
};

#endif //ADVPROG_MILESTONE2_MYSERIALSERVER_H
