# S21 Matrix Library

## Описание
**S21 Matrix Library** - это доработанная библиотека для работы с матрицами, предыдущая версия на языке C расположена [тут](https://github.com/RimTanaka/s21_matrix). Библиотека предоставляет собой набор функций для выполнения основных операций, таких как создание, сложение, вычитание, умножение, транспонирование, нахождение определителя, матрицы дополнений с перегрузкой соответствующих операторов. Библиотека реализована на языке **C++**, соответствует стандарту **C++17**, использует **Google Style** для оформления кода и поддерживает статическую компиляцию.

## Основные возможности
- Создание и удаление матриц
- Операции сложения, вычитания и умножения матриц
- Транспонирование матрицы
- Нахождение обратной матрицы
- Вычисление определителя и матрицы алгебраических дополнений
- Проверка матриц на равенство
- Перегрузка операторов для работы с матрицами
- Обработка ошибок с использованием исключений

## Структура класса
Матрица представлена классом `S21Matrix`:

```cpp

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

  void AllocateMemory();
  void CopyMatrix(const S21Matrix& other);
  void FreeMemory();
  S21Matrix Minor(int, int) const;

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  int GetRows() const;
  int GetCols() const;
  void SetRows(int rows);
  void SetCols(int cols);

  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);

  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*(const double num) const;
  bool operator==(const S21Matrix& other) const;
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  double& operator()(int row, int col);
  const double& operator()(int row, int col) const;
};

```

## Основные методы:

| Операция    | Описание   | Исключительные ситуации |
| ----------- | ----------- | ----------- |
| `bool EqMatrix(const S21Matrix& other)` | Проверяет матрицы на равенство между собой. |  |
| `void SumMatrix(const S21Matrix& other)` | Прибавляет вторую матрицу к текущей | различная размерность матриц. |
| `void SubMatrix(const S21Matrix& other)` | Вычитает из текущей матрицы другую | различная размерность матриц. |
| `void MulNumber(const double num)` | Умножает текущую матрицу на число. |  |
| `void MulMatrix(const S21Matrix& other)` | Умножает текущую матрицу на вторую. | число столбцов первой матрицы не равно числу строк второй матрицы. |
| `S21Matrix Transpose()` | Создает новую транспонированную матрицу из текущей и возвращает ее. |  |
| `S21Matrix CalcComplements()` | Вычисляет матрицу алгебраических дополнений текущей матрицы и возвращает ее. | Матрица не является квадратной. |
| `double Determinant()` | Вычисляет и возвращает определитель текущей матрицы. | Матрица не является квадратной. |
| `S21Matrix InverseMatrix()` | Вычисляет и возвращает обратную матрицу. | Определитель матрицы равен 0. |

Помимо реализации данных операций, также реализованы конструкторы и деструкторы:

| Метод    | Описание   |
| ----------- | ----------- |
| `S21Matrix()` | Базовый конструктор, инициализирующий матрицу некоторой заранее заданной размерностью. |  
| `S21Matrix(int rows, int cols)` | Параметризированный конструктор с количеством строк и столбцов. | 
| `S21Matrix(const S21Matrix& other)` | Конструктор копирования. |
| `S21Matrix(S21Matrix&& other)` | Конструктор переноса. |
| `~S21Matrix()` | Деструктор. |

А также перегружены следующие операторы, частично соответствующие операциям выше:

| Оператор          | Описание   | Исключительные ситуации |
| ----------------- | ----------- | ----------- |
| `+`               | Сложение двух матриц.  | Различная размерность матриц. |
| `-`               | Вычитание одной матрицы из другой. | Различная размерность матриц. |
| `*`               | Умножение матриц и умножение матрицы на число. | Число столбцов первой матрицы не равно числу строк второй матрицы. |
| `==`              | Проверка на равенство матриц (`EqMatrix`). | |
| `=`               | Присвоение матрице значений другой матрицы. | |
| `+=`              | Присвоение сложения (`SumMatrix`).   | Различная размерность матриц. |
| `-=`              | Присвоение разности (`SubMatrix`). | Различная размерность матриц. |
| `*=`              | Присвоение умножения (`MulMatrix`/`MulNumber`). | Число столбцов первой матрицы не равно числу строк второй матрицы. |
| `(int i, int j)`  | Индексация по элементам матрицы (строка, колонка). | Индекс за пределами матрицы. |


- Программа разработана на языке C++ стандарта C++17 с использованием компилятора gcc.
- При написании кода придерживался Google Style.
- Реализация матрицы в виде класса `S21Matrix`.
- Используются приватные поля `matrix_`, `rows_` и `cols_`.
- Реализован доступ к приватным полям `rows_` и `cols_` через accessor и mutator. При увеличении размера матрица дополняется нулевыми элементами, при уменьшении лишнее просто отбрасывается.
- Оформил решение как статическую библиотеку (с заголовочным файлом s21_matrix_oop.h).
- Реализовал операции, описанные выше.
- Подготовь полное покрытие unit-тестами функций библиотеки c помощью библиотеки GTest и lcov(`100%`).
- Предусмотрел Makefile для сборки библиотеки и тестов (с целями all, clean, test, s21_matrix_oop.a).

