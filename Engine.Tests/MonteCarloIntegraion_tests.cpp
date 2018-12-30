#include "stdafx.h"

#include <gtest/gtest.h>
#include "Common.h"
#include "MathFunction.h"
#include "MonteCarloIntegration.h"

using namespace std;
using namespace Common;
using namespace NumericalMethods;

namespace NumericalTests
{
	namespace
	{
		class FSin : public MathFunction<double>
		{
		public:
			virtual ~FSin() = default;
			double operator()( double x ) override;
			double operator()( double x, double y ) override;
		};

		// Sin(F)
		double FSin::operator()( const double x )
		{
			return sin( x );
		}

		// Not used.
		double FSin::operator()( const double x, const double y )
		{
			return 0;
		}
	}

	class MonteCarloIntegraionTests :
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

		TEST_F(MonteCarloIntegraionTests, SinIntegraion_Region_1, SinIntegraion,
		::testing::internal::GetTypeId<MonteCarloIntegraionTests>())
	{
		const auto expected_integral = 2;

		FSin f;
		MonteCarloIntegration mci( f );
		const auto actual_integral = mci.integrateRegion( 0.0, 1, 0, 2 );

		EXPECT_NEAR(expected_integral, actual_integral, 0.001);
	}

	TEST_F(MonteCarloIntegraionTests, SinIntegraion_1, SinIntegraion,
		::testing::internal::GetTypeId<MonteCarloIntegraionTests>())
	{
		const auto expected_integral = 1.74;

		FSin f;
		MonteCarloIntegration mci( f );
		const auto actual_integral = mci.getIntegral( 0.5, 2.5 );

		EXPECT_NEAR(expected_integral, actual_integral, 0.001 );
	}

	TEST_F(MonteCarloIntegraionTests, SinIntegraion_2, SinIntegraion,
		::testing::internal::GetTypeId<MonteCarloIntegraionTests>())
	{
		const auto expected_integral = 1.6702;

		FSin f;
		MonteCarloIntegration mci( f );
		mci.setNumSamples( 200000 );

		const auto actual_integral = mci.getIntegral( 0.5, 2.5 );

		EXPECT_NEAR(expected_integral, actual_integral, 0.0001);
	}
}
