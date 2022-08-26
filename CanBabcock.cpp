/**********************************
 * Name: Basic OO and Encapsulation
 * Author: Tanner Babcock
 * Created: August 26, 2022
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
***********************************/
#include <iostream>
#include <string>
using namespace std;

class Can {
private:
    string company;
    string content;
    float size;
    float price;
public:
    /* constructors */
    Can() {
        company = "Unknown";
        content = "Unknown";
        size = 1.0;
        price = 2.0;
    }
    Can(string comp) {
        company = comp;
        content = "Unknown";
        size = 1.0;
        price = 2.0;
    }
    Can(string comp, string cont) {
        company = comp;
        content = cont;
        size = 1.0;
        price = 2.0;
    }
    Can(string comp, string cont, float s) {
        company = comp;
        content = cont;
        size = s;
        price = 2.0;
    }
    Can(string comp, string cont, float s, float p) {
        company = comp;
        content = cont;
        size = s;
        price = p;
    }

    /* getters and setters */
    void setCompany(string comp) {
        company = comp;
    }
    string getCompany(void) {
        return company;
    }
    void setContent(string cont) {
        content = cont;
    }
    string getContent(void) {
        return content;
    }
    void setSize(float s) {
        size = s;
    }
    float getSize(void) {
        return size;
    }
    void setPrice(float p) {
        price = p;
    }
    float getPrice(void) {
        return price;
    }

    /* mutators */
    void doublePrice(void) {
        price *= 2;
    }
    void doubleSize(void) {
        size *= 2;
    }
    void halfPrice(void) {
        price /= 2;
    }
    void halfSize(void) {
        size /= 2;
    }

    /* display function */
    void print(void) {
        cout << getCompany() << " " << getContent() << endl;
        cout << "Size: " << getSize() << " ounces, Price: $" << getPrice() << endl;
    }
};

int main(void) {
    Can *a = new Can("Field Day", "Black Beans", 13.0, 0.99);
    Can *b = new Can("S&W", "Peaches", 12.0, 2.39);
    Can *c = new Can("Green Giant", "Green Beans", 11.9, 1.79);
    Can *d = new Can("Del Monte", "Creamed Corn", 13.4, 2.49);
    cout << "Can 1:" << endl;
    a->print();
    cout << "Can 2:" << endl;
    b->print();
    cout << "Can 3:" << endl;
    c->print();
    cout << "Can 4:" << endl;
    d->print();
    delete a;
    delete b;
    delete c;
    delete d;
    return 0;
}
