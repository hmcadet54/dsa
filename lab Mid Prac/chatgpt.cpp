#include <iostream>
using namespace std;

bool isSafe(string array[5][5], int x, int y, int n, char target)
{
    if (x < n && x >= 0 && y >= 0 && y < n && array[x][y][0] == target)
    {
        return true;
    }
    return false;
}

bool findFAST(string array[5][5], int x, int y, int n, int idx)
{
    if (idx == 4)
    {
        return true; // Found "FAST"
    }

    if (isSafe(array, x, y, n, "FAST"[idx]))
    {
        char temp = array[x][y][0];
        array[x][y] = "X"; // Mark the cell as visited

        // Check in all four directions
        if (findFAST(array, x + 1, y, n, idx + 1) || // Right
            findFAST(array, x - 1, y, n, idx + 1) || // Left
            findFAST(array, x, y + 1, n, idx + 1) || // Down
            findFAST(array, x, y - 1, n, idx + 1))   // Up
        {
            return true;
        }

        array[x][y] = temp; // Reset the cell if "FAST" path is not found
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

    if (findFAST(array, 0, 0, 5, 0))
    {
        cout << "The route for FAST is found!" << endl;
    }
    else
    {
        cout << "The route for FAST is not found." << endl;
    }

    return 0;
}
