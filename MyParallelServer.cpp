//
// Created by omer on 23/01/2020.
//

#include "MyParallelServer.h"

void MyParallelServer::open(int port, ClientHandler *c) {
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket"<<std::endl;
    }

    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);
    //we need to convert our number
    // to a number that the network understands.

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr<<"Could not bind the socket to an IP"<<std::endl;
    }

    //making socket listen to the port
    if (listen(socketfd, 10) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr<<"Error during listening command"<<std::endl;
    } else{
        std::cout<<"Server is now listening ..."<<std::endl;
    }
    std::thread thread1(&MyParallelServer::acceptClients, MyParallelServer(), socketfd, address, c);
    thread1.join();
}
void MyParallelServer::stop() {
    this->stopp = true;
}
void MyParallelServer:: acceptClients(int socketfd, sockaddr_in address, ClientHandler *c) {
    vector<thread> threadVec;
    struct timeval tv;
    tv.tv_sec = 60;
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    while (!stopp) {
        int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
        if (client_socket == -1) {
            if (errno == EWOULDBLOCK) {
                this->stop();
                cout << "TimeOut" << endl;
                break;
            } else {
                perror("Error accepting client");
                exit(1);
            }
        }
        cout<<"client in connected"<<endl;

        ClientHandler* newC = c->clone();
        std::thread clientThread(&ClientHandler::handleClient, newC, client_socket);
        clientThread.detach();
    }
}
