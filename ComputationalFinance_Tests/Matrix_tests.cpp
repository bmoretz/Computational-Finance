#include "stdafx.h"

#include "common.h"
#include "Matrix.h"
#include <gmock/gmock-matchers.h>

using namespace std;
using namespace Common;

using namespace testing;

namespace CommonTests
{
    class MatrixTests :
            public Test
    {
    protected:

        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F(MatrixTests, EmptyTraceTests)
    {
        auto expected_trace = 0;

        Matrix m( 0 );

        auto actual_trace = m.trace();

        EXPECT_EQ( expected_trace, actual_trace );
    }

    TEST_F(MatrixTests, AdditionTest_1)
    {
        Matrix expected_matrix( {
            Matrix::Row { 6, 6, 6 },
            Matrix::Row { 12, 12, 12 }
        } );

        Matrix actual_matrix( {
            Matrix::Row { 0, 1, 2 },
            Matrix::Row { 9, 8, 7 }
        } );

        Matrix m2( {
            Matrix::Row { 6, 5, 4 },
            Matrix::Row { 3, 4, 5 }
        } );

        actual_matrix.add( m2 );

        EXPECT_THAT( expected_matrix.getRows(), ContainerEq( actual_matrix.getRows() ) );
    }

    TEST_F(MatrixTests, AdditionTest_2)
    {
        Matrix expected_matrix( {
            Matrix::Row { 6, 6, 6 },
            Matrix::Row { 12, 12, 12 }
        } );

        Matrix m1( {
            Matrix::Row { 0, 1, 2 },
            Matrix::Row { 9, 8, 7 }
        } );

        Matrix m2( {
            Matrix::Row { 6, 5, 4 },
            Matrix::Row { 3, 4, 5 }
        } );

        auto actual_matrix = m1 + m2;

        EXPECT_THAT( expected_matrix.getRows(), ContainerEq( actual_matrix.getRows() ) );
    }

    TEST_F(MatrixTests, SubtractionTest_1)
    {
        Matrix expected_matrix( {
            Matrix::Row { -6, -4, -2 },
            Matrix::Row { 6, 4, 2 }
        } );

        Matrix actual_matrix( {
            Matrix::Row { 0, 1, 2 },
            Matrix::Row { 9, 8, 7 }
        } );

        Matrix m2( {
            Matrix::Row { 6, 5, 4 },
            Matrix::Row { 3, 4, 5 }
        } );

        actual_matrix.subtract( m2 );

        EXPECT_THAT( expected_matrix.getRows(), ContainerEq( actual_matrix.getRows() ) );
    }

    TEST_F(MatrixTests, SubtractionTest_2)
    {
        Matrix expected_matrix( {
            Matrix::Row { -6, -4, -2 },
            Matrix::Row { 6, 4, 2 }
        } );

        Matrix m1( {
            Matrix::Row { 0, 1, 2 },
            Matrix::Row { 9, 8, 7 }
        } );

        Matrix m2( {
            Matrix::Row { 6, 5, 4 },
            Matrix::Row { 3, 4, 5 }
        } );

        auto actual_matrix = m1 - m2;

        EXPECT_THAT( expected_matrix.getRows(), ContainerEq( actual_matrix.getRows() ) );
    }

    TEST_F(MatrixTests, MultiplicationTest_1)
    {
        Matrix expected_matrix( {
            Matrix::Row { 21, 18 },
            Matrix::Row { 66, 57 }
        } );

        Matrix actual_matrix( {
            Matrix::Row { 1, 2 },
            Matrix::Row { 4, 5 }
        } );

        Matrix m2( {
            Matrix::Row { 9, 8 },
            Matrix::Row { 6, 5 }
        } );

        actual_matrix.multiply( m2 );

        EXPECT_THAT( expected_matrix.getRows(), ContainerEq( actual_matrix.getRows() ) );
    }

    TEST_F(MatrixTests, MultiplicationTest_2)
    {
        Matrix expected_matrix( {
            Matrix::Row { 21, 18 },
            Matrix::Row { 66, 57 }
        } );

        Matrix m1( {
            Matrix::Row { 1, 2 },
            Matrix::Row { 4, 5 }
        } );

        Matrix m2( {
            Matrix::Row { 9, 8 },
            Matrix::Row { 6, 5 }
        } );

        auto actual_matrix = m1 * m2;

        EXPECT_THAT( expected_matrix.getRows(), ContainerEq( actual_matrix.getRows() ) );
    }
}
