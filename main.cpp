#include "SudokuSolver.hpp"

int main() {
    SudokuSolver solver("puzzle1.csv"); // Assuming puzzle.txt contains the initial puzzle numbers
    solver.display(); // Display the initial puzzle
    std::cout << std::endl;
    solver.Solver(); // Solve the puzzle
    solver.display(); // Display the solved puzzle
}