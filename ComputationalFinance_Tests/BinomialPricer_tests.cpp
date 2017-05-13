#include "stdafx.h"

#include "common.h"
#include "BinomialPricer.h"

#include <gtest/gtest.h>

using namespace std;
using namespace ComputationalFinance;
using namespace NumericalMethods;

namespace NumericalMethodsTests
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
			expected = 1.995;

		BinomialPricer pricer( price, up, down, rate );

		auto actual = round_digits( pricer.RiskNeutProb(), 3 );

		EXPECT_NE( Zero, actual);
		EXPECT_EQ( expected, actual );
	}
}