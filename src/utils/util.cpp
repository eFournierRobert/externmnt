#include "util.hpp"
#include "../drive/drive.h"
#include "../exceptions/couldNotCreate.h"

#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

namespace util {
    std::string prompt(const std::string &message) {
        std::cout << message;
        std::string input;
        std::getline(std::cin, input);
        return input;
    }

    std::vector<std::shared_ptr<Drive>> readDrives() {
        std::stringstream configDirStr;

        auto homeDir {getenv("HOME")};
        configDirStr << homeDir << "/.config/externmnt";
        fs::path configDir(configDirStr.str());

        if (!fs::exists(configDir)) {
            if (!fs::create_directory(configDir)) {
                throw CouldNotCreateConfigDirException("Couldn't create config directory.");
            }
        }
    }
}
