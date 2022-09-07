/*
 * Array-Based Stack Implementation Lab
 * CIS 152 - Data Structures
 * Tanner Babcock
 * September 7, 2022
*/
#ifndef STACKEMPTYEXCEPTION_H
#define STACKEMPTYEXCEPTION_H

#include <string>

class StackEmptyException {
private:
    std::string msg_;
public:
    StackEmptyException(const std::string& msg) :
        msg_(msg) { }
    StackEmptyException(void);
    ~StackEmptyException() { }

    std::string getMessage(void) const {
        return (msg_);
    }
};

#endif // STACKEMPTYEXCEPTION_H
