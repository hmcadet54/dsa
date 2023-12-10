#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>

using namespace std;

void DFS_traversalUtil(int v, unordered_map<int, list<int>> &adjacent_elem, vector<bool> &visited)
{
    visited[v] = true;
    cout << v << " ";

    for (auto i = adjacent_elem[v].begin(); i != adjacent_elem[v].end(); ++i)
    {
        if (!visited[*i])
        {
            DFS_traversalUtil(*i, adjacent_elem, visited);
        }
    }
}

void DFS_traversal(int v, unordered_map<int, list<int>> &adjacent_elem)
{
    vector<bool> visited(adjacent_elem.size(), false);
    DFS_traversalUtil(v, adjacent_elem, visited);
}

void BFS_traveral(int v, unordered_map<int, list<int>> &adjacent_elem)
{
    vector<bool> visited(adjacent_elem.size(), false);
    visited[v] = true;

    queue<int> q;
    q.push(v);

    while (!q.empty())
    {
        v = q.front();
        cout << v << " ";
        q.pop();

        for (auto i = adjacent_elem[v].begin(); i != adjacent_elem[v].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
}

int main()
{

    int vertices = 7;
    int edges = 12;
    vector<vector<int>> vec =
        {
            {0, 1, 1},
            {0, 2, 5},
            {1, 3, 8},
            {1, 2, 4},
            {2, 3, 6},
            {2, 5, 2},
            {1, 4, 7},
            {3, 4, 11},
            {3, 5, 9},
            {4, 5, 3},
            {4, 6, 10},
            {5, 6, 12}};

    unordered_map<int, list<int>> adjacent_elem;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];

        adjacent_elem[u].push_back(v);
        adjacent_elem[v].push_back(u);
    }

    int source = 5;

    cout << "DFS traversal: ";
    DFS_traversal(source, adjacent_elem);
    cout << endl;

    cout << "BFS traversal: ";
    BFS_traveral(source, adjacent_elem);
    cout << endl;

    return 0;
}