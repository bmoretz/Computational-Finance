#include "stdafx.h"

#include <gtest/gtest.h>
#include "Common.h"
#include "Matrix.h"
#include "MIPSolver.h"

#include <glpk.h>

#include <iostream>

using namespace std;
using namespace Common;
using namespace NumericalMethods;

namespace NumericalTests
{
	class MIPSolverTests :
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

	GTEST_TEST_(MIPSolverTests, ResourceAllocation, MIPSolverTests, ::testing::internal::GetTypeId<MIPSolverTests>())
	{
		static const double cost_array[][ 5 ] = {
			// Years
			// 1		2		3		4		5
			{ 1.81,		2.4,	0.97,	0.97,	1.5 },	// proj 1
			{ 1.29,		1.8,	2.3,	0.56,	0.5 },	// proj 2
			{ 1.22,		1.2,	0.1,	0.48,	0 },	// proj 3
			{ 1.43,		1.4,	1.2,	1.2,	1.2 },	// proj 4
			{ 1.62,		1.9,	2.5,	2.0,	1.8 },	// proj 5
		};

		Matrix costs( 5, 5 );

		for( auto i = 0; i <5; ++i)
		{
			for( auto j = 0; j < 5; ++j)
			{
				costs[ j ][ i ] = cost_array[ i ][ j ];
			}
		}

		const vector<double> returns = { 12.13, 3.95, 7.2, 4.21, 11.39 };
		const vector<double> budgets = { 5.1, 6.4, 6.84, 4.5, 3.8 };

		MIPSolver solver( costs, budgets, returns );

		for( auto i = 0; i < 5; ++i )
		{
			solver.setColBinary(i);
		}

		vector<double> results;
		double objVal;

		solver.solve( results, objVal );

		for( auto i = 0; i < results.size(); ++i)
		{
			cout << " x :" << i << " : " << results[i];
		}

		cout << endl;
	}	
}