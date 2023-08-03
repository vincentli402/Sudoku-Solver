/*
Vincent Li
CSCI235
Project 6
*/

#ifndef SUDOKU_SOLVER_HPP_
#define SUDOKU_SOLVER_HPP_
#include<iostream>
#include<fstream>
#include<sstream>


//We define Location within the Sudoku namespace.
//To use Location, you must specify the namespace Sudoku::Location
//Just like you do when using the standard namespace std::
namespace Sudoku
{ 
  struct Location
  {
    int row;
    int col;
  };
}

class SudokuSolver
{
public:
 
//Add your public members here
  //default constructor
  SudokuSolver();

  //parameterized constructor
  SudokuSolver(std::string input_file);

  //helper function
  bool Solver();

  //accesors and mutators
  bool isPuzzleSolvable();
  void setSolvable();
  int** getPuzzleNumbers();
  void setPuzzleNumbers(int** puzzle);

  //utility functions
  Sudoku::Location returnNextEmpty();
  bool checkLegalValue(int value, Sudoku::Location location);  
  void display();

private:
//Add your private members here
  int **puzzle;
  bool solvable;
  
};

#endif
