#include <iostream>
#include <vector>

using namespace std;

// Function to check if placing a queen at (row, col) is safe
bool isSafe(const vector<int> &board, int row, int col)
{
    // Check if there is a queen in the same column
    for (int i = 0; i < row; ++i)
    {
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row)
        {
            return false;
        }
    }
    return true;
}

// Recursive function to solve the N-queens problem
void solveNQueens(int n, int row, vector<int> &board, vector<vector<int>> &solutions)
{
    if (row == n)
    {
        // All queens are placed, add the solution to the list
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col)
    {
        if (isSafe(board, row, col))
        {
            // Place the queen and move to the next row
            board[row] = col;
            solveNQueens(n, row + 1, board, solutions);
            // Backtrack: remove the queen from the current position
            board[row] = -1;
        }
    }
}

// Function to print the solutions
void printSolutions(const vector<vector<int>> &solutions)
{
    for (const auto &solution : solutions)
    {
        cout << "Solution:" << endl;
        for (int i = 0; i < solution.size(); ++i)
        {
            for (int j = 0; j < solution.size(); ++j)
            {
                if (solution[i] == j)
                {
                    cout << "Q ";
                }
                else
                {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{
    const int n = 4;          // 4-queens problem
    vector<int> board(n, -1); // Initialize the board with -1
    vector<vector<int>> solutions;

    solveNQueens(n, 0, board, solutions);

    if (solutions.empty())
    {
        cout << "No solutions found for the " << n << "-queens problem." << endl;
    }
    else
    {
        cout << "All possible configurations for the " << n << "-queens problem:" << endl;
        printSolutions(solutions);
    }

    return 0;
}
