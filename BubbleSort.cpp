#include <iostream>
#include <algorithm>

// Very simple sort that swaps adjacent elements
// => O(n^2)
// Slower than insertion and selection in practice
// STABLE and IN PLACE
void bubbleSort(int* data, int length) {
    
    for (int i = 0; i < length - 1; i++) {
        // Guaranteed next last element is sorted after each pass
        bool swapped = false;
        for (int j = 0; j < length - i - 1; j++) {
            if (data[j + 1] < data[j]) {
                std::swap(data[j + 1], data[j]);
                swapped = true;
            }
        }
        // Guaranteed that no swaps in a pass means sort is finished
        if (!swapped) {
            break;
        }
    }

}

int main() {
    int randomArray[8] = {5, 9, 1, 5, -10, 3, 1, 6};
    bubbleSort(randomArray, 8);
    for (auto v : randomArray) {
        std::cout << v << ", ";
    }

    return 0;
}