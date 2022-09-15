#ifndef QUEUE_H
#define QUEUE_H
#include <string>
using namespace std;

class queue
{
private:
    // Members
    int head;  // TODO comment
    int tail;
    int queueSize;
    int maxSize; // TODO comment
    string *queueItems{nullptr};
public:
    queue();
    queue(int s);
    virtual ~queue();
    void enqueue(string);
    string dequeue();
    bool isFull();
    bool isEmpty();
    string peek();
    int size();
    string printQueue();
};

#endif // QUEUE_H
