#pragma once

namespace NumericalMethods {

	class BinomialPricer
	{
	public:

		BinomialPricer();

		BinomialPricer &operator= ( const BinomialPricer &p );

		~BinomialPricer();

		// Compute the risk-neutral probability
		double RiskNeutProb();

		// computing the stock price at node n, i
		double S( double S0, double U, double D, int n, int i );

		int Initialize( std::istream& input );

	private:

		double m_price, m_rate, m_up, m_down;
	};
}