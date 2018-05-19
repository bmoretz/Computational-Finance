#pragma once

#include <vector>

namespace Derivative
{
	class OptionProbabilities
	{
	public:

		explicit OptionProbabilities( double initialPrice, double strike, double avgStep, int nDays );
		OptionProbabilities( const OptionProbabilities &p ) = default;
		~OptionProbabilities() = default;
		OptionProbabilities& operator=( const OptionProbabilities &p );

		void setNumIterations( const int n )
		{
			m_numIterations = n;
		}

		double probFinishAboveStrike() const;
		double probFinishBelowStrike() const;
		double probFinalPriceBetweenPrices( double lowPrice, double highPrice ) const;
		std::vector<double> getWalk() const;

	private:
		double
			m_initialPrice,
			m_strike,
			m_avgStep;

		int
			m_numDays,
			m_numIterations;

		static double gaussianValue( double mean, double sigma );
		double getLastPriceOfWalk() const;
	};
}