#include <iostream>
#include <algorithm>

// Always involves Theta(n^2) comparisons no matter input permutation
// NOT STABLE but is IN PLACE
// Slower than insertion in practice (and theoretically in best case / average case)
// Useful when you want to minimise the number of swaps that are made e.g. if writes are slow

// Find minimum in unsorted array and swap into sorted array
void selectionSort(int* data, int length) {

    for (int i = 0; i < length; i++) {
        // Find minimum in rest of array
        int minIndex = i;
        for (int j = i + 1; j < length; j++) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        // Swap minimum
        std::swap(data[i], data[minIndex]);
    }

}

// (Easier?) tail-recursive version
void rSelectionSort(int* data, int start, int length) {

    if (start >= length) return;

    int minIndex = start;
    for (int j = start + 1; j < length; j++) {
        if (data[j] < data[minIndex]) {
            minIndex = j;
        }
    }
    std::swap(data[start], data[minIndex]);

    rSelectionSort(data, start + 1, length);


}

int main() {
    int randomArray[8] = {5, 9, 1, 5, -10, 3, 1, 6};
    selectionSort(randomArray, 8);
    for (auto v : randomArray) {
        std::cout << v << ", ";
    }

    return 0;   
}