#pragma once

#include "Exercise.h"

namespace miit::algebra
{
	/**
	 * @brief Реализация второго задания варианта 4
	 */
	class Task2 : public Exercise
	{
	private:
		/**
		* @brief Матрица с результатом второго задания
		*/
		Matrix result;

	public:
		/**
		* @brief Создать объект второго задания варианта 4
		* @param matrix Матрица, над которой будет выполняться задание
		* @param generator Генератор для заполнения матрицы
		*/
		Task2(Matrix& matrix, const Generator& generator);

		/**
		* @brief Удалить все строки, содержащие максимальные элементы
		* @return Матрица после выполнения второго задания
		*/
		Matrix& Solve() override;
	};
}
