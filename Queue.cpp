#include <iostream>
#include <stdint.h>

// Circular array implementation of a queue

// Define empty as when start = end pointers
// Define full as when end + 1 = start OR start = 0 and end = array length - 1

#define FAIL -1

class Queue {

    private:
        int* data;
        uint8_t startPtr;
        uint8_t nextFree;
        uint8_t dataSize;

        void incrementPtr(uint8_t* ptr) {
            if (*ptr == dataSize - 1) {
                (*ptr) = 0;
            } else {
                (*ptr)++;
            }
        }

    public:
        Queue(int capacity) : dataSize(capacity + 1), startPtr(0), nextFree(0) {
            data = new int[dataSize];
        }

        virtual ~Queue() {
            delete data;
        }

        bool isEmpty() {
            return startPtr == nextFree;
        }

        bool isFull() {
            return (startPtr == nextFree + 1) || (startPtr == 0 && nextFree == dataSize - 1);
        }

        bool enqueue(int x) {
            if (!isFull()) {
                data[nextFree] = x;

                incrementPtr(&nextFree);

                return true; // Success
            }
            return false; // Fail
        }

        int dequeue() {
            if (!isEmpty()) {
                int returnVal = data[startPtr];
                incrementPtr(&startPtr);
                return returnVal;
            }
            return FAIL;
        }
};

int main() {
    int randomArray[8] = {5, 9, 1, 5, -10, 3, 1, 6};

    Queue q(9);
    for (int i = 0; i < 8; i++) {
        q.enqueue(randomArray[i]);
    }
    q.enqueue(1337);

    for (int i = 0; i < 9; i++) {
        std::cout << q.dequeue() << ", ";
    }
    std::cout << std::endl;

    return 0;
}