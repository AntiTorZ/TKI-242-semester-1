#pragma once

#include "Exercise.h"

namespace miit::algebra
{
	/**
	 * @brief Реализация первого задания варианта 4
	 */
	class Task1 : public Exercise
	{
	private:
		/**
		* @brief Матрица с результатом первого задания
		*/
		Matrix result;

	public:
		/**
		* @brief Создать объект первого задания варианта 4
		* @param matrix Матрица, над которой будет выполняться задание
		* @param generator Генератор для заполнения матрицы
		*/
		Task1(Matrix& matrix, const Generator& generator);

		/**
		* @brief Заменить минимальный по модулю элемент каждого столбца на противоположный
		* @return Матрица после выполнения первого задания
		*/
		Matrix& Solve() override;
	};
}
