#include "stdafx.h"

#include "common.h"
#include "TimeSeriesTransformations.h"
#include <gmock/gmock-matchers.h>

using namespace std;
using namespace Common;

using namespace testing;

namespace CommonTests
{
    class TimeSeriesTransformationTests :
            public Test
    {
    protected:

        TimeSeriesTransformations m_transformer;

        void SetUp() override
        {
            vector<double> quotes = { 7, 6.4, 2.15, 5, 3, 7 };

            m_transformer.addValues( quotes );
        }

        void TearDown() override
        {
        }
    };

    TEST_F(TimeSeriesTransformationTests, IncreasePrices)
    {
        vector<double> expected = { 7.5, 6.9, 2.65, 5.5, 3.5, 7.5 };
        
        m_transformer.increasePrices( .5 );

        auto actual = m_transformer.getValues();

        EXPECT_THAT( expected, ContainerEq( actual ) );
    }

    TEST_F(TimeSeriesTransformationTests, ReducePrices)
    {
        vector<double> expected = { 6.5, 5.9, 1.65, 4.5, 2.5, 6.5 };
        
        m_transformer.reducePrices( .5 );

        auto actual = m_transformer.getValues();

        EXPECT_THAT( expected, ContainerEq( actual ) );
    }

    TEST_F(TimeSeriesTransformationTests, RemoveLessThan)
    {
        vector<double> expected = { 7, 6.4, 5, 7 };
               
        m_transformer.removePricesLessThan( 5.0 );

        auto actual = m_transformer.getValues();

        EXPECT_THAT( expected, ContainerEq( actual ) );
    }

    TEST_F(TimeSeriesTransformationTests, RemoveGreaterThan)
    {
        vector<double> expected = { 2.15, 5, 3 };
               
        m_transformer.removePricesGreatherThan( 5.0 );

        auto actual = m_transformer.getValues();

        EXPECT_THAT( expected, ContainerEq( actual ) );
    }

    TEST_F(TimeSeriesTransformationTests, FirstPriceLessThan)
    {
        auto expected = 2.15;

        auto actual = m_transformer.getFirstPriceLessThan( 3.0 );

        EXPECT_DOUBLE_EQ( expected, actual );
    }
}