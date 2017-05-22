#pragma once

using namespace std;

namespace Common
{
    class MACalculator
    {
    public:
        explicit MACalculator( int periods, double emaFactor = 2.0 );
        MACalculator( const MACalculator &v );
        MACalculator& operator=( const MACalculator &v );
        ~MACalculator();

        void addPriceQuote( double quote )
        {
            m_prices.push_back( quote );
        }
        
        void addPriceQuotes( vector<double> quotes )
        {
            m_prices.insert( m_prices.end(), quotes.begin(), quotes.end() );
        }

        vector<double> calculateMA();
        vector<double> calculateEMA();

    protected:
        vector<double> m_prices;
        int m_numPeriods;
        double m_emaFactor = 2.0;
    };
}
