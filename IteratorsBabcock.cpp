/* Module 0
 * Using Iterators
 * Tanner Babcock
 * August 25, 2022 */
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

