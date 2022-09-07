#ifndef STACKEMPTYEXCEPTION_H
#define STACKEMPTYEXCEPTION_H

#include <string>
using namespace std;

class StackEmptyException {
private:
    string msg_;
public:
    StackEmptyException(const string& msg) :
        msg_(msg) {
    }
    StackEmptyException();
    ~StackEmptyException() {
    }

    string getMessage() const {
        return (msg_);
    }
};

#endif // STACKEMPTYEXCEPTION_H
