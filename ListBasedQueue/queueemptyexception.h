/********************************************
 * Name: Linked List-Based Queue Implementation
 * Author: Tanner Babcock
 * Created: October 2, 2022
 * Course: CIS 152 - Data Structures
 * Version: 1.0
 * OS: Void GNU/Linux
 * IDE: Emacs
 * Copyright : This is my own original work based
 * on specifications issued by our instructor.
 * Academic Honesty: I attest that this is my original
 * work. I have not used unauthorized source code,
 * either modified or unmodified. I have not given
 * other fellow student(s) access to my program.
********************************************/
#ifndef QUEUEEMPTYEXCEPTION_H
#define QUEUEEMPTYEXCEPTION_H

#include <string>

class queueEmptyException {
private:
    std::string msg_;
public:
    queueEmptyException(const std::string& msg) : msg_(msg) { }
    queueEmptyException(void);
    ~queueEmptyException(void) {
    }

    std::string getMessage(void) const {
        return (msg_);
    }
};

#endif
