#include "../include/Matrix.h"
#include <iostream>


// constructor
template<typename T>
Matrix<T>::Matrix(int nRows, int nCols)
    : rows(nRows), 
      cols(nCols) {
    data.resize(rows, std::vector<T>(cols));
}


// value constructor
template<typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>>& initData)
    : rows(initData.size()),
      cols(initData[0].size()),
      data(initData) {}


// copy constructor
template<typename T>
Matrix<T>::Matrix(const Matrix<T>& other) 
    : rows(other.rows), 
      cols(other.cols), 
      data(other.data) {}


// destructor
template<typename T>
Matrix<T>::~Matrix() {}


// subscript operator
template<typename T>
std::vector<T>& Matrix<T>::operator[](int row) {
    return data[row];
}


// subscript operator read-only
template<typename T>
const std::vector<T>& Matrix<T>::operator[](int row) const {
    return data[row];
}


// addition
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    // sanity check
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument(
                "Matrices must have the same dimensions for addition.");
    }
    Matrix<T> result(rows, cols);   // instantiate matrix to hold result
    // perform O(n^2) sum
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = data[i][j] + other[i][j]; // use overloaded subscript
        }
    }
    return result;
}

// substraction
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const {
    // sanity check
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument(
                "Matrices must have the same dimensions for substraction.");
    }
    Matrix<T> result(rows, cols);   // instantiate matrix to hold result
    // perform O(n^2) sum
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = data[i][j] - other[i][j]; // use overloaded subscript
        }
    }
    return result;
}


// product
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
    // sanity check
    if (cols != other.rows) {
        throw std::invalid_argument(
                "Number of cols in left matrix must equal number of rows in right matrix.");
    }
    Matrix<T> result(rows, other.cols); // instantiate matrix for holding result
    // perform O(n^3) matrix product algorithm
    T temp;   // stores partial sums
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            temp = 0;
            for (int k = 0; k < cols; ++k) {
                temp += data[i][k] * other[k][j];
            }
            result[i][j] = temp;
        }
    }
    return result;
}


// transpose
template<typename T>
Matrix<T> Matrix<T>::transpose() const {
    Matrix<T> result(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = data[i][j];
        }
    }
    return result;
}


// shape
template<typename T>
std::vector<int> Matrix<T>::shape() const {
    return std::vector<int>{rows, cols};
}


// number of rows
template<typename T>
int Matrix<T>::nRows() const {
    return rows;
}


// number of rows
template<typename T>
int Matrix<T>::nCols() const {
    return cols;
}


// print matrix
template<typename T>
void Matrix<T>::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
