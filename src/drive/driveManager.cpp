#include "driveManager.h"
#include "../utils/util.hpp"
#include "cifs/cifsDrive.h"
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <memory>
#include <sstream>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

DriveManager::DriveManager() {
    driveVec = util::readDrive();
}

void DriveManager::addNewCifsDrive() {
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);
    if (pw == NULL) {
        perror("Error getting the username of the current user.");
        exit(1);
    }

    std::cout << "--CIFS drive creation--\n";

    std::string name = util::prompt("Name: ");
    if (name.empty()) {
        perror("Drive must have a name");
        exit(1);
    }

    std::stringstream uidPrompt;
    uidPrompt << "UID [" << pw->pw_name << "]: ";

    std::string driveUid = util::prompt(uidPrompt.str());
    if (driveUid.empty()) {
        driveUid = pw->pw_name;
    }

    std::stringstream gidPrompt;
    gidPrompt << "GID [" << pw->pw_name << "]: ";

    std::string driveGid = util::prompt(gidPrompt.str());
    if (driveGid.empty()) {
        driveGid = pw->pw_name;
    }

    std::string strNetworkPath = util::prompt("Network path: ");
    if (strNetworkPath.find("//") == std::string::npos) {
        perror("Enter a valid CIFS network path. Must start with //[ip]/");
        exit(1);
    }
    std::filesystem::path networkPath(strNetworkPath);

    std::string strLocalPath = util::prompt("Absolute local path: ");
    std::filesystem::path localPath(strLocalPath);
    if (!localPath.is_absolute() || !std::filesystem::exists(localPath)) {
        perror("Input a valid absolute path");
        exit(1);
    }

    std::string cifsUsername = util::prompt("Username: ");
    std::string cifsPassword = util::prompt("Password: ");

    auto newDrive = std::make_shared<CifsDrive>(
        name,
        driveUid,
        driveGid,
        cifsUsername,
        networkPath,
        localPath
    );
    newDrive->setPassword(cifsPassword);

    driveVec.push_back(newDrive);
}

std::string DriveManager::toString() {
    return "Not implemented yet";
}
