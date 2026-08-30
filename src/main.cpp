#include <iostream>
#include "main.h"
#include <string>
#include <filesystem>
#include <curl/curl.h>

using namespace std;
namespace fs = filesystem;

string cstring(const std::string& hex, const std::string& text)
{
    int r = std::stoi(hex.substr(1, 2), nullptr, 16);
    int g = std::stoi(hex.substr(3, 2), nullptr, 16);
    int b = std::stoi(hex.substr(5, 2), nullptr, 16);

    return "\033[38;2;" +
        std::to_string(r) + ";" +
        std::to_string(g) + ";" +
        std::to_string(b) + "m" +
        text +
        "\033[0m";
}

string INFO = "["+cstring("#0000ff", "INFO")+"] ";
string OK = "["+cstring("#00ff00", "OK")+"] ";
string ERROR = "["+cstring("#ff0000", "ERROR")+"] ";

void log(string message) {
    cout << message << endl;
}

int installer(craxxblox& config) {
    log(INFO+"Starting Installer");
    return 1;
}

int launcher(craxxblox& config, int argc, char* argv[]) {

    return 1;
}

int main(int argc, char* argv[]) {
    craxxblox config;
    log(cstring("#00ff00","CRAXXBLOX Launcher!"));

    string install_path = config.get_home_directory() + "/.local/CRAXXBLOX/";
    log("Install path set to: " + cstring("#00ff00", install_path));

    if(argc < 2 || !fs::is_directory(install_path)) {
        installer(config);
    } else {
        launcher(config, argc, argv);
    }

    return 0;
}