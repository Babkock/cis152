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
*********************************************/
#include <iostream>
#include <string>
#include "queue.h"
using namespace std;

int main(void) {
    queue *a = new queue("hello");
    a->enqueue("goodbye");
    cout << "The size of the first queue is " << a->getSize() << endl;

    cout << "Printing first queue" << endl;
    cout << a->printQueue() << endl;

    queue *b = new queue("one");
    b->enqueue("two");
    b->enqueue("three");
    b->enqueue("four");
    cout << "The size of the second queue is " << b->getSize() << endl;
    cout << "The head is " << b->getHead() << " and the tail is " << b->getTail() << endl;

    b->dequeue();
    b->enqueue("five");
    cout << "Printing second queue" << endl;
    cout << b->printQueue() << endl;

    queue *c = new queue("1");
    c->enqueue("2");
    c->enqueue("three");
    c->enqueue("quatro");
    c->enqueue("cinq");
    c->enqueue("six");
    c->enqueue("seven");
    c->enqueue("eight");
    c->enqueue("neuf");

    cout << "The size of the third queue is " << c->getSize() << endl;
    cout << "The head is " << c->getHead() << " and the tail is " << c->getTail() << endl;
    cout << "Printing third queue" << endl;
    cout << c->printQueue();

    try {
        c->enqueue("ten");
        c->enqueue("eleven");
    } catch (queueFullException e) {
        cerr << "Queue full exception: " << e.getMessage() << endl;
    }

    delete a;
    delete b;
    delete c;
    return 0;
}
