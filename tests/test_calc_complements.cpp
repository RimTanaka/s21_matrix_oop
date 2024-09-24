#include "test.h"

TEST(S21MatrixTest, CalcComplementsTest1) {
  S21Matrix A(3, 3);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 0;
  A(1, 1) = 4;
  A(1, 2) = 5;
  A(2, 0) = 1;
  A(2, 1) = 0;
  A(2, 2) = 6;

  S21Matrix expected(3, 3);
  expected(0, 0) = 24;
  expected(0, 1) = 5;
  expected(0, 2) = -4;
  expected(1, 0) = -12;
  expected(1, 1) = 3;
  expected(1, 2) = 2;
  expected(2, 0) = -2;
  expected(2, 1) = -5;
  expected(2, 2) = 4;

  S21Matrix result;
  ASSERT_NO_THROW(result = A.CalcComplements());

  for (int i = 0; i < result.GetRows(); i++) {
    for (int j = 0; j < result.GetCols(); j++) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-6);
    }
  }
}

TEST(S21MatrixTest, CalcComplementsTest5x5) {
  /*
   2 3 1 4 5
   1 0 2 3 4
   4 2 3 1 0
   5 1 4 2 3
   3 4 0 5 2

   */
  // Исходная матрица A (5x5)
  S21Matrix A(5, 5);
  A(0, 0) = 2;
  A(0, 1) = 3;
  A(0, 2) = 1;
  A(0, 3) = 4;
  A(0, 4) = 5;

  A(1, 0) = 1;
  A(1, 1) = 0;
  A(1, 2) = 2;
  A(1, 3) = 3;
  A(1, 4) = 4;

  A(2, 0) = 4;
  A(2, 1) = 2;
  A(2, 2) = 3;
  A(2, 3) = 1;
  A(2, 4) = 0;

  A(3, 0) = 5;
  A(3, 1) = 1;
  A(3, 2) = 4;
  A(3, 3) = 2;
  A(3, 4) = 3;

  A(4, 0) = 3;
  A(4, 1) = 4;
  A(4, 2) = 0;
  A(4, 3) = 5;
  A(4, 4) = 2;

  // Ожидаемая матрица алгебраических дополнений (5x5)
  /*
   -18  -2   18    2   18
   -22  -8   10    4    6
   -30  -14  22    2    6
    18    6  -8   -2  -10
     4   -8   2   -4    6

   */
  S21Matrix expected(5, 5);
  expected(0, 0) = 30;
  expected(0, 1) = -92;
  expected(0, 2) = -6;
  expected(0, 3) = 82;
  expected(0, 4) = -66;

  expected(1, 0) = 92;
  expected(1, 1) = 24;
  expected(1, 2) = -108;
  expected(1, 3) = -92;
  expected(1, 4) = 44;

  expected(2, 0) = 118;
  expected(2, 1) = -108;
  expected(2, 2) = -158;
  expected(2, 3) = -6;
  expected(2, 4) = 54;

  expected(3, 0) = -142;
  expected(3, 1) = 92;
  expected(3, 2) = 118;
  expected(3, 3) = 30;
  expected(3, 4) = -46;

  expected(4, 0) = -46;
  expected(4, 1) = 44;
  expected(4, 2) = 54;
  expected(4, 3) = -66;
  expected(4, 4) = 34;

  // det = -224
  // Вычисление матрицы алгебраических дополнений
  S21Matrix result = A.CalcComplements();
  for (int i = 0; i < result.GetRows(); i++) {
    for (int j = 0; j < result.GetCols(); j++) {
      printf("%lf ", result(i, j));
    }
    printf("\n");
  }
  ASSERT_TRUE(result.EqMatrix(expected));
}

TEST(MatrixComplementsTest, CalcComplementsConstTest) {
  S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;

  S21Matrix expected(2, 2);
  expected(0, 0) = 4.0;
  expected(0, 1) = -3.0;
  expected(1, 0) = -2.0;
  expected(1, 1) = 1.0;

  S21Matrix const constA = A;

  ASSERT_NO_THROW({
    S21Matrix const result = constA.CalcComplements();
    ASSERT_TRUE(result.EqMatrix(expected));
  });
}

TEST(S21MatrixTest, CalcComplementsErrTest1) {
  S21Matrix result1(1, 2);
  result1(0, 0) = 2.0;
  result1(0, 1) = 3.0;

  EXPECT_THROW(result1.CalcComplements(), std::invalid_argument);
}

TEST(S21MatrixTest, CalcComplementsErrTest2) {
  S21Matrix result1(1, 1);
  result1(0, 0) = 2.0;

  EXPECT_THROW(result1.CalcComplements(), std::invalid_argument);
}

TEST(S21MatrixTest, CalcComplementsErrTest3) {
  S21Matrix result1(3, 2);
  result1(0, 0) = 2.0;
  result1(1, 0) = 2.0;
  result1(2, 0) = 2.0;
  result1(0, 1) = 2.0;
  result1(1, 1) = 2.0;
  result1(2, 1) = 2.0;

  EXPECT_THROW(result1.CalcComplements(), std::invalid_argument);
}
