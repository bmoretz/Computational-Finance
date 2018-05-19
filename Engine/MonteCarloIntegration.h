#pragma once

#include "MathFunction.h"

namespace NumericalMethods
{
	class MonteCarloIntegration
	{
	public:

		explicit MonteCarloIntegration( MathFunction<double> &f );
		MonteCarloIntegration( const MonteCarloIntegration &p ) = default;
		~MonteCarloIntegration() = default;
		MonteCarloIntegration& operator=( const MonteCarloIntegration &p );

		void setNumSamples( const int n )
		{
			m_numSamples = n;
		};

		double getIntegral( double a, double b ) const;
		double integrateRegion( double a, double b, double min, double max ) const;
	private:
		MathFunction<double> &m_f;
		int m_numSamples;
	};
}
