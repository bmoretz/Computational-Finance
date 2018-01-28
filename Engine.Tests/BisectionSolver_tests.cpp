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
			virtual ~F1();
			double operator()( double value ) override;
		};

		F1::~F1()
		{
		}

		// test method f(x) = (x - 1)^3
		double F1::operator()( double x )
		{
			return ( x - 1 ) * ( x - 1 ) * ( x - 1 );
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

	TEST_F(BiseconSolverTests, F1Bisecion)
	{
		F1 f;

		auto expected_root = 0.9990234375;

		BisectionSolver bm( f );

		auto actual_root = bm.getRoot( -1, 3 );

		EXPECT_DOUBLE_EQ(expected_root, actual_root);
	}
}
