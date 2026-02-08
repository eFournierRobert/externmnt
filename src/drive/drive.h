#pragma once

#include <filesystem>
#include <string>
#include <nlohmann/json.hpp>

class Drive {
protected:
    std::string type;
    std::string name;
    std::string uid;
    std::string gid;
    std::filesystem::path networkPath;
    std::filesystem::path localPath;
public:
    std::string getName();
    std::string getLocalPath();
    std::string getNetworkPath();

    virtual void mount() = 0;
    virtual std::string toString() = 0;

    virtual ~Drive() = default;
};
