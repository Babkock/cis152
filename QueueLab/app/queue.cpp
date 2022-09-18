#include "queue.h"
#include "queueemptyexception.h"
#include "queuefullexception.h"

queue::queue(void) {
    maxSize = 5;
    queueSize = 0;
    head = -1;
    tail = -1;
    queueItems = new std::string[maxSize];
}

queue::queue(int s) {
    maxSize = s;
    queueSize = 0;
    head = -1;
    tail = -1;
    queueItems = new std::string[maxSize];
}

queue::~queue(void) { }

void queue::enqueue(std::string item) {
    /* add item to tail of queue */
    if ((tail >= (maxSize - 1)) || (queueSize >= maxSize))
        throw (queueFullException("Queue is full!"));
    head = 0;
    tail++;
    queueSize++;
    queueItems[tail] = item;
}

std::string queue::dequeue(void) {
    std::string item = "";
    /* remove item from head of queue */
    if (head == -1 || queueSize == 0)
        throw (queueEmptyException("Queue is empty!"));
    item = queueItems[0];
    head = 0;
    for (int x = 0; x < queueSize; x++) {
        queueItems[x] = queueItems[x+1];
    }
    tail--;
    queueSize--;
    return item;
}

bool queue::isFull(void) {
     return ((queueSize == maxSize) || (tail == (maxSize - 1)));
}

bool queue::isEmpty(void) {
     return ((head <= 0) || (tail <= 0) || (queueSize == 0));
}

std::string queue::peek(void) {
    std::string item = "";
    if ((head == -1) || (queueSize == 0))
        throw (queueEmptyException("Queue is empty!"));
    item = queueItems[head];
    return item;
}

int queue::size(void) {
    return queueSize;
}

std::string queue::printQueue(void) {
    std::string StackString = "";
    if ((head == -1) || (queueSize == 0))
        return "Queue is Empty";
    /* this doesn't make sense, instructions say to throw exception here,
     * but unit tests check for this "Queue is Empty" string */

    for (int x = 0; x < queueSize; x++) {
        StackString += queueItems[x] + "\n";
    }
    return StackString;
}
