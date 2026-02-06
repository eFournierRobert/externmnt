#pragma once

#include <exception>
#include <string>

class CouldNotCreateConfigDirException : public std::exception {
private :
    std::string message;
public :
    CouldNotCreateConfigDirException(const char* msg):
    message(msg) {}

    const char* what() const noexcept {
        return message.c_str();
    }
};
