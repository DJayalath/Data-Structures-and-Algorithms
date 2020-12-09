#include <iostream>

// O(log n)
// By querying middle elements we are effectively
// searching a binary search tree with depth log n

// Using inclusive indices (recursive implementation)
bool rBinarySearch(int* data, int start, int end, int t) {

    if (start > end) return false;

    int mid = (start + end) >> 1;

    if (data[mid] == t) {
        return true;
    } else if (data[mid] < t) {
        return rBinarySearch(data, mid + 1, end, t);
    } else {
        return rBinarySearch(data, start, mid - 1, t);
    }

}

// Simple iterative implementation
bool iBinarySearch(int* data, int length, int t) {

    int low = 0;
    int high = length - 1;

    do {
        int mid = (low + high) >> 1;

        if (data[mid] == t) {
            return true;
        } else if (data[mid] < t) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }

    } while (low <= high);

    return false;

}

int main() {

    int sortedArray[8] = {-10, 1, 1, 3, 5, 5, 6, 9};
    std::cout << rBinarySearch(sortedArray, 0, 7, -10) << std::endl;
    std::cout << iBinarySearch(sortedArray, 8, 6) << std::endl;

    return 0;
}