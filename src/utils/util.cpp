#include "util.hpp"
#include <iostream>
#include <string>

namespace util {
    std::string prompt(const std::string &message) {
        std::cout << message;
        std::string input;
        std::getline(std::cin, input);
        return input;
    }
}
