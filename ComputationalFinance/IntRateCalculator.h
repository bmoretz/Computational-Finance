#pragma once

namespace FixedIncome {

	class IntRateCalculator
	{
	public:
		IntRateCalculator( double rate );
		IntRateCalculator( const IntRateCalculator &v );
		IntRateCalculator &operator= ( const IntRateCalculator &v );
		~IntRateCalculator();

		inline double IntRateCalculator::singlePeriod( double value )
		{
			return value * ( 1 + this->m_rate );
		}

		inline double IntRateCalculator::mulitplePeriod( double value, int periods )
		{
			return value * pow( 1 + m_rate, periods );
		}

		inline double IntRateCalculator::continuousCompounding( double value, int periods )
		{
			return value * exp( m_rate * periods );
		}

	private:
		double m_rate;
	};
}