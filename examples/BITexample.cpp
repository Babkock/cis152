/* binary indexed tree example */
#include <iostream>
using namespace std;

/*
 *           n = number of elements present in input array
 * BITree[0..n] = Array that represents binary indexed tree
 *  arr[0..n-1] = Input array for which prefix sum is evaluated
*/
/* returns sum of arr[0..index] - function assumes
   that the array is preprocessed and partial sums of
   array elements are stored in BITree[] */
int getSum(int BITree[], int index) {
    int sum = 0;

    /* index in BITree is 1 more than index in arr */
    index++;

    while (index > 0) {
        sum += BITree[index]; // add current element to sum
        index -= index & (-index); // move index to parent node
    }
    return sum;
}

/* Updates a node in Binary Indexed Tree (BITree) at given
   index in BITree. The given value 'val' is added to
   BITree[i] and all of its ancestors in tree */
void updateBIT(int BITree[], int n, int index, int val) {
    index++;

    /* traverse all ancestors */
    while (index <= n) {
        BITree[index] += val; // add 'val' to current node
        index += index & (-index); // update index to that of parent
    }
}

/* constructs and returns a Binary Indexed Tree for given
   array of size n */
int *constructBITree(int arr[], int n) {
    /* create and initialize BITree[] as 0 */
    int *BITree = new int[n+1];

    for (int i = 1; i <= n; i++)
        BITree[i] = 0;

    /* store the actual values in BITree[] using update() */
    for (int i = 0; i < n; i++)
        updateBIT(BITree, n, i, arr[i]);

    /* print contents of BITree[] */
    for (int i = 0; i < n; i++)
        cout << BITree[i] << endl;
    return BITree;
}

/* driver */
int main(void) {
    int freq[] = { 2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(freq)/sizeof(freq[0]);
    int *BITree = constructBITree(freq, n);

    cout << "Sum of elements in arr[0..5] is " << getSum(BITree, 5) << endl;

    freq[3] += 6;
    updateBIT(BITree, n, 3, 6);

    cout << "Sum of elements in arr[0..5] after update is ";
    cout << getSum(BITree, 5) << endl;

	delete BITree;
    return 0;
}
