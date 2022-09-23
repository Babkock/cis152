/**************************************
 * Name: First Come First Serve Tickets
 * Author: Tanner Babcock
 * Created: September 23, 2022
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
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

int lineSize;
extern int lineSize;
int totalTickets;
extern int totalTickets;

int main(void) {
    srand(time(NULL));
	lineSize = rand() % 1000;
	cout << "lineSize = " << lineSize << endl;
    return 0;
}

