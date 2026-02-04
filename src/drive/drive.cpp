#include "drive.h"
#include <string>

std::string Drive::getName() {
    return name;
}

std::string Drive::getLocalPath() {
    return localPath;
}

std::string Drive::getNetworkPath() {
    return networkPath;
}
