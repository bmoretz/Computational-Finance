#include "stdafx.h"

#include "common.h"
#include "IntRateEngine.h"
#include "InvestmentInstrument.h"

using namespace std;
using namespace Common;
using namespace Instruments;
using namespace FixedIncome;

namespace FixedIncomeTests
{
    class IntRateEngineTests :
        public ::testing::Test
    {
    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F(IntRateEngineTests, BondBookExample)
    {
        auto expected_annualIntRate = 0.075;

        IntRateEngine<BondInstrument> bondEngine;

        BondInstrument bond( 250, 40000 );

        bondEngine.setInstrument( bond );

        auto actual_IntRate = bondEngine.getAnnualIntRate();

        EXPECT_NE( actual_IntRate, Zero );
        EXPECT_DOUBLE_EQ( expected_annualIntRate, actual_IntRate );
    }

    TEST_F(IntRateEngineTests, MortgageBookExample)
    {
        auto expected_annualIntRate = .067;

        IntRateEngine<MortgageInstrument> mortgageEngine;

        MortgageInstrument mortgage( 250, 50000, 5000 );

        mortgageEngine.setInstrument( mortgage );

        auto actual_IntRate = mortgageEngine.getAnnualIntRate();

        EXPECT_NE( actual_IntRate, Zero );
        EXPECT_DOUBLE_EQ( expected_annualIntRate, round_digits( actual_IntRate, 3 ) );
    }
}
