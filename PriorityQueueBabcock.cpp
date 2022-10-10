/*****************************************
 * Name: Priority Queue Implementation
 * Author: Tanner Babcock
 * Created: October 8, 2022
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
******************************************/
#include <iostream>
#include <string>
#include <queue>
#include "PriorityQueueBabcock.h"
using namespace std;

node makeNode(int j, char p) {
	return (node){ .job = j, .priority = p };
}

PriorityQueue::PriorityQueue(void) {
	size = 0;
	t = makeNode(1, 'B');
}

PriorityQueue::PriorityQueue(string e) {
	size = 1;
	t = makeNode(1, 'B');
	qu.push(e);
}

PriorityQueue::PriorityQueue(string e, int nj) {
	size = 1;
	t = makeNode(nj, 'B');
	qu.push(e);
}

PriorityQueue::PriorityQueue(string e, int nj, char np) {
	size = 1;
	t = makeNode(nj, np);
	qu.push(e);
}

PriorityQueue::PriorityQueue(string e, char np, int nj) {
	size = 1;
	t = makeNode(nj, np);
	qu.push(e);
}

PriorityQueue::~PriorityQueue(void) {
	size = 0;
	t = makeNode(0, 'X');
}

void PriorityQueue::enqueue(string e) {
	size++;
	qu.push(e);
}

string PriorityQueue::dequeue(void) {
	size--;
	string out = qu.front();
	qu.pop();
	return out;
}

void PriorityQueue::setNodeJob(int nj) {
	t.job = nj;
}

void PriorityQueue::setNodePriority(char np) {
	t.priority = np;
}

int PriorityQueue::getNodeJob(void) {
	return t.job;
}

char PriorityQueue::getNodePriority(void) {
	return t.priority;
}

bool PriorityQueue::isEmpty(void) {
	return (qu.empty());
}

string PriorityQueue::peek(void) {
	return qu.front();
}

int PriorityQueue::getSize(void) {
	return size;
}

string PriorityQueue::printQueue(void) {
	if (isEmpty())
		throw (queueEmptyException("Queue is empty!"));
	string queueString = "";

	while (!qu.empty()) {
		queueString += qu.front() + "\n";
		qu.pop();
	}
	return queueString;
}

queueEmptyException::queueEmptyException(void) { }

int main(void) {
    PriorityQueue *one = new PriorityQueue("first", 1, 'B');
	PriorityQueue *two = new PriorityQueue("second", 2, 'B');
	PriorityQueue *three = new PriorityQueue("third", 3, 'B');

	PriorityQueue *uno = new PriorityQueue("uno", 1, 'D');
	PriorityQueue *dos = new PriorityQueue("dos", 2, 'D');
	PriorityQueue *tres = new PriorityQueue("tres", 3, 'D');
	PriorityQueue *quatro = new PriorityQueue("quatro", 4, 'D');

	PriorityQueue *a = new PriorityQueue("one", 1, 'A');
	PriorityQueue *b = new PriorityQueue("two", 2, 'A');

	one->printQueue();
	two->printQueue();
	three->printQueue();

	delete one;
	delete two;
	delete three;
	delete uno;
	delete dos;
	delete tres;
	delete quatro;
	delete a;
	delete b;
	return 0;
}

