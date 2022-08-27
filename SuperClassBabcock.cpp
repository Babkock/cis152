/***********************************
 * Name: Inheritance and Polymorphism: SuperClass
 * Author: Tanner Babcock
 * Created: August 27, 2022
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
    int size;
    string color;
public:
    /* constructors */
    Clothing() {
        size = 0;
        color = "White";
    }
    Clothing(int s) {
        size = s;
        color = "White";
    }
    Clothing(int s, string c) {
        size = s;
        color = c;
    }

    /* getters and setters */
    void setSize(int s) {
        size = s;
    }
    int getSize(void) {
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
        return "Fold gently dry clean only";
    }
    void print(void) {
        cout << "Size: " << size << endl;
        cout << "Color: " << color << endl;
    }
};

int main(void) {
    Clothing *foo, *bar;
    foo = new Clothing(5, "red");
    bar = new Clothing(10, "blue");

    cout << "Washing first Clothing" << endl;
    cout << foo->wash() << endl;
    cout << "Packing second Clothing" << endl;
    cout << bar->pack() << endl << endl;

    cout << "Printing first Clothing" << endl;
    foo->print();
    cout << "Printing second Clothing" << endl;
    bar->print();

    delete foo;
    delete bar;
    return 0;
}
