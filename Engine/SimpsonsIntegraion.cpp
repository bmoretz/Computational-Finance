#include "stdafx.h"
#include "SimpsonsIntegraion.h"
#include "MathFunction.h"

namespace NumericalMethods
{
	namespace
	{
		const int DEFAULT_NUM_INTERVALS = 100;
	}

	SimpsonsIntegraion::SimpsonsIntegraion( MathFunction<double> &f ) :
		m_f( f ),
		m_numIntervals( DEFAULT_NUM_INTERVALS )
	{
	}

	SimpsonsIntegraion::SimpsonsIntegraion( const SimpsonsIntegraion &t ) :
		m_f( t.m_f ),
		m_numIntervals( t.m_numIntervals )
	{
	}

	SimpsonsIntegraion::~SimpsonsIntegraion() = default;

	SimpsonsIntegraion& SimpsonsIntegraion::operator=( const SimpsonsIntegraion &t )
	{
		if( this != &t )
		{
			m_f = t.m_f;
			m_numIntervals = t.m_numIntervals;
		}

		return *this;
	}

	void SimpsonsIntegraion::setNumIntervals( const int n )
	{
		m_numIntervals = n;
	}

	double SimpsonsIntegraion::getIntegral( const double a, const double b ) const
	{
		auto S = 0.0;
		const auto intSize = ( b - a ) / m_numIntervals;
		auto x = a;

		for( auto index = 0; index < m_numIntervals; ++index )
		{
			S += ( intSize / 6 ) * ( m_f( x ) + m_f( x + intSize ) + 4 * m_f( ( x + x + intSize ) / 2 ) );
			x += intSize;
		}

		return S;
	}
}
