/***********************************
 * Name: Inheritance and Polymorphism: Derived Classes
 * Author: Tanner Babcock
 * Created: August 29, 2022
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
************************************/
#include <iostream>
#include <string>
#include "Clothing.h"
using namespace std;

Clothing::Clothing() {
    size = 'M';
    color = "White";
}

Clothing::Clothing(char s) {
    size = s;
    color = "White";
}

Clothing::Clothing(char s, string c) {
    size = s;
    color = c;
}

/* getters and setters */
void Clothing::setSize(char s) {
    size = s;
}

char Clothing::getSize(void) {
    return size;
}

void Clothing::setColor(string c) {
    color = c;
}

string Clothing::getColor(void) {
    return color;
}

/* methods */
string Clothing::wash(void) {
    return "Wash in cold water";
}

string Clothing::pack(void) {
    return "Fold gently";
}

void Clothing::print(void) {
    cout << "Size: " << size << endl;
    cout << "Color: " << color << endl;
}
