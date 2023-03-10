/************************************
 * Name: Inheritance and Polymorphism: Derived Classes
 * Author: Tanner Babcock
 * Created: August 31, 2022
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
*************************************/
#include <iostream>
#include <string>
#include "Clothing.h"
using namespace std;

Pants::Pants(void):
    Clothing() { }
Pants::Pants(char s):
    Clothing(s) { }
Pants::Pants(char s, string c):
    Clothing(s, c) { }

/* methods */
string Pants::wash(void) {
    return "Pants are dry clean only!";
}
string Pants::hang(void) {
    return "Hanging the pants";
}
