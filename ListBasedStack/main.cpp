/*****************************************
 * Name: List-Based Stack Implementation
 * Author: Tanner Babcock
 * Created: September 29, 2022
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
*****************************************/
#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

int main(void) {
    stack *a = new stack("hello");
    a->push("goodbye");
	cout << "The size of the first stack is " << a->getSize() << endl;

	cout << "Printing stack" << endl;
	cout << a->printStackUp() << endl;

	stack *b = new stack("one");
	b->push("two");
	b->push("three");
	b->push("four");
	cout << "The size of the second stack is " << b->getSize() << endl;

	cout << "Printing stack" << endl;
	cout << b->printStackUp() << endl;

	b->pop();
	b->push("five");
	cout << "Printing stack" << endl;
	cout << b->printStackUp() << endl;

	stack *c = new stack("uno");
	c->push("dos");
	c->push("tres");
	c->push("quatro");
	c->push("cinco");
	c->push("sais");
	c->push("seite");
	c->push("ocho");
	c->push("nueve");
	
	cout << "The size of the third stack is " << c->getSize() << endl;
	cout << "Printing stack" << endl;
	cout << c->printStackUp();

	try {
		c->push("dies");
		c->push("11");
	} catch (StackFullException e) {
		cerr << "Stack full exception: " << e.getMessage() << endl;
	}

	delete a;
	delete b;
	delete c;
    return 0;
}

