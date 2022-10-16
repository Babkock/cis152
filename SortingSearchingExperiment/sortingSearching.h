#ifndef SORTINGSEARCHING_H
#define SORTINGSEARCHING_H

/* linear.cpp */
int linearSearch(int *a, int size, int x);

/* binary.cpp */
int binarySearch(int *a, int low, int high, int x);

/* bubble.cpp */
void bubble(int *a, int size);
void bubbleDriver(void);

/* selection.cpp */
void selection(int *a, int size);
void selectionDriver(void);

/* insertion.cpp */
void insertion(int *a, int size);
void insertionDriver(void);

/* sortingSearching.cpp */
void printArray(int *a, int size);
void swap(int *s, int *d);

const int TRIALONE = 10000;
const int TRIALTWO = 100000;

#endif
