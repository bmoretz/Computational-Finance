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
        vector<double> m_prices;

        void SetUp() override
        {
            m_prices = { 2381.73,2365.72,2357.03,2400.67,2402.32,2390.9,2394.44,2399.63,2396.92,2399.38,2399.29,2389.52,2388.13,2391.17,2388.33,2384.2,2388.77,2387.45,2388.61,2374.15,2348.69,2355.84,2338.17,2342.19,2349.01,2328.95,2344.93,2353.78,2357.16 };
        }

        void TearDown() override
        {
        }
    };

    // 10,000 face, 1 period at 8%
    TEST_F(MACalculatorTests, SPX)
    {
        auto periods = 20;
        vector<double> expected = { 2505.85, 2504.56, 2503.18, 2502.44, 2499.86, 2496.19, 2493.89, 2491.86, 2489.73 };

        MACalculator maCalc( periods );

        maCalc.addPriceQuotes( m_prices );

        auto actual = round_digits( maCalc.calculateMA(), 2 );

        EXPECT_NE( Zero, actual.size() );

        EXPECT_THAT( expected, ContainerEq( actual ) );
    }
}
