#include <iostream>

#include "../include/Matrix.h"
#include "../include/Generator.h"
#include "../include/RandomGenerator.h"
#include "../include/IStreamGenerator.h"
#include "../include/ConstantGenerator.h"
#include "../include/ZeroGenerator.h"
#include "../include/Task1.h"
#include "../include/Task2.h"

using namespace miit::algebra;

/**
 * @brief Варианты выбора способа заполнения матрицы
 */
enum MyEnum
{
	ONE = 1, TWO, THREE, FOUR,
};

/**
 * @brief Выбрать генератор, заполнить им матрицу и сразу решить оба задания
 * @param matrix Матрица, которую заполняет выбранный генератор и над которой выполняются задания
 */
void chooseGenerator(Matrix& matrix);

/**
 * @brief Заполнить матрицу заданным генератором и сразу решить оба задания
 * @param matrix Матрица, над которой выполняются задания
 * @param generator Конкретный генератор, выбранный пользователем
 */
void solveTasks(Matrix& matrix, const Generator& generator);

/**
 * @brief Точка входа в программу
 */
int main()
{
	system("chcp 1251");
	system("CLS");

	try {
		int rows = 0;
		int columns = 0;

		std::cout << "Введите число строк n: ";
		std::cin >> rows;
		std::cout << "Введите число столбцов m: ";
		std::cin >> columns;

		Matrix matrix(rows, columns);

		chooseGenerator(matrix);
	}
	catch (const std::exception& e)
	{
		std::cout << "Ошибка: " << e.what() << std::endl;
	}

	return 0;
}


void chooseGenerator(Matrix& matrix)
{
	int choice = 0;

	std::cout << "Как заполнить матрицу?\n"
		<< ONE << " - случайными числами\n"
		<< TWO << " - вводом с клавиатуры\n"
		<< THREE << " - одним конкретным числом\n"
		<< FOUR << " - нулями\n"
		<< "Ваш выбор: ";

	std::cin >> choice;

	switch (choice)
	{
		case ONE:
		{
			int min = 0; int max = 0;

			std::cout << "Введите минимум: ";
			std::cin >> min;

			std::cout << "Введите максимум: ";
			std::cin >> max;

			if (min >= max)
			{
				std::cout << "Неверный ввод\n";
				exit(1);
			}

			const RandomGenerator generator(min, max);
			solveTasks(matrix, generator);
			return;
		}

		case TWO:
		{
			const IStreamGenerator generator(std::cin);
			solveTasks(matrix, generator);
			return;
		}

		case THREE:
		{
			int value = 0;
			std::cout << "Введите число: ";
			std::cin >> value;

			const ConstantGenerator generator(value);
			solveTasks(matrix, generator);
			return;
		}

		case FOUR:
		{
			const ZeroGenerator generator;
			solveTasks(matrix, generator);
			return;
		}

		default:
		{
			std::cout << "Неверный выбор\n";
			exit(1);
		}
	}
}


void solveTasks(Matrix& matrix, const Generator& generator)
{
	matrix.fill(generator);

	Task1 task1(matrix, generator);
	Task2 task2(matrix, generator);

	std::cout << "\nИсходная матрица:\n" << matrix;

	Matrix result1 = task1.Solve();
	std::cout << "\nПосле задания 1\n" << result1;

	Matrix result2 = task2.Solve();

	std::cout << "\nПосле задания 2\n";

	if (result2.rowsCount() == 0 || result2.columnsCount() == 0)
	{
		std::cout << "Матрица пустая\n";
	}
	else
	{
		std::cout << result2;
	}
}
