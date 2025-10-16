#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
 
// Function prototypes 
void printBoard(int** board, int n); 
bool isSafe(int** board, int row, int col, int n); 
bool solveNQ(int** board, int row, int n); 
 
int main() 
{ 
    int n; 
    printf("Enter the number of queens (board size n): "); 
    scanf("%d", &n);  // input number of queens 
 
    if (n <= 0) 
    { 
        printf("Please enter a positive number for the board size.\n"); 
        return 1; 
    } 
 
    // Allocate memory for chess board 
    int** board = (int**)malloc(n * sizeof(int*)); 
    if (board == NULL) 
    { 
        printf("Memory allocation failed.\n"); 
        return 1; 
    } 
 
    for (int i = 0; i < n; i++) 
    { 
        board[i] = (int*)malloc(n * sizeof(int)); 
        if (board[i] == NULL) 
        { 
            printf("Memory allocation failed.\n"); 
            for (int j = 0; j < i; j++) 
            { 
                free(board[j]); 
            } 
            free(board); 
            return 1; 
        } 
    } 
 
    // Initialize all locations on the board to 0 
    for (int i = 0; i < n; i++) 
    { 
        for (int j = 0; j < n; j++) 
        { 
            board[i][j] = 0; 
        } 
    } 
 
    // Solve the N-Queens problem 
    if (!solveNQ(board, 0, n)) 
    { 
        printf("No solution exists for n = %d\n", n); 
    } 
 
    // Free allocated memory 
    for (int i = 0; i < n; i++) 
    { 
        free(board[i]); 
    } 
    free(board); 
 
    return 0; 
} 
 
// Function to print the chessboard 
void printBoard(int** board, int n) 
{ 
    static int solutionCount = 1; 
    printf("Solution #%d:\n", solutionCount++); 
    for (int i = 0; i < n; i++) 
    { 
        for (int j = 0; j < n; j++) 
        { 
            printf("%d ", board[i][j]); 
        } 
        printf("\n"); 
    } 
    printf("\n"); 
} 
 
// Function to check if a queen can be placed at board[row][col] 
bool isSafe(int** board, int row, int col, int n) 
{ 
    int i, j; 
 
    // Check this column on upper side 
    for (i = 0; i < row; i++) 
    { 
        if (board[i][col] == 1) 
        { 
            return false; 
        } 
    } 
 
    // Check upper-left diagonal 
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
    { 
        if (board[i][j] == 1) 
        { 
            return false; 
        } 
    } 
 
    // Check upper-right diagonal 
    for (i = row, j = col; i >= 0 && j < n; i--, j++) 
    { 
        if (board[i][j] == 1) 
        { 
            return false; 
        } 
    } 
 
    return true; 
} 
 
// Recursive function to solve the N-Queens problem 
bool solveNQ(int** board, int row, int n) 
{ 
    if (row == n) 
    { 
        printBoard(board, n); 
        return true; 
    } 
 
    bool res = false; 
 
    for (int col = 0; col < n; col++) 
    { 
        if (isSafe(board, row, col, n)) 
        { 
            board[row][col] = 1; 
 
            // Recur to place rest of the queens 
            res = solveNQ(board, row + 1, n) || res; 
 
            // Backtrack 
            board[row][col] = 0; 
        } 
    } 
 
    return res; 
} 