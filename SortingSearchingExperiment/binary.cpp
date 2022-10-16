/* Sorting and Searching Experiment: Binary Search
 * Tanner Babcock
 * CIS 152 - Data Structures
 * October 16, 2022 */
#include <iostream>
#include "sortingSearching.h"

/* This is binary search. It is recursive, and splits the array in half
 * down the middle. This only works if the values of the array are in
 * order from smallest to largest. */
int binarySearch(int *a, int low, int high, int x) {
    if (high >= low) {
        int mid = (low + (high - low) / 2);

        if (a[mid] == x)
            return mid;

        /* present in left half */
        if (a[mid] > x)
            return binarySearch(a, low, mid - 1, x);

        /* else present in right half */
        return binarySearch(a, mid + 1, high, x);
    }
    /* element is not present */
    return -1;
}
