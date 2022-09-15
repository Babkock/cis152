#ifndef QUEUEFULLEXCEPTION_H
#define QUEUEFULLEXCEPTION_H
#include<string>
using namespace std;

class queueFullException
{
private:
    string msg_;
public:
    queueFullException(const string& msg) :
            msg_(msg) {
    }
    queueFullException();
    ~queueFullException() {
    }

    string getMessage() const {
        return (msg_);
    }
};

#endif // QUEUEFULLEXCEPTION_H
