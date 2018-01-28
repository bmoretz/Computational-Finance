#include "stdafx.h"
#include "BisectionSolver.h"
#include "MathFunction.h"

using namespace std;

namespace NumericalMethods
{
	namespace
	{
		const double DEFAULT_ERROR = 0.001;
	}

	BisectionSolver::BisectionSolver( MathFunction<double> &f ) :
		m_f( f ),
		m_error( DEFAULT_ERROR )
	{
	}

	BisectionSolver::BisectionSolver( const BisectionSolver &p ) :
		m_f( p.m_f ),
		m_error( DEFAULT_ERROR )
	{
	}

	BisectionSolver::~BisectionSolver()
	{
	}

	BisectionSolver& BisectionSolver::operator=( const BisectionSolver &p )
	{
		if( this != &p )
		{
			m_f = p.m_f;
			m_error = p.m_error;
		}

		return *this;
	}

	double BisectionSolver::getRoot( double x1, double x2 ) const
	{
		auto root = 0.0;

		while( abs( x1 - x2 ) > m_error )
		{
			auto x3 = root = ( x1 + x2 ) / 2.0;

			if( m_f( x1 ) * m_f( x2 ) < 0 )
			{
				x2 = x3;
			}
			else
			{
				x1 = x3;
			}

			if( m_f( x1 ) * m_f( x2 ) > 0 )
			{
				cout << " function does not converge " << endl;
				break;
			}
		}

		return root;
	}
}
