#include "stdafx.h"

#include "common.h"
#include "Recommendation.h"
#include "RecommendationProcessor.h"

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
			const Recommendation r1( "aapl", BUY, 45.50 );
            m_processor.addRecommendation( r1 );

			const Recommendation r2( "aapl", SELL, 50.09 );
            m_processor.addRecommendation( r2 );

			const Recommendation r3( "aapl", BUY, 39.90 );
            m_processor.addRecommendation( r3 );

			const Recommendation r4( "aapl", BUY, 35.50 );
            m_processor.addRecommendation( r4 );

			const Recommendation r5( "aapl", BUY, 50.50 );
            m_processor.addRecommendation( r5 );
        }

        void TearDown() override
        {
        }
    };

    TEST_F(RecommendationProcessorTests, TestTargets)
    {
		const auto actual_avg = m_processor.averageTargetPrice( "aapl" );

        EXPECT_DOUBLE_EQ( round_digits( actual_avg, 1 ), 44.3 );
    }

    TEST_F(RecommendationProcessorTests, TestRecommendations)
    {
        EXPECT_EQ( m_processor.averageRecommendation( "aapl" ), BUY );
    }
}
