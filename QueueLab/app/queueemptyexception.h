#ifndef QUEUEEMPTYEXCEPTION_H
#define QUEUEEMPTYEXCEPTION_H
#include<string>
using namespace std;

class queueEmptyException
{
private:
    string msg_;
public:
    queueEmptyException(const string& msg) :
            msg_(msg) {
    }
    queueEmptyException();
    ~queueEmptyException() {
    }

    string getMessage() const {
        return (msg_);
    }
};

#endif // QUEUEEMPTYEXCEPTION_H
