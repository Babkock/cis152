/**********************************
 * Name: Lab Learn About the Call Stack
 * Author: Tanner Babcock
 * Created: September 8, 2022
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
#include <cstdlib>
#include <ctime>
using namespace std;

int method1(void) {
    cout << "In method1()" << endl;
    srand(time(NULL));
    int ret = rand() % 30;
    cout << "Exiting method1() with value " << ret << endl;
    return ret;
}

int method2(int offset = 0) {
    cout << "In method2()" << endl;
    cout << "Got offset " << offset << endl;
    srand(time(NULL));
    int ret = (rand() % 30) + offset;
    cout << "Exiting method2() with value " << ret << endl;
    return ret;
}

int method3(int offset = 0) {
    cout << "In method3()" << endl;
    cout << "Got offset " << offset << endl;
    srand(time(NULL));
    int ret = ((rand() % 30) + offset) * 2;
    cout << "Exiting method3() with value " << ret << endl;
    return ret;
}

int method4(int offset = 0) {
    cout << "In method4()" << endl;
    cout << "Got offset " << offset << endl;
    srand(time(NULL));
    int ret = ((rand() % 30) + offset) * 3;
    cout << "Exiting method4() with value " << ret << endl;
    return ret;
}

int main(void) {
    cout << "In main() method" << endl << endl;
    cout << "method2() -> method3() -> method4() -> method1()" << endl;
    int a = method2(method3(method4(method1())));
    cout << "A = " << a << endl << endl;

    cout << "method4() -> method3() -> method2() -> method1()" << endl;
    int b = method4(method3(method2(method1())));
    cout << "B = " << b << endl << endl;

    cout << "Exiting main()" << endl;
    return 0;
}
