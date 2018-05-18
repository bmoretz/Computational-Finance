#pragma once

#include "stdafx.h"
#include "LPSolver.h"

#include <vector>

namespace NumericalMethods
{
	class MIPSolver : public LPSolver
	{
	public:

		MIPSolver( Matrix &A, const std::vector<double> &b, const std::vector<double> &c );
		MIPSolver( const MIPSolver &p ) = default;
		~MIPSolver() = default;
		MIPSolver& operator=( const MIPSolver &p );

		void setColInteger( int colNum ) const;
		void setColBinary( int colNum ) const;
		virtual ResultType solve( std::vector<double> &result, double &objValue );
	};
}
