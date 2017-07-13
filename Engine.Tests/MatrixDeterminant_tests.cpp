#include "stdafx.h"

#include <gtest/gtest.h>
#include "Common.h"
#include "Matrix.h"
#include "Determinant.h"

using namespace std;
using namespace Common;
using namespace NumericalMethods;

namespace NumericalTests
{
    class MatrixDeterminantTests :
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

    TEST_F( MatrixDeterminantTests, Example1 )
    {
        auto expected_determinant = 0.0;

        vector<Matrix::Row> rows;

        for( auto i = 0; i < 3; ++i )
        {
            Matrix::Row row;

            for( auto j = 0; j < 3; ++j )
            {
                row.push_back( sin( 3 * j ) );
            }

            rows.push_back( row );
        }

        Matrix m( rows );

        Determinant d;

        auto actual_determinant = d.getDeterminant( m );

        EXPECT_EQ( expected_determinant, actual_determinant );
    }
}
