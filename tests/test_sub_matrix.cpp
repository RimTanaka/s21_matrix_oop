#include "test.h"

TEST(S21MatrixTests, SubMatrixTest1) {
  S21Matrix A(1, 1);
  A(0, 0) = 2.0;

  S21Matrix B(1, 1);
  B(0, 0) = 2.0;

  S21Matrix result(1, 1);
  A.SubMatrix(B);
  result(0, 0) = 0.0;

  EXPECT_TRUE(A.EqMatrix(result));
}

TEST(S21MatrixTests, SubMatrixTest2) {
  S21Matrix A(1, 2);
  A(0, 0) = 3.1234;
  A(0, 1) = 2.0;

  S21Matrix B(1, 2);
  B(0, 0) = 2.0;
  B(0, 1) = 5.0;

  S21Matrix result(1, 2);
  A.SubMatrix(B);
  result(0, 0) = 1.1234;
  result(0, 1) = -3.0;

  EXPECT_TRUE(A.EqMatrix(result));
}

TEST(S21MatrixTests, SubMatrixErrTest1) {
  S21Matrix A(1, 1);
  A(0, 0) = 2.0;

  S21Matrix B(2, 1);
  B(0, 0) = 2.0;
  B(1, 0) = 2.0;

  EXPECT_THROW(A.SubMatrix(B), std::out_of_range);
}
