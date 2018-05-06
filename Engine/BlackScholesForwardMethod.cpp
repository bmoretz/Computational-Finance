#include "stdafx.h"
#include "BlackScholesForwardMethod.h"

#include <cmath>
#include <vector>
#include <iomanip>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;
using std::setw;

namespace NumericalMethods
{
	BlackScholesForwardMethod::BlackScholesForwardMethod( double expiration, double maxPrice, double strike,
														double intRate )
		: m_expiration( expiration ),
		m_maxPrice( maxPrice ),
		m_strike( strike ),
		m_intRate( intRate )
	{
	}

	BlackScholesForwardMethod& BlackScholesForwardMethod::operator=( const BlackScholesForwardMethod &p )
	{
		if( this != &p )
		{
			m_expiration = p.m_expiration;
			m_maxPrice = p.m_maxPrice;
			m_strike = p.m_strike;
			m_intRate = p.m_intRate;
		}

		return *this;
	}

	vector<double> BlackScholesForwardMethod::solve( double volatility, const int nx, const int timeSteps ) const
	{
		const auto dt = m_expiration / static_cast<double>( timeSteps );
		const auto dx = m_maxPrice / static_cast<double>( nx );

		vector<double> a( nx - 1 );
		vector<double> b( nx - 1 );
		vector<double> c( nx - 1 );

		int i;
		for( i = 0; i < nx - 1; i ++ )
		{
			b[ i ] = 1.0 - m_intRate * dt - dt * pow( volatility * ( i + 1 ), 2 );
		}

		for( i = 0; i < nx - 2; i++ )
		{
			c[ i ] = 0.5 * dt * pow( volatility * ( i + 1 ), 2 ) - 0.5 * dt * m_intRate * ( i + 1 );
		}

		for( i = 0; i < nx - 1; i++ )
		{
			a[ i ] = 0.5 * dt * pow( volatility * ( i + 1 ), 2 ) - 0.5 * dt * m_intRate * ( i + 1 );
		}

		vector<double> u( ( nx - 1 ) * ( timeSteps + 1 ) );

		auto u0 = 0.0;

		for( i = 0; i < nx - 1; i++ )
		{
			u0 += dx;
			u[ i + 0 * ( nx - 1 ) ] = ( u0 - m_strike ) > 0.0 ? u0 - m_strike : 0.0;
		}

		for( auto j = 0; j < timeSteps; j++ )
		{
			const auto t = static_cast<double>( j ) * m_expiration / static_cast<double>( timeSteps );

			auto p = 0.5 * dt * ( nx - 1 ) * ( volatility * volatility * ( nx - 1 ) + m_intRate )
				* ( m_maxPrice - m_strike * exp( -m_intRate * t ) );

			for( i = 0; i < nx - 1; i++ )
			{
				u[ i + ( j + 1 ) * ( nx - 1 ) ] = b[ i ] * u[ i + j * ( nx - 1 ) ];
			}

			for( i = 0; i < nx - 2; i++ )
			{
				u[ i + ( j + 1 ) * ( nx - 1 ) ] += c[ i ] * u[ i + 1 + j * ( nx - 1 ) ];
			}

			for( i = 1; i < nx - 1; i++ )
			{
				u[ i + ( j + 1 ) * ( nx - 1 ) ] += a[ i ] * u[ i - 1 + j * ( nx - 1 ) ];
			}

			u[ nx - 2 + ( j + 1 ) * ( nx - 1 ) ] += p;
		}

		return u;
	}
}