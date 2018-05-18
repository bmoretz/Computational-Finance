#include "stdafx.h"

#include <gtest/gtest.h>
#include "Common.h"
#include "Matrix.h"
#include "LPSolver.h"

#include <glpk.h>

using namespace std;
using namespace Common;
using namespace NumericalMethods;

namespace NumericalTests
{
	class LPSolverTests :
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

	GTEST_TEST_(LPSolverTests, LP_Problem_1, LPSolverTests, ::testing::internal::GetTypeId<LPSolverTests>())
	{
		Matrix A(3);

		A[0][0] = 1;	A[0][1] = 1;	A[0][2] = 1;
		A[1][0] = 10;	A[1][1] = 2;	A[1][2] = 4;
		A[2][0] = 2;	A[2][1] = 5;	A[2][2] = 6;

		const vector<double> c = { 10, 6, 4 };
		const vector<double> b = { 100, 600, 300 };

		LPSolver solver(A, b, c);

		solver.setMaximization();

		vector<double> results;
		double objVal;

		auto res = solver.solve(results, objVal);

		EXPECT_EQ(res, LPSolver::ResultType::FEASIBLE);

		EXPECT_EQ(results.size(), 3);

		EXPECT_NEAR(results.at(0), 52.1739, 0.0001);
		EXPECT_NEAR(results.at(1), 39.1304, 0.0001);
		EXPECT_NEAR(results.at(2), 0, 0.0001);

		EXPECT_NEAR(objVal, 756.522, 0.001);
	}
}
