/* Sorting and Searching: Linear Search
 * CIS 152 - Data Structures
 * Tanner Babcock
 * October 16, 2022 */
#include <iostream>
#include "searchingSorting.h"

/* This is linear search. It traverses the array one by one from the beginning.
 * It works better for smaller data sets than larger ones. */
int linearSearch(int *a, int size, int x) {
	for (int y = 0; y < size; y++) {
		if (a[y] == x)
			return y;
	}
	return -1;
}

