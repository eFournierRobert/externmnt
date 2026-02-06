#pragma once

#include <string>
#include <vector>
#include "../drive/drive.h"

namespace util {
    std::string prompt(const std::string& message);

    std::vector<std::shared_ptr<Drive>> readDrives();
}
