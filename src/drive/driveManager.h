#pragma once

#include <vector>

#include "cifs/cifsDrive.h"

class DriveManager {
private :
    std::vector<CifsDrive> cifsDriveVec;
public :
    DriveManager();

    void addNewCifsDrive();

    std::string toString();
};
