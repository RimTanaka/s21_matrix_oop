#include "test.h"

TEST(S21MatrixTest, GetRowsGetColsTest) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1.0;
  matrix1(0, 1) = 2.0;
  matrix1(1, 0) = 3.0;
  matrix1(1, 1) = 4.0;

  EXPECT_EQ(matrix1.GetRows(), 2);
  EXPECT_EQ(matrix1.GetCols(), 2);
}

TEST(S21MatrixTest, SetRowsSetColUpTest) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1.0;
  matrix1(0, 1) = 2.0;
  matrix1(1, 0) = 3.0;
  matrix1(1, 1) = 4.0;
  matrix1.SetRows(3);
  matrix1.SetCols(3);
  EXPECT_EQ(matrix1.GetRows(), 3);
  EXPECT_EQ(matrix1.GetCols(), 3);
  for (int i = 0; i < matrix1.GetRows(); i++) {
    for (int j = 0; j < matrix1.GetCols(); j++) {
      printf("%lf ", matrix1(i, j));
    }
    printf("\n");
  }
}

TEST(S21MatrixTest, SetRowsSetColDownTest) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1.0;
  matrix1(0, 1) = 2.0;
  matrix1(1, 0) = 3.0;
  matrix1(1, 1) = 4.0;
  matrix1.SetRows(1);
  matrix1.SetCols(1);
  EXPECT_EQ(matrix1.GetRows(), 1);
  EXPECT_EQ(matrix1.GetCols(), 1);
  for (int i = 0; i < matrix1.GetRows(); i++) {
    for (int j = 0; j < matrix1.GetCols(); j++) {
      printf("%lf ", matrix1(i, j));
    }
    printf("\n");
  }
}
