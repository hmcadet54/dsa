#include <iostream>
#include <algorithm>
using namespace std;

// Custom swap function for arrays
template <typename T, size_t N>
void array_swap(T (&a)[N], T (&b)[N]) {
    for (size_t i = 0; i < N; ++i) {
        swap(a[i], b[i]);
    }
}
template <class T>
int partition(T array[], int left, int right)
{
    T pivot = {array[right][0], array[right][1]};
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (array[j][0] < pivot[0] || (array[j][0] == pivot[0] && array[j][1] < pivot[1]))
        {
            i++;
            array_swap(array[i], array[j]);
        }
    }
    array_swap(array[i + 1], array[right]);
    return i + 1;
}

template <class T>
void quicksort(T array[], int left, int right)
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
    int array[3][2] = {{1, 2}, {0, 1}, {6, 3}};
    quicksort(array, 0, 2);
    for (int i = 0; i < 3; i++)
    {
        cout << "(" << array[i][0] << "," << array[i][1] << ")";
    }
    cout << endl;
    return 0;
}
