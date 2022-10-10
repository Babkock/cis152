/***************************************
 * Name: Priority Queue Application
 * Author: Tanner Babcock
 * Created: October 10, 2022
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
****************************************/
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAXPRIORITY = 5;
const int MAXNAMES = 11;
const int MAXCUSTOMERS = 100;
const string first[] = {
    "Bob", "Tom", "Peter", "Harold", "George", "Samantha", "Marissa", "Donald", "Bernard", "Fred", "Jim"
};
const string last[] = {
    "Johnson", "Stevenson", "Harrison", "Cronenberg", "Norris", "Smith", "Albertson", "Cruz", "Rodriguez", "Ericson", "Thompson"
};

typedef struct {
    int priority;    /* random number 1-5 */
    string name;     /* random name */
} Customer;

int main(void) {
    cout << "Welcome to the Department of Motor Vehicles" << endl;
    list<Customer> *customers = new list<Customer>;
    list<Customer>::iterator it, at;
    queue<Customer> *priority = new queue<Customer>;
    Customer c;
    int p, y, z;

    srand(time(NULL));
    cout << "Generating customers" << endl;
    /* generate customers */
    for (int x = 0; x < MAXCUSTOMERS; x++) {
        p = rand() % MAXPRIORITY;
        y = rand() % MAXNAMES;
        z = rand() % MAXNAMES;
        /* the name is a combination of a random index from first
           names array, and a random index from last names */
        customers->push_back((Customer){ .priority = (p+1), .name = first[y] + " " + last[z] });
    }

    /* prioritizing customers */
    for (int x = 5; x > 2; x--) {
        for (it = customers->begin(); it != customers->end(); ++it) {
            if (it->priority == x) {
                c = *it;
                priority->push(c);
            }
        }
    }

    cout << "Printing customers list" << endl;
    cout << endl;
    int a;
    for (at = customers->begin(), a = 1; at != customers->end(); ++at) {
        cout << a << ". Name: " << at->name << ", Priority: " << at->priority << endl;
        a++;
    }
    cout << endl;

    cout << priority->size() << " in Priority queue" << endl;
    cout << "Printing Priority queue" << endl << endl;
    for (a = 1; (!priority->empty()); a++) {
        c = priority->front();
        cout << a << ". Name: " << c.name << ", Priority: " << c.priority << endl;
        priority->pop();
    }

    delete customers;
    delete priority;
    return 0;
}
