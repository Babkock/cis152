/****************************************
 * Name: Module 12 Learn Maps
 * Author: Tanner Babcock
 * Created: November 11, 2022
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
#include <map>
#include <iterator>
using namespace std;

int main(void) {
    map<int, int> m;
    map<int, int>::iterator i;
    m.insert(pair<int, int>(1, 2));
    m.insert(pair<int, int>(3, 4));

    for (i = m.begin(); i != m.end(); ++i) {
        cout << "\t" << i->first << "\t" << i->second << endl;
    }

    cout << "Hello world" << endl;
    return 0;
}
