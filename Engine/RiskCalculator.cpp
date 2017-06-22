#include "stdafx.h"
#include "RiskCalculator.h"

namespace Common
{
    #pragma region Constructor / Deconstructor

    RiskCalculator::RiskCalculator()
        : m_creditRisks( 0 )
    {
    }

    RiskCalculator::RiskCalculator( const RiskCalculator &c )
    {
    }

    RiskCalculator & RiskCalculator::operator=( const RiskCalculator &c )
    {
        if( this != &c )
        {
            m_creditRisks = c.m_creditRisks;
        }

        return *this;
    }

    RiskCalculator::~RiskCalculator()
    {
    }

    #pragma endregion

    void RiskCalculator::addCreditRisk( shared_ptr<CreditRisk> risk )
    {
        m_creditRisks.push_back( risk );
    }

    CreditRisk::RiskType RiskCalculator::portfolioMaxRisk() const
    {
        auto max = CreditRisk::UNKNOWN;

        for( auto risk : m_creditRisks )
        {
            if( risk->getRaiting() > max || max == CreditRisk::UNKNOWN )
            {
                max = risk->getRaiting();
            }
        }

        return max;
    }

    CreditRisk::RiskType RiskCalculator::portfolioMinRisk() const
    {
        auto min = CreditRisk::UNKNOWN;

        for( auto risk : m_creditRisks )
        {
            if( risk->getRaiting() < min || min == CreditRisk::UNKNOWN )
            {
                min = risk->getRaiting();
            }
        }

        return min;
    }
}
