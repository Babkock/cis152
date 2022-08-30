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
using namespace std;

class Clothing {
private:
	char size;
	string color;
public:
	/* constructors */
	Clothing() {
		size = 'M';
		color = "White";
	}
	Clothing(char s) {
		size = s;
		color = "White";
	}
	Clothing(char s, string c) {
		size = s;
		color = c;
	}
};

class Shirt : public Clothing {
private:
	string sleeves;
public:
	/* constructors */
	Shirt(string ss):
		Clothing(), sleeves(ss) { }
	Shirt(string ss, char s):
		Clothing(s), sleeves(ss) { }
	Shirt(string ss, char s, string c):
		Clothing(s, c), sleeves(ss) { }

	/* getters and setters */
	void setSleeves(string s) {
		sleeves = s;
	}
	string getSleeves(void) {
		return sleeves;
	}

	/* methods */
	string wash(void) {
		return "Dry clean only!";
	}
};

