#pragma once

using namespace std;

namespace Equity
{
    enum RecommendationType
    {
        BUY,
        SELL,
        HOLD,
        NO_RECOMMENDATION
    };

    class Recommendation
    {
    public:
        Recommendation();
        Recommendation( const string ticker, RecommendationType rec, double target );
        Recommendation( const Recommendation &r );
        Recommendation& operator=( Recommendation & r );
        ~Recommendation();

        double getTarget() const;
        RecommendationType getRecommendation() const;
        string getTicker() const;

    protected:
        double m_target;
        RecommendationType m_rec;
        string m_ticker;
    };
}