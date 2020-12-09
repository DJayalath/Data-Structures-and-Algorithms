#include <iostream>
#include <algorithm>
#include <climits>

// Min-Heap is a binary tree satisfying...
// 1. It is a complete tree (all levels fully occupied above lowest and nodes on lowest all to the left)
// 2. Each child has a value >= parent

// Fastest heap implementation uses an array (b/c tree is complete this is easy)

// Adding is O(logn)
// Removing min. is O(logn)

// Adding array of n elements to a heap is therefore O(n * logn)
// (in practice) O(n) depending on implementation

// Parent = floor[(child - 1)/2]
// Left child = parent * 2 + 1

class MinHeap {

    private:

        int capacity;
        int size;
        int* data;

        int getLeftChildIndex(int k) {
            return (k << 1) + 1;
        }

        int getParentIndex(int k) {
            return (k - 1) >> 1;
        }

        void percolateLastUp() {

            int childIndex = size - 1;

            while (childIndex > 0) {

                int parentIndex = getParentIndex(childIndex);

                if (data[childIndex] >= data[parentIndex]) break;

                std::swap(data[childIndex], data[parentIndex]);
                childIndex = parentIndex;

            }

        }

        void percolateRootDown() {

            int parentIndex = 0;
            int child = getLeftChildIndex(parentIndex);

            while (child < size) {

                if (child + 1 < size && data[child + 1] < data[child]) child++;

                if (data[child] >= data[parentIndex]) break;

                std::swap(data[parentIndex], data[child]);
                parentIndex = child;
                child = getLeftChildIndex(parentIndex);

            }

        }

    public:

        MinHeap(int capacity) : capacity(capacity), size(0) {
            data = new int[capacity];
        }

        bool isFull() {
            return size == capacity;
        }

        bool isEmpty() {
            return size == 0;
        }

        bool add(int v) {

            // Fail if heap is full
            if (isFull()) return false;

            size++;
            data[size - 1] = v;

            percolateLastUp();

            return true;

        }

        int removeMin() {

            // Check if empty
            if (isEmpty()) return INT_MAX;

            int minimum = data[0];

            data[0] = data[size - 1];
            size--;

            percolateRootDown();

            return minimum;

        }

};

// Simple heap sort in O(nlogn) time but O(n) space
// Standard heap sort can do this in place
void heapSort(int* data, int size) {

    MinHeap heap(size);

    for (int i = 0; i < size; i++) {
        heap.add(data[i]);
    }

    for (int i = 0; i < size; i++) {
        data[i] = heap.removeMin();
    }

}

int main() {

    int randomArray[8] = {5, 9, 1, 5, -10, 3, 1, 6};
    heapSort(randomArray, 8);
    for (auto v : randomArray) {
        std::cout << v << ", ";
    }
    std::cout << std::endl;

    return 0;
}