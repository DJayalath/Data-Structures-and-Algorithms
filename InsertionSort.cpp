#include <iostream>
#include <algorithm>

// Worst and Average case => Theta(n^2)
// Best case => Theta(n)
// STABLE and IN PLACE
// Construct leftmost subarray that is kept sorted
void insertionSort(int* data, int length) {
    for (int i = 1; i < length; i++) {
        int j = i - 1;
        int key = data[i];
        while (j >= 0) {
            if (key < data[j]) {
                std::swap(data[j + 1], data[j]);
            } else {
                break;
            }

            j--;
        }
    }
}

// Easily derived tail recursive version
void rInsertionSort(int* data, int start, int length) {

    if (start >= length) return;

    int key = data[start];
    int j = start - 1;
    while (j >= 0) {
        if (key < data[j]) {
            std::swap(data[j], data[j + 1]);
        } else {
            break;
        }

        j--;
    }
    rInsertionSort(data, start + 1, length);
}

int main() {

    int randomArray[8] = {5, 9, 1, 5, -10, 3, 1, 6};
    rInsertionSort(randomArray, 0, 8);
    for (auto v : randomArray) {
        std::cout << v << ", ";
    }

    return 0;
}