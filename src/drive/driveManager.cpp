#include "driveManager.h"
#include "../utils/util.hpp"
#include <sstream>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

DriveManager::DriveManager() {
    driveVec = util::readDrives();
}

void DriveManager::mountAllDrives() {
    for (auto& d : driveVec) {
        d->mount();
    }
}

std::string DriveManager::toString() {
    std::stringstream ss;
    ss << "[\n";

    for (int i = 0; i < driveVec.size(); i++) {
        ss << driveVec.at(i)->toString();

        if (i != driveVec.size() - 1) {
            ss << ",\n";
        }
    }

    ss << "\n]";
    return ss.str();
}
