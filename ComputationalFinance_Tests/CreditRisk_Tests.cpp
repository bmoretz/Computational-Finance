#include "stdafx.h"

#include "common.h"
#include "CreditRisk.h"
#include "RiskCalculator.h"
#include <gmock/gmock-matchers.h>

using namespace std;
using namespace Common;

using namespace testing;

namespace CommonTests
{
    class CreditRiskTests :
            public Test
    {
    protected:

        RiskCalculator m_calculator;

        vector<shared_ptr<CreditRisk>> m_risks;

        void SetUp() override
        {
            m_risks.push_back( make_shared<CreditRisk>( CreditRisk::C ) );
            m_risks.push_back( make_shared<CreditRisk>( CreditRisk::BPlus ) );
            m_risks.push_back( make_shared<CreditRisk>( CreditRisk::B ) );
            m_risks.push_back( make_shared<CreditRisk>( CreditRisk::B ) );
            m_risks.push_back( make_shared<CreditRisk>( CreditRisk::A ) );
        }

        void TearDown() override
        {
        }
    };

    TEST_F(CreditRiskTests, MaxPortfolioRisk)
    {
        auto expected = CreditRisk::C;

        for( auto risk : m_risks )
        {
            m_calculator.addCreditRisk( risk );
        }

        auto actual = m_calculator.portfolioMaxRisk();

        EXPECT_EQ( expected, actual );
    }

    TEST_F(CreditRiskTests, MinPortfolioRisk)
    {
        auto expected = CreditRisk::A;

        for( auto risk : m_risks )
        {
            m_calculator.addCreditRisk( risk );
        }

        auto actual = m_calculator.portfolioMinRisk();

        EXPECT_EQ( expected, actual );
    }
}