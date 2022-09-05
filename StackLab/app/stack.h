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
    Stack();
    Stack(int s);
    virtual ~Stack();
    void push(string);
    string pop();
    bool isFull();
    bool isEmpty();
    string peek();
    int size();
    string printStackUp();
};

#endif // STACK_H
