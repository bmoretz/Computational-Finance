#include "stdafx.h"

#include <gtest/gtest.h>
#include "Common.h"
#include "Matrix.h"
#include "LPSolver.h"

#include <glpk.h>
#include "TwoDimensionalLPSolver.h"

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

	GTEST_TEST_(LPSolverTests, LP_Problem_2, LPSolverTests, ::testing::internal::GetTypeId<LPSolverTests>())
	{
		const vector<double> A1 = { -2.1, 3.1, 7.9 };
		const vector<double> A2 = { 1, 1, 1 };
		const vector<double> c = { 5.3, 7.1 };
		const vector<double> b = { 3.4, 4.3, 6 };

		TwoDimensionalLPSolver solver(c, A1, A2, b);
		vector<double> results;
		double objVal;

		auto res = solver.solveProblem(results, objVal);

		EXPECT_EQ(res, LPSolver::ResultType::FEASIBLE);

		EXPECT_EQ(results.size(), 2);

		EXPECT_NEAR(results.at(0), 0.173077, 0.0001);
		EXPECT_NEAR(results.at(1), 3.76346, 0.0001);
		
		EXPECT_NEAR(objVal, 27.6379, 0.001);
	}
}
