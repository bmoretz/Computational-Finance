#include "stdafx.h"
#include "Recommendation.h"

namespace Equity
{
    #pragma region Constructor / Deconstructor

    Recommendation::Recommendation()
        : m_target( 0 ),
          m_rec( NO_RECOMMENDATION ),
          m_ticker( "" )
    {
    }

    Recommendation::Recommendation( const string ticker, RecommendationType rec, double target )
    {
        m_ticker = ticker;
        m_rec = rec;
        m_target = target;
    }

    Recommendation::Recommendation( const Recommendation &r )
    {
        m_ticker = r.m_ticker;
        m_rec = r.m_rec;
        m_target = r.m_target;
    }

    Recommendation& Recommendation::operator=( Recommendation &r )
    {
        if( this != &r )
        {
            m_ticker = r.m_ticker;
            m_rec = r.m_rec;
            m_target = r.m_target;
        }

        return *this;
    }

    Recommendation::~Recommendation()
    {
    }

    #pragma endregion

    double Recommendation::getTarget() const
    {
        return m_target;
    }

    RecommendationType Recommendation::getRecommendation() const
    {
        return m_rec;
    }

    string Recommendation::getTicker() const
    {
        return m_ticker;
    }
}
