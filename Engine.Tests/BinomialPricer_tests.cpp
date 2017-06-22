#include "stdafx.h"

#include <gtest/gtest.h>
#include "Common.h"
#include "BinomialPricer.h"

using namespace std;
using namespace Common;
using namespace NumericalMethods;

namespace NumericalTests
{
	class BinomialPricerTests :
		public ::testing::Test
	{
	protected:
		void SetUp() override {}
		void TearDown() override { }
	};

	TEST_F( BinomialPricerTests, RiskNeutralProb )
	{	

		double 
			price = 45, up = 10, down = 15, rate = 0.05, 
			expected = 2.99;

		BinomialPricer pricer( price, up, down, rate );

		auto actual = pricer.RiskNeutProb();

		EXPECT_NE( Zero, actual);
		EXPECT_DOUBLE_EQ( expected, actual );
	}
}