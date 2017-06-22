#pragma once

namespace FixedIncome {

	class IntRateCalculator
	{
	public:
		IntRateCalculator( double rate );
		IntRateCalculator( const IntRateCalculator &v );
		IntRateCalculator &operator= ( const IntRateCalculator &v );
		~IntRateCalculator();

	    double IntRateCalculator::singlePeriod( double value ) const
		{
			return value * ( 1 + this->m_rate );
		}

	    double IntRateCalculator::mulitplePeriod( double value, int periods ) const
		{
			return value * pow( 1 + m_rate, periods );
		}

	    double IntRateCalculator::continuousCompounding( double value, int periods ) const
		{
			return value * exp( m_rate * periods );
		}

	private:
		double m_rate;
	};
}