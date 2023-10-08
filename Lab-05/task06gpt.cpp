#include <iostream>
using namespace std;

#define N 4

bool issafe(int mat[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && mat[x][y] != 0);
}

bool findPath(int mat[N][N], int x, int y, int sol[N][N]) {
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    if (issafe(mat, x, y)) {
        int maxJump = mat[x][y];
        
        // Try to move forward (right)
        for (int i = 1; i <= maxJump; i++) {
            if (findPath(mat, x, y + i, sol)) {
                sol[x][y] = 1;
                return true;
            }
            if (findPath(mat, x + i, y, sol)) {
                sol[x][y] = 1;
                return true;
            }
        }
        sol[x][y]=1;
        return
    }

    return false;
}

int main() {
    int mat[N][N] = {{2, 1, 0, 0},
                     {3, 0, 0, 1},
                     {0, 1, 0, 1},
                     {0, 0, 0, 1}};

    int sol[N][N] = {{0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}};

    bool found = findPath(mat, 0, 0, sol);

    if (found) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No path found." << endl;
    }

    return 0;
}
     