#include <iostream>

void mergeSort(int* data, int start, int end);
void merge(int* data, int start, int mid, int end);

// Merge Sort is asymptotically optimal = O(nlogn)
// STABLE but NOT IN PLACE => O(n) memory complexity from arrays used to merge

// Like quicksort we can improve it using hybrid sorts e.g. insertion when array size is smalL!

void mergeSort(int* data, int start, int end) {

    // Base case!
    if (start >= end) return;

    // Recursively split into halves (DIVIDE)
    int mid = (start + end) >> 1;
    mergeSort(data, start, mid);
    mergeSort(data, mid + 1, end);

    // Merge into sorted array (CONQUER)
    merge(data, start, mid, end);

}

void merge(int* data, int start, int mid, int end) {

    // Construct two left and right arrays
    int lsize = mid - start + 1;
    int rsize = end - mid;
    int* l = new int[lsize];
    int* r = new int[rsize];

    // Fill arrays
    for (int i = start; i <= mid; i++) {
        l[i - start] = data[i];
    }
    for (int i = mid + 1; i <= end; i++) {
        r[i - (mid + 1)] = data[i];
    }

    // Merge arrays
    int i = 0;
    int j = 0;
    int k = start;

    while (i < lsize && j < rsize) {

        // Pick smallest
        if (l[i] < r[j]) {
            data[k] = l[i];
            i++;
        } else {
            data[k] = r[j];
            j++;
        }
        k++;

    }

    // Add remaining elements if any
    while (i < lsize) {
        data[k] = l[i];
        i++; k++;
    }
    while (j < rsize) {
        data[k] = r[j];
        j++; k++;
    }

}

int main() {
    int randomArray[8] = {5, 9, 1, 5, -10, 3, 1, 6};
    mergeSort(randomArray, 0, 7);
    for (auto v : randomArray) {
        std::cout << v << ", ";
    }

    return 0;
}