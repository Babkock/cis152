#include "stack.h"
#include "stackfullexception.h"
#include "stackemptyexception.h"

Stack::Stack(void) {
    maxSize = 5;
    top = -1;
    stackItems = new string[maxSize];
}

Stack::Stack(int s) {
    maxSize = s;
    top = -1;
    stackItems = new string[maxSize];
}

Stack::~Stack() {
}

bool Stack::isFull(void) {
    return top == maxSize - 1; // TODO comment
}

bool Stack::isEmpty(void) {
    // TODO
    return false; // Possibly you will remove this line, this is for running Unit Tests before writing code
}

int Stack::size(void) {
    // TODO
    return -1; // Possibly you will remove this line, this is for running Unit Tests before writing code
}

string Stack::peek(void) {
    if (!isEmpty())
        return stackItems[top];
    throw (StackEmptyException("Stack is empty!"));
}

string Stack::pop(void) {
    string item = "";
    // TODO
    return item; // Possibly you will remove this line, this is for running Unit Tests before writing code
}

void Stack::push(string item) {
    //TODO
}

string Stack::printStackUp(void) {
    string StackString = "";
    // TODO
    return StackString; // Possibly you will remove this line, this is for running Unit Tests before writing code
}
