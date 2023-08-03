# Project6
Background:

Sudoku is a popular, logic-based, number puzzle. Made popular in the 19th century, Sudoku is still found in most newspapers and puzzle books to this day.

The objective of the game is to fill up the 9x9 grid with digits, such that each digit is unique in its row and column and 3x3 sub-grid. The puzzle contains some initial digits and the player must fill up the grid. Sudoku puzzles are generally easier when they contain more initial digits. That's because this dramatically narrows down the number of possible solutions or legal moves.


Legal moves:

The objective of the puzzle is to fill up the grid. Each square must be filled with a digit 1-9, as follows: 
Each digit in a row must be unique, that is, if we place a 9 into a square that MUST  be the only 9 in that row.
Similarly, each digit in a column must be unique, that is, if we place a 9 into a square that MUST  be the only 9 in that column and cannot repeat.
The grid is further subdivided into nine 3x3 sub-grids. Each digit in a sub-grid must also be unique. Note in the example there is a thicker line that subdivides the 9x9 Sudoku board into 3x3 sub-grids. Each of these sub-grids must contain each digit 1-9 without repetition.


Implementation:

For this project you will build the SudokuSolver, which reads a sudoku puzzle from a file and finds a solution, if one exists.
You must implement each function in this class sequentially (implement and test). Only move on to implementing the next function when you are confident the previous one has been thoroughly tested and it is correct. Some functions will depend on others, so choose the order of implementation carefully. Use stubs where necessary. Remember that the names of all functions, parameters and return types must match exactly those in this specification. 

You are given a puzzle csv file for testing. You should also make your own input files to test different cases. The input files consist of 9 digits on each row separated by commas, and 9 rows separated by new line characters \n, corresponding to a sudoku board. So if the first digit is a 7, then the digit in the first row and first column in the sudoku board is a 7. Missing digits are indicated by 0.


Struct:

Location (provided with the starter files) is a struct that consists of 2 integers, a row index and a column index representing a square within the 9x9 grid of the sudoku puzzle. We start from index 0, as usual, so the possible values for row and column are 0-8. 0,0 is the top left square of the board, 0,8 is the top right, 8,0 is bottom left, and 8,8 is be the bottom right square. Note that this is inside the namespace Sudoku. You have dealt with namespaces plenty of times, specifically the standard namespace std. When using the standard library you use std:: followed by the object, for example, std::cout or std::vector. When using Location you need to do the same thing, Sudoku::Location , using the Sudoku:: namespace. 
Puzzle Representation:

You must store the puzzle as a 2D pointer to int ( int** a pointer of pointers to int) used to dynamically allocate a 2-dimensional array. See the resource link above for a review of 2D pointer arrays.
Constructors:

SudokuSolver(), the default constructor initializes an emtpy board, that is, a board filled with zeros (an array of 9 arrays, each filled with 9 zeros). This board will be marked unsolvable. 
SudokuSolver(std::string input_file), the parameterized constructor reads the input file to initialize the board. The input files consist of 9 digits on each row separated by commas, and 9 rows separated by new line characters \n, corresponding to a sudoku board. Empty squares contain the digit 0. After reading the puzzle, the constructor tries to solve it and records whether the puzzle has a solution or not.
TIP! We strongly suggest that you break down this task with the use of helper functions (reading the file, solving the puzzle etc.) and thoroughly test and debug each functionality separately.
 

Accessors and mutators:

-isPuzzleSolvable() returns true if the puzzle is solvable, false otherwise. We suggest you keep track of this when solving the problem at construction, rather than solving the puzzle again each time this function is called.
-setSolvable() records the puzzle as being solvable.
-getPuzzleNumbers() returns the  2D pointer array representing the puzzle
-setPuzzleNumbers(int** puzzle) sets the  2D pointer array representing the puzzle to the value of the parameter 


Utility functions:

-returnNextEmpty() returns a Location object with the coordinates of the first 0 found in the 2D pointer array, meaning that it is an empty square in the sudoku board. To find the first empty square you must read the 2D array from top-left (0,0) to bottom right (8,8), one row at a time. Set the row and col of the Location to the indices at which the first 0 is found in the 2D array. If there are no empty squares the Location object should have row and col values of -1.
-checkLegalValue(int value, Sudoku::Location location) returns true if the value parameter (which can take on values 1-9) can legally be placed at the given location in the 2D array without breaking the rules of sudoku. It returns false if placing value at location is not a legal move. Remember, in order to be a valid move, the value must be unique with a row, column, and sub-grid.
Hint: to define the top-left corner of the sub-grid in which the location falls, integer division of the coordinates (row and col) by 3 will come in handy since all sub-grids are 3x3.
-display() will display the board as illustrated below: 

Example:
N X X  | N X N  | X X N
N X N  | X N N  | X X X
N X N  | N X X  | X X X
- - - - - - - - - - - - 
X N X  | N X N  | N X X
X X X  | X N X  | X X X
X X N  | N X N  | X N X
- - - - - - - - - - - - 
X X X  | X X N  | N X N
X X X  | N N X  | N X N
N X X  | N X N  | X X N
N is an integer 1-9 (the function displays the actual integer not an N)
X represents a blank box where there is a zero (the function displays the X not the zero)
After every 3 numbers (columns), we have a " | " to separate sub-grids. Note that each " | " is preceded by two space characters and followed by a single space character.
After every 3 rows, we have 12 dashes " - " to separate the sub-grids.  
Note: the principle of Information Hiding would dictate that setSolvable(), getPuzzleNumbers(), setPuzzleNumbers(int** puzzle), returnNextEmpty() and checkLegalValue(int value, Sudoku::Location location) should be private. We require these to be public here for unit-testing purposes.


Solving the Puzzle:  

With the help of the utility functions indicated above, we suggest you solve the puzzle using backtracking. You may  choose to implement it recursively or using a stack (you may use the STL stack if you choose the stack implementation).