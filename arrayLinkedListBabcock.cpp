/****************************************
 * Name: Array-Based Linked List Implementation
 * Author: Tanner Babcock
 * Created: September 25, 2022
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
*****************************************/
#include <iostream>
#include <cstdio>
using namespace std;

class ListFullException : public exception {
private:
    string message;
public:
    ListFullException(void) {
        message = "List is full";
    }
    ListFullException(string m) : message(m) { }
    string getMessage(void) {
        return message;
    }
};

class ListEmptyException : public exception {
private:
    string message;
public:
    ListEmptyException(void) {
        message = "List is empty";
    }
    ListEmptyException(string m) : message(m) { }
    string getMessage(void) {
        return message;
    }
};

class LinkedList {
private:
    int size;
    int maxSize;
    string *list{nullptr};
public:
    LinkedList(void) {
        maxSize = 5;
        size = -1;
        list = new string[maxSize];
    }
    LinkedList(int s) {
        maxSize = s;
        size = -1;
        list = new string[maxSize];
    }
    LinkedList(int m, int s) {
        maxSize = m;
        size = s;
        list = new string[maxSize];
    }

    LinkedList *createList(int m, int s) {
        LinkedList *l = new LinkedList(m, s);
        return l;
    }

    bool isFull(void) {
        return (size == (maxSize - 1));
    }
    bool isEmpty(void) {
        return (size == -1) || (size == 0);
    }
    void insert(string e) {
        if (isFull())
            throw (ListFullException("The list is full!"));
        list[++size] = e;
    }
    void remove(string e) {
        if (isEmpty())
            throw (ListEmptyException("The list is empty!"));
        for (int x = 0; x < size; x++) {
            if (list[x] == e) {
                list[x] = "";
                size--;
                break;
            }
        }
    }
    void replace(string e1, string e2) {
        if (isEmpty())
            throw (ListEmptyException("The list is empty!"));
        for (int x = 0; x < size; x++) {
            if (list[x] == e1) {
                list[x] = e2;
                break;
            }
        }
    }
    int getSize(void) {
        return size;
    }
    string print(void) {
        string out = "";
        for (int x = 0; x < size+1; x++) {
            out += list[x] + "\n";
        }
        return out;
    }
};

int main(void) {
    LinkedList *one = new LinkedList(10);
    LinkedList *two = new LinkedList(5);
    one->insert("Uno");
    one->insert("Dos");
    one->insert("Tres");
    cout << "Printing first list" << endl;
    cout << one->print() << endl;
    cout << "Size of first list: " << one->getSize() << endl;

    one->remove("Tres");
    one->remove("Dos");
    cout << "Printing first list" << endl;
    cout << one->print() << endl;
    cout << "Size of first list: " << one->getSize() << endl;
    one->remove("Uno");

    try {
        one->remove("Uno");
    } catch (ListEmptyException e) {
        cerr << "List empty error: " << e.getMessage() << endl;
    }
    delete one;

    return 0;
}

