// Quick sort
#include <iostream>
#include <algorithm>
using namespace std;

template <class T1, class T2>
int partition(pair<T1, T2> array[], int left, int right)
{
    pair<T1, T2> pivot = array[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[right]);
    return i + 1;
}
template <class T1, class T2>
void quicksort(pair<T1, T2> array[], int left, int right)
{
    if (left < right)
    {
        int pivot = partition(array, left, right);
        quicksort(array, left, pivot - 1);
        quicksort(array, pivot + 1, right);
    }
}

int main()
{
    pair<int, string> array[3] = {make_pair(1, "abdullah"), make_pair(0, "haroon"), make_pair(6, "shafiq")};
    quicksort(array, 0, 2);
    for (int i = 0; i < 3; i++)
    {
        cout << "(" << array[i].first << "," << array[i].second << ")";
    }
    cout << endl;
    return 0;
}