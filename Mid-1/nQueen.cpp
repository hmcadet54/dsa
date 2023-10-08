#include <iostream>
using namespace std;

bool isSafe(int **array, int x, int y, int n)
{
    // check rows
    for (int rows = 0; rows < x; rows++)
    {
        if (array[rows][y] == 1)
        {
            return false;
        }
    }
    // check left diognal
    int row = x;
    int col = y;
    while (row >= 0 && col >= 0)
    {
        if (array[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }

    // check right diognal
    row = x;
    col = y;
    while (row >= 0 && col < n)
    {
        if (array[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}

bool nQueen(int **array, int x, int n)
{
    if (x >= n)
    {
        return true;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(array, x, col, n))
        {
            array[x][col] = 1;

            if (nQueen(array, x + 1, n))
            {
                return true;
            }
            array[x][col] = 0;
        }
    }
    return false;
}
int main()
{
    int n;
    cout<<"Enter Numbber: ";
    cin >>n;

    int **array = new int*[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            array[i][j] = 0;
        }
    }
    if (nQueen(array, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution found." << endl;
    }
    return 0;
}