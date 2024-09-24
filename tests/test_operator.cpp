#include "test.h"

TEST(MatrixOperatorsTest, AddOperator) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  S21Matrix expected(2, 2);

  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;

  B(0, 0) = 1.0;
  B(0, 1) = 1.0;
  B(1, 0) = 1.0;
  B(1, 1) = 1.0;

  expected(0, 0) = 2.0;
  expected(0, 1) = 3.0;
  expected(1, 0) = 4.0;
  expected(1, 1) = 5.0;

  S21Matrix result = A + B;

  ASSERT_TRUE(result == expected);
}

TEST(MatrixOperatorsTest, AddOperatorConst) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  S21Matrix expected(2, 2);

  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;

  B(0, 0) = 1.0;
  B(0, 1) = 1.0;
  B(1, 0) = 1.0;
  B(1, 1) = 1.0;

  S21Matrix const A_Const = A;
  S21Matrix const B_Const = B;

  expected(0, 0) = 2.0;
  expected(0, 1) = 3.0;
  expected(1, 0) = 4.0;
  expected(1, 1) = 5.0;

  S21Matrix result = A_Const + B_Const;

  ASSERT_TRUE(result == expected);
}

TEST(S21MatrixTest, AddOperatorErrConst) {
  S21Matrix A(1, 1);
  A(0, 0) = 2.0;

  S21Matrix B(1, 2);
  B(0, 0) = 2.0;
  B(0, 1) = 2.0;

  EXPECT_THROW(A + B, std::out_of_range);
}

TEST(MatrixOperatorsTest, SubOperator) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  S21Matrix expected(2, 2);

  A(0, 0) = 3.0;
  A(0, 1) = 4.0;
  A(1, 0) = 5.0;
  A(1, 1) = 6.0;

  B(0, 0) = 1.0;
  B(0, 1) = 1.0;
  B(1, 0) = 1.0;
  B(1, 1) = 1.0;

  expected(0, 0) = 2.0;
  expected(0, 1) = 3.0;
  expected(1, 0) = 4.0;
  expected(1, 1) = 5.0;

  S21Matrix result = A - B;

  ASSERT_TRUE(result == expected);
}

TEST(S21MatrixTests, SubOperatorErr) {
  S21Matrix A(1, 1);
  A(0, 0) = 2.0;

  S21Matrix B(2, 1);
  B(0, 0) = 2.0;
  B(1, 0) = 2.0;

  EXPECT_THROW(A - B, std::out_of_range);
}

TEST(MatrixOperatorsTest, MulMatrixOperator) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  S21Matrix expected(2, 2);

  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;

  B(0, 0) = 1.0;
  B(0, 1) = 0.0;
  B(1, 0) = 0.0;
  B(1, 1) = 1.0;

  expected(0, 0) = 1.0;
  expected(0, 1) = 2.0;
  expected(1, 0) = 3.0;
  expected(1, 1) = 4.0;

  S21Matrix result = A * B;

  ASSERT_TRUE(result == expected);
}

TEST(S21MatrixTest, MulMatrixOperatorErr) {
  S21Matrix A(1, 1);
  S21Matrix B(2, 1);

  A(0, 0) = 2.0;
  B(0, 0) = 2.0;
  B(1, 0) = 2.0;

  EXPECT_THROW(A * B, std::out_of_range);
}

TEST(MatrixOperatorsTest, Eq_PEREMESHENIE) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  S21Matrix expected(2, 2);

  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;

  B(0, 0) = 1.0;
  B(0, 1) = 0.0;
  B(1, 0) = 0.0;
  B(1, 1) = 1.0;

  expected(0, 0) = 1.0;
  expected(0, 1) = 2.0;
  expected(1, 0) = 3.0;
  expected(1, 1) = 4.0;

  S21Matrix result;
  S21Matrix tmp = A * B;
  result = std::move(tmp);

  ASSERT_TRUE(result == expected);
}

TEST(MatrixOperatorsTest, MulNumberOperator) {
  S21Matrix A(2, 2);
  S21Matrix expected(2, 2);

  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;

  expected(0, 0) = 2.0;
  expected(0, 1) = 4.0;
  expected(1, 0) = 6.0;
  expected(1, 1) = 8.0;

  S21Matrix result = A * 2.0;

  ASSERT_TRUE(result == expected);
}

//

TEST(MatrixOperatorsTest, AddOperator_eq) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  S21Matrix expected(2, 2);

  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;

  B(0, 0) = 1.0;
  B(0, 1) = 1.0;
  B(1, 0) = 1.0;
  B(1, 1) = 1.0;

  expected(0, 0) = 2.0;
  expected(0, 1) = 3.0;
  expected(1, 0) = 4.0;
  expected(1, 1) = 5.0;

  A += B;

  ASSERT_TRUE(A == expected);
}

TEST(MatrixOperatorsTest, SubOperator_eq) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  S21Matrix expected(2, 2);

  A(0, 0) = 3.0;
  A(0, 1) = 4.0;
  A(1, 0) = 5.0;
  A(1, 1) = 6.0;

  B(0, 0) = 1.0;
  B(0, 1) = 1.0;
  B(1, 0) = 1.0;
  B(1, 1) = 1.0;

  expected(0, 0) = 2.0;
  expected(0, 1) = 3.0;
  expected(1, 0) = 4.0;
  expected(1, 1) = 5.0;

  A -= B;

  ASSERT_TRUE(A == expected);
}

TEST(MatrixOperatorsTest, MulMatrixOperator_eq) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  S21Matrix expected(2, 2);

  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;

  B(0, 0) = 1.0;
  B(0, 1) = 0.0;
  B(1, 0) = 0.0;
  B(1, 1) = 1.0;

  expected(0, 0) = 1.0;
  expected(0, 1) = 2.0;
  expected(1, 0) = 3.0;
  expected(1, 1) = 4.0;

  A *= B;

  ASSERT_TRUE(A == expected);
}

TEST(MatrixOperatorsTest, MulNumberOperator_eq) {
  S21Matrix A(2, 2);
  S21Matrix expected(2, 2);

  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;

  expected(0, 0) = 2.0;
  expected(0, 1) = 4.0;
  expected(1, 0) = 6.0;
  expected(1, 1) = 8.0;

  A *= 2.0;

  ASSERT_TRUE(A == expected);
}

//

TEST(MatrixOperatorsTest, AssignmentOperator) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);

  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;

  B = A;

  ASSERT_TRUE(B == A);
}

TEST(MatrixOperatorsTest, EqualityOperator) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);

  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;

  B(0, 0) = 1.0;
  B(0, 1) = 2.0;
  B(1, 0) = 3.0;
  B(1, 1) = 4.0;

  ASSERT_TRUE(A == B);
}

TEST(MatrixOperatorsTest, IndexOperator_err) {
  S21Matrix A(2, 2);

  A(0, 0) = 1.0;
  A(1, 1) = 4.0;

  ASSERT_EQ(A(0, 0), 1.0);
  ASSERT_EQ(A(1, 1), 4.0);

  ASSERT_THROW(A(2, 2), std::out_of_range);
}

TEST(MatrixOperatorsTest, IndexOperator_correct_const) {
  S21Matrix A(2, 2);

  A(0, 0) = 1.0;
  A(1, 1) = 4.0;

  ASSERT_EQ(A(0, 0), 1.0);
  ASSERT_EQ(A(1, 1), 4.0);

  S21Matrix const B = A;
  ASSERT_EQ(B(1, 1), 4);
}

TEST(MatrixOperatorsTest, Const_IndexOperator_err) {
  S21Matrix A(2, 2);

  A(0, 0) = 1.0;
  A(1, 1) = 4.0;

  ASSERT_EQ(A(0, 0), 1.0);
  ASSERT_EQ(A(1, 1), 4.0);
  const S21Matrix A_const = A;
  ASSERT_THROW(A_const(4, 2), std::out_of_range);
}
