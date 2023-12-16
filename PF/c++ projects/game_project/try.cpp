#include <iostream>

const int ROWS = 3;
const int COLS = 3;

void moveUp(int matrix[ROWS][COLS]) {
    // Move each column one step up
    for (int j = 0; j < COLS; ++j) {
        // Save the first element of the column
        int temp = matrix[0][j];

        // Shift elements up
        for (int i = 0; i < ROWS - 1; ++i) {
            matrix[i][j] = matrix[i + 1][j];
        }

        // Place the saved element at the bottom
        matrix[ROWS - 1][j] = temp;
    }
}

// Function to print a 2D matrix
void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Example usage:
    int inputMatrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::cout << "Original Matrix:" << std::endl;
    printMatrix(inputMatrix);

    moveUp(inputMatrix);

    std::cout << "\nMatrix After Moving Up:" << std::endl;
    printMatrix(inputMatrix);

    return 0;
}
