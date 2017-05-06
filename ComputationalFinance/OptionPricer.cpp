#include "stdafx.h"
#include "OptionPricer.h"

using namespace std;
using namespace ComputationalFinance;

// Validation Source: 
// http://www.hoadley.net/options/binomialtree.aspx?tree=B
namespace NumericalMethods 
{
	OptionPricer::OptionPricer( double price, double up, double down, double rate, int steps, double strike )
		: BinomialPricer( price, up, down, rate )
	{ }

	OptionPricer::~OptionPricer() { }

	double OptionPricer::PriceByCRR()
	{
		double prob = RiskNeutProb();

		vector<double> price( m_steps + 1 );

		for( auto index = 0; index <= m_steps; index++ ) {
			price.at( index ) = CallPayoff( S( m_price, m_up, m_down, index, m_strike ) );
		}

		for( auto n = m_steps - 1; n >= 0; n-- ) {
			for( auto index = 0; index <= m_steps; index++ ) {
				price.at( index ) = ( prob * price.at( index + 1 ) + ( 1 - prob ) * price.at( index ) ) / ( 1 + m_rate );
			}
		}

		return price.at( 0 );
	}

	double OptionPricer::CallPayoff( double z )
	{
		return z > m_strike ? z - m_strike : Zero;
	}
}