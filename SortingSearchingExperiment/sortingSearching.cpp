/* Sorting and Searching Experiment: Driver
 * CIS 152 - Data Structures
 * Tanner Babcock
 * October 16, 2022 */
#include <iostream>
#include "sortingSearching.h"
using namespace std;

void printArray(int *a, int size) {
    for (int x = 0; x < (size-1); x++) {
        cout << (x+1) << ". = " << a[x] << endl;
    }
}

void swap(int *s, int *d) {
    int temp = *s;
    *s = *d;
    *d = temp;
}

int main(void) {
    int arr[] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    const int ARRSIZE = 11;
    /* try binary search with 5 */
    cout << "The index of 5 in the array is: " << binarySearch(arr, 0, ARRSIZE, 5) << endl;
    /* should print 4 */
    cout << "The index of 55 in the array is: " << binarySearch(arr, 0, ARRSIZE, 55) << endl;
    /* should print 9 */

    cout << "Bubble driver" << endl;
    bubbleDriver();

    cout << "Selection driver" << endl;
    selectionDriver();

    cout << "Insertion driver" << endl;
    insertionDriver();

    int arr2[] = { 5, 1, 4, 9, 8, 7, 2, 3 };
    const int ARR2SIZE = 8;

    cout << "Printing array before bubble()" << endl;
    printArray(arr2, ARR2SIZE);
    bubble(arr2, ARR2SIZE);
    /* should be in order now */
    cout << "Printing array after bubble()" << endl;
    printArray(arr2, ARR2SIZE);

    return 0;
}
