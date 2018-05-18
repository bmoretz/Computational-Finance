#pragma once

#include "stdafx.h"

#include <vector>

namespace NumericalMethods
{
	class TwoDimensionalLPSolver
	{
	public:
		typedef std::vector<double> Vector;

		explicit TwoDimensionalLPSolver( Vector c, Vector A1, Vector A2, Vector b );
		TwoDimensionalLPSolver( const TwoDimensionalLPSolver &p ) = default;
		TwoDimensionalLPSolver& operator=( const TwoDimensionalLPSolver &p );

		~TwoDimensionalLPSolver() = default;

		bool solveProblem( Vector &results, double &objValue );
	private:
		std::vector<double> m_c;
		std::vector<double> m_A1;
		std::vector<double> m_A2;
		std::vector<double> m_b;
	};
}
