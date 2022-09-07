/*
 * Array-Based Stack Implementation Lab
 * CIS 152 - Data Structures
 * Tanner Babcock
 * September 7, 2022
*/
#include <iostream>
#include "stack.h"
using namespace std;

int main(void) {
    Stack stack = Stack(2);
    string item = "StackItem";

    cout << "Pushing..." << endl;
    stack.push(item + "1");
    stack.push(item + "2");
    cout << stack.printStackUp() << endl;

    return 0;
}
