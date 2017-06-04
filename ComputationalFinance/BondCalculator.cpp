#include "stdafx.h"
#include "BondCalculator.h"

namespace FixedIncome 
{
    #pragma region Constructor / Deconstructor

	BondCalculator::BondCalculator( string instution, double principal, double coupon, int numPeriods ) 
		: m_instution( instution ), m_principal( principal ), m_coupon( coupon ), m_numPeriods( numPeriods )
	{ }
	
	BondCalculator::BondCalculator( const BondCalculator &v )
		: m_instution( v.m_instution ), m_principal( v.m_principal ), m_coupon( v.m_coupon ), m_numPeriods( v.m_numPeriods )
	{ }
	
	BondCalculator& BondCalculator::operator=( const BondCalculator& v )
	{
		if( this != &v )
		{
			this->m_instution = v.m_instution;
			this->m_principal = v.m_principal;
			this->m_coupon = v.m_coupon;
			this->m_numPeriods = v.m_numPeriods;
		}

		return *this;
	}

	BondCalculator::~BondCalculator() {}

    #pragma endregion

	double BondCalculator::interestRate() const
	{
		return m_coupon / m_principal;
	}
}