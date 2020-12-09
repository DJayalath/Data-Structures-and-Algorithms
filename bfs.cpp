#include <iostream>
#include <queue>
#include <set>

#include "graph.hpp"

// O(V + E) using adjacency list
// O(V^2) using adjacency matrix
void bfs(Graph* g, int start) {

    std::queue<int> queue;
    std::set<int> discovered;

    queue.push(start);
    discovered.insert(start);

    while(!queue.empty()) {

        int v = queue.front();
        queue.pop();

        std::cout << v << std::endl;

        for (int c : g->adj[v]) {
            if (discovered.find(c) == discovered.end()) {
                discovered.insert(c);
                queue.push(c);
            }
        }
    }

}

int main() {
    Graph g = Graph::ExampleGraph();
    bfs(&g, 2);
}