#include "test.h"

TEST(S21MatrixTest, SumMatrixTest1) {
  S21Matrix A(1, 1);
  A(0, 0) = 2.0;

  S21Matrix B(1, 1);
  B(0, 0) = 2.0;

  S21Matrix result(1, 1);
  A.SumMatrix(B);
  result(0, 0) = 4.0;

  EXPECT_TRUE(A.EqMatrix(result));
}

TEST(S21MatrixTest, SumMatrixTest2) {
  S21Matrix A(1, 2);
  A(0, 0) = 3.0;
  A(0, 1) = 2.0;

  S21Matrix B(1, 2);
  B(0, 0) = 2.0;
  B(0, 1) = 5.0;

  S21Matrix result(1, 2);
  A.SumMatrix(B);
  result(0, 0) = 5.0;
  result(0, 1) = 7.0;

  EXPECT_TRUE(A.EqMatrix(result));
}

TEST(S21MatrixTest, SumMatrixErrTest1) {
  S21Matrix A(1, 1);
  A(0, 0) = 2.0;

  S21Matrix B(1, 2);
  B(0, 0) = 2.0;
  B(0, 1) = 2.0;

  EXPECT_THROW(A.SumMatrix(B), std::out_of_range);
}

TEST(S21MatrixTest, SumMatrixErrTest2) {
  S21Matrix A(1, 1);
  A(0, 0) = 2.0;

  S21Matrix B(2, 1);
  B(0, 0) = 2.0;
  B(1, 0) = 2.0;

  EXPECT_THROW(A.SumMatrix(B), std::out_of_range);
}
