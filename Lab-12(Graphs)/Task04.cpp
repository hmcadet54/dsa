#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <vector>
#include <list>
#include <climits>

using namespace std;

vector<int> bellmanFord(vector<vector<int>>& edges, int vertices, int source) {
    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;

    for (int i = 0; i < vertices - 1; i++) {
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
            return {-1}; // Negative cycle detected
        }
    }

    return distance;
}

int main() {
    int vertices = 3; // Number of vertices
    vector<vector<int>> edges = {
        {0, 1, 5}, // Edge 1: u=0, v=1, w=5
        {1, 0, 3}, // Edge 2: u=1, v=0, w=3
        {1, 2, -1}, // Edge 3: u=1, v=2, w=-1
        {2, 0, 1} // Edge 4: u=2, v=0, w=1
    };
    int source = 2;

    vector<int> distance = bellmanFord(edges, vertices, source);

    cout << "Shortest distances from the source vertex:" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << distance[i] << " ";
    }
    cout << endl;

    return 0;
}
