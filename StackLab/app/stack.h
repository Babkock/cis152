#ifndef STACK_H
#define STACK_H
#include <string>
using namespace std;

class Stack
{
private:
    // Members
    int top;  // TODO comment
    int maxSize; // TODO comment
    string *stackItems{nullptr};
public:
    Stack(void);
    Stack(int s);
    virtual ~Stack();
    void push(string);
    string pop(void);
    bool isFull(void);
    bool isEmpty(void);
    string peek(void);
    int size(void);
    string printStackUp(void);
};

#endif // STACK_H
