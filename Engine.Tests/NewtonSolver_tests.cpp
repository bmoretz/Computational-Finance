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
			virtual ~F3();
			double operator()( double value ) override;
		};

		F3::~F3()
		{
		}

		// test method f(x) = (x - 1)^3
		double F3::operator()( double x )
		{
			return ( x - 1 ) * ( x - 1 ) * ( x - 1 );
		}

		class D3 : public MathFunction<double>
		{
		public:
			virtual ~D3();
			double operator()( double value ) override;
		};

		D3::~D3()
		{
		}

		// test method f(x) = (x - 1)^3
		double D3::operator()( double x )
		{
			return 3 * ( x - 1 ) * ( x - 1 );
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

	TEST_F(NewtonSolverTests, F1Bisecion)
	{
		F3 f;
		D3 d;

		auto expected_root = 1.0017424;

		NewtonSolver nm( f, d );

		auto actual_root = nm.getRoot( 100 );

		EXPECT_NEAR(expected_root, actual_root, .00001);
	}
}
