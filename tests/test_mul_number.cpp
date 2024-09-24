#include "test.h"

TEST(S21MatrixTest, MulNumberTest1) {
  S21Matrix A(1, 1);
  A(0, 0) = 2.0;

  double num = 5.0;
  S21Matrix expected(1, 1);
  expected(0, 0) = 10.0;

  EXPECT_NO_THROW(A.MulNumber(num));

  for (int i = 0; i < A.GetRows(); ++i) {
    for (int j = 0; j < A.GetCols(); ++j) {
      EXPECT_NEAR(A(i, j), expected(i, j), 1e-6);
    }
  }
}

TEST(S21MatrixTest, MulNumberTest2) {
  S21Matrix A(1, 2);
  A(0, 0) = 3.12345;
  A(0, 1) = 2.0;

  double num = 5.0;
  S21Matrix expected(1, 2);
  expected(0, 0) = 15.61725;
  expected(0, 1) = 10.0;

  EXPECT_NO_THROW(A.MulNumber(num));

  for (int i = 0; i < A.GetRows(); ++i) {
    for (int j = 0; j < A.GetCols(); ++j) {
      EXPECT_NEAR(A(i, j), expected(i, j), 1e-6);
    }
  }
}
