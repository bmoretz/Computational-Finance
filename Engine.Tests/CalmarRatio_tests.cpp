#include "stdafx.h"
#include "Common.h"
#include "Ratios.h"
#include <gmock/gmock-matchers.h>

using namespace NumericalMethods;

using namespace testing;

namespace NumericalTests
{
    class CalmarRatioTests :
            public Test
    {
    protected:

        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F(CalmarRatioTests, PctTest)
    {
        auto expected_return = 3.12, expect_drawdown = 28.36;

        CalmarRatio<CalmarRatioPerc> ratio( 0.110, 3.12 );

        EXPECT_EQ( expected_return, ratio.getReturn() );
        EXPECT_EQ( expect_drawdown, Common::round_digits( ratio.getDrawDown(), 2 ) );
    }


    TEST_F(CalmarRatioTests, BasisPointsTest)
    {
        auto expected_return = 2.15, expect_drawdown = 44.79;

        CalmarRatio<CalmarRatioBPS> ratio( 480, 2.15 );

        EXPECT_EQ( expected_return, ratio.getReturn() );
        EXPECT_EQ( expect_drawdown, Common::round_digits( ratio.getDrawDown(), 2 ) );
    }
}