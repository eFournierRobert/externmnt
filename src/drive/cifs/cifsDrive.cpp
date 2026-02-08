#include "cifsDrive.h"
#include <iostream>

CifsDrive::CifsDrive(
    std::string name,
    std::string uid,
    std::string gid,
    std::string username,
    std::filesystem::path networkPath,
    std::filesystem::path localPath
) {
    this->type = "cifs";
    this->name = name;
    this->uid = uid;
    this->gid = gid;
    this->username = username;
    this->networkPath = networkPath;
    this->localPath = localPath;
}

void CifsDrive::setPassword(std::string password) {
    this->password = password;
}

void CifsDrive::mount() {
    std::cout << "Not implemented yet\n";
}

std::string CifsDrive::toString() {
    return "Not implemented yet\n";
}
