/***********************************
 * Name: Inheritance and Polymorphism: Derived Classes
 * Author: Tanner Babcock
 * Created: August 30, 2022
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

/* constructors */
Shirt::Shirt(string ss):
    Clothing(), sleeves(ss) { }
Shirt::Shirt(string ss, char s):
    Clothing(s), sleeves(ss) { }
Shirt::Shirt(string ss, char s, string c):
    Clothing(s, c), sleeves(ss) { }

/* getters and setters */
void Shirt::setSleeves(string s) {
    sleeves = s;
}
string Shirt::getSleeves(void) {
    return sleeves;
}

/* methods */
string Shirt::wash(void) {
    return "Dry clean only!";
}

void Shirt::print(void) {
	cout << "Shirt sleeves: " << sleeves << endl;
	cout << "Shirt size: " << this->getSize() << endl;
	cout << "Shirt color: " << this->getColor() << endl;
}

