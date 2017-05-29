#include "stdafx.h"

#include "common.h"
#include "MACalculator.h"
#include <gmock/gmock-matchers.h>

using namespace std;
using namespace Common;

using namespace testing;

namespace CommonTests
{
    class MACalculatorTests :
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

    // SMA: Book, SMA
    TEST_F(MACalculatorTests, BookExample_SMA)
    {
        auto periods = 5;
        vector<double> quotes = { 10, 11, 22, 12, 13, 23, 12, 32, 12 };

        vector<double> expected_sma = { 18.2, 18.6, 22.8, 20.8, 19, 16.8, 16.6, 20.6 };

        MACalculator maCalc( periods );

        for( auto q : quotes )
        {
            maCalc.addPriceQuote( q );
        }

        auto actual_sma = maCalc.calculateMA();

        for( auto index = 0; index < actual_sma.size(); index++ )
        {
            EXPECT_DOUBLE_EQ( actual_sma.at( index ), expected_sma.at( index ) );
        }
    }

    // SMA: Book, EMA
    TEST_F(MACalculatorTests, BookExample_EMA)
    {
        auto periods = 5;
        vector<double> quotes = { 10, 11, 22, 12, 13, 23, 12, 32, 12 };

        vector<double> expected_ema = { 18.2, 16.1333, 21.4222, 18.2815, 13.1877, 9.45844, 13.639, 19.7593 };

        MACalculator maCalc( periods );

        for( auto q : quotes )
        {
            maCalc.addPriceQuote( q );
        }

        auto actual_ema = maCalc.calculateEMA();

        for( auto index = 0; index < actual_ema.size(); index++ )
        {
            EXPECT_DOUBLE_EQ( round_digits( actual_ema.at( index ), 4 ), expected_ema.at( index ) );
        }
    }

    // SMA: SPX
    TEST_F(MACalculatorTests, SPX)
    {
        auto periods = 20;
        vector<double> prices = { 2381.73,2365.72,2357.03,2400.67,2402.32,2390.9,2394.44,2399.63,2396.92,2399.38,2399.29,2389.52,2388.13,2391.17,2388.33,2384.2,2388.77,2387.45,2388.61,2374.15,2348.69,2355.84,2338.17,2342.19,2349.01,2328.95,2344.93,2353.78,2357.16 };
        
        vector<double> expected = { 2505.85, 2504.56, 2503.18, 2502.44, 2499.86, 2496.19, 2493.89, 2491.86, 2489.73 };

        MACalculator maCalc( periods );

        maCalc.addPriceQuotes( prices );

        auto actual = round_digits( maCalc.calculateMA(), 2 );

        EXPECT_NE(Zero, actual.size());

        EXPECT_THAT(expected, ContainerEq(actual));
    }
}
