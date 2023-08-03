/*
Vincent Li
CSCI235
Project 6
*/

#include "SudokuSolver.hpp"


//default constructor
SudokuSolver::SudokuSolver() {
    puzzle = new int*[9];
    for (int i = 0; i < 9; i++) {
        puzzle[i] = new int[9];
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            puzzle[i][j] = 0;
        }
    }
}

//parameterized constructor
SudokuSolver::SudokuSolver(std::string input_file) {
    //open input file
    std::ifstream fin(input_file);
    if(fin.fail()) {
        std::cerr << "File cannot be opened for reading. \n";
        exit(1);
    }

    puzzle = new int*[9];
    for (int i = 0; i < 9; i++) {
        puzzle[i] = new int[9];
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            puzzle[i][j] = 0;
        }
    }

    std::string puzzle_, num;
    int row = -1, col;

    // Read input file into puzzle array
    while(getline(fin, puzzle_)) {
        std::stringstream ss(puzzle_);
        row++;
        col = -1;
        while(getline(ss, num, ',')) {
            col++;
            puzzle[row][col] = stoi(num);
        }
    }
    
    //solves puzzle
    Solver();
}

//helper function
/**
 * @brief recursive backtracking to get solution
 * 
 * @return true or false based on if Sudoku can be solved
 */
bool SudokuSolver::Solver() {
    Sudoku::Location pos = returnNextEmpty();
    int row = pos.row;
    int col = pos.col;
    if (row == -1 && col == -1) {
        setSolvable(); // Puzzle solved
        return true;
    }

    for (int i = 1; i <= 9; i++) {
        if (checkLegalValue(i, pos)) {
            puzzle[row][col] = i; // sets pos to value of i
            if (Solver()) {
                return true;
            }
            puzzle[row][col] = 0;
        }
    }
    return false;  // Puzzle unsolved
}

//accesors and mutators
/** 
 * @return: if puzzle is solvable(true or false)
 */
bool SudokuSolver::isPuzzleSolvable() {
    return solvable;
}

/**
 * @brief: records puzzle as solvable
 */
void SudokuSolver::setSolvable() {
    solvable = true;
}

/**
 * @return: 2D pointer array representing puzzle 
 */
int** SudokuSolver::getPuzzleNumbers() {
    return puzzle;
}

/**
 * @brief: sets 2D pointer array represenitng puzzle to value of parameter
 * 
 * @param: puzzle 
 */
void SudokuSolver::setPuzzleNumbers(int** puzzle) {
    this->puzzle = puzzle;
}

//utility functions
/**
 * @brief: finds the next empty square in the 2D pointer array
 * 
 * @return: a Location object with coordinates of first 0 found in 2D pointer array
 */
Sudoku::Location SudokuSolver::returnNextEmpty() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (puzzle[i][j] == 0) {
        return {i, j};
      }
    }
  }
  return {-1, -1};  // No empty cells left
}

/**
 * @brief: checks if value parameter can be legally placed at a given location in the 2D array without breaking rules of Sudoku
 * 
 * @param value(1 to 9)
 * @param location(in the 2D array) 
 * @return true or false
 */
bool SudokuSolver::checkLegalValue(int value, Sudoku::Location location) {
    // Check if we find the same num 
    // in the similar row or col, 
    // return false
    for (int i = 0; i < 9; i++) {
        if (puzzle[location.row][i] == value || puzzle[i][location.col] == value) {
            return false;
        }
    }

    // Check if we find the same num in 
    // the particular 3*3 matrix,
    // we return false
    int startRow = (location.row / 3) * 3, startCol = (location.col / 3) * 3;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (puzzle[i + startRow][j + startCol] == value) {
                return false;
            }
        }
    }
  
    return true;
}

/**
 * @brief displays Sudoku board
 * 
 */
void SudokuSolver::display() {
   for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if(j == 3 || j == 6) {
            std::cout << " | ";
        }
         if (puzzle[i][j] == 0) {
            std::cout << "X ";
        } else {
            std::cout << puzzle[i][j] <<" ";
        }
      }
      if(i == 2 || i == 5) {
         std::cout << std::endl;
         for(int x = 0; x < 12; x++) {
            std::cout << "- ";
         }
      }
      std::cout << std::endl;
   }
}
