/*
 * Array-Based Stack Implementation Lab
 * CIS 152 - Data Structures
 * Tanner Babcock
 * September 7, 2022
*/
#ifndef STACK_H
#define STACK_H

#include <string>

class Stack {
private:
    // Members
    int top;  // The position of the newest stack entry
    int maxSize; // The maximum amount of strings the array is able to hold
    std::string *stackItems{nullptr};
public:
    Stack(void);
    Stack(int s);
    virtual ~Stack();
    void push(std::string);
    std::string pop(void);
    bool isFull(void);
    bool isEmpty(void);
    std::string peek(void);
    int size(void);
    std::string printStackUp(void);
};

#endif // STACK_H
