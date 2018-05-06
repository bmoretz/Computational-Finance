#include "stdafx.h"

#include <gtest/gtest.h>
#include "Common.h"
#include "BlackScholesForwardMethod.h"

using namespace std;
using namespace Common;
using namespace NumericalMethods;

namespace NumericalTests
{
	class BlackScholesTests :
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

	TEST_F(BlackScholesTests, BlackScholesForwardMethod, Scenario_1, ::testing::internal::GetTypeId<EulerMethodTests>())
	{
		const auto strike = 5.0;
		const auto intRate = 0.03;
		const auto sigma = 0.5;
		const auto t1 = 1.0;
		const auto numSteps = 11;
		const auto numDays = 29;
		const auto maxPrice = 10.0;

		BlackScholesForwardMethod bsfm( t1, maxPrice, strike, intRate );

		auto u = bsfm.solve( sigma, numSteps, numDays );

		vector<double> actual_res;

		const auto minPrice = 0.0;
		for( auto i = 0; i < numSteps - 1; i++ )
		{
			auto s = ( ( numSteps - i - 2 ) * minPrice + ( i + 1 ) ) / static_cast<double>( numSteps - 1 );

			actual_res.push_back( u[ i + numDays * ( numSteps - 1 ) ] );
		}

		EXPECT_EQ(actual_res.size(), numSteps - 1);

		// TODO: Validate results against external model.
	}
}
