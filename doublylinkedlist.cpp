#include <iostream>

struct Node {
    Node* next;
    Node* prev;
    int value;
};

class DoublyLinkedList {
    
    public:

        Node* head;

        DoublyLinkedList() {
            head = new Node();
        }

        ~DoublyLinkedList() {
            delete head;
        }

        // Splice x into front of linked list O(1)
        void insert(Node* x) {
            x->next = head;

            if (head != nullptr) {
                head->prev = x;
            }

            head = x;
            x->prev = nullptr;
        }

        // O(n)
        Node* search(int k) {
            Node* x = head;
            while (x != nullptr && x->value != k) {
                x = x->next;
            }
            return x;
        }

        // Remove is O(1) in a doubly linked list!
        void remove(Node* x) {

            if (x->prev != nullptr) {
                x->prev->next = x->next;
            } else {
                head = x->next;
            }

            if (x->next != nullptr) {
                x->next->prev = x->prev;
            }

        }

};

int main() {
    DoublyLinkedList L;
    Node* r;

    for (int i = 0; i < 10; i++) {
        Node* n = new Node();
        n->value = i;

        if (i == 5) r = n;

        L.insert(n);
    }

    L.remove(r);

    Node* found = L.search(3);
    if (found != nullptr) {
        std::cout << found->value << std::endl;
    }

    return 0;
}

