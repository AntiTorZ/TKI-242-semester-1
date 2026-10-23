#include "../include/Task1.h"
#include <cstdlib>

namespace miit::algebra
{
	Task1::Task1(Matrix& matrix, const Generator& generator)
		: Exercise(matrix, generator)
	{
	}

	Matrix& Task1::Solve()
	{
		result = OurMatrix;

		for (size_t j = 0; j < result.columnsCount(); ++j)
		{
			size_t minRow = 0;

			for (size_t i = 1; i < result.rowsCount(); ++i)
			{
				if (std::abs(result(static_cast<int>(i), static_cast<int>(j))) <
					std::abs(result(static_cast<int>(minRow), static_cast<int>(j))))
				{
					minRow = i;
				}
			}

			result(static_cast<int>(minRow), static_cast<int>(j)) =
				-result(static_cast<int>(minRow), static_cast<int>(j));
		}

		return result;
	}
}
