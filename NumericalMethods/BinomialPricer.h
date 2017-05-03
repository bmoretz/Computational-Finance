#pragma once

#define ASSERT_WITH_MSG(cond, msg) do \
{ if (!(cond)) { std::ostringstream str; str << msg; std::cerr << str.str(); std::abort(); } \
} while(0)

namespace NumericalMethods {

	class BinomialPricer
	{
	public:
		BinomialPricer();
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