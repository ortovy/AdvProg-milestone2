#include "Main.h"

int main(int argc, char *argv[]) {
    if(argc == 1) {
        cout<<"No arguments were passed"<<endl;
    } else {
        boot::Main().main(stoi(argv[1]));
    }
    return 0;
}
