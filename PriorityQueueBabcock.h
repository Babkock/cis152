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
#ifndef QUEUEEMPTYEXCEPTION_H
#define QUEUEEMPTYEXCEPTION_H

#include <queue>
#include <string>

typedef struct {
	int job;
	char priority;
} node;

node makeNode(int j, char p);

class PriorityQueue {
private:
	std::queue<std::string> qu;
	node t;
	int size;
public:
	PriorityQueue(void);
	PriorityQueue(std::string e);
	PriorityQueue(std::string e, int nj);
	PriorityQueue(std::string e, int nj, char np);
	PriorityQueue(std::string e, char np, int nj);
	~PriorityQueue(void);
	void enqueue(std::string e);
	std::string dequeue(void);
	void setNodeJob(int nj);
	void setNodePriority(char np);
	int getNodeJob(void);
	char getNodePriority(void);
	bool isEmpty(void);
	std::string peek(void);
	int getSize(void);
	std::string printQueue(void);
};

class queueEmptyException {
private:
	std::string msg;
public:
	queueEmptyException(const std::string& m) : msg(m) { }
	queueEmptyException(void);
	~queueEmptyException(void) { }

	std::string getMessage(void) const {
		return (msg);
	}
};

#endif

