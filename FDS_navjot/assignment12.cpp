#include <iostream>
#include <vector>
using namespace std;

const int N = 4; // N-queens problem where N = 4

bool isSafe(vector<vector<int>>& board, int row, int col) {
    int i, j;

    // Check left side of this row
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

void printBoard(vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << "----------" << endl;
}

bool solveNQueens(vector<vector<int>>& board, int col) {
    if (col >= N) {
        printBoard(board);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            res = solveNQueens(board, col + 1) || res;
            board[i][col] = 0; // Backtrack if placement doesn't lead to a solution
        }
    }

    return res;
}

int main() {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueens(board, 0)) {
        cout << "No solution exists";
    }

    return 0;
}
