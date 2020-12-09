#include <string>
#include <list>

// Simple adjacency list representation of a graph
// Uses an array of lists (easy to add edges but not to add new nodes)

class Graph
{
public:

    int numVertices; // Number of vertices
    std::list<int>* adj; // Array of adjacency lists

    Graph(int V);
    void addEdge(int v, int w); 

    static Graph ExampleGraph() {
        Graph g(4);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);
        return g;
    }
};
 
Graph::Graph(int numVertices) : numVertices(numVertices)
{
    adj = new std::list<int>[numVertices];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}