#include <gtest/gtest.h>
#include "Matrix.h"

// constructor
TEST(MatrixTest, ConstructorTest) {
    Matrix<int> matInt(3, 4);
    Matrix<int> matIntSquare(5, 5);
    Matrix<float> matFloat(3, 4);
    Matrix<float> matFloatSquare(5, 5);

    EXPECT_EQ(matInt.nRows(), 3);
    EXPECT_EQ(matInt.nCols(), 4);

    EXPECT_EQ(matIntSquare.nRows(), 5);
    EXPECT_EQ(matIntSquare.nCols(), 5);

    EXPECT_EQ(matFloat.nRows(), 3);
    EXPECT_EQ(matFloat.nCols(), 4);

    EXPECT_EQ(matFloatSquare.nRows(), 5);
    EXPECT_EQ(matFloatSquare.nCols(), 5);
}
