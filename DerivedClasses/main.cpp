/**************************************
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
**************************************/
#include <iostream>
#include <string>
#include "Clothing.h"
using namespace std;

int main(void) {
	Pants *p1 = new Pants();
	Pants *p2 = new Pants('L');
	Pants *p3 = new Pants('L', "Blue");

	cout << "Printing Pants p1" << endl;
	p1->print();
	cout << "Washing Pants p1" << endl;
	cout << p1->wash() << endl;
	cout << "Printing Pants p2" << endl;
	p2->print();
	cout << "Hanging Pants p2" << endl;
	cout << p2->hang() << endl;
	cout << "Printing Pants p3" << endl;
	p3->print();
	cout << "Washing Pants p3" << endl;
	cout << p3->wash() << endl;
	cout << endl;
	cout << "Changing Pants p3..." << endl;

	p3->setSize('M');
	p3->setColor("Green");

	cout << endl;
	cout << "Size of p3: " << p3->getSize() << endl;
	cout << "Color of p3: " << p3->getColor() << endl;
	cout << endl;

	delete p1;
	delete p2;
	delete p3;

	Shirt *s1 = new Shirt("long");
	Shirt *s2 = new Shirt("short", 'L');
	Shirt *s3 = new Shirt("long", 'M', "Red");

	cout << "Printing Shirt s1" << endl;
	s1->print();
	cout << "Washing Shirt s1" << endl;
	cout << s1->wash() << endl;
	cout << "Printing Shirt s2" << endl;
	s2->print();
	cout << "Printing Shirt s3" << endl;
	s3->print();
	cout << endl;
	cout << "Changing Shirt s3..." << endl;

	s3->setSize('S');
	s3->setColor("Yellow");
	s3->setSleeves("medium");

	cout << endl;
	cout << "Size of s3: " << s3->getSize() << endl;
	cout << "Color of s3: " << s3->getColor() << endl;
	cout << "Sleeves of s3: " << s3->getSleeves() << endl;

	delete s1;
	delete s2;
	delete s3;
	return 0;
}

