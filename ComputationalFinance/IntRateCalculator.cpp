#include "stdafx.h"
#include "IntRateCalculator.h"

using namespace std;

namespace FixedIncome {

	IntRateCalculator::IntRateCalculator( double rate )
		: m_rate( rate )
	{ }


	IntRateCalculator::IntRateCalculator( const IntRateCalculator &v )
		: m_rate( v.m_rate ) 
	{}

	IntRateCalculator &IntRateCalculator::operator=( const IntRateCalculator &v )
	{
		if( this != &v )
		{
			this->m_rate = v.m_rate;
		}

		return *this;
	}

	IntRateCalculator::~IntRateCalculator() { }
}