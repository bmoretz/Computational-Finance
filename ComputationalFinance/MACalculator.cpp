#include "stdafx.h"
#include "MACalculator.h"

namespace Common
{
    #pragma region Constructor / Deconstructor

    MACalculator::MACalculator( int periods, double emaFactor ) :
        m_numPeriods( periods ),
        m_emaFactor( emaFactor )
    {
    }

    MACalculator::MACalculator( const MACalculator &v )
    {
        m_prices = v.m_prices;
        m_numPeriods = v.m_numPeriods;
        m_emaFactor = v.m_emaFactor;
    }

    MACalculator& MACalculator::operator=( const MACalculator &v )
    {
        if( this != &v )
        {
            this->m_prices = v.m_prices;
            this->m_numPeriods = v.m_numPeriods;
            this->m_emaFactor = v.m_emaFactor;
        }

        return *this;
    }

    MACalculator::~MACalculator()
    {
    }

    #pragma endregion

    vector<double> MACalculator::calculateMA()
    {
        vector<double> ma;
        auto sum = 0.0;

        for( auto index = 0; index < m_prices.size(); index++ )
        {
            sum += m_prices[ index ];

            if( index >= m_numPeriods )
            {
                ma.push_back( sum / m_numPeriods );
                sum -= m_prices[ index - m_numPeriods ];
            }
        }

        return ma;
    }

    vector<double> MACalculator::calculateEMA()
    {
        vector<double> ema;
        auto multiplier = m_emaFactor / ( m_numPeriods + 1 );
        auto sum = 0.0;

        for( auto index = 0; index < m_prices.size(); index++ )
        {
            sum += m_prices[ index ];

            if( index == m_numPeriods )
            {
                ema.push_back( sum / m_numPeriods );
                sum -= m_prices[ index - m_numPeriods ];
            }
            else if( index > m_numPeriods )
            {
                auto val = ( 1 - multiplier ) * ema.back() + multiplier * m_prices[ index ];
                ema.push_back( val );
            }
        }

        return ema;
    }
}
