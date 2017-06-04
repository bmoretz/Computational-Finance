#include "stdafx.h"

#include "common.h"
#include "TimeSeries.h"
#include "CorrelationCalculator.h"

using namespace std;
using namespace Common;

namespace CommonTests
{
    class CorrelationCalculatorTests :
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

    TEST_F(CorrelationCalculatorTests, BookExample_1)
    {
        auto expected_correl = -0.05060099;

        TimeSeries a, b;

        a.addValues( { 1.2,
                        2,
                        2.5,
                        4,
                        3,
                        6,
                        5.5,
                        6.3,
                        7.1,
                        5.4 } );

     b.addValues( { 3.4,
                    3.3,
                    3,
                    5.5,
                    1.2,
                    2.4,
                    3.2,
                    3.1,
                    2.9,
                    3.2,
                    } );
    
        auto actual_correl = CorrelationCalculator( a, b ).correlation();

        EXPECT_DOUBLE_EQ( expected_correl, round_digits( actual_correl, 8 ) );
    }

    TEST_F(CorrelationCalculatorTests, BookExample_2)
    {
        auto expected_correl = -1;

        TimeSeries a, b;

        a.addValues( { 1,
                        2,
                        3,
                        4,
                        5,
                        6,
                        7 } );

     b.addValues( { 10,
                    9,
                    8,
                    7,
                    6,
                    5,
                    4 } );
    
        auto actual_correl = CorrelationCalculator( a, b ).correlation();

        EXPECT_DOUBLE_EQ( expected_correl, round_digits( actual_correl, 2 ) );
    }

    TEST_F(CorrelationCalculatorTests, BSE_SPX)
    {
        auto
            expected_correl = .6305;

        // BSE500, 2-Jun-17 - 21-Apr-17
        vector<double> bseClose = 
        {
            13290.23,
            13221.57,
            13199.15,
            13158.31,
            13112.1,
            13164.84,
            13007.44,
            12810.75,
            12893.54,
            13016.74,
            13051.03,
            13085.67,
            13270.3,
            13273.3,
            13195.46,
            13112.98,
            13167.6,
            13151.07,
            13027.62,
            13001.19,
            12945.57,
            13062.14,
            12997.91,
            13006.66,
            12979.24,
            12993.79,
            13005.91,
            12982.49,
            12854.14,
            12729.13
        };

        TimeSeries ts_bse;

        ts_bse.addValues( bseClose );

        EXPECT_NE( Zero, ts_bse.size() );

        // SPX, 2-Jun-17 - 21-Apr-17
        vector<double> spxClose = 
        {
            2439.07,
            2430.06,
            2411.8,
            2412.91,
            2415.82,
            2415.07,
            2404.39,
            2398.42,
            2394.02,
            2381.73,
            2365.72,
            2357.03,
            2400.67,
            2402.32,
            2390.9,
            2394.44,
            2399.63,
            2396.92,
            2399.38,
            2399.29,
            2389.52,
            2388.13,
            2391.17,
            2388.33,
            2384.2,
            2388.77,
            2387.45,
            2388.61,
            2374.15,
            2348.69
        };

        TimeSeries ts_spx;

        ts_spx.addValues( spxClose );

        EXPECT_NE( Zero, ts_spx.size() );

        CorrelationCalculator correl( ts_bse, ts_spx );

        EXPECT_DOUBLE_EQ( expected_correl, round_digits( correl.correlation(), 4 ) );
    }
}