#include <Matrix.h>
#include <iostream>


// constructor
template<typename T>
Matrix<T>::Matrix(int nRows, int nCols)
    : rows(nRows), 
      cols(nCols) {
    data.resize(rows, std::vector<T>(cols));
}

// copy constructor
template<typename T>
Matrix<T>::Matrix(const Matrix<T>& other) 
    : rows(other.rows), 
      cols(other.cols), 
      data(oters.data) {}

// destructor
Matrix<T>::~Matrix() {}
