#ifndef STACKFULLEXCEPTION_H
#define STACKFULLEXCEPTION_H

#include <string>
using namespace std;

class StackFullException {
private:
    string msg_;
public:
    StackFullException(const string& msg) : msg_(msg) { }
    StackFullException(void);
    ~StackFullException(void) { }

    string getMessage(void) const {
        return (msg_);
    }
};

#endif
