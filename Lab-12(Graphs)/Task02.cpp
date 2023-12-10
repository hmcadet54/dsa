#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

void printAdjacencyList(const unordered_map<int, list<int>>& adj, int vertices) {
    for (int i = 0; i < vertices; i++) {
        cout << "Node " << i << " is connected to: ";
        if (adj.count(i)) 
        {
            vector<int> neighbors(adj.at(i).begin(), adj.at(i).end());
            sort(neighbors.begin(), neighbors.end());
            for (const auto& neighbor : neighbors) {
                cout << neighbor << ", ";
            }
        }
        cout << endl;
    }
}

int main()
{
   
    int vertices = 5; 
    int edges = 7; 

    vector<vector<int>> vec = {
        {0,1}, 
        {0,4}, 
        {4,1}, 
        {4,3}, 
        {1,3}, 
        {1,2}, 
        {3,2} 
    };
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);  
    }
    printAdjacencyList(adj, vertices);

}