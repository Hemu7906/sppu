#include <iostream>
#include <vector>
using namespace std;

bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    for (int i = 0; i < col; i++)
        if (board[row][i] == 1) return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1) return false;

    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j] == 1) return false;

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int col, int n) {
    if (col >= n) return true;

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;

            if (solveNQueens(board, col + 1, n))
                return true;

            board[i][col] = 0;
        }
    }
    return false;
}

void printBoard(const vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the board (N): ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQueens(board, 0, n)) {
        cout << "One of the possible solutions:\n";
        printBoard(board, n);
    } else {
        cout << "No solution exists for N = " << n << endl;
    }

    return 0;
}
