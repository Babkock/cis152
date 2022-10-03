/*********************************************
 * Name: Linked List-Based Queue Implementation
 * Author: Tanner Babcock
 * Created: October 2, 2022
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
**********************************************/
#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <list>
#include <iterator>
#include "queueemptyexception.h"
#include "queuefullexception.h"

class queue {
private:
    // Members
    int head;
    int tail;
    int size;
    std::list<std::string> *l = {nullptr};
public:
    queue(void);
    queue(std::string e);
    virtual ~queue(void);
    void enqueue(std::string item);
    std::string dequeue(void);
    bool isFull(void);
    bool isEmpty(void);
    std::string peek(void);
    int getSize(void);
    int getHead(void);
    int getTail(void);
    std::string printQueue(void);
};

#endif
