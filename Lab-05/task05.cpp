#include <iostream>
using namespace std;
#define N 4

bool issafe(int array[N][N], int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < N && array[x][y] >= 1)
    {
        return true;
    }
    return false;
}
bool solveMazeUtil(int array[N][N], int x, int y, int sol[N][N])
{
    if (x == N - 1 && y == N - 1)
    {
        sol[x][y] = 1;
        return true;
    }
    if (issafe(array, x, y))
    {
        int jump = array[x][y];
        for (int i = 1; i <= jump; i++)
        {
            if (solveMazeUtil(array, x + i, y, sol))
            {   
                sol[x][y]=1;
                return true;
            }
            if (solveMazeUtil(array, x, y+ i, sol))
            {
                sol[x][y]=1;
                return true;
            }
        }
        sol[x][y]=0;
        return false;
    }
    return false;
}

int main()
{
    int maze[N][N] = {{2, 1, 0, 0},
                      {3, 0, 0, 1},
                      {0, 1, 0, 1},
                      {0, 0, 0, 1}};

    int sol[N][N] = {{1, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}};
    int i = 0, j = 0;
    if (solveMazeUtil(maze, 0, 0, sol))
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
