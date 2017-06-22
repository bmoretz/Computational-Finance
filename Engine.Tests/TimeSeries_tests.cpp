#include "stdafx.h"

#include "common.h"
#include "TimeSeries.h"

using namespace std;
using namespace Common;

namespace CommonTests
{
    class TimeSeriesTests :
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

    // BSE500, 2-Jun-17 - 21-Apr-17
    TEST_F(TimeSeriesTests, BSE500)
    {
        auto
            expected_bar = 13058.93,
            expected_stDev = 136.93;

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

        TimeSeries ts;

        ts.addValues( bseClose );

        EXPECT_NE( Zero, ts.size() );

        EXPECT_DOUBLE_EQ( expected_bar, round_digits( ts.mean(), 2 ) );
        EXPECT_DOUBLE_EQ( expected_stDev, round_digits( ts.stdDev(), 2 ) );
    }

    // SPX500, 2-Jun-17 - 21-Apr-17
    TEST_F(TimeSeriesTests, SPX)
    {
        auto
            expected_bar = 2394.62,
            expected_stDev = 18.86;

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

        TimeSeries ts;

        ts.addValues( spxClose );

        EXPECT_NE( Zero, ts.size() );

        EXPECT_DOUBLE_EQ( expected_bar, round_digits( ts.mean(), 2 ) );
        EXPECT_DOUBLE_EQ( expected_stDev, round_digits( ts.stdDev(), 2 ) );
    }
}