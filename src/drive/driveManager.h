#pragma once

#include <vector>
#include "drive.h"

class DriveManager {
private :
    std::vector<std::shared_ptr<Drive>> driveVec;
public :
    DriveManager();

    void mountAllDrives();
    std::string toString();
};
