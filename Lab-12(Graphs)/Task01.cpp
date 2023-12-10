#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));  
        
    }

    vector<int> distance(vertices);
    for (int i=0;i<vertices;i++)
    {
        distance[i]=INT32_MAX;
    }

    set<pair<int,int>>set_storing;

    distance[source]=0;
    set_storing.insert(make_pair(0,source));

    while(!set_storing.empty())
    {
        auto top=*(set_storing.begin());
        int n_dis=top.first;
        int only_n=top.second;

        set_storing.erase(set_storing.begin());


        for (auto neig: adj[only_n])
        {
            if(n_dis+neig.second<distance[neig.first])
            {
                auto rec= set_storing.find(make_pair(distance[neig.first],neig.first));
                if(rec!=set_storing.end())
                {
                    set_storing.erase(rec);
                }

                distance[neig.first]=n_dis+neig.second;
                set_storing.insert(make_pair(distance[neig.first],neig.first));
            }
        }
    }
    return distance;
}

int main()
{
    // int vertices, edges;
    // cout << "Enter the number of vertices: ";
    // cin >> vertices;
    // cout << "Enter the number of edges: ";
    // cin >> edges;

    // vector<vector<int>> vec(edges, vector<int>(3));

    // cout << "Enter the edges in the format (u v w):" << endl;
    // for (int i = 0; i < edges; i++)
    // {
    //     cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
    // }

    // int source;
    // cout << "Enter the source vertex: ";
    // cin >> source;
    int vertices = 6; // Number of vertices
    int edges = 9; // Number of edges

    vector<vector<int>> vec = {
        {0, 1,1}, // Edge 1: u=0, v=1, w=4
        {0, 2,5}, // Edge 2: u=0, v=2, w=2
        {1, 2, 2}, // Edge 3: u=1, v=2, w=1
        {1, 3, 2}, // Edge 4: u=1, v=3, w=5
        {1,4,1}, // Edge 5: u=2, v=3, w=8
        {2, 4,2}, // Edge 6: u=2, v=4, w=10
        {3, 4, 3},
        {3, 5, 1}, // Edge 7: u=3, v=4, w=2
        {4,5,2} // Edge 7: u=3, v=4, w=2
         // Edge 7: u=3, v=4, w=2
    };
    int source=5;

    vector<int> distance = dijkstra(vec, vertices, edges, source);

    cout << "Shortest distances from the source vertex:" << endl;
    for (int i = 0; i < vertices; i++)
    {
        cout << distance[i] << " ";
    }
    cout << endl;
}