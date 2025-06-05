# 🧩 Sudoku Solver in C++

A fast and clean Sudoku solver implemented in C++ using recursive backtracking with constraint checking. This project solves any standard 9×9 Sudoku puzzle with empty cells represented as `'.'`.

---

## ✅ Features

- Solves any valid 9x9 Sudoku grid with high accuracy
- Uses backtracking and 3-in-1 constraint validation (row, column, subgrid)
- Clean and modular object-oriented code using a `Solution` class
- Includes a sample puzzle and terminal output
- Easy to extend with optimizations or GUI

---

## 🔧 How It Works

The solver uses recursive backtracking:
1. Scans the board to find the first empty cell.
2. Tries digits `'1'` to `'9'` in that cell.
3. Validates the digit using `isValid()`:
   - Checks row
   - Checks column
   - Checks 3×3 subgrid
4. If valid, places the digit and recursively continues.
5. If stuck, backtracks to try the next possibility.

---

## 🖥️ Example Input

```cpp
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
