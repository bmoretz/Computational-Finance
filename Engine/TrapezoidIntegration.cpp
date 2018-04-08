#include "stdafx.h"
#include "TrapezoidIntegration.h"
#include "MathFunction.h"

namespace NumericalMethods
{
	namespace
	{
		const int DEFAULT_NUM_INTERVALS = 100;
	}

	TrapezoidIntegration::TrapezoidIntegration( MathFunction<double> &f ) :
		m_f( f ),
		m_numIntervals( DEFAULT_NUM_INTERVALS )
	{
	}

	TrapezoidIntegration::TrapezoidIntegration( const TrapezoidIntegration &t ) :
		m_f( t.m_f ),
		m_numIntervals( t.m_numIntervals )
	{
	}

	TrapezoidIntegration::~TrapezoidIntegration() = default;

	TrapezoidIntegration& TrapezoidIntegration::operator=( const TrapezoidIntegration &t )
	{
		if( this != &t )
		{
			m_f = t.m_f;
			m_numIntervals = t.m_numIntervals;
		}

		return *this;
	}

	void TrapezoidIntegration::setNumIntervals( const int n )
	{
		m_numIntervals = n;
	}

	double TrapezoidIntegration::getIntegral( const double a, const double b ) const
	{
		auto S = 0.0;
		const auto intSize = ( b - a ) / m_numIntervals;
		auto x = a;

		for( auto index = 0; index < m_numIntervals; ++index )
		{
			const auto midpt = ( m_f( x ) + m_f( x + intSize ) ) / 2;

			S += intSize * midpt;
			x += intSize;
		}

		return S;
	}
}
