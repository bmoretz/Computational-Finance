#include "stdafx.h"

#include <gtest/gtest.h>
#include "Common.h"
#include "MathFunction.h"
#include "NewtonSolver.h"

using namespace std;
using namespace Common;
using namespace NumericalMethods;

namespace NumericalTests
{
	namespace
	{
		class F3 : public MathFunction<double>
		{
		public:
			virtual ~F3() = default;
			double operator()( double x ) override;
			double operator()( double x, double y ) override;
		};

		// test method f(x) = (x - 1)^3
		double F3::operator()( double x )
		{
			return ( x - 1 ) * ( x - 1 ) * ( x - 1 );
		}

		// Not used.
		double F3::operator()( double x, double y )
		{
			return 0;
		}

		class D3 : public MathFunction<double>
		{
		public:
			virtual ~D3() = default;
			double operator()( double x ) override;
			double operator()( double x, double y ) override;
		};

		// test method f(x) = (x - 1)^3
		double D3::operator()( double x )
		{
			return 3 * ( x - 1 ) * ( x - 1 );
		}

		// Not used.
		double D3::operator()( double x, double y )
		{
			return 0;
		}
	}

	class NewtonSolverTests :
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

	GTEST_TEST_(NewtonSolverTests, F1Bisecion, NewtonSolverTests, ::testing::internal::GetTypeId<NewtonSolverTests>())
	{
		F3 f;
		D3 d;

		const auto expected_root = 1.0017424;

		NewtonSolver nm( f, d );

		const auto actual_root = nm.getRoot( 100 );

		EXPECT_NEAR(expected_root, actual_root, .00001);
	}
}
