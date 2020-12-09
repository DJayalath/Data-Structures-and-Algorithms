#include <iostream>
#include <stack>
#include <set>

#include "graph.hpp"

// O(V + E) using adjacency list
// O(V^2) using adjacency matrix
// O(b^d) = O(n) in a tree with depth d and branching factor b
void dfs(Graph* g, int start) {

    std::stack<int> stack;
    std::set<int> discovered;

    stack.push(start);
    discovered.insert(start);

    while(!stack.empty()) {

        int v = stack.top();
        stack.pop();

        std::cout << v << std::endl;

        for (int c : g->adj[v]) {
            if (discovered.find(c) == discovered.end()) {
                discovered.insert(c);
                stack.push(c);
            }
        }
    }

}

// More naturally expressed recursively!
void rdfs(Graph* g, int v, std::set<int>* discovered) {

    discovered->insert(v);

    std::cout << v << std::endl;

    for (int c : g->adj[v]) {
        if (discovered->find(c) == discovered->end()) {
            rdfs(g, c, discovered);
        }
    }

}

int main() {
    Graph g = Graph::ExampleGraph();
    dfs(&g, 2);
    rdfs(&g, 2, new std::set<int>);
}