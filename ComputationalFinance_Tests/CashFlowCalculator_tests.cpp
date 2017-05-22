#include "stdafx.h"

#include "common.h"
#include "CashflowCalculator.h"

using namespace std;
using namespace Common;
using namespace FixedIncome;

namespace FixedIncomeTests
{
    class CashFlowCalculatorTests :
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

    // rate: 5%, values: 200, 300, 500, -1000
    TEST_F( CashFlowCalculatorTests, BookExample )
    {
        auto rate = 0.05, // Book erratum, example displays 5% rate, however example actually uses 8%
            expected = 71.801361; // Correct EV

        CashFlowCalculator cfc( rate );

        cfc.addCashPayment( 200, 1 );
        cfc.addCashPayment( 300, 2 );
        cfc.addCashPayment( 500, 3 );

        cfc.addCashPayment( -1000, 4 );

        auto actual = cfc.presentValue();

        EXPECT_NE( Zero, actual );
        EXPECT_FLOAT_EQ( expected, actual );
    }

    // rate: 8%, values: $200.00 $300.00 $500.00 $1,500.00 $600.00 ($3,100.00)
    TEST_F( CashFlowCalculatorTests, Example_2 )
    {
        auto rate = 0.08,
            expected = 396.6718; // Correct EV

        CashFlowCalculator cfc( rate );

        cfc.addCashPayment( 200, 1 );
        cfc.addCashPayment( 300, 2 );
        cfc.addCashPayment( 500, 3 );
        cfc.addCashPayment( 1500, 4 );
        cfc.addCashPayment( 600, 5 );

        cfc.addCashPayment( -3100, 6 );

        auto actual = cfc.presentValue();

        EXPECT_NE( Zero, actual );
        EXPECT_FLOAT_EQ( expected, actual );
    }
}
