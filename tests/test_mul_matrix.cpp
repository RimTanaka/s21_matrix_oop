#include "test.h"

TEST(S21MatrixTest, MulMatrixTest1) {
  S21Matrix A(1, 1);
  S21Matrix B(1, 1);

  A(0, 0) = 2.0;
  B(0, 0) = 2.0;

  S21Matrix expected(1, 1);
  expected(0, 0) = 4.0;

  EXPECT_NO_THROW(A.MulMatrix(B));

  for (int i = 0; i < A.GetRows(); ++i) {
    for (int j = 0; j < A.GetCols(); ++j) {
      EXPECT_NEAR(A(i, j), expected(i, j), 1e-6);
    }
  }
}

TEST(S21MatrixTest, MulMatrixTest2) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);

  A(0, 0) = 2.0;
  A(0, 1) = 4.0;
  A(1, 0) = 2.0;
  A(1, 1) = 4.0;
  B(0, 0) = 2.0;
  B(0, 1) = 3.0;
  B(1, 0) = 2.0;
  B(1, 1) = 3.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = 12.0;
  expected(0, 1) = 18.0;
  expected(1, 0) = 12.0;
  expected(1, 1) = 18.0;

  EXPECT_NO_THROW(A.MulMatrix(B));

  for (int i = 0; i < A.GetRows(); ++i) {
    for (int j = 0; j < A.GetCols(); ++j) {
      EXPECT_NEAR(A(i, j), expected(i, j), 1e-6);
    }
  }
}

TEST(S21MatrixTest, MulMatrixTest3) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);

  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  B(0, 0) = 5.0;
  B(0, 1) = 6.0;
  B(1, 0) = 7.0;
  B(1, 1) = 8.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = 19.0;
  expected(0, 1) = 22.0;
  expected(1, 0) = 43.0;
  expected(1, 1) = 50.0;

  EXPECT_NO_THROW(A.MulMatrix(B));

  for (int i = 0; i < A.GetRows(); ++i) {
    for (int j = 0; j < A.GetCols(); ++j) {
      EXPECT_NEAR(A(i, j), expected(i, j), 1e-6);
    }
  }
}

TEST(S21MatrixTest, MulMatrixErrTest1) {
  S21Matrix A(1, 1);
  S21Matrix B(2, 1);

  A(0, 0) = 2.0;
  B(0, 0) = 2.0;
  B(1, 0) = 2.0;

  EXPECT_THROW(A.MulMatrix(B), std::out_of_range);
}

TEST(S21MatrixTest, MulMatrixErrTest2) {
  S21Matrix A(1, 2);
  S21Matrix B(1, 2);

  A(0, 0) = 2.0;
  A(0, 1) = 2.0;
  B(0, 0) = 2.0;
  B(0, 1) = 2.0;

  EXPECT_THROW(A.MulMatrix(B), std::out_of_range);
}
