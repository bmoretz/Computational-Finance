#include "stdafx.h"
#include "Common.h"
#include "OptionPricer.h"

using namespace std;
using namespace Common;
using namespace NumericalMethods;

// Validation Source: 
// http://www.hoadley.net/options/binomialtree.aspx?tree=B
namespace Derivative
{
	OptionPricer::OptionPricer( double price, double up, double down, double rate, int steps, double strike )
		: BinomialPricer( price, up, down, rate ),
		m_steps( 0 ),
		m_strike( 0 )
	{
	}

	OptionPricer::~OptionPricer()
	{
	}

	double OptionPricer::PriceByCRR() const
	{
		auto prob = RiskNeutProb();

		vector<double> price( m_steps + 1 );

		for( auto index = 0; index <= m_steps; index++ )
		{
			price.at( index ) = CallPayoff( S( m_price, m_up, m_down, m_steps, index ) );
		}

		for( auto n = m_steps - 1; n >= 0; n-- )
		{
			for( auto index = 0; index <= m_steps; index++ )
			{
				price.at( index ) = ( prob * price.at( index + 1 ) + ( 1 - prob ) * price.at( index ) ) / ( 1 + m_rate );
			}
		}

		return price.at( 0 );
	}

	double OptionPricer::CallPayoff( double z ) const
	{
		return z > m_strike ? z - m_strike : Zero;
	}
}
