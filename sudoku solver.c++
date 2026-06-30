#include <iostream>
using namespace std;

bool isSafe(int board[9][9], int row, int col, int num) {

    for (int x = 0; x < 9; x++)
        if (board[row][x] == num)
            return false;

    for (int x = 0; x < 9; x++)
        if (board[x][col] == num)
            return false;

    int sr = row - row % 3;
    int sc = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[sr + i][sc + j] == num)
                return false;

    return true;
}

bool solveSudoku(int board[9][9]) {

    int row = -1, col = -1;
    bool empty = false;

    for (int i = 0; i < 9 && !empty; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                empty = true;
                break;
            }
        }
    }

    if (!empty)
        return true;

    for (int num = 1; num <= 9; num++) {

        if (isSafe(board, row, col, num)) {

            board[row][col] = num;

            if (solveSudoku(board))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {

    int board[9][9] = {
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };

    if (solveSudoku(board)) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}
