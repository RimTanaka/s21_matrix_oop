#include "test.h"

TEST(S21MatrixTest, MoveConstructorTest) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1.0;
  matrix1(0, 1) = 2.0;
  matrix1(1, 0) = 3.0;
  matrix1(1, 1) = 4.0;

  // Перемещаем matrix1 в matrix2
  S21Matrix matrix2(std::move(matrix1));

  // Проверяем, что matrix2 содержит правильные данные
  EXPECT_EQ(matrix2.GetRows(), 2);
  EXPECT_EQ(matrix2.GetCols(), 2);
  EXPECT_NE(matrix2(0, 0), 0);  // Убедимся, что данные переместились

  EXPECT_EQ(matrix1.GetRows(), 0);
  EXPECT_EQ(matrix1.GetCols(), 0);
  //    EXPECT_EQ(matrix1.matrix_, nullptr);

  // Проверка на использование перемещенного объекта
  EXPECT_THROW(matrix1(0, 0), std::out_of_range);
}

TEST(S21MatrixTest, MoveConstructorTest2) {
  S21Matrix matrix1;
  matrix1(0, 0) = 1.0;
  matrix1(0, 1) = 2.0;
  matrix1(0, 2) = 4.0;
  matrix1(1, 0) = 1.0;
  matrix1(1, 1) = 2.0;
  matrix1(1, 2) = 4.0;
  matrix1(2, 0) = 1.0;
  matrix1(2, 1) = 2.0;
  matrix1(2, 2) = 4.0;

  // Перемещаем matrix1 в matrix2
  S21Matrix matrix2(std::move(matrix1));

  // Проверяем, что matrix2 содержит правильные данные
  EXPECT_EQ(matrix2.GetRows(), 3);
  EXPECT_EQ(matrix2.GetCols(), 3);
  EXPECT_NE(matrix2(0, 0), 0);  // Убедимся, что данные переместились

  EXPECT_EQ(matrix1.GetRows(), 0);
  EXPECT_EQ(matrix1.GetCols(), 0);
  //    EXPECT_EQ(matrix1.matrix_, nullptr);

  // Проверка на использование перемещенного объекта
  EXPECT_THROW(matrix1(0, 0), std::out_of_range);
}

TEST(S21MatrixTest, MoveAssignmentOperatorTest) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1.0;
  matrix1(0, 1) = 2.0;

  S21Matrix matrix2;
  matrix2 = std::move(matrix1);

  EXPECT_EQ(matrix2.GetRows(), 2);
  EXPECT_EQ(matrix2.GetCols(), 2);
  EXPECT_NE(matrix2(0, 0), 0);
}

TEST(S21MatrixTest, CreateErr) {
  ASSERT_THROW(S21Matrix A(0, 3), std::invalid_argument);
}

TEST(S21MatrixTest, DefaultConstructor) {
  S21Matrix mat;
  EXPECT_EQ(mat.GetRows(), 3);
  EXPECT_EQ(mat.GetCols(), 3);
}

TEST(S21MatrixTest, ParameterizedConstructor) {
  S21Matrix mat(5, 5);
  EXPECT_EQ(mat.GetRows(), 5);
  EXPECT_EQ(mat.GetCols(), 5);
}

TEST(S21MatrixTest, InvalidSizeConstructor) {
  EXPECT_THROW(S21Matrix mat(0, 5), std::invalid_argument);
  EXPECT_THROW(S21Matrix mat(5, 0), std::invalid_argument);
}

TEST(S21MatrixTest, CopyConstructor) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  S21Matrix mat2(mat1);
  EXPECT_TRUE(mat1.EqMatrix(mat2));
}

TEST(S21MatrixTest, MoveConstructor) {
  S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  S21Matrix mat2(std::move(mat1));
  EXPECT_EQ(mat1.GetRows(), 0);
  EXPECT_EQ(mat1.GetCols(), 0);
}

TEST(S21MatrixTest, Destructor) {
  { S21Matrix mat(5, 5); }
}
