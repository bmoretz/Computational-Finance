#include "stdafx.h"
#include "VolatilityCalculator.h"
#include "Common.h"

namespace Common
{
    VolatilityCalculator::VolatilityCalculator()
    {
    }

    VolatilityCalculator::VolatilityCalculator( const VolatilityCalculator &v )
    {
        m_prices = v.m_prices;
    }

    VolatilityCalculator& VolatilityCalculator::operator=( const VolatilityCalculator &v )
    {
        if( this != &v )
        {
            m_prices = v.m_prices;
        }

        return *this;
    }

    VolatilityCalculator::~VolatilityCalculator()
    {
    }

    double VolatilityCalculator::rangeVolatility()
    {
        if( m_prices.size() == 0 )
            return Zero;

        auto
                high = numeric_limits<double>::lowest(),
                low = numeric_limits<double>::infinity();

        for( auto p : m_prices )
        {
            high = max( high, p );
            low = min( p, low );
        }

        return high - low;
    }

    double VolatilityCalculator::avgDailyRange()
    {
        if( m_prices.size() <= 2 )
            return Zero;

        auto previous = m_prices[ 0 ];
        auto sum = 0.0;

        for( auto index = 1; index < m_prices.size(); index++ )
        {
			const auto current = m_prices[ index ];

            sum += abs( current - previous );
            previous = current;
        }

        return sum / ( m_prices.size() - 1 );
    }

    double VolatilityCalculator::stdDev() const
    {
        return Common::stdDev( m_prices );
    }
}
