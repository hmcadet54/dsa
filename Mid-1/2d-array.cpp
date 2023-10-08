#include <iostream>
using namespace std;

void sort(int array[][5])
{
    int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            for (k = 0; k < 5; k++)
            {
                if (array[i][k] > array[i][k + 1])
                {
                    swap(array[i][k], array[i][k + 1]);
                }
            }
        }
    }
    for (i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
void dioganllySort(int array[][5])
{
    int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (j == i)
            {
                continue;
            }
            if (array[i][i] < array[j][j])
            {
                cout << "I am in " << i << " Line and on " << j << " element" << endl;
                swap(array[i][i], array[j][j]);
            }
        }
    }
    for (i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j == i)
            {
                cout << "[";
                cout << array[i][j];
                cout << "]";
            }
            else
            {
                cout << array[i][j] << " ";
            }
        }
        cout << endl;
    }
}
void onlynthcolsort(int array[][5], int n)
{
    int i = 0, j = 0, k = 0, l = 0, m = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (array[i][n] < array[j][n])
            {
                swap(array[i][n], array[j][n]);
            }
        }
    }
    for (i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j == n)
            {
                cout << "[";
                cout << array[i][j];
                cout << "]";
            }
            else
            {
                cout << array[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int array[5][5] = {
        {45, 23, 78, 33, 65},
        {19, 19, 87, 27, 6},
        {91, 42, 58, 73, 88},
        {14, 10, 67, 21, 50},
        {3, 1, 77, 41, 23}};

    // sort(array);
    cout << "=====================================" << endl;
    // dioganllySort(array);
    onlynthcolsort(array, 1);
}