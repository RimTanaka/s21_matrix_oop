#include "test.h"

TEST(S21MatrixTest, EqMatrixTest1) {
  S21Matrix A(1, 1);
  S21Matrix B(1, 1);

  A(0, 0) = 2.0;
  B(0, 0) = 2.0;

  EXPECT_TRUE(A.EqMatrix(B));
}

TEST(S21MatrixTest, EqMatrixTest2) {
  S21Matrix A(1, 1);
  S21Matrix B(1, 1);

  A(0, 0) = 2.0;
  B(0, 0) = 1.0;

  EXPECT_FALSE(A.EqMatrix(B));
}

TEST(S21MatrixTest, EqMatrixTest3) {
  S21Matrix A(1, 2);
  S21Matrix B(1, 3);

  A(0, 0) = 2.0;
  A(0, 1) = 2.0;
  B(0, 0) = 2.0;
  B(0, 1) = 2.0;
  B(0, 2) = 2.0;

  EXPECT_FALSE(A.EqMatrix(B));
}

TEST(S21MatrixTest, EqMatrixTest4) {
  S21Matrix A(1, 1);
  S21Matrix B(1, 1);

  A(0, 0) = -2.0;
  B(0, 0) = 2.0;

  EXPECT_FALSE(A.EqMatrix(B));
}

TEST(S21MatrixTest, EqMatrixTest5_Const) {
  S21Matrix const A(1, 2);
  S21Matrix const B(1, 3);

  EXPECT_FALSE(A.EqMatrix(B));
}
