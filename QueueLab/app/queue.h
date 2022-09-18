#ifndef QUEUE_H
#define QUEUE_H

#include <string>

class queue {
private:
    // Members
    int head;       /* the front (beginning) of the queue */
    int tail;       /* the rear (end) of the queue */
    int queueSize;  /* current size of queue (total non-empty elements in array) */
    int maxSize;    /* maximum size of queue (total all elements) */
    std::string *queueItems{nullptr};
public:
    queue(void);
    queue(int s);
    virtual ~queue(void);
    void enqueue(std::string);
    std::string dequeue(void);
    bool isFull(void);
    bool isEmpty(void);
    std::string peek(void);
    int size(void);
    std::string printQueue(void);
};

#endif // QUEUE_H
