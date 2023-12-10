#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int prim(vector<vector<pair<int, int>>>& adj, int vertices) {
    vector<int> distance(vertices, INT32_MAX);
    vector<bool> visited(vertices, false);
    vector<int> parent(vertices, -1);   

    distance[0] = 0;

    for (int i = 0; i < vertices - 1; i++) {
        int u = -1;
        for (int j = 0; j < vertices; j++) {
            if (!visited[j] && (u == -1 || distance[j] < distance[u])) {
                u = j;
            }
        }

        visited[u] = true;

        for (auto neig : adj[u]) {
            int v = neig.first;
            int w = neig.second;

            if (!visited[v] && w < distance[v]) {
                distance[v] = w;
                parent[v] = u;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < vertices; i++) {
        if (parent[i] != -1) {
            sum += distance[i];
        }
    }

    return sum;
}

int main() {
    int vertices = 3;
    int edges = 3;

    vector<vector<pair<int, int>>> adj(vertices);

    adj[0].push_back(make_pair(1, 5));
    adj[0].push_back(make_pair(2, 1));
    adj[1].push_back(make_pair(0, 5));
    adj[1].push_back(make_pair(2, 3));
    adj[2].push_back(make_pair(0, 1));
    adj[2].push_back(make_pair(1, 3));

    int sum = prim(adj, vertices);

    cout << "Sum of weights of the Minimum Spanning Tree: " << sum << endl;

    return 0;
}