#ifndef MATRIX_H
#define MATRIX_H

#include  <vector>

template <typename T>
class Matrix {
    private:
        std::vector<std::vector<T>> data;
        int rows;
        int cols;

    public:
        Matrix(int nRows, int nCols);                           // constructors
        Matrix(const std::vector<std::vector<T>>& initData);
        Matrix(const Matrix<T>& other);
        ~Matrix();                                              // destructor

        std::vector<T>& operator[](int row);                    // subscript
        const std::vector<T>& operator[](int row) const;
        Matrix<T> operator+(const Matrix<T>& other) const;      // sum
        Matrix<T> operator-(const Matrix<T>& other) const;      // substract
        Matrix<T> operator*(const Matrix<T>& other) const;      // product

        Matrix<T> transpose() const;    // compute transpose

        std::vector<int> shape() const; // get matrix shape (nRows, nCols)
        int nRows() const;              // get number of rows
        int nCols() const;              // get number of cols

        void print() const;     // print the matrix
}

#endif
