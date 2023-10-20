#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_SIZE = 100;

void readMatricesFromFile(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int& size, const char* filename);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size);
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int size;

    readMatricesFromFile(matrixA, matrixB, size, "input.txt");

    std::cout << "Your name" << std::endl;
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

void readMatricesFromFile(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int& size, const char* filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the input file." << std::endl;
        exit(1);
    }

    inputFile >> size;

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

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

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

void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}


