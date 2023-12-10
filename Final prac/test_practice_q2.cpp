#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> closest_hoses(vector<int>& array_vector, int k, int X)
{
    vector<int> result;
    for (int i = 0; i < array_vector.size(); i++)
    {
        if (array_vector[i] >= X)
        {
            result.push_back(array_vector[i]);
        }
    }
    sort(result.begin(), result.end());
    if (result.size() > k)
    {
        result.resize(k);
    }
    return result;
}

int main()
{
    int N = 6;
    int array[N] = {10, 2, 14, 4, 7, 6};
    cout << "Enter Lucy's House Number: ";
    int X;
    cin >> X;
    vector<int> array_vector;
    for (int i = 0; i < N; i++)
    {
        array_vector.push_back(array[i]);
    }
    sort(array_vector.begin(), array_vector.end());
    cout << "Enter Number of houses you want to find which are closest to: ";
    int k;
    cin >> k;
    vector<int> result = closest_hoses(array_vector, k, X);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    //  vector<array<int, N> > vect;
    // vect.push_back({ 1, 2, 3 });
    // vect.push_back({ 10, 20, 30 });
    // vect.push_back({ 30, 60, 90 });
    // vect.push_back({ 10, 20, 10 });
}