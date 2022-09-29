/****************************************
 * Name: List-Based Stack Implementation
 * Author: Tanner Babcock
 * Created: September 29, 2022
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
****************************************/
#include <string>
#include "stack.h"
using namespace std;

const int MAXSIZE = 10;


stack::stack(void) {
    l = new list<string>;
    size = 0;
}

stack::stack(string e) {
    l = new list<string>;
    l->push_front(e);
    size = 1;
}

stack::~stack(void) {
    delete l;
    size = 0;
}

void stack::push(string item) {
    if (isFull())
        throw (StackFullException("Stack is full!"));
    l->push_front(item);
    size++;
}

void stack::pop(void) {
    if (isEmpty())
        throw (StackEmptyException("Stack is empty!"));
    size--;
    l->pop_front();
}

bool stack::isFull(void) {
    return (size == MAXSIZE);
}

bool stack::isEmpty(void) {
    return (size == 0);
}

string stack::peek(void) {
    if (isEmpty())
        throw (StackEmptyException("Stack is empty!"));
    return l->front();
}

int stack::getSize(void) {
    return size;
}

string stack::printStackUp(void) {
    if (isEmpty())
        throw (StackEmptyException("Stack is empty!"));
    string stackString = "";
	auto l_front = l->begin();

    for (int x = 0; x < size; x++) {
        stackString += *l_front + '\n';
		advance(l_front, 1);
    }
    return stackString;
}

