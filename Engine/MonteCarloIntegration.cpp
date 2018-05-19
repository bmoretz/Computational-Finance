#include "stdafx.h"
#include "MathFunction.h"
#include "MonteCarloIntegration.h"

#include <cmath>
#include <cstdlib>
#include <iostream>

#include <boost/math/distributions.hpp>
#include <boost/random.hpp>
#include <boost/random/uniform_real.hpp>

using namespace std;
using namespace boost::random;

namespace NumericalMethods
{
	static boost::rand48 random_generator;

	namespace
	{
		const int DEFAULT_NUM_SAMPLES = 1000;
	}

	MonteCarloIntegration::MonteCarloIntegration( MathFunction<double> &f )
		: m_f( f ),
		m_numSamples( DEFAULT_NUM_SAMPLES )
	{
	}

	MonteCarloIntegration& MonteCarloIntegration::operator=( const MonteCarloIntegration &p )
	{
		if( this != &p )
		{
			m_f = p.m_f;
			m_numSamples = p.m_numSamples;
		}

		return *this;
	}

	double MonteCarloIntegration::integrateRegion( const double a, const double b, const double min,
													const double max ) const
	{
		const uniform_real_distribution<> xDistrib( a, b );
		const uniform_real_distribution<> yDistrib( min, max );

		auto pointsIn = 0.0;
		auto pointsOut = 0.0;
		const auto positive = max > 0.0;

		for( auto index = 0; index < m_numSamples; ++index )
		{
			const auto x = xDistrib( random_generator );
			const auto y = m_f( x );

			const auto ry = yDistrib( random_generator );

			if( positive && min <= ry && ry <= max )
			{
				pointsIn++;
			}
			else if( !positive && y <= ry && ry <= max )
			{
				pointsIn++;
			}
			else
			{
				pointsOut++;
			}
		}

		auto percentageArea = 0.0;
		const auto total_points = pointsIn + pointsOut;

		if( total_points > 0 )
		{
			percentageArea = pointsIn / double( total_points );
		}

		if( percentageArea > 0 )
		{
			percentageArea = ( b - a ) * ( max - min ) * percentageArea;
		}

		return percentageArea;
	}


	double MonteCarloIntegration::getIntegral( const double a, const double b ) const
	{
		const uniform_real_distribution<> distrib( a, b );

		auto max = 0.0, min = 0.0;

		for( auto index = 0; index < m_numSamples; ++index )
		{
			const auto x = distrib( random_generator );
			const auto y = m_f( x );

			if( y > max )
				max = y;

			if( y < min )
				min = y;
		}

		const auto positiveIntg = max > 0 ? integrateRegion( a, b, 0, max ) : 0;
		const auto negativeIntg = min < 0 ? integrateRegion( a, b, min, 0 ) : 0;

		return positiveIntg - negativeIntg;
	}
}
