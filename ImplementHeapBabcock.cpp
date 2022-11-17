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

class Heap {
private:
    vector<string> *heap;
    int size;
public:
    Heap(void) {
        heap = new vector<string>();
        size = 0;
        cout << "Constructor called with no arguments" << endl;
    }
    Heap(string i, int s = 1) {
        heap = new vector<string>({i});
        make_heap(heap->begin(), heap->end());
        size = s;
        cout << "Constructor called with entry" << endl;
    }
    Heap(vector<string> v, int s = 0) {
        heap = new vector<string>(v);
        make_heap(heap->begin(), heap->end());
        size = ((s == 0) ? v.size() : s);
        cout << "Constructor called with vector" << endl;
    }
    ~Heap(void) {
        delete heap;
        size = 0;
        cout << "Destructor called" << endl;
    }
};

int main(void) {
    string i;
    cout << "Input a string for the heap: ";
    cin >> i;
    cout << "That string was: " << i << endl;
    Heap *heap = new Heap(i);
    delete heap;
    return 0;
}
