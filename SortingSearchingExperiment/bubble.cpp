/* Sorting and Searching Experiment: Bubble Sort
 * CIS 152 - Data Structures
 * Tanner Babcock
 * October 16, 2022 */
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
