#include <iostream>

struct Node {
    Node* next;
    int value;
};

class SinglyLinkedList {
    
    public:

        Node* head;

        SinglyLinkedList() {
            head = new Node();
        }

        ~SinglyLinkedList() {
            delete head;
        }

        // Splice x into front of linked list O(1)
        void insert(Node* x) {
            x->next = head;
            head = x;
        }

        // O(n)
        Node* search(int k) {
            Node* x = head;
            while (x != nullptr && x->value != k) {
                x = x->next;
            }
            return x;
        }

        // Remove is O(n) in a singly linked list! O(1) in doubly linked.
        void remove(Node* x) {
            // Search for node prior to x
            Node* y = head;
            while (y != nullptr && y->next->value != x->value) {
                y = y->next;
            }

            if (y == nullptr) return; // x not in list so can't remove

            y->next = y->next->next;

            delete x;
        }

};

int main() {
    SinglyLinkedList L;

    for (int i = 0; i < 10; i++) {
        Node* n = new Node();
        n->value = i;
        L.insert(n);
    }

    // Node* r = new Node();
    // r->value = 5;
    // L.remove(r);

    Node* found = L.search(3);
    if (found != nullptr) {
        std::cout << found->value << std::endl;
    }

    return 0;
}

