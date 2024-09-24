CC=gcc
CFLAGS=-std=c++17 -pedantic -Wall -Werror -Wextra
DEBUG_FLAG= -g

C_FILES = $(wildcard *.cpp)

O_FILES = $(subst .cpp,.o, $(C_FILES))

# Директория для тестов
TEST_DIR=./tests/
TEST_FILES=$(wildcard ./tests/*.cpp)
OUT_TEST=$(TEST_DIR)test.out
OS := $(shell uname -s)

# Флаги для линукса отдельно
ifeq ($(OS),Linux)
	OPEN_CMD = xdg-open
	TEST_LIBS = -lgtest -lsubunit -lrt -lm -pthread -lstdc++
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
	TEST_LIBS = -lgtest -pthread -lstdc++
endif

all: clean s21_matrix_oop.a

s21_matrix_oop.a: $(O_FILES)
	ar rcs s21_matrix_oop.a $^
	ranlib s21_matrix_oop.a

test: rebuild
	${OUT_TEST}
	
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

build: clean
	$(CC) $(CFLAGS) -o ${OUT_TEST} $(C_FILES) $(TEST_FILES) $(TEST_LIBS)

debug: clean
	$(CC) $(CFLAGS) $(DEBUG_FLAG) -o ${OUT_TEST} $(C_FILES) $(TEST_FILES) $(TEST_LIBS)

gcov_report: clean
	$(CC) $(CFLAGS) --coverage -o ./tests/gtest_test $(C_FILES) $(TEST_FILES) $(TEST_LIBS)
	chmod +x ./tests/gtest_test
	./tests/gtest_test
	lcov --capture --branch-coverage --directory . --output-file ./tests/coverage.info --no-external --ignore-errors inconsistent,inconsistent
	lcov --list ./tests/coverage.info
	genhtml ./tests/coverage.info --output-directory ./tests/coverage_report
	$(OPEN_CMD) ./tests/coverage_report/index.html

valgrind: rebuild
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=leaks_log.txt $(OUT_TEST)
	echo --- Valgrind summary --- && cat leaks_log.txt | grep 'total heap usage' && cat leaks_log.txt | grep 'ERROR SUMMARY'

style_test:
	clang-format -n */*.cpp */*.h
	clang-format -n *.cpp *.h

format_style:
	clang-format -i */*.cpp */*.h
	clang-format -i *.cpp *.h

clean: clean_test
	rm -rf *.o */*.o s21_matrix_oop.a *.out report debug test.out leaks_log.txt

clean_test:
	rm -rf ./tests/*.gc* ./tests/*.info ./tests/gtest_test ./tests/coverage_report ./tests/*.out ./tests/*.out.*

rebuild: clean build

# Собираем docker image с тегом 'v1' на основании dockerfile и создаем контейнер
docker_build:
	docker rm decimal_vault
	docker image rm vault:v1
	docker build -t vault:v1 .
	docker create -it --name decimal_vault vault:v1
	docker start -i decimal_vault
