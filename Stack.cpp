#include <iostream>
#include <stdint.h>

// Empty is defined as top = -1
// Full is defined as top = array length - 1
class Stack {

    private:
        int* data;
        uint8_t size;
        int8_t top;

    public:

        Stack(int capacity) : size(capacity), top(-1) {
            data = new int[capacity];
        }

        virtual ~Stack() {
            delete data;
        }

        bool isEmpty() {
            return top == -1;
        }

        bool isFull() {
            return top == size - 1;
        }

        void push(int x) {
            if (!isFull()) {
                top++;
                data[top] = x;
            }
        }

        int pop() {
            if (!isEmpty()) {
                return data[top--];
            }
        }

        int peek() {
            if (!isEmpty()) {
                return data[top];
            }
        }

};

// Queue implemented using two stacks
// Should really check size using sum of items in each stack too!
class QueueS {

    private:
        Stack s1;
        Stack s2;

    public:
        QueueS(int capacity) : s1(capacity), s2(capacity) {}

        bool isEmpty() {
            return s1.isEmpty() && s2.isEmpty();
        }

        void enqueue(int x) {
            // Add to stack 1
            if (!s1.isFull()) {
                s1.push(x);
            }
        }

        int dequeue() {

            if (s2.isEmpty()) {

                // Push everything in s1 onto s2
                while (!s1.isEmpty()) {
                    s2.push(s1.pop());
                }

                if (!s2.isEmpty()) {
                    // Top of s2 will be oldest item in queue
                    return s2.pop();
                }

                // If s2 empty then s1 also was empty, then it fails

            } else {
                // If s2 contains items then just pop
                return s2.pop();
            }

        }

};

int main() {

    int randomArray[8] = {5, 9, 1, 5, -10, 3, 1, 6};

    // Test stack
    Stack s(9);
    for (int i = 0; i < 8; i++) {
        s.push(randomArray[i]);
    }
    s.push(1337);

    for (int i = 0; i < 9; i++) {
        std::cout << s.pop() << ", ";
    }
    std::cout << std::endl;


    // Test two-stack queue
    QueueS q(9);
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