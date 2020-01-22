//
// Created by omer on 12/01/2020.
//

#include "MySerialServer.h"
void MySerialServer::open(int port, ClientHandler *c) {
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
    thread thread1([=] {acceptClients(socketfd, address, c); });
    thread1.join();
}
void MySerialServer::stop() {
    close(socketfd);
}
void MySerialServer:: acceptClients(int socketfd, sockaddr_in address, ClientHandler *c) {
    cout << "thread function\n";
    struct timeval tv;
    tv.tv_sec = 60;
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    int client_socket = accept(socketfd, (struct sockaddr *)&address, (socklen_t*)&address);
    while (client_socket != -1) {
        cout<<"accept client";
        c->handleClient(client_socket);
        client_socket = accept(socketfd, (struct sockaddr *)&address, (socklen_t*)&address);
    }
    stop();
}