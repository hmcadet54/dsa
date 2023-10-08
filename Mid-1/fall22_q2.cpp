// Given a square maze containing positive numbers, find a path from the corner cell (marked as 2 in
// bold) to the middle cell (marked as 0 in bold). You can move exactly ‘n’ steps from any cell in two
// directions i.e. right and down. where n is value of the cell. For instance, if a cell has a value 2, the
// number 2 indicates that movement along 2 cells are allowed. These 2 cells can be taken in any
// combination and in any of the allowable direction. For instance, 1 step right and 1 step down will be
// allowed; however, 2 cells right and 2 cells down will not be allowed as this will count to 4 steps in
// total. The movement should not exceed the boundary.
// Your task is to write a function using recursion with backtracking to find a path from corner cell to
// middle cell in maze.
// Sample Input: 5 x 5 maze
// [ 2, 2, 4, 4, 3,]
// [ 3, 4, 3, 2, 2,]
// [ 1, 1, 0, 3, 2,]
// [ 3, 2, 2, 1, 2,]
// [ 3, 3, 4, 3, 1,]
// Where cell (0,0) with value three is the source and the destination is (2,2) with value 0.


#include <iostream>
using namespace std;
#define N 5

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
    if (x == 2 && y == 2)
    {
        sol[x][y] = 1;
        return true;
    }
    if (issafe(array, x, y))
    {
        int jump = array[x][y];
        for (int i = 1; i <= jump; i++)
        {
            if (array[x][y] > 0)
            {
                if (solveMazeUtil(array, x + i, y, sol))
                {
                    sol[x][y] = 1;
                    // if (array[x][y] == 0)
                    // {
                    //     return true;
                    // }
                    return true;
                }
                if (solveMazeUtil(array, x, y + i, sol))
                {
                    sol[x][y] = 1;
                    // if (array[x][y] == 0)
                    // {
                    //     return true;
                    // }
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{
    int maze[N][N] = {{2, 2, 4, 4, 3},
                      {2, 4, 3, 2, 2},
                      {1, 1, 0, 3, 2},
                      {3, 2, 2, 1, 2},
                      {3, 3, 4, 3, 1}};

    int sol[N][N] = {{1, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0}};
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
