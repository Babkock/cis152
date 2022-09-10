/*********************************
 * Name: Using Iterators
 * Author: Tanner Babcock
 * Created: August 25, 2022
 * Course: CIS 152 - Data Structures
 * Version: 1.0
 * OS: Void GNU/Linux
 * Complexity: O(1)
 * IDE: Vim
 * Copyright : This is my own original work based
 * on specifications issued by our instructor.
 * Academic Honesty: I attest that this is my original
 * work. I have not used unauthorized source code,
 * either modified or unmodified. I have not given
 * other fellow student(s) access to my program.
*********************************/
#include <iostream>
#include <iterator>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(void) {
	vector<int> collection;
	vector<int>::iterator ptr;
	const int TOTAL = 10;

	srand(time(NULL));
	for (int x = 0; x < TOTAL; x++) {
		collection.push_back((rand() % 20) + 5);
	}
	int y = 0;
	for (ptr = collection.begin(); ptr != collection.end(); advance(ptr, 1)) {
		cout << "collection[" << y << "] = " << collection[y] << endl;
		y++;
	}
	return 0;
}

