#include "stdafx.h"

#include "Common.h"
#include "VolatilityCalculator.h"
#include <gmock/gmock-matchers.h>

using namespace std;
using namespace Common;

using namespace testing;

namespace CommonTests
{
	class VolatilityCalculatorTests :
		public Test
	{
	protected:

		void SetUp() override
		{
		}

		void TearDown() override
		{
		}
	};

	// avg Daily: Book Example (which is wrong, AvgDaily for these is .6, not .7)
	GTEST_TEST_(VolatilityCalculatorTests, StdDev_Book, VolatilityCalculatorTests, 
		::testing::internal::GetTypeId<VolatilityCalculatorTests>())
	{
		const vector<double> quotes = { 3, 3.5, 5, 4.48, 5.2, 6, 6.1, 5.5, 5.2, 5.7 };

		const auto expected = 1.02957;

		VolatilityCalculator vol;

		vol.addPriceQuotes( quotes );

		const auto actual = round_digits( vol.stdDev(), 5 );

		EXPECT_NE(Zero, actual );

		EXPECT_DOUBLE_EQ( expected, actual );
	}

	// avg Daily: Book Example (which is wrong, AvgDaily for these is .6, not .7)
	GTEST_TEST_(VolatilityCalculatorTests, StdDev_SPX, VolatilityCalculatorTests, 
		::testing::internal::GetTypeId<VolatilityCalculatorTests>())
	{
		const vector<double> quotes =
		{
			2381.73, 2365.72, 2357.03, 2400.67, 2402.32, 2390.9, 2394.44, 2399.63, 2396.92, 2399.38, 2399.29, 2389.52, 2388.13,
			2391.17, 2388.33, 2384.2, 2388.77, 2387.45, 2388.61, 2374.15, 2348.69, 2355.84, 2338.17, 2342.19, 2349.01, 2328.95,
			2344.93, 2353.78, 2357.16
		};

		const auto expected = 22.48457428;

		VolatilityCalculator vol;

		vol.addPriceQuotes( quotes );

		const auto actual = round_digits( vol.stdDev(), 8 );

		EXPECT_NE(Zero, actual );

		EXPECT_DOUBLE_EQ( expected, actual );
	}

	// avg Daily: Book Example (which is wrong, AvgDaily for these is .6, not .7)
	GTEST_TEST_(VolatilityCalculatorTests, AvgDaily_SPX, VolatilityCalculatorTests, 
		::testing::internal::GetTypeId<VolatilityCalculatorTests>())
	{
		const vector<double> quotes =
		{
			2381.73, 2365.72, 2357.03, 2400.67, 2402.32, 2390.9, 2394.44, 2399.63, 2396.92, 2399.38, 2399.29, 2389.52, 2388.13,
			2391.17, 2388.33, 2384.2, 2388.77, 2387.45, 2388.61, 2374.15, 2348.69, 2355.84, 2338.17, 2342.19, 2349.01, 2328.95,
			2344.93, 2353.78, 2357.16
		};

		const auto expected = 8.84;

		VolatilityCalculator vol;

		vol.addPriceQuotes( quotes );

		const auto actual = round_digits( vol.avgDailyRange(), 2 );

		EXPECT_NE(Zero, actual );

		EXPECT_DOUBLE_EQ( expected, actual );
	}

	// avg Daily: Book Example (which is wrong, AvgDaily for these is .6, not .7)
	GTEST_TEST_(VolatilityCalculatorTests, AvgDaily_Book, VolatilityCalculatorTests, 
		::testing::internal::GetTypeId<VolatilityCalculatorTests>())
	{
		const vector<double> quotes = { 3, 3.5, 5, 4.48, 5.2, 6, 6.1, 5.5, 5.2, 5.7 };

		const auto expected = 0.6;

		VolatilityCalculator vol;

		vol.addPriceQuotes( quotes );

		auto actual = round_digits( vol.avgDailyRange(), 1 );

		EXPECT_NE(Zero, actual );

		EXPECT_DOUBLE_EQ( expected, actual );
	}

	// range vol: SPX
	GTEST_TEST_(VolatilityCalculatorTests, RangeVol_SPX, VolatilityCalculatorTests, 
		::testing::internal::GetTypeId<VolatilityCalculatorTests>())
	{
		const vector<double> quotes = {
			2381.73, 2365.72, 2357.03, 2400.67, 2402.32, 2390.9, 2394.44, 2399.63, 2396.92, 2399.38, 2399.29, 2389.52, 2388.13,
			2391.17, 2388.33, 2384.2, 2388.77, 2387.45, 2388.61, 2374.15, 2348.69, 2355.84, 2338.17, 2342.19, 2349.01, 2328.95,
			2344.93, 2353.78, 2357.16
		};

		const auto expected = 73.3700;

		VolatilityCalculator vol;

		vol.addPriceQuotes( quotes );

		const auto actual = round_digits( vol.rangeVolatility(), 4 );

		EXPECT_NE( Zero, actual );

		EXPECT_DOUBLE_EQ( expected, actual );
	}

	// range vol: Book Example
	GTEST_TEST_(VolatilityCalculatorTests, RangeVol_Book, VolatilityCalculatorTests, 
		::testing::internal::GetTypeId<VolatilityCalculatorTests>())
	{
		const vector<double> quotes = { 3, 3.5, 5, 4.48, 5.2, 6, 6.1, 5.5, 5.2, 5.7 };

		const auto expected = 3.1;

		VolatilityCalculator vol;

		vol.addPriceQuotes( quotes );

		const auto actual = round_digits( vol.rangeVolatility(), 1 );

		EXPECT_NE(Zero, actual );

		EXPECT_DOUBLE_EQ( expected, actual );
	}

	// RangeVol: Empty Set Validation
	GTEST_TEST_(VolatilityCalculatorTests, RangeVol_EmptyTest, VolatilityCalculatorTests, 
		::testing::internal::GetTypeId<VolatilityCalculatorTests>())
	{
		VolatilityCalculator vol;

		vol.addPriceQuotes( vector<double>() );

		const auto actual = vol.rangeVolatility();

		EXPECT_EQ( Zero, actual );
	}

	// AvgDaily: Empty Set Validation
	GTEST_TEST_(VolatilityCalculatorTests, AvgDaily_EmptyTest, VolatilityCalculatorTests, 
		::testing::internal::GetTypeId<VolatilityCalculatorTests>())
	{
		VolatilityCalculator vol;

		vol.addPriceQuotes( vector<double>() );

		const auto actual = vol.avgDailyRange();

		EXPECT_EQ( Zero, actual );
	}


	// StdDev: Empty Set Validation
	GTEST_TEST_(VolatilityCalculatorTests, StdDev_EmptyTest, VolatilityCalculatorTests, 
		::testing::internal::GetTypeId<VolatilityCalculatorTests>())
	{
		VolatilityCalculator vol;

		vol.addPriceQuotes( vector<double>() );

		const auto actual = vol.stdDev();

		EXPECT_EQ( Zero, actual );
	}
}
