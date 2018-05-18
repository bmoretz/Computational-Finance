#include "stdafx.h"
#include "MIPSolver.h"
#include "Matrix.h"

#include <glpk.h>

namespace NumericalMethods
{
	MIPSolver::MIPSolver( Matrix &A, const std::vector<double> &b, const std::vector<double> &c )
		: LPSolver( A, b, c )
	{
	}

	MIPSolver& MIPSolver::operator=( const MIPSolver &p )
	{
		return *this;
	}

	void MIPSolver::setColInteger( int colNum )
	{
		glp_set_col_kind( getLP(), colNum + 1, GLP_IV );
	}

	void MIPSolver::setColBinary( int colNum )
	{
		glp_set_col_kind( getLP(), colNum + 1, GLP_BV );
	}

	LPSolver::ResultType MIPSolver::solve( std::vector<double> &result, double &objValue )
	{
		glp_simplex( getLP(), nullptr );

		auto res = glp_intopt( getLP(), nullptr );

		if( res != 0 )
		{
		}

		result.resize( getNumCols(), 0 );
		objValue = glp_mip_obj_val( getLP() );

		for( auto i = 0; i < getNumCols(); ++i )
		{
			result[ i ] = glp_mip_col_val( getLP(), i + 1 );

		}

		return LPSolver::FEASIBLE;
	}
}
