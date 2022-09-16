#include "queue.h"
#include "queueemptyexception.h"
#include "queuefullexception.h"

queue::queue(void) {
    maxSize = 5;
    queueSize = 0;
    head = -1;
    tail = -1;
    queueItems = new string[maxSize];
}

queue::queue(int s) {
    maxSize = s;
    queueSize = 0;
    head = -1;
    tail = -1;
    queueItems = new string[maxSize];
}

queue::~queue(void) { }

void queue::enqueue(string) {
   //TODO
}

string queue::dequeue(void) {
    string item = "";
    // TODO
    return item; // Possibly you will remove this line, this is for running Unit Tests before writing code
}

bool queue::isFull(void) {
     //TODO
     return false; // Possibly you will remove this line, this is for running Unit Tests before writing code
}

bool queue::isEmpty(void) {
     //TODO
     return false; // Possibly you will remove this line, this is for running Unit Tests before writing code
}

string queue::peek(void) {
    string item = "";
    // TODO
    return item; // Possibly you will remove this line, this is for running Unit Tests before writing code
}

int queue::size(void) {
     //TODO
    return -1; // Possibly you will remove this line, this is for running Unit Tests before writing code
}

string queue::printQueue(void) {
    string StackString = "";
    // TODO
    return StackString; // Possibly you will remove this line, this is for running Unit Tests before writing code
}
