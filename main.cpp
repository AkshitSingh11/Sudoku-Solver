#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Main function to initiate solving the Sudoku
    void solveSudoku(vector<vector<char>>& board) {
        solve(board); 
    }

private:
    // Recursive function to solve the board using backtracking
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {          // Traverse each row
            for (int j = 0; j < 9; j++) {      // Traverse each column
                if (board[i][j] == '.') {      
                    for (char k = '1'; k <= '9'; k++) {  
                        if (isValid(k, board, i, j)) {   
                            board[i][j] = k;             
                            
                            if (solve(board))            // Recurse to solve remaining board
                                return true;
                            else
                                board[i][j] = '.';       // Backtrack if not solvable
                        }
                    }
                    return false;  
                }
            }
        }
        return true;  
    }

    // Helper function to check if placing digit k at (row, col) is valid
    bool isValid(char k, vector<vector<char>>& board, int row, int col) {
        for (int i = 0; i < 9; i++) {
            // Check row
            if (board[row][i] == k)
                return false;
            // Check column
            if (board[i][col] == k)
                return false;
            // Check 3x3 subgrid
            int subgridRow = 3 * (row / 3) + i / 3;
            int subgridCol = 3 * (col / 3) + i % 3;
            if (board[subgridRow][subgridCol] == k)
                return false;
        }
        return true; 
    }
};

// Utility function to print the board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

int main() {
    // Example Sudoku puzzle with empty cells as '.'
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution solver;
    solver.solveSudoku(board);

    cout << "Solved Sudoku Board:\n";
    printBoard(board);

    return 0;
}
