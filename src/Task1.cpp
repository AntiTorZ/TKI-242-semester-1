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
				if (std::abs(result(static_cast<size_t>(i), static_cast<size_t>(j))) <
					std::abs(result(static_cast<size_t>(minRow), static_cast<size_t>(j))))
				{
					minRow = i;
				}
			}

			result(static_cast<size_t>(minRow), static_cast<size_t>(j)) =
				-result(static_cast<size_t>(minRow), static_cast<size_t>(j));
		}

		return result;
	}
}
