#ifndef STACKEMPTYEXCEPTION_H
#define STACKEMPTYEXCEPTION_H

#include <string>
using namespace std;

class StackEmptyException {
private:
    string msg_;
public:
    StackEmptyException(const string& msg) : msg_(msg) { }
    StackEmptyException(void);
    ~StackEmptyException(void) { }

    string getMessage(void) const {
        return (msg_);
    }
};

#endif
