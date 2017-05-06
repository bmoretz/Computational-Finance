#include "stdafx.h"
#include "common.h"
#include "CashFlowCalculator.h"

using namespace std;
using namespace ComputationalFinance;

namespace FixedIncome
{
	CashFlowCalculator::CashFlowCalculator( double rate ) : 
		m_rate( rate )
	{ }

	CashFlowCalculator &CashFlowCalculator::operator=( const CashFlowCalculator& v )
	{
		if( this != &v )
		{
			this->m_rate = v.m_rate;
			this->m_payments = v.m_payments;
		}

		return *this;
	}

	CashFlowCalculator::~CashFlowCalculator() { }

	void CashFlowCalculator::addCashPayment( double value, int timePeriod )
	{
		m_payments.push_back( CashPayment( value, timePeriod ) );
	}

	double CashFlowCalculator::presentValue()
	{
		auto total = 0.0;

		for( auto payment : m_payments ) {
			total += presentValue( payment.Value(), payment.Period() );
		}

		return total;
	}

	double CashFlowCalculator::presentValue( double futureValue, int timePeriod )
	{
		auto pv = futureValue / pow( 1 + m_rate , timePeriod );

		DBOUT( "present value: " << pv );

		return pv;
	}
}
