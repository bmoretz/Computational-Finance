#include "stdafx.h"
#include "IntRateCalculator.h"

namespace FixedIncome {

	IntRateCalculator::IntRateCalculator( double rate )
		: m_rate( rate )
	{ }


	IntRateCalculator::IntRateCalculator( const IntRateCalculator &v )
		: m_rate( v.m_rate ) 
	{}

	IntRateCalculator &IntRateCalculator::operator=( const IntRateCalculator &v )
	{
		if( &v != this )
		{
			this->m_rate = v.m_rate;
		}

		return *this;
	}

	IntRateCalculator::~IntRateCalculator()
	{ }


	inline double IntRateCalculator::singlePeriod( double value )
	{
		double f = value * ( 1 + this->m_rate );

		return f;
	}
}