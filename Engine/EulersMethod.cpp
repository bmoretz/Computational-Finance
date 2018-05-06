#include "stdafx.h"
#include "EulersMethod.h"
#include "MathFunction.h"

namespace NumericalMethods
{
	EulersMethod::EulersMethod( MathFunction<double> &f )
		: m_f( f )
	{
	}

	EulersMethod& EulersMethod::operator=( const EulersMethod &p )
	{
		if( this != &p )
		{
			m_f = p.m_f;
		}

		return *this;
	}

	double EulersMethod::solve( const int n, const double x0, const double y0, const double c ) const
	{
		// problem: y' = f( x, y ) ; y( x0 ) = y0

		auto x = x0;
		auto y = y0;
		const auto h = ( c - x0 ) / n;

		for( auto index = 0; index < n; index++ )
		{
			const auto F = m_f( x, y );
			const auto G = m_f( x + h, y + h * F );

			// Update values of x, y
			x += h;
			y += h * ( F + G ) / 2;
		}

		return y;
	}
}