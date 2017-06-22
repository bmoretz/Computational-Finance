#pragma once

#include "Recommendation.h"

using namespace std;

namespace Equity
{
    class RecommendationProcessor
    {
    public:
        RecommendationProcessor();
        RecommendationProcessor( const RecommendationProcessor &r );
        RecommendationProcessor& operator=( RecommendationProcessor &r );
        ~RecommendationProcessor();

        void addRecommendation( const string &ticker, RecommendationType rec, double target );
        void addRecommendation( const Recommendation& rec );

        double averageTargetPrice( const string &ticker );
        RecommendationType averageRecommendation( const string &ticker );

    protected:
        map<string, vector<Recommendation>> m_recommendations;
    };
}