#include <iostream>
#include <algorithm>

void quickSort(int* data, int start, int end);
int pivot(int* data, int start, int end);
int partition(int* data, int pivot, int start, int end);

// Quick sort is NOT asympotically optimal.
// Worst case => O(n^2) when pivot is always smallest element (can happen if pivot strategy is first element and list is sorted)
// BUT in practice it is O(nlogn) on average and often faster than merge sort because there's less data movement (but more comparisons)
// UNSTABLE but it is IN PLACE => O(1) memory usage unlike merge sort

// We can improve QuickSort with multi-pivots, and hybrid sorting with e.g. insertion sort in small lists.
// Can also utilise insertion sort improvement for small lists in merge sort too.

// C++ std requires an asympotically optimal sort algorithm so compiler implementations can't use QuickSort.
// Instead, it uses IntroSort which is a hybrid using QuickSort, HeapSort, and Insertion Sort

// Java's Arrays.sort (sorts arrays) uses dual-pivot QuickSort on primitives (because instability has no effect), but MergeSort on objects (needs to be stable)!
// Java's Collections.sort calls underlying Arrays.sort and will obviously use MergeSort since collections store objects.

// start and end are inclusive array indices
void quickSort(int* data, int start, int end) {

    // DON'T FORGET THE BASE CASE!
    if (start >= end) return;

    // Pick a pivot element
    int pvt = pivot(data, start, end);
    // Partition the data
    int mid = partition(data, pvt, start, end);
    // Recursively quickSort the two halves (DO NOT INCLUDE THE PIVOT)
    quickSort(data, start, mid - 1);
    quickSort(data, mid + 1, end);

}

// Options:
// 1. Pick first
// 2. Pick random to reduce chance of worst case (e.g. using Knuth Suffle)
// 3. Pick median to optimize algorithm runtime (but cost of finding median!)
int pivot(int* data, int start, int end) {
    // Or just the middle element?
    return data[(start + end) >> 1];
}

// Use a partitioning scheme to move all elements < pivot to left of pivot and
// all elements > pivot to right of pivot
// Using Hoare partitioning scheme
int partition(int* data, int pvt, int start, int end) {

    int i = start;
    int j = end;

    // While the two pointers do not cross
    while (i < j) {

        // Find leftmost element greater than pivot (i.e. on wrong side)
        while (data[i] < pvt) {
            i++;
        }

        // Find rightmost element less than pivot (i.e. on wrong side)
        while (data[j] > pvt) {
            j--;
        }

        // Swap the violations
        std::swap(data[i], data[j]);

    }

    // This will be the index of the pivot
    return i;

}

int main() {
    // int randomArray[8] = {5, 9, 1, 2, -10, 3, 12, 6};
    int randomArray[8] = {5, 9, 1, 5, -10, 3, 1, 6};
    // int randomArray[8] = {100, 156, 98, 260, 1, 5, -10, -2};
    quickSort(randomArray, 0, 7);
    for (auto v : randomArray) {
        std::cout << v << ", ";
    }
    
    return 0;
}