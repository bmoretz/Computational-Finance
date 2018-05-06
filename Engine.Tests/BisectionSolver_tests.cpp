#include "stdafx.h"

#include <gtest/gtest.h>
#include "Common.h"
#include "MathFunction.h"
#include "BisectionSolver.h"

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
			double operator()( double value ) override;
			double operator()( double x, double y ) override;
		};

		// test method f(x) = (x - 1)^3
		double F1::operator()( double x )
		{
			return ( x - 1 ) * ( x - 1 ) * ( x - 1 );
		}

		// test method f(x) = (x - 1)^3
		double F1::operator()( double x, double y )
		{
			return 0;
		}
	}

	class BiseconSolverTests :
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

	GTEST_TEST_(BiseconSolverTests, F1Bisecion, BiseconSolverTests, ::testing::internal::GetTypeId<BiseconSolverTests>())
	{
		F1 f;

		const auto expected_root = 0.99902;

		BisectionSolver bm( f );

		const auto actual_root = bm.getRoot( -1, 3 );

		EXPECT_NEAR(expected_root, actual_root, .00001);
	}
}