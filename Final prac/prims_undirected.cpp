#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a node in the graph
struct Node {
    int vertex, weight;
};

// Function to compare two nodes based on their weights
struct CompareNode {
    bool operator()(const Node& n1, const Node& n2) {
        return n1.weight > n2.weight;
    }
};

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(vector<vector<Edge>>& graph, int startVertex) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    vector<int> parent(numVertices, -1);
    vector<int> weight(numVertices, INT_MAX);

    priority_queue<Node, vector<Node>, CompareNode> pq;

    // Start with the given start vertex
    pq.push({startVertex, 0});
    weight[startVertex] = 0;

    while (!pq.empty()) {
        int u = pq.top().vertex;
        pq.pop();

        visited[u] = true;

        for (const auto& edge : graph[u]) {
            int v = edge.dest;
            int w = edge.weight;

            if (!visited[v] && w < weight[v]) {
                parent[v] = u;
                weight[v] = w;
                pq.push({v, w});
            }
        }
    }

    // Print the minimum spanning tree
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 1; i < numVertices; i++) {
        cout << parent[i] << " - " << i << endl;
    }
}

int main() {
    // Create a graph
    int numVertices = 5;
    int numEdges = 7;

    vector<vector<Edge>> graph(numVertices);

    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    for (const auto& edge : edges) {
        int src = edge.src;
        int dest = edge.dest;
        int weight = edge.weight;
        graph[src].push_back({src, dest, weight});
        graph[dest].push_back({dest, src, weight});
    }

    int startVertex = 0;

    // Find the minimum spanning tree
    primMST(graph, startVertex);

    return 0;
}
