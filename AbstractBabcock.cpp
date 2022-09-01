/**************************************
 * Name: Abstract Class
 * Author: Tanner Babcock
 * Created: September 1, 2022
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
#include "AbstractBabcock.h"
using namespace std;

/* Cycle */
Cycle::Cycle(void) {
    numberOfTires = 0;
    numberOfFlats = 0;
}

Cycle::Cycle(int t) {
    numberOfTires = t;
    numberOfFlats = 0;
}

Cycle::Cycle(int t, int f) {
    numberOfTires = t;
    numberOfFlats = 0;
}

int Cycle::getNumberOfTires(void) {
    return numberOfTires;
}

void Cycle::setNumberOfTires(int t) {
    numberOfTires = t;
}

int Cycle::getNumberOfFlats(void) {
    return numberOfFlats;
}

void Cycle::setNumberOfFlats(int f) {
    numberOfFlats = f;
}

/* Unicycle */
Unicycle::Unicycle(void):
    Cycle(1), color("blue") { }

Unicycle::Unicycle(string c):
    Cycle(1), color(c) { }

string Unicycle::getColor(void) {
    return color;
}

void Unicycle::setColor(string c) {
    color = c;
}

void Unicycle::ride(void) {
    cout << "I am riding a " << color << " unicycle! Weee" << endl;
}

void Unicycle::stop(void) {
    cout << "Woooaah! Easy there! Stopping unicycle" << endl;
}

/* Bicycle */

Bicycle::Bicycle(void):
    Cycle(2), type("road"), color("blue") { }

Bicycle::Bicycle(string t):
    Cycle(2), type(t), color("blue") { }

Bicycle::Bicycle(string t, string c):
    Cycle(2), type(t), color(c) { }

string Bicycle::getType(void) {
    return type;
}

void Bicycle::setType(string t) {
    type = t;
}

string Bicycle::getColor(void) {
    return color;
}

void Bicycle::setColor(string c) {
    color = c;
}

void Bicycle::ride(void) {
    cout << "I am riding my " << color << " " << type << " bike! Weee" << endl;
}

void Bicycle::stop(void) {
    cout << "I am stopping my bike! Good thing I have brakes!" << endl;
}

/* Tricycle */
Tricycle::Tricycle(void):
    Cycle(3), type("mountain"), color("blue") { }

Tricycle::Tricycle(string t):
    Cycle(3), type(t), color("blue") { }

Tricycle::Tricycle(string t, string c):
    Cycle(3), type(t), color(c) { }

string Tricycle::getType(void) {
    return type;
}

void Tricycle::setType(string t) {
    type = t;
}

string Tricycle::getColor(void) {
    return color;
}

void Tricycle::setColor(string c) {
    color = c;
}

void Tricycle::ride(void) {
    cout << "I am riding my " << color << " " << type << " trike! Weee! I'm a big boy" << endl;
}

void Tricycle::stop(void) {
    cout << "It's easy to stop a tricycle!" << endl;
}

int main(void) {
    Bicycle *bike = new Bicycle("mountain", "red");
    Unicycle *uni = new Unicycle("green");
    Tricycle *trike = new Tricycle("road", "yellow");

    cout << "Riding bike..." << endl;
    bike->ride();
    cout << "Stopping bike..." << endl;
    bike->stop();
    cout << "Bike has " << bike->getNumberOfTires() << " tires ";
    cout << "and " << bike->getNumberOfFlats() << " flats" << endl;
    cout << endl;

    cout << "Riding uni..." << endl;
    uni->ride();
    cout << "Stopping uni..." << endl;
    uni->stop();
    cout << "Uni has " << uni->getNumberOfTires() << " tires ";
    cout << "and " << uni->getNumberOfFlats() << " flats" << endl;
    cout << endl;

    cout << "Riding trike..." << endl;
    trike->ride();
    cout << "Stopping trike..." << endl;
    trike->stop();
    cout << "Trike has " << trike->getNumberOfTires() << " tires ";
    cout << "and " << trike->getNumberOfFlats() << " flats" << endl;

    delete bike;
    delete uni;
    delete trike;
    return 0;
}
