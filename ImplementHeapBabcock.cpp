/****************************************
 * Name: Implement a Heap
 * Author: Tanner Babcock
 * Created: November 17, 2022
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
#include <algorithm>
#include <vector>
using namespace std;

template <typename T> class Heap {
private:
    vector<T> *heap;
    unsigned int size;
public:
    Heap(void) {
        heap = new vector<T>();
        size = 0;
        cout << "Constructor called with no arguments" << endl;
    }
    Heap(T i, unsigned int s = 1) {
        heap = new vector<T>({i});
        make_heap(heap->begin(), heap->end());
        size = s;
        cout << "Constructor called with entry" << endl;
    }
    Heap(vector<T> v, unsigned int s = 0) {
        heap = new vector<T>(v);
        make_heap(heap->begin(), heap->end());
        size = ((s == 0) ? v.size() : s);
        cout << "Constructor called with vector" << endl;
    }
    ~Heap(void) {
        delete heap;
        size = 0;
        cout << "Destructor called" << endl;
    }

    void push(T i) {
        if (size == 0) {
            delete heap;
            heap = new vector<T>({i});
            make_heap(heap->begin(), heap->end());
            size++;
        } else {
            heap->push_back(i);
            push_heap(heap->begin(), heap->end());
            sort_heap(heap->begin(), heap->end());
            size++;
        }
    }

    void pop(void) {
        if (size == 0) {
            cerr << "Cannot pop empty heap!" << endl;
        } else {
            pop_heap(heap->begin(), heap->end());
            heap->pop_back();
            size--;
            if (size != 0)
                sort_heap(heap->begin(), heap->end());
        }
    }

    T front(void) {
        return heap->front();
    }

    void sort(void) {
        sort_heap(heap->begin(), heap->end());
    }

    unsigned int getSize(void) {
        unsigned int s = heap->size();
        if (s != size)
            return s;
        else
            return size;
    }

    void print(void) {
        cout << "Printing heap" << endl;
        for (unsigned int i = 0; i < heap->size(); i++)
            cout << heap->at(i) << endl;
        cout << endl;
    }
};

int main(void) {
    string i;
    cout << "Input a string for the heap: ";
    getline(cin, i);
    cout << "That string was: " << i << endl << endl;

    /* first heap is for strings */
    Heap<string> *heap = new Heap<string>(i);
    heap->push("second element");
    heap->sort();
    heap->push("third element");
    heap->sort();
    heap->push("fourth");
    heap->sort();
    cout << "The front element of heap 1 is: " << heap->front() << endl;
    cout << "Size of first heap is now " << heap->getSize() << endl << endl;
    heap->print();

    heap->pop();
    heap->sort();
    heap->pop();
    heap->sort();
    cout << "Size of first heap is now " << heap->getSize() << endl << endl;
    heap->print();

    int a;
    cout << "Input an integer for the heap: ";
    cin >> a;
    cout << "That integer was: " << a << endl << endl;

    /* second heap is for integers */
    Heap<int> *h2 = new Heap<int>();

    /* should print "cannot pop empty heap" */
    h2->pop();
    h2->push(a);
    h2->push(a * 2);
    h2->push((a * 2) * 2);
    cout << "The front element of heap 2 is: " << h2->front() << endl;
    cout << "Size of second heap is now " << h2->getSize() << endl << endl;
    h2->print();

    delete heap;
    delete h2;
    return 0;
}

/* Expected output:
$ ./a.out
Input a string for the heap: hello
That string was: hello

Constructor called with entry
The front element of heap 1 is: hello
Size of first heap is now 3

Printing heap
hello
test string
third element

Size of first heap is now 1

Printing heap
third element

Input an integer for the heap: 2
That integer was: 2

Constructor called with no arguments
Cannot pop empty heap!
The front element of heap 2 is: 2
Size of second heap is now 3

Printing heap
2
4
8

Destructor called
Destructor called
*/
