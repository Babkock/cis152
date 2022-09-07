/*
 * Array-Based Stack Implementation Lab
 * CIS 152 - Data Structures
 * Tanner Babcock
 * September 7, 2022
*/
#include "stack.h"
#include "stackfullexception.h"
#include "stackemptyexception.h"
using namespace std;

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
    return top == maxSize - 1;
    /* To determine if the stack is full, this function compares top of the stack to the maximum size of the stack.
     * If the newest element is the same as the max size, it means there is no room for other elements */
}

bool Stack::isEmpty(void) {
    return top == -1;
}

int Stack::size(void) {
    return top + 1;
}

string Stack::peek(void) {
    if (!isEmpty())
        return stackItems[top];
    throw (StackEmptyException("Stack is empty!"));
}

string Stack::pop(void) {
    string item = "";
    if (isEmpty())
        throw (StackEmptyException("Stack is empty!"));
    item = stackItems[top];
    stackItems[top] = "";
    top--;
    return item;
}

void Stack::push(string item) {
    if (top == maxSize - 1)
        throw (StackFullException("Stack is full!"));
    top++;
    stackItems[top] = item;
}

string Stack::printStackUp(void) {
    string StackString = "";
    if (isEmpty())
        throw (StackEmptyException("Stack is empty!"));
    for (int x = top; x > -1; x--) {
        StackString += stackItems[x] + "\n";
    }
    return StackString;
}
