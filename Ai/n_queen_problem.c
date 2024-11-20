#include <stdio.h>
#include <stdbool.h>

#define N 4  // Size of the chessboard (4x4)

// Function to print the chessboard with queens placed
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check the column for any queens already placed
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Function to solve the N-Queen problem using backtracking
bool solveNQueens(int board[N][N], int row) {
    // If all queens are placed
    if (row >= N) {
        printSolution(board);  // Print the board when a solution is found
        return false;  // Return false to continue searching for other solutions
    }

    // Consider this row and try placing this queen in all columns
    for (int col = 0; col < N; col++) {
        // Check if it's safe to place a queen in the current position
        if (isSafe(board, row, col)) {
            board[row][col] = 1; // Place the queen

            // Recur to place the next queen
            if (solveNQueens(board, row + 1)) {
                return true;
            }

            // If placing queen in board[row][col] doesnt lead to a solution
            board[row][col] = 0; // Backtrack
        }
    }

    // If no place is found, return false
    return false;
}

int main() {
    int board[N][N] = {0}; // Initialize the board with 0s

    printf("All solutions for 4 Queens on a 4x4 board:\n");
    solveNQueens(board, 0);

    return 0;
}
