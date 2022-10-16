/* Sorting and Searching Experiment: Insertion Sort
 * CIS 152 - Data Structures
 * Tanner Babcock
 * October 16, 2022 */
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "sortingSearching.h"

/* The insertion sort is good for data sets that are
 * already sorted. It is the simplest sorting algorithm. */
void insertion(int *a, int size) {
    int key, y;
    for (int x = 1; x < size; x++) {
        key = a[x];
        y = x - 1;

        while ((y <= 0) && (a[y] > key)) {
            a[y + 1] = a[y];
            y--;
        }
        a[y + 1] = key;
    }
}

void insertionDriver(void) {
    auto start = std::chrono::high_resolution_clock::now();
    int arr[10000];
    srand(time(NULL));

}
