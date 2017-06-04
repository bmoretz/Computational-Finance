#include "stdafx.h"

#include "FundamentalsCalculator.h"
#include "common.h"

using namespace std;
using namespace Fundamentals;

namespace FundamentalsTests
{
    class FundamentalsCalculatorTests :
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

    TEST_F(FundamentalsCalculatorTests, BookExample)
    {
        auto
            expected_pe = 13.52,
            expected_fpe = 12.3,
            expected_bookValue = 165.23,
            expected_priceBook = 4094.90,
            expected_priceEarningsGrowth = 61463.21,
            expected_ROE = 0.3,
            expected_dividend = 12.20;

        FundamentalsCalculator fc( "AAPL", 543.99, 12.20 );

        // Values in mm

        fc.setAssets( 243139 );
        fc.setBookValue( 165234 );
        fc.setEarnings( 35885 );
        fc.setEpsGrowth( 0.22 );
        fc.setExpectedEarnings( 39435 );
        fc.setLiabilitiesAndIntangibles( 124642 );
        fc.setNetIncome( 37235 );
        fc.setNumOfShares( 891990 );
        fc.setShareHoldersEquity( 123549 );

        // Test in Thousands
        EXPECT_DOUBLE_EQ( expected_pe, Common::round_digits( fc.PE() / 1000, 2 ) );
        EXPECT_DOUBLE_EQ( expected_fpe, Common::round_digits( fc.forwardPE() / 1000, 2 ) );
        EXPECT_DOUBLE_EQ( expected_bookValue, Common::round_digits( fc.bookValue() / 1000, 2 ) );
        EXPECT_DOUBLE_EQ( expected_priceBook, Common::round_digits( fc.priceToBookRatio(), 2 ) );
        EXPECT_DOUBLE_EQ( expected_priceEarningsGrowth, Common::round_digits( fc.priceEarningsToGrowth(), 2 ) );
        EXPECT_DOUBLE_EQ( expected_ROE, Common::round_digits( fc.returnOnEquity(), 2 ) );
        EXPECT_DOUBLE_EQ( expected_dividend, Common::round_digits( fc.getDividend(), 2 ) );
    }
}
