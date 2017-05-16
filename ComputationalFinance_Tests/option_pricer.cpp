#include "stdafx.h"

#include "common.h"
#include "OptionPricer.h"

using namespace std;
using namespace ComputationalFinance;
using namespace NumericalMethods;

namespace NumericalMethodsTests
{
	class OptionPricerTests :
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
	TEST_F(OptionPricerTests, BookExample)
	{
		auto steps = 30;

		double
			assetPrice = 60, up = 10, down = 15, rate = 0.1, strikePrice = 60,
			expected = 2.98;

		OptionPricer pricer(assetPrice, up, down, rate, steps, strikePrice);

		auto actual = round_digits( pricer.RiskNeutProb(), 3 );

		EXPECT_NE( Zero, actual);
		EXPECT_FLOAT_EQ( expected, actual);
	}
}