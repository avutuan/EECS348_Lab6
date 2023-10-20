#include <iostream>
#include <fstream>
#include <iomanip>

// Matrices can be up to 100 in size
const int MAX_SIZE = 100;

// Prototype functions
void readMatricesFromFile(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int& size, const char* filename);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size);
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

int main() {
    // Initialize variables
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int size;

    // File reading
    readMatricesFromFile(matrixA, matrixB, size, "matrix_input.txt");

    // Calling functions and pretty formatting
    std::cout << "Tuan Vu" << std::endl;
    std::cout << "Lab #6: Matrix manipulation" << std::endl;

    std::cout << "\nMatrix A:" << std::endl;
    printMatrix(matrixA, size);

    std::cout << "\nMatrix B:" << std::endl;
    printMatrix(matrixB, size);

    addMatrices(matrixA, matrixB, result, size);
    std::cout << "\nMatrix Sum (A + B):" << std::endl;
    printMatrix(result, size);

    multiplyMatrices(matrixA, matrixB, result, size);
    std::cout << "\nMatrix Product (A * B):" << std::endl;
    printMatrix(result, size);

    subtractMatrices(matrixA, matrixB, result, size);
    std::cout << "\nMatrix Difference (A - B):" << std::endl;
    printMatrix(result, size);

    return 0;
}

// Function for reading from file
void readMatricesFromFile(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int& size, const char* filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "File open error: " << filename << std::endl;
        exit(1);
    }

    inputFile >> size; // Reads the size 

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inputFile >> matrixA[i][j];
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inputFile >> matrixB[i][j];
        }
    }

    inputFile.close();
}

// Function for printing matrices in a pretty formatt
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function for adding matrices
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function for multiplying matrices
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function for subtracting matrices
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}


