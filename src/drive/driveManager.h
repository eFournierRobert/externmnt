#pragma once

#include <vector>
#include "drive.h"

class DriveManager {
private :
    std::vector<std::shared_ptr<Drive>> driveVec;
public :
    DriveManager();

    void addNewCifsDrive();

    std::string toString();
};
