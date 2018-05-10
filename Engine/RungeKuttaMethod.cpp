#include "stdafx.h"
#include "RungeKuttaMethod.h"

namespace NumericalMethods
{
	RungeKuttaMethod::RungeKuttaMethod( MathFunction<double> &f )
		: m_f( f )
	{
	}

	RungeKuttaMethod& RungeKuttaMethod::operator=( const RungeKuttaMethod &p )
	{
		if( this != &p )
		{
			m_f = p.m_f;
		}

		return *this;
	}

	double RungeKuttaMethod::solve( const int n, const double x0, const double y0, const double c ) const
	{
		// problem: y' = f( x, y ) ; y( x0 ) = y0

		auto x = x0;
		auto y = y0;
		const auto h = ( c - x0 ) / n;

		for( auto index = 0; index < n; index++ )
		{
			const auto k1 = h * m_f( x, y );
			const auto k2 = h * m_f( x + h / 2, y + k1 / 2 );
			const auto k3 = h * m_f( x + h / 2, y + k2 / 2 );
			const auto k4 = h * m_f( x + h, y + k3 );

			x += h;
			y += ( k1 + 2 * k2 + 2 * k3 + k4 ) / 6;
		}

		return y;
	}
}