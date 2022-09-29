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

	delete a;
    return 0;
}

