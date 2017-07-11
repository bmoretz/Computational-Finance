#pragma once

using namespace std;

namespace FixedIncome
{
	class CashPayment
	{
		double m_value;
		int m_period;

	public:
		CashPayment( double value, int period ) :
			m_value( value ), m_period( period )
		{ }

		CashPayment &operator= ( const CashPayment& v )
		{
			if( this != &v )
			{
				this->m_value = v.m_value;
				this->m_period = v.m_period;
			}

			return *this;
		}

		double Value() const
		{ 
			return m_value;
		}

		double Period() const
		{
			return m_period;
		}
	};

	class CashFlowCalculator
	{
	public:
	    explicit CashFlowCalculator( double rate );
		CashFlowCalculator &operator =( const CashFlowCalculator& c );

		~CashFlowCalculator();

		void addCashPayment( double value, int timePeriod );
		double presentValue();
	
	private:

		vector<CashPayment> m_payments;
		
		double m_rate;
		double presentValue( const CashPayment& p ) const;
	};
}