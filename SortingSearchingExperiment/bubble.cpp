/* Sorting and Searching Experiment: Bubble Sort
 * CIS 152 - Data Structures
 * Tanner Babcock
 * October 16, 2022 */
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "sortingSearching.h"

/* The bubble sort compares the value of each element
 * of the array with the value of the element after it.
 * If the first value is greater than the second, swap
 * the values, so the greater one comes later. */
void bubble(int *a, int size) {
    for (int x = 0; x < (size - 1); x++) {
        for (int y = 0; y < (size - x) - 1; y++) {
            if (a[y] > a[y+1])
                swap(&a[y], &a[y+1]);
        }
    }
}

void bubbleDriver(void) {
    auto start = std::chrono::high_resolution_clock::now();
    int arr[TRIALONE];
    srand(time(NULL));

    for (int i = 0; i < TRIALONE; i++) {
        arr[i] = rand() % 30;
    }
//    printArray(arr, 10000);
    bubble(arr, TRIALONE);
//    printArray(arr, 10000);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "First bubble() took " << duration.count() << " milliseconds" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    int arr2[TRIALTWO];
    srand(time(NULL));

    for (int i = 0; i < TRIALTWO; i++) {
        arr2[i] = rand() % 30;
    }
    bubble(arr2, TRIALTWO);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Second bubble() took " << duration.count() << " milliseconds" << std::endl;
}
