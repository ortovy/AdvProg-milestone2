//
// Created by omer on 12/01/2020.
//
#ifndef ADVPROG_MILESTONE2_CLIENTHANDLER_H
#define ADVPROG_MILESTONE2_CLIENTHANDLER_H

//this interface defines how to handle client requests

class ClientHandler {
public:
    virtual void handleClient(int clientSocket) = 0;
    virtual ClientHandler* clone() = 0;
    virtual ~ClientHandler() {
    }
};

#endif //ADVPROG_MILESTONE2_CLIENTHANDLER_H
