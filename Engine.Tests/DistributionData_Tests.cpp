#include "stdafx.h"

#include "DistrubutionData.h"
#include <gmock/gmock-matchers.h>

using namespace NumericalMethods;

using namespace testing;

namespace NumericalTests
{
    class DistrubutionDataTests :
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

    TEST_F(DistrubutionDataTests, NormalDataTest)
    {
        auto expected_elements = 10;

        auto actual_elements = DistrubutionData::gaussianData( 10, 1, 0 );

        EXPECT_EQ( expected_elements, actual_elements.size() );
    }


    TEST_F(DistrubutionDataTests, chiSquaredDataTest)
    {
        auto expected_elements = 10;

        auto actual_elements = DistrubutionData::chiSquaredData( 10, .05 );

        EXPECT_EQ( expected_elements, actual_elements.size() );
    }

    TEST_F(DistrubutionDataTests, exponentialDataTest)
    {
        auto expected_elements = 10;

        auto actual_elements = DistrubutionData::exponentialData( 10, .05 );

        EXPECT_EQ( expected_elements, actual_elements.size() );
    }

    
    TEST_F(DistrubutionDataTests, logNormalDataTest)
    {
        auto expected_elements = 10;

        auto actual_elements = DistrubutionData::logNormalData( 10, 0, 1 );

        EXPECT_EQ( expected_elements, actual_elements.size() );
    }
}