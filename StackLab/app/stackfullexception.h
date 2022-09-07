/*
 * Array-Based Stack Implementation Lab
 * CIS 152 - Data Structures
 * Tanner Babcock
 * September 7, 2022
*/
#ifndef STACKFULLEXCEPTION_H
#define STACKFULLEXCEPTION_H

#include <string>

class StackFullException {
private:
    std::string msg_;
public:
    StackFullException(const std::string& msg) :
        msg_(msg) { }
    StackFullException(void);
    ~StackFullException() { }

    std::string getMessage(void) const {
        return (msg_);
    }
};

#endif // STACKFULLEXCEPTION_H
