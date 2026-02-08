#pragma once

#include "../drive.h"
#include <filesystem>

class CifsDrive : public Drive {
private:
    std::string username;
    std::string password;
public:
    CifsDrive(
        std::string name,
        std::string uid,
        std::string gid,
        std::string username,
        std::filesystem::path networkPath,
        std::filesystem::path localPath
    );

    void setPassword(std::string password);

    void mount();
    std::string toString();
};
