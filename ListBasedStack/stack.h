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
*****************************************/
#ifndef STACK_H
#define STACK_H

#include <string>
#include <list>
#include <iterator>
#include "StackEmptyException.h"
#include "StackFullException.h"
using namespace std;

class stack {
private:
    // Members
    /* int top;   We do not need top because it's not a queue */
    /* int maxSize; There is no maximum size, just current size */
    int size;
    list<string> *l = {nullptr};
public:
    stack(void);
    stack(string);
    virtual ~stack(void);
    void push(string);
    void pop(void);
    bool isFull(void);
    bool isEmpty(void);
    string peek(void);
    int getSize(void);
    string printStackUp(void);
};

#endif
