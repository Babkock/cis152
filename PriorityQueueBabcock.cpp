/*****************************************
 * Name: Priority Queue Implementation
 * Author: Tanner Babcock
 * Created: October 7, 2022
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
	return 0;
}

