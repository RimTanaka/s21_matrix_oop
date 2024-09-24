#include "s21_matrix_oop.h"

// Приватные методы
void S21Matrix::AllocateMemory() {
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_]();
  }
}

void S21Matrix::CopyMatrix(const S21Matrix& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  AllocateMemory();
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::FreeMemory() {
  if (matrix_) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
  matrix_ = nullptr;
}

// Конструкторы и деструктор
S21Matrix::S21Matrix() : rows_(3), cols_(3) { AllocateMemory(); }

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::invalid_argument("Размеры матрицы не могут быть меньше 1.");
  }
  AllocateMemory();
}

S21Matrix::S21Matrix(const S21Matrix& other) { CopyMatrix(other); }

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
  if (matrix_) {
    FreeMemory();
  }
}

// Методы доступа
int S21Matrix::GetRows() const { return rows_; }
int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(int rows) {
  if (rows != rows_) {
    S21Matrix temp(rows, cols_);
    int min_rows = std::min(rows, rows_);
    for (int i = 0; i < min_rows; i++) {
      for (int j = 0; j < cols_; ++j) {
        temp.matrix_[i][j] = matrix_[i][j];
      }
    }
    *this = std::move(temp);
  }
}

void S21Matrix::SetCols(int cols) {
  if (cols != cols_) {
    S21Matrix temp(rows_, cols);
    int min_cols = std::min(cols, cols_);
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < min_cols; j++) {
        temp.matrix_[i][j] = matrix_[i][j];
      }
    }
    *this = std::move(temp);
  }
}

// Операции над матрицами
bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  int flag = true;
  if (rows_ != other.rows_ || cols_ != other.cols_) flag = false;
  for (int i = 0; i < rows_ && flag; ++i) {
    for (int j = 0; j < cols_ && flag; ++j) {
      if (std::fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-7) {
        flag = false;
      }
    }
  }
  return flag;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range("Матрицы должны быть одинаковой длинны и ширины");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range("Матрицы должны быть одинаковой длинны и ширины");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(double num) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::out_of_range(
        "Число столбцов первой матрицы должно быть равно числу строк второй "
        "матрицы");
  }

  S21Matrix result(rows_, other.cols_);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      result.matrix_[i][j] = 0;
      for (int k = 0; k < cols_; k++) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }

  *this = result;
}

S21Matrix S21Matrix::Transpose() const {
  S21Matrix result(cols_, rows_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }

  return result;
}

S21Matrix S21Matrix::Minor(int row, int col) const {
  S21Matrix result(rows_ - 1, cols_ - 1);
  for (int i = 0, new_i = 0; i < rows_; i++) {
    if (i == row) continue;
    for (int j = 0, new_j = 0; j < cols_; j++) {
      if (j == col) continue;
      result.matrix_[new_i][new_j] = matrix_[i][j];
      new_j++;
    }
    new_i++;
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() const {
  if (cols_ != rows_)
    throw std::invalid_argument("Матрица должна быть квадратной.");
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix minor_matrix = Minor(i, j);
      double minor_det = minor_matrix.Determinant();
      result.matrix_[i][j] = ((i + j) % 2 == 0) ? minor_det : -minor_det;
    }
  }
  return result;
}

double S21Matrix::Determinant() const {
  if (cols_ != rows_)
    throw std::invalid_argument("Матрица должна быть квадратной.");

  if (rows_ == 1) {
    return matrix_[0][0];
  }

  if (rows_ == 2) {
    return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  }

  double det = 0.0;
  for (int j = 0; j < rows_; j++) {
    S21Matrix tmp = Minor(j, 0);
    det += matrix_[j][0] * ((j % 2 == 0) ? 1.0 : -1.0) * tmp.Determinant();
  }

  return det;
}

S21Matrix S21Matrix::InverseMatrix() const {
  if (cols_ != rows_)
    throw std::invalid_argument("Матрица должна быть квадратной.");
  S21Matrix inverse_matrix;
  if (rows_ == 1) {
    S21Matrix inverse_matr(1, 1);
    inverse_matr(0, 0) = 1.0 / (*this)(0, 0);
    inverse_matrix = inverse_matr;
  } else {
    S21Matrix complements = this->CalcComplements();
    S21Matrix transposed = complements.Transpose();
    double det = this->Determinant();
    if (det == 0) {
      throw std::runtime_error("Детерминант равен 0.");
    }
    inverse_matrix = transposed * (1.0 / det);
  }
  return inverse_matrix;
}

// Перегрузка операторов
S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) const {
  S21Matrix result(*this);
  result.MulNumber(num);
  return result;
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    FreeMemory();
    CopyMatrix(other);
  }
  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) {
  if (this != &other) {
    FreeMemory();
    matrix_ = other.matrix_;
    rows_ = other.rows_;
    cols_ = other.cols_;

    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  return EqMatrix(other);
}

double& S21Matrix::operator()(int row, int col) {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
    throw std::out_of_range("Индекс вне границ.");
  }
  return matrix_[row][col];
}

const double& S21Matrix::operator()(int row, int col) const {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
    throw std::out_of_range("Индекс вне границ.");
  }
  return matrix_[row][col];
}
