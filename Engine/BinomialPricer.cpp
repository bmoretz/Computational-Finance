#include "stdafx.h"
#include "BinomialPricer.h"

using namespace std;

namespace NumericalMethods
{
	BinomialPricer::BinomialPricer( double price, double up, double down, double rate ) 
	{
		ASSERT_WITH_MSG( price >= 0 || up <= -1.0 || down <= -1.0 || up <= down || rate <= -1.0, "Must have non-zero price, up/down interval, and non-negative rate." );

		ASSERT_WITH_MSG( rate >= up || rate <= down, "Arbitrage situation detected." );

		m_price = price; m_rate = rate; m_up = up; m_down = down;
	}
	
	BinomialPricer &BinomialPricer::operator=( const BinomialPricer &p )
	{
		if( &p != this )
		{
			this->m_price = p.m_price;
			this->m_up = p.m_up;
			this->m_down = p.m_down;
			this->m_rate = p.m_rate;
		}

		return *this;
	}

	BinomialPricer::~BinomialPricer() { }

	double BinomialPricer::RiskNeutProb() const
	{
		return ( m_rate - m_down ) / ( m_up - m_down );
	}

	double BinomialPricer::S( double S0, double U, double D, int n, int i ) const
	{
		return S0 * pow( 1 + U, i ) * pow( 1 + D, n - i );
	}
}