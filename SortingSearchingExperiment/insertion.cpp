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
    int key, y = 0;
    for (int x = 1; x < size; x++) {
        key = a[x];
        y = x - 1;

        while ((y >= 0) && (a[y] > key)) {
            a[y+1] = a[y];
            y--;
        }
        a[y+1] = key;
    }
}

void insertionDriver(void) {
    auto start = std::chrono::high_resolution_clock::now();
    int arr[TRIALONE]; /* 10000 */
    srand(time(NULL));

    for (int i = 0; i < TRIALONE; i++) {
        arr[i] = rand() % 30;
    }
    insertion(arr, TRIALONE);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "First insertion() took " << duration.count() << " milliseconds" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    int arr2[TRIALTWO]; /* 100000 */
    srand(time(NULL));

    for (int i = 0; i < TRIALTWO; i++) {
        arr2[i] = rand() % 30;
    }
    insertion(arr2, TRIALTWO);
    //printArray(arr2, TRIALTWO);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Second insertion() took " << duration.count() << " milliseconds" << std::endl;
}
