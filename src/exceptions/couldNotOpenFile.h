#pragma once

#include <exception>
#include <string>

class CouldNotOpenFileException : public std::exception {
private :
    std::string message;
public :
    CouldNotOpenFileException(const char* msg):
    message(msg) {}

    const char* what() const noexcept {
        return message.c_str();
    }
};
