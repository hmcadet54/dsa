#include <iostream>
using namespace std;

bool isSafe(string array[5][5], int x, int y, int n)
{
    if (x < n && x >= 0 && y >= 0 && y <= n && (array[x][y] == "F"||array[x][y] == "A"||array[x][y] == "S"||array[x][y] == "T"))
    {
        cout << "I am HERE ";
        return true;
    }
    return false;
}

bool rat(string array[5][5], int x, int y, int n, int solve[5][5])
{
    if (x == 4 && y == 4 &array[x][y]=="T")
    {
        solve[x][y] = 1;
        return true;
    }

    if (isSafe(array, x, y, n))
    {
        solve[x][y]=1;
        if (rat(array, x + 1, y, n, solve))
        {
            return true;
        }
        if (rat(array, x, y + 1, n, solve))
        {
            return true;
        }
        solve[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{

    string array[5][5] = {{"F", "D", "K", "F", "G"},
                          {"A", "C", "L", "A", "0"},
                          {"S", "F", "A", "S", "T"},
                          {"T", "C", "P", "T", "G"},
                          {"W", "A", "B", "Q", "X"}};

    int solve[5][5] = {{1, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0}

    };

    if (rat(array, 0, 0, 5, solve))
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