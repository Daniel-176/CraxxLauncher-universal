#include <iostream>
#include "main.h"

using namespace std;

int installer(craxxblox& config) {

    return 1;
}

int launcher(craxxblox& config, int argc, char* argv[]) {

    return 1;
}

int main(int argc, char* argv[]) {
    cout << "CRAXXBLOX Launcher!";
    craxxblox config;

    if(argc < 2) {
        installer(config);
    } else {
        launcher(config, argc, argv);
    }

    return 0;
}