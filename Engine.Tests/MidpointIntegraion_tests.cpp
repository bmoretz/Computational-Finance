#include "stdafx.h"

#include <gtest/gtest.h>
#include "Common.h"
#include "MathFunction.h"
#include "MidpointIntegration.h"
#include "TrapezoidIntegration.h"
#include "SimpsonsIntegraion.h"

using namespace std;
using namespace Common;
using namespace NumericalMethods;

namespace NumericalTests
{
	namespace
	{
		class F1 : public MathFunction<double>
		{
		public:
			virtual ~F1() = default;
			double operator()( double x ) override;
			double operator()( double x, double y ) override;
		};

		// test method f(x) = x^2 + 1
		// Actual Area Under Curve: 45 1/3
		double F1::operator()( const double x )
		{
			return x * x + 1;
		}

		// test method f(x) = (x - 1)^3
		double F1::operator()( double x, double y )
		{
			return 0;
		}
	}

	class IntegrationTests :
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

	// Close.
	GTEST_TEST_(IntegrationTests, F1Midpoint, IntegrationTests, ::testing::internal::GetTypeId<IntegrationTests>())
	{
		F1 f;

		const auto expected_area = 45.3328;

		MidpointIntegration mp( f );

		const auto actual_area = mp.getIntegral( 1, 5 );

		EXPECT_NEAR( expected_area, actual_area, .0001 );
	}

	// Closer.
	GTEST_TEST_(IntegrationTests, F1Trapezoid, IntegrationTests, ::testing::internal::GetTypeId<IntegrationTests>())
	{
		F1 f;

		const auto expected_area = 45.3344;

		TrapezoidIntegration t( f );

		const auto actual_area = t.getIntegral( 1, 5 );

		EXPECT_NEAR( expected_area, actual_area, .0001 );
	}

	// Money.
	GTEST_TEST_(IntegrationTests, F1Simpson, IntegrationTests, ::testing::internal::GetTypeId<IntegrationTests>())
	{
		F1 f;

		const auto expected_area = 45.3333;

		SimpsonsIntegraion s( f );

		const auto actual_area = s.getIntegral( 1, 5 );

		EXPECT_NEAR( expected_area, actual_area, .0001 );
	}
}