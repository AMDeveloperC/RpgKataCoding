#ifndef EXCEPTIONS
#define EXCEPTIONS

#include <exception>
#include <string>

class IllegalActionException : public std::exception {
public:
    IllegalActionException(const std::string& msg) : _msg(msg) {}
    const char* what() const noexcept override {
        return _msg.c_str();
    }
    private:
    std::string _msg;
};

#endif