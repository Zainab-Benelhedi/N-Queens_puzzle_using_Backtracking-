#include <iostream>
#include <vector>
using namespace std;

class NQueens {
private:
    int N;
    vector<vector<int>> board;

public:
    // Constructor
    NQueens(int n) {
        N = n;
        for (int i = 0; i < N; i++) {
            vector<int> row;
            for (int j = 0; j < N; j++) {
                row.push_back(0);
            }
            board.push_back(row);
        }
    }

    // Function to check if it's safe to place a queen
    bool satisfiesConstraints(int row, int col) {
        // 1. Check left side of this row
        for (int j = 0; j < col; j++) {
            if (board[row][j] == 1)
                return false;
        }

        // 2. Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1)
                return false;
        }

        // 3. Check lower-left diagonal
        for (int i = row, j = col; i < N && j >= 0; i++, j--) {
            if (board[i][j] == 1)
                return false;
        }

        return true;
    }

    // Backtracking function
    bool solveWithBacktracking(int col) {

        // Base case: all queens are placed
        if (col >= N)
            return true;

        // Try placing queen in all rows of this column
        for (int i = 0; i < N; i++) {

            if (satisfiesConstraints(i, col)) {

                // Place queen
                board[i][col] = 1;

                // Recur for next column
                if (solveWithBacktracking(col + 1))
                    return true;

                // Backtrack (remove queen)
                board[i][col] = 0;
            }
        }

        // No valid position found
        return false;
    }

    // Solve function
    void solve() {
        if (!solveWithBacktracking(0)) {
            cout << "No solution exists" << endl;
            return;
        }

        printBoard();
    }

    // Print board
    void printBoard() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;

    NQueens q(n);
    q.solve();

    return 0;
}