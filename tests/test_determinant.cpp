#include "test.h"

TEST(S21MatrixTest, DeterminantTest1) {
  S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;

  EXPECT_DOUBLE_EQ(A.Determinant(), -2.0);
}

TEST(S21MatrixTest, DeterminantTest2) {
  S21Matrix A(3, 3);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(0, 2) = 3.0;
  A(1, 0) = 0.0;
  A(1, 1) = 1.0;
  A(1, 2) = 4.0;
  A(2, 0) = 5.0;
  A(2, 1) = 6.0;
  A(2, 2) = 0.0;

  EXPECT_DOUBLE_EQ(A.Determinant(), 1.0);
}

TEST(S21MatrixTest, DeterminantTest3) {
  S21Matrix A(4, 4);
  A(0, 0) = 2.0;
  A(0, 1) = 3.0;
  A(0, 2) = 4.0;
  A(0, 3) = 5.0;
  A(1, 0) = 6.0;
  A(1, 1) = 7.0;
  A(1, 2) = 8.0;
  A(1, 3) = 9.0;
  A(2, 0) = 10.0;
  A(2, 1) = 11.0;
  A(2, 2) = 11.0;
  A(2, 3) = 0.0;
  A(3, 0) = 1.0;
  A(3, 1) = 2.0;
  A(3, 2) = 3.0;
  A(3, 3) = 4.0;

  EXPECT_DOUBLE_EQ(A.Determinant(), 0.0);
}

TEST(S21MatrixTest, DeterminantTest4) {
  S21Matrix A(1, 1);
  A(0, 0) = 1.0;

  EXPECT_DOUBLE_EQ(A.Determinant(), 1.0);
}

TEST(S21MatrixTest, DeterminantThrowsOnInvalidMatrix) {
  S21Matrix A(1, 2);

  EXPECT_THROW(A.Determinant(), std::invalid_argument);
}
