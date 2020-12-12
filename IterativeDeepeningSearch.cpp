#include <iostream>
#include <set>

#include "Graph.hpp"

// Depth limited search applied to increasing values of n until solution found or failure
// Complete and optimal (if step cost is 1)

// O(b^d) time (on trees)
// O(bd) space (LINEAR!!)

// Captures desirable time complexity of BFS with linear memory of DFS/DLS

// NOTE: Really this should be done on trees. If we want to do graphs then modify
// to ensure we don't end up in loops with a 'discovered' set (or mark nodes discovered).

// Recursive depth-limited search
void rdls(Graph* g, int v, int depth, int limit) {

    std::cout << v << std::endl;

    if (depth == limit) return;

    for (int c : g->adj[v]) {
        rdls(g, c, depth + 1, limit);
    }

}

#define MAX_DEPTH 10
// Iterative deepening search
void ids(Graph* g, int v) {
    for (int limit = 1; limit < MAX_DEPTH; limit++) {
        rdls(g, v, 0, limit);
    }
}

int main() {
    Graph g = Graph::ExampleGraph();
    ids(&g, 2);
}