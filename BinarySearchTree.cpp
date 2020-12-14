#include <iostream>

struct Node {
    int key;
    Node* leftChild = nullptr;
    Node* rightChild = nullptr;
    Node* parent = nullptr;
    Node(int k) : key(k) {}
};

class BST {

    private:

        // O(h) = O(logn) insertion as we traverse down one branch
        void insertFromNode(Node* fromNode, int key) {
            if (key > fromNode->key) {
                if (!fromNode->rightChild) {
                    Node* x = new Node(key);
                    fromNode->rightChild = x;
                    x->parent = fromNode;
                } else {
                    insertFromNode(fromNode->rightChild, key);
                }
            } else {
                if (!fromNode->leftChild) {
                    Node* x = new Node(key);
                    fromNode->leftChild = x;
                    x->parent = fromNode;
                } else {
                    insertFromNode(fromNode->leftChild, key);
                }
            }
        }

        // De-allocate memory in post-order walk
        void recursiveDestruct(Node* r) {
            if (r) {
                recursiveDestruct(r->leftChild);
                recursiveDestruct(r->rightChild);
                delete r;
            }
        }
    
    public:
        BST() {}

        virtual ~BST() {
            recursiveDestruct(root);
        }

        Node* root = nullptr;

        void insert(int key) {
            // Create root if it doesn't exist
            if (!root) {
                root = new Node(key);
            } else {
                insertFromNode(root, key);
            }
        }

        // This DFS strategy will print the tree in sorted order O(n)
        void inOrderWalk(Node* s) {
            if (s != nullptr) {
                inOrderWalk(s->leftChild);
                std::cout << s->key << std::endl;
                inOrderWalk(s->rightChild);
            }
        }

        // Search for node with key O(h) = O(logn)
        Node* search(Node* r, int key) {
            if (r->key == key) {
                return r;
            }
            else if (key > r->key) {
                if (!r->rightChild) {
                    return nullptr; // Not in tree
                } else {
                    return search(r->rightChild, key);
                }
            } else {
                if (!r->leftChild) {
                    return nullptr;
                } else {
                    return search(r->leftChild, key);
                }
            }
        }

        // O(h) = O(logn) again since we either go down to leaf or go up toward root
        // Do opposite to find the tree predecessor
        Node* successor(Node* x) {

            if (!x->rightChild) {
                // successor will be parent of ancestor who is a left-child
                Node* p = x->parent;
                Node* y = x;
                while (p != nullptr && y != p->leftChild) {
                    y = p;
                    p = p->parent;
                }
                return p;

            } else {
                // successor will be left-most element in right subtree
                Node* y = x->rightChild;
                while (y->leftChild) {
                    y = y->leftChild;
                }
                return y;
            }

        }

        // Worst case O(n) in case we go through lots of successor cases with two children
        void remove(Node* x) {

            if (!x) return;

            // If x has no children, just remove x
            if (!x->leftChild && !x->rightChild) {

                // Handle root edge case
                if (root == x) {
                    root = nullptr;
                    delete x;
                    return;
                }
                
                if (x->parent->leftChild == x) {
                    x->parent->leftChild = nullptr;
                } else {
                    x->parent->rightChild = nullptr;
                }

                delete x;
                return;

            }

            // If node has a single child, replace x with child
            if (x->rightChild && !x->leftChild) {

                // Handle root edge case
                if (root == x) {
                    root = x->rightChild;
                    delete x;
                    return;
                }

                // Check if x itself is a left or right child
                if (x->parent->leftChild == x) {
                    x->parent->leftChild = x->rightChild;
                } else {
                    x->parent->rightChild = x->rightChild;
                }

                delete x;
                return;

            } else if (x->leftChild && !x->rightChild) {

                // Handle root edge case
                if (root == x) {
                    root = x->leftChild;
                    delete x;
                    return;
                }

                if (x->parent->leftChild == x) {
                    x->parent->leftChild = x->leftChild;
                } else {
                    x->parent->rightChild = x->leftChild;
                }

                delete x;
                return;

            }

            // If x has two children, replace x with its successor, and delete successor
            if (x->leftChild && x->rightChild) {

                // No edge cases here as successor guaranteed if x has right subtree

                Node* s = successor(x);
                x->key = s->key;
                
                remove(s);

            }
        }

        // Remove by key requires a search first
        void remove(int key) {
            remove(search(root, key));
        }
};

int main() {
    int randomArray[8] = {5, 9, 1, 5, -10, 3, 1, 6};
    BST t;
    for (int i = 0; i < 8; i++) {
        t.insert(randomArray[i]);
    }
    // t.inOrderWalk(t.root);

    // Print root and successors
    Node* r = t.root;
    while (r) {
        std::cout << r->key << ",";
        r = t.successor(r);
    }
    std::cout << std::endl;

    // Remove root
    t.remove(t.root);
    t.inOrderWalk(t.root);
}