#include <iostream>
#include <cstring>
#include <set>

#include "graph.hpp"

// Weighted quick union with path compression
// id points to parent in tree
class DisjointSet {

private:

    int* id;
    int* size;
    int length;
    int connectedComponents;

    int findRoot(int p) {

        while (p != id[p]) {
            id[p] = id[id[p]]; // Path compression
            p = id[p];
        }

        return p;

    }

public:

    // O(n)
    DisjointSet(int length) : length(length), connectedComponents(length) {
        id = new int[length];
        for (int i = 0; i < length; i++) id[i] = i;
        size = new int[length];
        memset(size, 1, sizeof(size));
    }

    bool isConnected(int p, int q) {
        return findRoot(p) == findRoot(q);
    }

    // O(log*n)
    int find(int p) {
        return findRoot(p);
    }

    // O(log*n)
    void doUnion(int p, int q) {

        int rootP = findRoot(p);
        int rootQ = findRoot(q);

        // No need if already connected
        if (rootP == rootQ) return;

        // Merge smaller tree into larger tree
        // Guarantees at most log n depth for finding roots
        // (log*(n) with path compression)
        if (size[rootP] < size[rootQ]) {
            id[rootP] = rootQ;
            size[rootQ] += size[rootP];
        } else {
            id[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }

        // Decrease number of components
        connectedComponents--;

    }

    int getConnectedComponents() {
        return connectedComponents;
    }

};

// Checks for cycles in an UNDIRECTED graph
bool containsCycle(Graph* g) {

    DisjointSet uf(g->numVertices);
    
    // Loop over all edges
    for (int i = 0; i < g->numVertices; i++) {
        for (auto j : g->adj[i]) {
            // If we have previously connected these components
            // then a cycle must exist
            if (uf.isConnected(i, j)) {
                // Cycle exists
                return true;
            } else {
                uf.doUnion(i, j);
            }
        }
    }

    return false;
}


int main() {

    Graph g = Graph::ExampleGraph();
    Graph g2(2);
    g2.addEdge(0, 1);
    std::cout << containsCycle(&g) << std::endl;
    std::cout << containsCycle(&g2) << std::endl;

    return 0;
}