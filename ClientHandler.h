//
// Created by omer on 12/01/2020.
//

#ifndef ADVPROG_MILESTONE2_CLIENTHANDLER_H
#define ADVPROG_MILESTONE2_CLIENTHANDLER_H


class ClientHandler {
public:
    virtual void handleClient(int clientSocket) = 0;
};

#endif //ADVPROG_MILESTONE2_CLIENTHANDLER_H
