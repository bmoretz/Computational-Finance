#include "stdafx.h"
#include "MidpointIntegration.h"
#include "MathFunction.h"

namespace NumericalMethods
{
	namespace
	{
		const int DEFAULT_NUM_INTERVALS = 100;
	}

	MidpointIntegration::MidpointIntegration( MathFunction<double> &f ) :
		m_f( f ),
		m_numIntervals( DEFAULT_NUM_INTERVALS )
	{
	}

	MidpointIntegration::MidpointIntegration( const MidpointIntegration &mp ) :
		m_f( mp.m_f ),
		m_numIntervals( mp.m_numIntervals )
	{
	}

	MidpointIntegration::~MidpointIntegration() = default;

	MidpointIntegration& MidpointIntegration::operator=( const MidpointIntegration &mp )
	{
		if( this != &mp )
		{
			m_f = mp.m_f;
			m_numIntervals = mp.m_numIntervals;
		}

		return *this;
	}

	void MidpointIntegration::setNumIntervals( const int n )
	{
		m_numIntervals = n;
	}

	double MidpointIntegration::getIntegral( const double a, const double b ) const
	{
		auto S = 0.0;
		const auto intSize = ( b - a ) / m_numIntervals;
		auto x = a;

		for( auto index = 0; index < m_numIntervals; ++index )
		{
			const auto midpt = m_f( x + ( intSize / 2 ) );

			S += intSize * midpt;
			x += intSize;
		}

		return S;
	}
}
