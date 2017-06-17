#include "stdafx.h"

#include "common.h"
#include "Recommendation.h"
#include "RecommendationProcessor.h"
#include <functional>

using namespace std;
using namespace Common;
using namespace Equity;

namespace EquityTests
{
    class RecommendationProcessorTests :
            public ::testing::Test
    {
    protected:
        RecommendationProcessor m_processor;

        void SetUp() override
        {
            Recommendation r1( "aapl", BUY, 45.50 );
            m_processor.addRecommendation( r1 );

            Recommendation r2( "aapl", SELL, 50.09 );
            m_processor.addRecommendation( r2 );

            Recommendation r3( "aapl", BUY, 39.90 );
            m_processor.addRecommendation( r3 );

            Recommendation r4( "aapl", BUY, 35.50 );
            m_processor.addRecommendation( r4 );

            Recommendation r5( "aapl", BUY, 50.50 );
            m_processor.addRecommendation( r5 );
        }

        void TearDown() override
        {
        }
    };

    TEST_F(RecommendationProcessorTests, TestTargets)
    { 
        EXPECT_DOUBLE_EQ( m_processor.averageTargetPrice( "aapl" ), 43 );
    }

    TEST_F(RecommendationProcessorTests, TestRecommendations)
    {
        EXPECT_EQ( m_processor.averageRecommendation( "aapl" ), BUY );
    }
}
