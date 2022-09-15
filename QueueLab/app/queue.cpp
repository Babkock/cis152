#include "queue.h"
#include "queueemptyexception.h"
#include "queuefullexception.h"

queue::queue()
{
    maxSize = 5;
    queueSize = 0;
    head = -1;
    tail = -1;
    queueItems = new string[maxSize];
}

queue::queue(int s){
    maxSize = s;
    queueSize = 0;
    head = -1;
    tail = -1;
    queueItems = new string[maxSize];
}

queue::~queue(){}

void queue::enqueue(string){
   //TODO
}

string queue::dequeue(){
    string item = "";
    // TODO
    return item; // Possibly you will remove this line, this is for running Unit Tests before writing code
}

bool queue::isFull(){
     //TODO
     return false; // Possibly you will remove this line, this is for running Unit Tests before writing code
}
bool queue::isEmpty(){
     //TODO
     return false; // Possibly you will remove this line, this is for running Unit Tests before writing code
}

string queue::peek(){
    string item = "";
    // TODO
    return item; // Possibly you will remove this line, this is for running Unit Tests before writing code
}

int queue::size(){
     //TODO
    return -1; // Possibly you will remove this line, this is for running Unit Tests before writing code
}

string queue::printQueue(){
    string StackString = "";
    // TODO
    return StackString; // Possibly you will remove this line, this is for running Unit Tests before writing code
}
