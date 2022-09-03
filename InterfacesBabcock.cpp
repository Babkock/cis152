/**************************************
 * Name: Interfaces and Polymorphism
 * Author: Tanner Babcock
 * Created: September 3, 2022
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
using namespace std;

class Measurements {
public:
    Measurements(void) { }
    virtual ~Measurements() { }

    /* methods */
    virtual double perimeter(void) = 0;
    virtual double area(void) = 0;
};

class Rectangle : public Measurements {
private:
    double length;
    double width;
public:
    Rectangle(void):
        Measurements(), length(3), width(2) { }
    Rectangle(double l):
        Measurements(), length(l), width(2) { }
    Rectangle(double l, double w):
        Measurements(), length(l), width(w) { }

    /* getters and setters */
    double getLength(void) {
        return length;
    }
    void setLength(double l) {
        length = l;
    }
    double getWidth(void) {
        return width;
    }
    void setWidth(double w) {
        width = w;
    }

    /* methods */
    double perimeter(void) {
        return (length * 2) + (width * 2);
    }
    double area(void) {
        return length * width;
    }
};

class Square : public Measurements {
private:
    double side;
public:
    Square(void):
        Measurements(), side(2) { }
    Square(double s):
        Measurements(), side(s) { }

    /* getters and setters */
    double getSide(void) {
        return side;
    }
    void setSide(double s) {
        side = s;
    }

    /* methods */
    double perimeter(void) {
        return side * 4;
    }
    double area(void) {
        return side * side;
    }
};

int main(void) {
    Square *s = new Square(5);
    cout << "Calculating perimeter of Square s..." << endl;
    cout << "Perimeter: " << s->perimeter() << endl;
    cout << "Calculating area of Square s..." << endl;
    cout << "Area: " << s->area() << endl;
    delete s;

    Rectangle *r = new Rectangle(7, 6);
    cout << "Calculating perimeter of Rectangle r..." << endl;
    cout << "Perimeter: " << r->perimeter() << endl;
    cout << "Calculating area of Rectangle r..." << endl;
    cout << "Area: " << r->area() << endl;
    delete r;
    return 0;
}
