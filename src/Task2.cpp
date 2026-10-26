#include "../include/Task2.h"

namespace miit::algebra
{
	Task2::Task2(Matrix& matrix, const Generator& generator)
		: Exercise(matrix, generator)
	{
	}

	Matrix& Task2::Solve()
	{
		result = OurMatrix;

		if (result.rowsCount() == 0 || result.columnsCount() == 0)
		{
			return result;
		}

		const int maximumValue = result.maximum();

		size_t row = 0;

		while (row < result.rowsCount())
		{
			bool containsMaximum = false;

			for (size_t column = 0; column < result.columnsCount(); ++column)
			{
				if (result(static_cast<size_t>(row), static_cast<size_t>(column)) == maximumValue)
				{
					containsMaximum = true;
					break;
				}
			}

			if (containsMaximum)
			{
				result.removeRow(row);
			}
			else
			{
				++row;
			}
		}

		return result;
	}
}
