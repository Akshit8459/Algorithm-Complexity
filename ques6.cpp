#include <iostream>
#include <vector>
using namespace std;

// Function to print the chessboard configuration
void printBoard(const vector<int>& board, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i] == j) {
                cout << "Q ";  // Queen is placed
            } else {
                cout << ". ";  // Empty space
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Backtracking function to solve the N-Queens problem
bool solveNQueens(int row, vector<int>& board, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, int n) {
    // If all queens are placed
    if (row == n) {
        printBoard(board, n);
        return true;
    }

    bool result = false;
    
    // Try placing a queen in each column of the current row
    for (int col = 0; col < n; ++col) {
        // Check if the column or diagonals are already attacked
        if (cols[col] || diag1[row - col + n - 1] || diag2[row + col]) {
            continue;
        }

        // Place the queen on the current position
        board[row] = col;
        cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;

        // Recursively place queens on the next row
        result = solveNQueens(row + 1, board, cols, diag1, diag2, n) || result;

        // Backtrack and remove the queen
        cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
    }

    return result;
}

int main() {
    int n = 8;  // Set the board size (8x8 for the standard problem)
    
    vector<int> board(n, -1);  // Board representation (index is row, value is column)
    vector<bool> cols(n, false);  // Track columns (true means occupied)
    vector<bool> diag1(2 * n - 1, false);  // Track primary diagonals
    vector<bool> diag2(2 * n - 1, false);  // Track secondary diagonals
    
    // Start the recursive backtracking process
    if (!solveNQueens(0, board, cols, diag1, diag2, n)) {
        cout << "No solution found." << endl;
    }

    return 0;
}
