#include "stdafx.h"

#include "common.h"
#include "BondCalculator.h"

#include <gtest/gtest.h>

using namespace std;
using namespace ComputationalFinance;
using namespace FixedIncome;

namespace FixedIncomeTests
{
    class CashflowCalculatorTest : 
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

    // Base Case: XYZ, principal $10,000, Coupon: $5,000,
    // IR: 5%
    TEST_F(CashflowCalculatorTest, Base_Intrest_Rate) {

        string issuer("XYZ");

        auto periods = 30;

        double principal = 100000, coupon = 5000,
            expectedRate = 0.05, actualRate = Zero;

        BondCalculator bc(issuer, principal, coupon, periods);

        actualRate = bc.interestRate();

        EXPECT_NE(Zero, actualRate);
        EXPECT_EQ(expectedRate, actualRate);
    }

    // Issuer: XOM, Principal, $200,000, Coupon: $7,500
    // IR: 3.75%
    TEST_F(CashflowCalculatorTest, XOM) {

        string issuer("XOM");

        auto periods = 20;

        double principal = 200000, coupon = 7500,
            expectedRate = 0.0375;

        BondCalculator bc(issuer, principal, coupon, periods);

        auto actualRate = bc.interestRate();

        EXPECT_NE(Zero, actualRate);
        EXPECT_EQ(expectedRate, actualRate);
    }

    // Issuer: MSFT, Principal, $190,000, Coupon: $6,589.00
    // IR: 3.4679%
    TEST_F(CashflowCalculatorTest, MSFT) {

        string issuer("MSFT");
        
        auto periods = 25;

        double principal = 190000, coupon = 6589.00,
            expectedRate = 0.034679;

        BondCalculator bc(issuer, principal, coupon, periods);

        auto actualRate = round_digits( bc.interestRate(), 6 );

        EXPECT_NE(Zero, actualRate);
        EXPECT_EQ(expectedRate, actualRate);
    }
}