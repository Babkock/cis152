/********************************************
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
********************************************/
#include <string>
#include "queue.h"
using namespace std;

const int MAXSIZE = 10;

queue::queue(void) {
    l = new list<string>;
    size = 0;
    head = 0;
    tail = 0;
}

queue::queue(string e) {
    l = new list<string>;
    l->push_front(e);
    size = 1;
    head = 0;
    tail = 1;
}

queue::~queue(void) {
    delete l;
    size = 0;
}

void queue::enqueue(string item) {
    if (isFull())
        throw (queueFullException("Queue is full!"));
    l->push_front(item);
    size++;
    head = 0;
    tail = size;
}

string queue::dequeue(void) {
    if (isEmpty())
        throw (queueEmptyException("Queue is empty!"));
    string out = l->front();
    tail = size--;
    l->pop_front();
    head = 1;
    return out;
}

bool queue::isFull(void) {
    return (size == MAXSIZE);
}

bool queue::isEmpty(void) {
    return (size == 0);
}

string queue::peek(void) {
    if (isEmpty())
        throw (queueEmptyException("Queue is empty!"));
    return l->front();
}

int queue::getSize(void) {
    return size;
}

int queue::getHead(void) {
    return head;
}

int queue::getTail(void) {
    return tail;
}

string queue::printQueue(void) {
    if (isEmpty())
        throw (queueEmptyException("Queue is empty!"));
    string queueString = "";
    auto l_front = l->begin();

    for (int x = head; x < tail; x++) {
        queueString += *l_front + '\n';
        advance(l_front, 1);
    }
    return queueString;
}
