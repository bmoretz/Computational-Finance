#include "stdafx.h"
#include "RecommendationProcessor.h"
#include <numeric>

namespace Equity
{
    #pragma region Constructor / Deconstructor

    RecommendationProcessor::RecommendationProcessor()
    {
    }

    RecommendationProcessor::RecommendationProcessor( const RecommendationProcessor &r )
    {
        m_recommendations = r.m_recommendations;
    }

    RecommendationProcessor& RecommendationProcessor::operator=( RecommendationProcessor &r )
    {
        if( this != &r )
        {
            m_recommendations = r.m_recommendations;
        }

        return *this;
    }

    RecommendationProcessor::~RecommendationProcessor()
    {
    }

    #pragma endregion

    void RecommendationProcessor::addRecommendation( const string &ticker, RecommendationType rec, double target )
    {
        Recommendation r( ticker, rec, target );
        m_recommendations[ ticker ].push_back( r );
    }

    void RecommendationProcessor::addRecommendation( const Recommendation &rec )
    {
        m_recommendations[ rec.getTicker() ].push_back( rec );
    }

    double RecommendationProcessor::averageTargetPrice( const string &ticker )
    {
        if( m_recommendations.find( ticker ) == m_recommendations.end() )
            return 0;

        auto vrec = m_recommendations[ ticker ];

        vector<double> prices;

        for( auto rec : vrec )
        {
            prices.push_back( rec.getTarget() );
        }

        return accumulate( prices.begin(), prices.end(), 0 ) / prices.size();
    }

    RecommendationType RecommendationProcessor::averageRecommendation( const string &ticker )
    {
        if( m_recommendations.find( ticker ) == m_recommendations.end() )
            return NO_RECOMMENDATION;

        auto vrec = m_recommendations[ ticker ];

        vector<int> recs;

        for( auto rec : vrec )
        {
            recs.push_back( static_cast<int>( rec.getRecommendation() ) );
        }

        auto avg = accumulate( recs.begin(), recs.end(), 0 ) / recs.size();

        return static_cast<RecommendationType>( avg );
    }
}