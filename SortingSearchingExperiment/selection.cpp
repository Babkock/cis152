/* Sorting and Searching Experiment: Selection Sort
 * CIS 152 - Data Structures
 * Tanner Babcock
 * October 16, 2022 */
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "sortingSearching.h"

/* The selection sort compares the value of each
 * element with the value of each other element, to
 * try to find the minimum and place at the
 * beginning. */
void selection(int *a, int size) {
    int min;
    for (int x = 0; x < (size - 1); x++) {
        /* find the minimum element */
        min = x;
        for (int y = x+1; y < size; y++) {
            if (a[y] < a[min])
                min = y;
        }

        /* swap elements */
        if (min != x)
            swap(&a[min], &a[x]);
    }
}

void selectionDriver(void) {
    auto start = std::chrono::high_resolution_clock::now();
    int arr[10000];
    srand(time(NULL));

    for (int i = 0; i < 10000; i++) {
        arr[i] = rand() % 30;
    }
    selection(arr, 10000);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "First selection() took " << duration.count() << " milliseconds" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    int arr2[100000];
    srand(time(NULL));

    for (int i = 0; i < 100000; i++) {
        arr2[i] = rand() % 30;
    }
    selection(arr2, 100000);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Second selection() took " << duration.count() << " milliseconds" << std::endl;
}
