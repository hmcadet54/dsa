#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <vector>
#include <list>
#include <climits>

using namespace std;

vector<string> dijkstra(vector<vector<int>> &vec, int vertices, int edges, char source)
{
    // create adjacency list
    unordered_map<char, list<pair<char, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        char u = vec[i][0];
        char v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
    }

    vector<int> distance(vertices, INT_MAX);
    distance[source - 'A'] = 0;

    set<pair<int, char>> set_storing;
    set_storing.insert(make_pair(0, source));

    while (!set_storing.empty())
    {
        auto top = *(set_storing.begin());
        int n_dis = top.first;
        char only_n = top.second;

        set_storing.erase(set_storing.begin());

        for (auto neig : adj[only_n])
        {
            if (n_dis + neig.second < distance[neig.first - 'A'])
            {
                auto rec = set_storing.find(make_pair(distance[neig.first - 'A'], neig.first));
                if (rec != set_storing.end())
                {
                    set_storing.erase(rec);
                }

                distance[neig.first - 'A'] = n_dis + neig.second;
                set_storing.insert(make_pair(distance[neig.first - 'A'], neig.first));
            }
        }
    }

    vector<string> shortestPaths;
    for (int i = 0; i < vertices; i++)
    {
        string path = "";
        char vertex = 'A' + i;
        if (distance[i] != INT_MAX)
        {
            path += vertex;
            path += "->";
            path += (char)(distance[i] + '0');
        }
        else
        {
            path += vertex;
            path += "->INF";
        }
        shortestPaths.push_back(path);
    }

    return shortestPaths;
}

int main()
{
    int vertices = 6; // Number of vertices
    int edges = 9;    // Number of edges

    vector<vector<int>> vec = {
        {'A', 'B', 1}, // Edge 1: u='A', v='B', w=1
        {'A', 'C', 5}, // Edge 2: u='A', v='C', w=5
        {'B', 'C', 2}, // Edge 3: u='B', v='C', w=2
        {'B', 'D', 2}, // Edge 4: u='B', v='D', w=2
        {'B', 'E', 1}, // Edge 5: u='B', v='E', w=1
        {'C', 'E', 2}, // Edge 6: u='C', v='E', w=2
        {'D', 'E', 3}, // Edge 7: u='D', v='E', w=3
        {'D', 'F', 1}, // Edge 8: u='D', v='F', w=1
        {'E', 'F', 2}  // Edge 9: u='E', v='F', w=2
    };
    char source = 'A'; // Change the source vertex to 'A'

    vector<string> shortestPaths = dijkstra(vec, vertices, edges, source);

    cout << "Shortest distances from the source vertex:" << endl;
    for (int i = 0; i < vertices; i++)
    {
        cout << shortestPaths[i] << " ";
    }
    cout << endl;
}