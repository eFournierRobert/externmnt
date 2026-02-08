#include "util.hpp"
#include "../drive/drive.h"
#include "../drive/cifs/cifsDrive.h"
#include "../exceptions/couldNotCreate.h"
#include "../exceptions/couldNotOpenFile.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace fs = std::filesystem;

using json = nlohmann::json;

namespace util {
    std::shared_ptr<Drive> json_to_cifs(const json& element) {
        return std::make_shared<CifsDrive>(
            element["name"],
            element["uid"],
            element["gid"],
            element["username"],
            element["networkPath"],
            element["localPath"]
        );
    }

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

            return std::vector<std::shared_ptr<Drive>> {};
        }

        std::stringstream filepathSs;
        filepathSs << configDirStr.str() << "/drives.json";

        std::ifstream file(filepathSs.str());
        if (!file.is_open()) {
            throw CouldNotOpenFileException("Couldn't read config file drives.json");
        }

        auto data { json::parse(file) };
        auto drives { std::vector<std::shared_ptr<Drive>>() };

        for (auto& element : data[0]) {
            if (element["type"] == "cifs") {
                drives.push_back(json_to_cifs(element));
            }
        }

        return drives;
    }
}
