#include "stdafx.h"
#include "TwoDimensionalLPSolver.h"

#include "Matrix.h"
#include "LPSolver.h"
#include <utility>

using std::vector;

namespace NumericalMethods
{
	TwoDimensionalLPSolver::
	TwoDimensionalLPSolver( Vector c, Vector A1, Vector A2, Vector b ) :
		m_c( std::move( c ) ),
		m_A1( std::move( A1 ) ),
		m_A2( std::move( A2 ) ),
		m_b( std::move( b ) )
	{
	}

	TwoDimensionalLPSolver& TwoDimensionalLPSolver::operator=( const TwoDimensionalLPSolver &p )
	{
		if( this != &p )
		{
			m_c = p.m_b;
			m_A1 = p.m_A1;
			m_A2 = p.m_A2;
			m_b = p.m_b;
		}

		return *this;
	}

	bool TwoDimensionalLPSolver::solveProblem( Vector &results, double &objValue )
	{
		const auto size = m_b.size();
		Matrix A( size, 2 );

		for( auto j = 0; j < size; ++j )
		{
			A[ j ][ 0 ] = m_A1[ j ];
			A[ j ][ 1 ] = m_A2[ j ];
		}

		LPSolver solver( A, m_b, m_c );
		
		solver.setMaximization();

		return solver.solve( results, objValue ) == LPSolver::ResultType::FEASIBLE;
	}
}