#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    MySerialServer s = MySerialServer();
    ClientHandler *c =  new MyTestClientHandler();
    s.open(5400, c);
    cout<<"blaa"<<endl;
    return 0;
}