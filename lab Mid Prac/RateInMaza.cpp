#include <iostream>
using namespace std;

bool isSafe(int array[5][5], int x, int y, int n)
{
    if (x < n && x >= 0 && y >= 0 && y <= n && array[x][y] >= 1)
    {
        return true;
    }
    return false;
}

bool rat(int array[5][5], int x, int y, int n, int solve[5][5])
{
    if (x == n - 1 && y == n - 1)
    {
        solve[x][y] = 1;
        return true;
    }

    if (isSafe(array, x, y, n))
    {
        solve[x][y] = 1;
        if (rat(array, x + 1, y, n, solve))
        {
            return true;
        }
        if (rat(array, x, y + 1, n, solve))
        {
            return true;
        }
        if (rat(array, x - 1, y, n, solve))
        {
            return true;
        }
        if (rat(array, x, y - 1, n, solve))
        {
            return true;
        }
        solve[x][y] = 0;
        return false;
    }
    return false;
}
bool rat2(int array[5][5], int x, int y, int n, int solve[5][5])
{
    if (x == n - 1 && y == n - 1)
    {
        solve[x][y] = 1;
        return true;
    }

    if (isSafe(array, x, y, n))
    {
        int jump = array[x][y];
        for (int i = 1; i <= jump; i++)
        {
            if (rat2(array, x + i, y, n, solve))
            {
                solve[x][y] = 1;

                return true;
            }
            if (rat2(array, x, y + i, n, solve))
            {
                solve[x][y] = 1;
                return true;
            }
        }
        solve[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{

    int array[5][5] = {{2, 2, 1, 1, 0},
                       {0, 0, 3, 0, 0},
                       {1, 0, 0, 0, 0},
                       {0, 0, 2, 0, 1},
                       {0, 0, 3, 0, 0}};

    int solve[5][5] = {{1, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0}

    };

    if (rat2(array, 0, 0, 5, solve))
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << solve[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "The path do";
    }
}