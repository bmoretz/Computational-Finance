#include "stdafx.h"

#include <gtest/gtest.h>
#include "Common.h"
#include "MathFunction.h"
#include "EulersMethod.h"

using namespace std;
using namespace Common;
using namespace NumericalMethods;

namespace NumericalTests
{
	namespace
	{
		class SampleF : public MathFunction<double>
		{
		public:
			virtual ~SampleF() = default;
			double operator()( double value ) override;
			double operator()( double x, double y ) override;
		};

		// Not used.
		double SampleF::operator()( const double x )
		{
			return 0;
		}

		// test method f(x) = 3x + 2y + 1
		double SampleF::operator()( const double x, const double y )
		{
			return 3 * x + 2 * y + 1;
		}
	}

	class EulerMethodTests :
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

	TEST_F(EulerMethodTests, SimpleTest, EulerMethodTests, ::testing::internal::GetTypeId<EulerMethodTests>())
	{
		SampleF f;

		const auto expected_res = 77.5625;

		EulersMethod m( f );

		const auto actual_res = m.solve( 100, 0, .25, 2 );

		EXPECT_NEAR(expected_res, actual_res, .0001);
	}
}
