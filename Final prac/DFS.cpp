#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<set>
#include<queue>

using namespace std;

void make_adj(unordered_map<int, set<int>>&adj,vector<pair<int,int>>&edges)
{
    for (int i=0;i<edges.size();i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].insert(v);
        adj[v].insert(u);
    }
}

void create_dfs(unordered_map<int, set<int>>&adj,unordered_map<int , bool> &visited,vector<int>&answer, int node)
{
    visited[node]=1;
    answer.push_back(node);

    for (auto i: adj[node])
    {
        if(!visited[i])
        {
            create_dfs(adj,visited,answer,i);
        }
    }
}

vector<int> DFS(int vertex, vector<pair<int,int>>edges)
{
    unordered_map<int, set<int>>adj;
    vector<int>answer;
    unordered_map<int , bool> visited;

    make_adj(adj,edges);

    for (int i=0;i<vertex;i++)
    {
        if(!visited[i])
        {
            create_dfs(adj,visited,answer,i);
        }
    }
    return answer;
}

void printAdjList(const unordered_map<int, set<int>>& adj)
{
    for (const auto& pair : adj)
    {
        cout << "Adjacency list for vertex " << pair.first << ": ";
        for (const auto& neighbor : pair.second)
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main()
{
    int vertex = 5;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 4}};
    
    vector<int> result = DFS(vertex, edges);
    
    cout << "DFS traversal: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    unordered_map<int, set<int>> adj;
    make_adj(adj, edges);
    printAdjList(adj);
    
    return 0;
}
