#include <iostream>
using namespace std;

int maze[4][4] = {
    {1,0,0,0},
    {1,1,0,1},
    {0,1,0,0},
    {1,1,1,1}
};

int sol[4][4] = {0};

bool solveMaze(int x, int y) {

    if (x == 3 && y == 3) {
        sol[x][y] = 1;
        return true;
    }

    if (x >= 0 && x < 4 && y >= 0 && y < 4 && maze[x][y] == 1) {

        sol[x][y] = 1;

        if (solveMaze(x + 1, y))
            return true;

        if (solveMaze(x, y + 1))
            return true;

        // Backtrack
        sol[x][y] = 0;
    }

    return false;
}

int main() {

    if (solveMaze(0, 0)) {

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++)
                cout << sol[i][j] << " ";
            cout << endl;
        }

    } else {
        cout << "No Path";
    }

    return 0;
}
