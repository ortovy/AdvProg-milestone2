//
// Created by omer on 12/01/2020.
//


#include "MyTestClientHandler.h"
#include <sys/socket.h>
#include <unistd.h>
void MyTestClientHandler::handleClient(int clientSocket) {
    char buffer[1024] = {0};
    int valread = read(clientSocket , buffer, 1024);
    while (strcmp(buffer, "end")) {
        cout << buffer << endl;
        char* msg;
        if(cache.existsSolution(buffer)) {
            string m= cache.getSolution(buffer);
            msg = strcpy(new char[m.length() + 1], m.c_str());
        } else {
            string result = s.solve(buffer);
            msg = strcpy(new char[result.length() + 1], result.c_str());
            cache.saveSolution(buffer, result);
        }
        //writing back to client
        //char *hello = "Hello, I can hear you! \n";
        send(clientSocket, msg, strlen(msg), 0);
        cout << msg << endl;
        //reset the buffer
        memset(buffer,'\0',strlen(buffer));
        valread = read(clientSocket , buffer, 1024);
    }
    cout<<"end of programing"<<endl;
    close(clientSocket);
}