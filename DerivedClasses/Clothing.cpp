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

    /* getters and setters */
    void setSize(char s) {
        size = s;
    }
    char getSize(void) {
        return size;
    }
    void setColor(string c) {
        color = c;
    }
    string getColor(void) {
        return color;
    }

    /* methods */
    string wash(void) {
        return "Wash in cold water";
    }
    string pack(void) {
        return "Fold gently";
    }
    void print(void) {
        cout << "Size: " << size << endl;
        cout << "Color: " << color << endl;
    }
};

