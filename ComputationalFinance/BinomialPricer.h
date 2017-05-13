#pragma once

namespace NumericalMethods
{
	class BinomialPricer
	{
	public:
		BinomialPricer( double price, double up, double down, double rate );
		BinomialPricer &operator= ( const BinomialPricer &p );

		~BinomialPricer();

		// Compute the risk-neutral probability
		double RiskNeutProb() const;

		// computing the stock price at node n, i
		double S( double S0, double U, double D, int n, int i ) const;

	protected:

		double m_price, m_rate, m_up, m_down;
	};
}