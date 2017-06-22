#include "stdafx.h"

#include "common.h"
#include "VolatilityCalculator.h"
#include <gmock/gmock-matchers.h>

using namespace std;
using namespace Common;

using namespace testing;

namespace CommonTests
{
    class VolatilityCalculatorTests :
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

    // avg Daily: Book Example (which is wrong, AvgDaily for these is .6, not .7)
    TEST_F(VolatilityCalculatorTests, StdDev_Book)
    {
        vector<double> quotes = { 3, 3.5, 5, 4.48, 5.2, 6, 6.1, 5.5, 5.2, 5.7 };

        auto expected = 1.02957;

        VolatilityCalculator vol;

        vol.addPriceQuotes( quotes );

        auto actual = round_digits( vol.stdDev(), 5 );

        EXPECT_NE(Zero, actual );

        EXPECT_DOUBLE_EQ( expected, actual );
    }

    // avg Daily: Book Example (which is wrong, AvgDaily for these is .6, not .7)
    TEST_F(VolatilityCalculatorTests, StdDev_SPX)
    {
        vector<double> quotes = { 2381.73, 2365.72, 2357.03, 2400.67, 2402.32, 2390.9, 2394.44, 2399.63, 2396.92, 2399.38, 2399.29, 2389.52, 2388.13, 2391.17, 2388.33, 2384.2,2388.77, 2387.45, 2388.61, 2374.15, 2348.69, 2355.84, 2338.17, 2342.19, 2349.01, 2328.95, 2344.93, 2353.78, 2357.16 };

        auto expected = 22.48457428;

        VolatilityCalculator vol;

        vol.addPriceQuotes( quotes );

        auto actual = round_digits( vol.stdDev(), 8 );

        EXPECT_NE(Zero, actual );

        EXPECT_DOUBLE_EQ( expected, actual );
    }

    // avg Daily: Book Example (which is wrong, AvgDaily for these is .6, not .7)
    TEST_F(VolatilityCalculatorTests, AvgDaily_SPX)
    {
        vector<double> quotes = { 2381.73, 2365.72, 2357.03, 2400.67, 2402.32, 2390.9, 2394.44, 2399.63, 2396.92, 2399.38, 2399.29, 2389.52, 2388.13, 2391.17, 2388.33, 2384.2,2388.77, 2387.45, 2388.61, 2374.15, 2348.69, 2355.84, 2338.17, 2342.19, 2349.01, 2328.95, 2344.93, 2353.78, 2357.16 };

        auto expected = 8.84;

        VolatilityCalculator vol;

        vol.addPriceQuotes( quotes );

        auto actual = round_digits( vol.avgDailyRange(), 2 );

        EXPECT_NE(Zero, actual );

        EXPECT_DOUBLE_EQ( expected, actual );
    }

    // avg Daily: Book Example (which is wrong, AvgDaily for these is .6, not .7)
    TEST_F(VolatilityCalculatorTests, AvgDaily_Book)
    {
        vector<double> quotes = { 3, 3.5, 5, 4.48, 5.2, 6, 6.1, 5.5, 5.2, 5.7 };

        auto expected = 0.6;

        VolatilityCalculator vol;

        vol.addPriceQuotes( quotes );

        auto actual = round_digits( vol.avgDailyRange(), 1 );

        EXPECT_NE(Zero, actual );

        EXPECT_DOUBLE_EQ( expected, actual );
    }

    // range vol: SPX
    TEST_F(VolatilityCalculatorTests, RangeVol_SPX)
    {
        vector<double> quotes = { 2381.73, 2365.72, 2357.03, 2400.67, 2402.32, 2390.9, 2394.44, 2399.63, 2396.92, 2399.38, 2399.29, 2389.52, 2388.13, 2391.17, 2388.33, 2384.2,2388.77, 2387.45, 2388.61, 2374.15, 2348.69, 2355.84, 2338.17, 2342.19, 2349.01, 2328.95, 2344.93, 2353.78, 2357.16 };
        auto expected = 73.3700;

        VolatilityCalculator vol;

        vol.addPriceQuotes( quotes );

        auto actual = round_digits( vol.rangeVolatility(), 4 );

        EXPECT_NE( Zero, actual );

        EXPECT_DOUBLE_EQ( expected, actual );
    }

    // range vol: Book Example
    TEST_F(VolatilityCalculatorTests, RangeVol_Book)
    {
        vector<double> quotes = { 3, 3.5, 5, 4.48, 5.2, 6, 6.1, 5.5, 5.2, 5.7 };

        auto expected = 3.1;

        VolatilityCalculator vol;

        vol.addPriceQuotes( quotes );

        auto actual = round_digits( vol.rangeVolatility(), 1 );

        EXPECT_NE(Zero, actual );

        EXPECT_DOUBLE_EQ( expected, actual );
    }

    // RangeVol: Empty Set Validation
    TEST_F(VolatilityCalculatorTests, RangeVol_EmptyTest)
    {
        VolatilityCalculator vol;

        vol.addPriceQuotes( vector<double>() );

        auto actual = vol.rangeVolatility();

        EXPECT_EQ( Zero, actual );
    }

    // AvgDaily: Empty Set Validation
    TEST_F(VolatilityCalculatorTests, AvgDaily_EmptyTest)
    {
        VolatilityCalculator vol;

        vol.addPriceQuotes( vector<double>() );

        auto actual = vol.avgDailyRange();

        EXPECT_EQ( Zero, actual );
    }


    // StdDev: Empty Set Validation
    TEST_F(VolatilityCalculatorTests, StdDev_EmptyTest)
    {
        VolatilityCalculator vol;

        vol.addPriceQuotes( vector<double>() );

        auto actual = vol.stdDev();

        EXPECT_EQ( Zero, actual );
    }
}
