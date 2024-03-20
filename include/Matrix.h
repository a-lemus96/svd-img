#ifndef MATRIX_H
#define MATRIX_H

#include  <vector>


template <typename T>
class Matrix {
    Matrix<T> operator+(const Matrix<T>& lhs, const Matrix<T>& rhs) const {
        // sanity check
        if (lhs.rows != rhs.rows || lhs.cols != rhs.cols) {
            throw std::invalid_argument(
                    "Matrices must have the same dimensions.");
        }
        Matrix<T> result(lhs.rows, lhs.cols);
        for (int i = 0; i < lhs.rows; ++i) {
            for (int j = 0; j < lhs.cols; ++j) {
                result[i][j] = lhs[i][j] + rhs[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator-(const Matrix<T>& lhs, const Matrix<T>& rhs) const {
        return lhs + (-1 * rhs);

    Matrix<T> operator*(const T& k, const Matrix<T> rhs) const {
        Matrix<T> result(rhs.rows, rhs.cols);
        for (int i = 0; i < rhs.rows; ++i) {
            for (int j = 0; j < rhs.rows; ++j) {
                result[i][j] = k * rhs[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator*(const Matrix<T> lhs, const T& k) const {
        return k * lhs;

    Matrix<T> operator*(const Matrix<T>& lhs, const Matrix<T>& rhs) const {
        // sanity check
        if (lhs.cols != rhs.rows) {
            throw std::invalid_argument(
                    "Number of left cols must equal number of right rows.");
        }
        Matrix<T> result(lhs.rows, rhs.cols);
        T temp;   // stores partial sums
        for (int i = 0; i < lhs.rows; ++i) {
            for (int j = 0; j < rhs.cols; ++j) {
                temp = 0;
                for (int k = 0; k < lhs.cols; ++k) {
                    temp += data[i][k] * other[k][j];
                }
                result[i][j] = temp;
            }
        }
        return result;
    }

    private:
        std::vector<std::vector<T>> data;
        int rows;
        int cols;

    public:
        // constructors
        Matrix() {}

        Matrix(int nRows, int nCols) 
            : rows(nRows),
              cols(nCols) {
            data.resize(rows, std::vector<T>(cols));
        }

        Matrix(const std::vector<std::vector<T>>& initData)
            : rows(initData.size()),
              cols(initData[0].size()),
              data(initData) {}

        Matrix(const Matrix<T>& other) 
            : rows(other.rows),
              cols(other.cols),
              data(other.data) {}

        // destructor
        ~Matrix() {}

        // operators
        std::vector<T>& operator[](int row) {
            return data[row];
        }

        const std::vector<T>& operator[](int row) const {
            return data[row];
        }

        Matrix<T> transpose() const {
            Matrix<T> result(cols, rows);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    result[j][i] = data[i][j];
                }
            }
            return result;
        }

        std::vector<int> shape() const {
            return std::vector<int>{rows, cols};
        }

        int nRows() const {
            return rows;
        }

        int nCols() const {
            return cols;
        }

        void print() const {
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    std::cout << data[i][j] << ' ';
                }
                std::cout << std::endl;
            }
        }
};

#endif
