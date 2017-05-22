#include "stdafx.h"

#include "common.h"
#include "IntRateCalculator.h"

using namespace std;
using namespace Common;
using namespace FixedIncome;

namespace FixedIncomeTets
{
    class IntRateCalculatorTests :
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

    // 10,000 face, 1 period at 8%
    TEST_F(IntRateCalculatorTests, BookExample)
    {
        double rate = 0.08, face = 10000,
            expected_fv = 10800;

        IntRateCalculator irCalc( rate );

        auto actual_fv = irCalc.singlePeriod( face );

        EXPECT_NE( Zero, actual_fv);
        EXPECT_FLOAT_EQ( expected_fv, actual_fv);
    }

    // $10,000 face, 4 periods, 5% rate:
    TEST_F(IntRateCalculatorTests, MultiplePeriodIntRate)
    {
        auto periods = 4;

        double rate = 0.05, face = 10000,
            expected_fv = 12155.06;

        IntRateCalculator irCalc( rate );

        auto actual_fv = irCalc.mulitplePeriod( face, periods );

        EXPECT_NE(Zero, actual_fv);
        EXPECT_FLOAT_EQ(expected_fv, actual_fv);
    }

    // $10,000 face, 4 periods, 5% rate:
    TEST_F(IntRateCalculatorTests, ContiniousPeriodIntRate)
    {
        auto periods = 4;
        double rate = 0.05, face = 10000;

        IntRateCalculator irCalc( rate );

        auto single_fv = irCalc.singlePeriod( face );
        auto multiple_fv = irCalc.mulitplePeriod( face, periods );
        auto continious_fv = irCalc.continuousCompounding( face, periods );

        EXPECT_NE( Zero, single_fv );
        EXPECT_NE( Zero, multiple_fv);
        EXPECT_NE( Zero, continious_fv);

        EXPECT_TRUE( multiple_fv < continious_fv );
        EXPECT_TRUE(single_fv < multiple_fv );
        EXPECT_TRUE( Zero < single_fv );
    }
}
