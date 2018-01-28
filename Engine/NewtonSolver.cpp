#include "stdafx.h"
#include "NewtonSolver.h"
#include "MathFunction.h"

using namespace std;

namespace NumericalMethods
{
	namespace
	{
		const double DEFAULT_ERROR = 0.001;
	}

	NewtonSolver::NewtonSolver( MathFunction<double> &f, MathFunction<double> &d ) :
		m_f( f ),
		m_derivative( d ),
		m_error( DEFAULT_ERROR )
	{
	}

	NewtonSolver::NewtonSolver( const NewtonSolver &p ) :
		m_f( p.m_f ),
		m_derivative( p.m_derivative ),
		m_error( DEFAULT_ERROR )
	{
	}

	NewtonSolver::~NewtonSolver()
	{
	}

	NewtonSolver& NewtonSolver::operator=( const NewtonSolver &p )
	{
		if( this != &p )
		{
			m_f = p.m_f;
			m_error = p.m_error;
		}

		return *this;
	}

	double NewtonSolver::getRoot( double x0 ) const
	{
		auto x1 = x0;

		do
		{
			x0 = x1;
			auto d = m_derivative( x0 );
			auto y = m_f( x0 );

			x1 = x0 - y / d;
		} while( abs( x0 - x1 ) > m_error );

		return x1;
	}
}
