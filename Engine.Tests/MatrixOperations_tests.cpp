#include "stdafx.h"

#include <gtest/gtest.h>
#include "Common.h"
#include "MatrixOperations.h"

using namespace std;
using namespace Common;
using namespace NumericalMethods;

namespace NumericalTests
{
	class MatrixOperationsTests :
		public ::testing::Test
	{
	protected:
		void SetUp() override {}
		void TearDown() override { }
	};

	TEST_F( MatrixOperationsTests, Transpose )
	{
        vector<Matrix::Row> expected_rows =
        {
            { 1, 4, 7 },
            { 2, 5, 8 },
            { 3, 6, 9 },
        };

        vector<Matrix::Row> input_rows =
        {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 },
        };

        MatrixOperations mo;

        for( auto row : input_rows )
            mo.addRow( row );

        auto actual = mo.transpose();

        auto expected = Matrix( expected_rows );

        EXPECT_EQ( actual, expected );
	}
}