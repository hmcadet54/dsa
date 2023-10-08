#include <iostream>
using namespace std;
const int MAX_CITIES = 10;
int cities[MAX_CITIES][MAX_CITIES] = {
    {0, 100, 50, 75, 0},
    {100, 0, 80, 0, 120},
    {50, 80, 0, 0, 90},
    {75, 0, 0, 0, 70},
    {0, 120, 90, 70, 0}};
int budget = 200;
int max_cities_visited = 0;


    int best_route[MAX_CITIES];
int current_route[MAX_CITIES];
void find_route(int current_city, int current_distance, int cities_visited)
{
    if (current_distance > budget || cities_visited > max_cities_visited)
    {
        return;
    }
    if (cities_visited == MAX_CITIES)
    {
        max_cities_visited = cities_visited;
        for (int i = 0; i < MAX_CITIES; i++)
        {
            best_route[i] = current_route[i];
        }
        return;
    }
    for (int i = 0; i < MAX_CITIES; i++)
    {
        if (cities[current_city][i] > 0)
        {
            current_distance += cities[current_city][i];
            current_route[cities_visited] = i;
            find_route(i, current_distance, cities_visited + 1);
            current_distance -= cities[current_city][i];
        }
    }
}
int main()
{
    find_route(0, 0, 1);
    cout << "Optimal route: ";
    for (int i = 0; i < max_cities_visited; i++)
    {
        cout << best_route[i] << " ";
    }
    cout << endl;
    cout << "Number of cities visited: " << max_cities_visited << endl;
    return 0;
}