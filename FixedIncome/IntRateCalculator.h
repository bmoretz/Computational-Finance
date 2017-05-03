#pragma once
class IntRateCalculator
{
public:
	IntRateCalculator( double rate );
	IntRateCalculator( const IntRateCalculator &v);
	IntRateCalculator &operator= ( const IntRateCalculator &v );
	~IntRateCalculator();

	double singlePeriod( double value );

private:
	double m_rate;
};

