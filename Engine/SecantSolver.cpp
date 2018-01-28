#include "stdafx.h"
#include "SecantSolver.h"
#include "MathFunction.h"

using namespace std;

namespace NumericalMethods
{
	namespace
	{
		const double DEFAULT_ERROR = 0.001;
	}

	SecantSolver::SecantSolver( MathFunction<double> &f ) :
		m_f( f ),
		m_error( DEFAULT_ERROR )
	{
	}

	SecantSolver::SecantSolver( const SecantSolver &p ) :
		m_f( p.m_f ),
		m_error( DEFAULT_ERROR )
	{
	}

	SecantSolver::~SecantSolver()
	{
	}

	SecantSolver& SecantSolver::operator=( const SecantSolver &p )
	{
		if( this != &p )
		{
			m_f = p.m_f;
			m_error = p.m_error;
		}

		return *this;
	}

	double SecantSolver::getRoot( double a, double b ) const
	{
		auto root = 0.0;

		auto fa = m_f( a );
		auto fb = m_f( b );

		auto c = 0.0, fc = 0.0;

		do
		{
			c = b - fb * ( b - a ) / ( fb - fa );
			root = c;

			fc = m_f( c );

			a = b;
			fa = fb;
			b = c;
			fb = fc;
		} while( abs( a - b ) > m_error );

		return root;
	}
}