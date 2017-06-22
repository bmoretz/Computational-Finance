#pragma once

#include "Common.h"

using namespace std;

namespace Common
{
    class VolatilityCalculator
    {
    public:
        VolatilityCalculator();
        VolatilityCalculator( const VolatilityCalculator &v );;
        VolatilityCalculator& operator=( const VolatilityCalculator &v );
        ~VolatilityCalculator();

        void addPriceQuote( double quote )
        {
            m_prices.push_back( quote );
        }
        
        void addPriceQuotes( vector<double> quotes )
        {
            m_prices.insert( m_prices.end(), quotes.begin(), quotes.end() );
        }

        double rangeVolatility();
        double avgDailyRange();
        double stdDev() const;

    protected:
        vector<double> m_prices;
    };
}