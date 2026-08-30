#pragma once
#include <string>
#include <cstdlib>

using namespace std;

class craxxblox {
public:
    string BASE_URL = "http://xrc.ham.gd";

    string JOIN_ENDPOINT = "http://xrc.ham.gd/game/join.php";

    string EDIT_ENDPOINT = "http://xrc.ham.gd/game/edit.php";

    string NOTIFY_ENDPOINT = "http://xrc.ham.gd/game/notify_watcher.php";

    string MD5HASH_ENDPOINT = "http://xrc.ham.gd/Install/Installer/md5hash.php";

    string CLIENT_DOWNLOAD_ENDPOINT = "http://xrc.ham.gd/Install/Installer/CRAXXBLOX.zip";

    string STUDIO_DLL_ENDPOINT = "http://xrc.ham.gd/Install/Studio/RbxTestHooks.dll";

    string STUDIO_FOLDER_NAME = "CRAXXBLOX Studio";

    string CLIENT_EXE_NAME = "CRAXXBLOX.exe";

    string APP_NAME = "CRAXXBLOX";

    string get_home_directory() {
        #if defined(_WIN32)
            // Windows typical environment variable
            const char* user_profile = std::getenv("USERPROFILE");
            if (user_profile) return std::string(user_profile);
            
            // Fallback for older/specific configurations
            const char* home_drive = std::getenv("HOMEDRIVE");
            const char* home_path = std::getenv("HOMEPATH");
            if (home_drive && home_path) {
                return std::string(home_drive) + std::string(home_path);
            }
        #else
            // Linux and macOS
            const char* home = std::getenv("HOME");
            if (home) return std::string(home);
        #endif

        return "";
    }

    string APP_PATH = "";
    int SCRIPT_MAX_AGE_SECONDS = 3600;
};
