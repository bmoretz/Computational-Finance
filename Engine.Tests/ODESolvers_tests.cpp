#include "stdafx.h"

#include <gtest/gtest.h>
#include "Common.h"
#include "MathFunction.h"
#include "EulersMethod.h"
#include "RungeKuttaMethod.h"

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
			double operator()( double value ) override;
			double operator()( double x, double y ) override;
		};

		// Not used.
		double FSin::operator()( const double x )
		{
			return 0;
		}

		// test method f(x) = 3x + 2y + 1
		double FSin::operator()( const double x, const double y )
		{
			return 3 * x + 2 * y + 1;
		}
	}

	class ODESolverTests :
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

	TEST_F(ODESolverTests, EulerMethod, EulerMethod_1, ::testing::internal::GetTypeId<EulerMethodTests>())
	{
		FSin f;

		const auto expected_res = 77.5625;

		EulersMethod m( f );

		const auto actual_res = m.solve( 100, 0, .25, 2 );

		EXPECT_NEAR(expected_res, actual_res, .0001);
	}

	TEST_F(ODESolverTests, RugeKuttaMethod, RugeKuttaMethod_1, ::testing::internal::GetTypeId<EulerMethodTests>())
	{
		FSin f;

		const auto expected_res = 77.6472;

		RungeKuttaMethod m( f );

		const auto actual_res = m.solve( 100, 0, .25, 2 );

		EXPECT_NEAR(expected_res, actual_res, .0001);
	}
}
