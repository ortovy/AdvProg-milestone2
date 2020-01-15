//
// Created by omer on 12/01/2020.
//

#ifndef ADVPROG_MILESTONE2_SERVERI_H
#define ADVPROG_MILESTONE2_SERVERI_H

#include "ClientHandler.h"
#include <thread>
class ServerI {
public:
    virtual void open(int port, ClientHandler *c) = 0;
    virtual void stop() = 0;
};


#endif //ADVPROG_MILESTONE2_SERVERI_H