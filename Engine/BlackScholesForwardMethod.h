#pragma once

#include <vector>

namespace NumericalMethods
{
	class BlackScholesForwardMethod
	{
	public:
		explicit BlackScholesForwardMethod( double expiration, double maxPrice, double strike, double intRate );
		BlackScholesForwardMethod( const BlackScholesForwardMethod &p ) = default;
		~BlackScholesForwardMethod() = default;
		BlackScholesForwardMethod& operator=( const BlackScholesForwardMethod &p );

		std::vector<double> solve( double volatility, int nx, int timeSteps ) const;

	private:
		double m_expiration;
		double m_maxPrice;
		double m_strike;
		double m_intRate;
	};
}