#include <iostream>
#include <vector>
using namespace std;

void insertion(vector<pair<string,int>> vec)
{
    
}

int main()
{
    vector<pair<string, int>> vec;
    string pos[8] = {"Emp",
                     "CFO",
                     "MGR",
                     "Emp",
                     "VP",
                     "CTO",
                     "MGR",
                     "CEO"};
    int number[8] = {6, 3, 5, 6, 4, 2, 5, 1};
    for (int i = 0; i < 8; i++)
    {
        vec.push_back(make_pair(pos[i], number[i]));
    }
    for (const auto &element : vec)
    {
        cout << element.first << ": " << element.second << endl;
    }
}
