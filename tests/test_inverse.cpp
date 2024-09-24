#include "test.h"

TEST(S21MatrixTest, InverseMatrixTest1) {
  S21Matrix A(2, 2);
  A(0, 0) = 4.0;
  A(0, 1) = 7.0;
  A(1, 0) = 2.0;
  A(1, 1) = 6.0;

  S21Matrix result(2, 2);
  result(0, 0) = 0.6;
  result(0, 1) = -0.7;
  result(1, 0) = -0.2;
  result(1, 1) = 0.4;

  S21Matrix inverse = A.InverseMatrix();
  EXPECT_TRUE(inverse.EqMatrix(result));
}

TEST(S21MatrixTest, InverseMatrixSingularMatrixTest) {
  S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 2.0;
  A(1, 1) = 4.0;

  EXPECT_THROW(A.InverseMatrix(), std::runtime_error);
}

TEST(S21MatrixTest, InverseMatrixNonSquareMatrixTest1) {
  S21Matrix A(2, 3);

  EXPECT_THROW(A.InverseMatrix(), std::invalid_argument);
}

TEST(S21MatrixTest, InverseMatrixNonSquareMatrixTest2) {
  S21Matrix A(1, 3);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(0, 2) = 2.0;
  EXPECT_THROW(A.InverseMatrix(), std::invalid_argument);
}

TEST(S21MatrixTest, InverseMatrixNonSquareMatrixTest3) {
  S21Matrix A(3, 1);
  A(0, 0) = 1.0;
  A(1, 0) = 2.0;
  A(2, 0) = 2.0;
  EXPECT_THROW(A.InverseMatrix(), std::invalid_argument);
}

void fill_matrix(S21Matrix &matrix, const std::vector<double> &values) {
  int index = 0;
  for (int i = 0; i < matrix.GetRows(); ++i) {
    for (int j = 0; j < matrix.GetCols(); ++j) {
      matrix(i, j) = values[index++];
    }
  }
}

TEST(MatrixInverseTest, InverseTest1) {
  S21Matrix A(3, 3);
  S21Matrix expected(3, 3);
  S21Matrix result;

  std::vector<double> values = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  fill_matrix(A, values);

  std::vector<double> expected_values = {1.0,   -1.0, 1.0,   -38.0, 41.0,
                                         -34.0, 27.0, -29.0, 24.0};
  fill_matrix(expected, expected_values);

  ASSERT_NO_THROW(result = A.InverseMatrix());
  ASSERT_TRUE(result == expected);
}

TEST(MatrixInverseTest, InverseTest2) {
  S21Matrix A(3, 3);
  S21Matrix expected(3, 3);
  S21Matrix result;

  std::vector<double> identity_values = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  fill_matrix(A, identity_values);
  fill_matrix(expected, identity_values);

  ASSERT_NO_THROW(result = A.InverseMatrix());
  ASSERT_TRUE(result == expected);
}

TEST(MatrixInverseTest, InverseTest3) {
  S21Matrix A(2, 3);

  std::vector<double> values = {1, 2, 3, 4, 5, 6};
  fill_matrix(A, values);

  ASSERT_THROW(A.InverseMatrix(), std::invalid_argument);
}

TEST(MatrixInverseTest, InverseTest4) {
  S21Matrix A(3, 3);
  S21Matrix expected(3, 3);
  S21Matrix result;

  A(0, 0) = 2.0;
  A(0, 1) = 5.0;
  A(0, 2) = 7.0;
  A(1, 0) = 6.0;
  A(1, 1) = 3.0;
  A(1, 2) = 4.0;
  A(2, 0) = 5.0;
  A(2, 1) = -2.0;
  A(2, 2) = -3.0;

  expected(0, 0) = 1.0;
  expected(0, 1) = -1.0;
  expected(0, 2) = 1.0;
  expected(1, 0) = -38.0;
  expected(1, 1) = 41.0;
  expected(1, 2) = -34.0;
  expected(2, 0) = 27.0;
  expected(2, 1) = -29.0;
  expected(2, 2) = 24.0;

  ASSERT_NO_THROW(result = A.InverseMatrix());
  ASSERT_TRUE(result == expected);
}

TEST(MatrixInverseTest, InverseTest6) {
  S21Matrix A(1, 1);
  S21Matrix expected(1, 1);
  S21Matrix result;

  A(0, 0) = 21;
  expected(0, 0) = 1.0 / 21.0;

  ASSERT_NO_THROW(result = A.InverseMatrix());
  ASSERT_TRUE(result.EqMatrix(expected));
}

TEST(MatrixInverseTest, InverseTest7) {
  S21Matrix A(3, 3);
  S21Matrix expected(3, 3);
  S21Matrix result;

  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;

  expected(0, 0) = 1;
  expected(0, 1) = -1;
  expected(0, 2) = 1;
  expected(1, 0) = -38;
  expected(1, 1) = 41;
  expected(1, 2) = -34;
  expected(2, 0) = 27;
  expected(2, 1) = -29;
  expected(2, 2) = 24;

  ASSERT_NO_THROW(result = A.InverseMatrix());
  ASSERT_TRUE(result == expected);
}

TEST(MatrixInverseTest, InverseTest8) {
  S21Matrix A(1, 1);
  S21Matrix expected(1, 1);

  A(0, 0) = 21;
  expected(0, 0) = 1.0 / 21.0;

  S21Matrix const result = A.InverseMatrix();
  ASSERT_TRUE(result.EqMatrix(expected));
}

TEST(MatrixInverseTest, InverseTest9) {
  S21Matrix A(3, 3);
  S21Matrix expected(3, 3);
  S21Matrix result;

  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(0, 2) = 3.0;
  A(1, 0) = 0.0;
  A(1, 1) = 1.0;
  A(1, 2) = 4.0;
  A(2, 0) = 5.0;
  A(2, 1) = 6.0;
  A(2, 2) = 0.0;

  expected(0, 0) = -24.0;
  expected(0, 1) = 18.0;
  expected(0, 2) = 5.0;
  expected(1, 0) = 20.0;
  expected(1, 1) = -15.0;
  expected(1, 2) = -4.0;
  expected(2, 0) = -5.0;
  expected(2, 1) = 4.0;
  expected(2, 2) = 1.0;

  ASSERT_NO_THROW(result = A.InverseMatrix());
  ASSERT_TRUE(result == expected);
}

TEST(MatrixInverseTest, InverseTest10) {
  S21Matrix A(4, 4);
  S21Matrix expected(4, 4);
  S21Matrix result;

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(0, 3) = 4;
  A(1, 0) = 5;
  A(1, 1) = 6;
  A(1, 2) = 7;
  A(1, 3) = 8;
  A(2, 0) = 9;
  A(2, 1) = 10;
  A(2, 2) = 11;
  A(2, 3) = 12;
  A(3, 0) = 13;
  A(3, 1) = 14;
  A(3, 2) = 15;
  A(3, 3) = 16;

  // Матрица не обратима, детерминант равен 0
  EXPECT_THROW(A.InverseMatrix(), std::runtime_error);
}

TEST(MatrixInverseTest, InverseTest11) {
  S21Matrix A(2, 2);
  S21Matrix expected(2, 2);
  S21Matrix result;

  A(0, 0) = 0.5;
  A(0, 1) = 2.5;
  A(1, 0) = 1.5;
  A(1, 1) = 3.5;

  expected(0, 0) = -1.75;
  expected(0, 1) = 1.25;
  expected(1, 0) = 0.75;
  expected(1, 1) = -0.25;

  ASSERT_NO_THROW(result = A.InverseMatrix());
  ASSERT_TRUE(result.EqMatrix(expected));
}

TEST(MatrixInverseTest, InverseTest12) {
  S21Matrix A(2, 2);
  S21Matrix result;

  // Опробуем матрицу с нулевым элементом
  A(0, 0) = 0;
  A(0, 1) = 1;
  A(1, 0) = 1;
  A(1, 1) = 0;

  S21Matrix expected(2, 2);
  expected(0, 0) = 0;
  expected(0, 1) = 1;
  expected(1, 0) = 1;
  expected(1, 1) = 0;

  ASSERT_NO_THROW(result = A.InverseMatrix());
  ASSERT_TRUE(result.EqMatrix(expected));
}

TEST(MatrixInverseTest, InverseZeroMatrix) {
  S21Matrix A(2, 2);
  A(0, 0) = 0;
  A(0, 1) = 0;
  A(1, 0) = 0;
  A(1, 1) = 0;

  EXPECT_THROW(A.InverseMatrix(), std::runtime_error);
}

TEST(MatrixInverseTest, InverseLargeZeroMatrix) {
  S21Matrix A(3, 3);
  A(0, 0) = 0;
  A(0, 1) = 0;
  A(0, 2) = 0;
  A(1, 0) = 0;
  A(1, 1) = 0;
  A(1, 2) = 0;
  A(2, 0) = 0;
  A(2, 1) = 0;
  A(2, 2) = 0;

  EXPECT_THROW(A.InverseMatrix(), std::runtime_error);
}

TEST(MatrixInverseTest, InverseNegativeMatrix) {
  S21Matrix A(2, 2);
  A(0, 0) = -1;
  A(0, 1) = -2;
  A(1, 0) = -3;
  A(1, 1) = -4;

  S21Matrix expected(2, 2);
  expected(0, 0) = 2;
  expected(0, 1) = -1;
  expected(1, 0) = -1.5;
  expected(1, 1) = 0.5;

  ASSERT_NO_THROW(A.InverseMatrix());
  ASSERT_TRUE(A.InverseMatrix().EqMatrix(expected));
}

TEST(MatrixInverseTest, InverseSmallValuesMatrix) {
  S21Matrix A(2, 2);
  A(0, 0) = 0.0001;
  A(0, 1) = 0.0002;
  A(1, 0) = 0.0003;
  A(1, 1) = 0.0004;

  S21Matrix expected(2, 2);
  expected(0, 0) = -20000;
  expected(0, 1) = 10000;
  expected(1, 0) = 15000;
  expected(1, 1) = -5000;

  ASSERT_NO_THROW(A.InverseMatrix());
  ASSERT_TRUE(A.InverseMatrix().EqMatrix(expected));
}
