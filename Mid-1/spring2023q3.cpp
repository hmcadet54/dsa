#include <iostream>
using namespace std;
#define N 5

bool optimal(int array[N][N], int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < N && array[x][y] > 1)
    {
        return true;
    }
    return false;
}
bool bestroutw(int array[N][N], int x, int y, int sol[N][N])
{
    if (x == N - 1 && y == N - 1)
    {
        sol[x][y] = 1;
        return true;
    }
    if (optimal(array, x, y))
    {
        sol[x][y] = 1;
        // down
        if (bestroutw(array, x + 1, y, sol))
        {
            return true;
        }
        // up
        if (bestroutw(array, x, y + 1, sol))
        {
            return true;
        }

        if (bestroutw(array, x, y + 1, sol))
        {
            return true;
        }
        // left
        if (bestroutw(array, x, y - 1, sol))
        {
            return true;
        }
        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{
    int budget[N][N] = {{1, 100, 50, 75, 0},
                      {100, 0, 80, 0, 120},
                      {50, 80, 0, 0, 90},
                      {75, 0, 0, 0, 70},
                      {0, 120, 90, 70, 0}};
    int sol[N][N] = {{1, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0}};
    int i = 0, j = 0;
    // sol[0][0] = 1;
    if (bestroutw(budget, 0, 0, sol))
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
