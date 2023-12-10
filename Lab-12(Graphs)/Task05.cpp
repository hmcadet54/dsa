
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& grid, int row, int col) {
    int numRows = grid.size();
    int numCols = grid[0].size();

    if (row < 0 || row >= numRows || col < 0 || col >= numCols || grid[row][col] != 1) {
        return;
    }

    grid[row][col] = -1; // Mark the current land as visited

    // Recursively visit all adjacent lands
    dfs(grid, row - 1, col); // Up
    dfs(grid, row + 1, col); // Down
    dfs(grid, row, col - 1); // Left
    dfs(grid, row, col + 1); // Right
    dfs(grid, row - 1, col - 1); // Diagonal: Up-Left
    dfs(grid, row - 1, col + 1); // Diagonal: Up-Right
    dfs(grid, row + 1, col - 1); // Diagonal: Down-Left
    dfs(grid, row + 1, col + 1); // Diagonal: Down-Right
}

int countIslands(vector<vector<int>>& grid) {
    int numRows = grid.size();
    int numCols = grid[0].size();
    int count = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (grid[i][j] == 1) {
                count++;
                dfs(grid, i, j);
            }
        }
    }

    return count;
}

int main() {
    vector<vector<int>> grid = {
        {0, 1},
        {1, 0},
        {1, 1},
        {1, 0}
    };

    int numIslands = countIslands(grid);
    cout << "Number of islands: " << numIslands << endl;

    return 0;
}
