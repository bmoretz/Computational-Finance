#include "stdafx.h"
#include "TimeSeriesTransformations.h"
#include <functional>
#include "Common.h"

namespace Common
{
    #pragma region Constructor / Deconstructor

    TimeSeriesTransformations::TimeSeriesTransformations()
        : m_prices( 0 )
    {
    }

    TimeSeriesTransformations::TimeSeriesTransformations( const TimeSeriesTransformations &t )
    {
        m_prices = t.m_prices;
    }

    TimeSeriesTransformations& TimeSeriesTransformations::operator=( const TimeSeriesTransformations &t )
    {
        if( this != &t )
        {
            m_prices = t.m_prices;
        }

        return *this;
    }

    TimeSeriesTransformations::~TimeSeriesTransformations()
    {
    }

    #pragma endregion

    void TimeSeriesTransformations::reducePrices( double val )
    {
        vector<double> res( m_prices.size() );

        transform( m_prices.begin(), m_prices.end(), res.begin(), bind2nd( minus<double>(), val ) );

        m_prices.swap( res );
    }

    void TimeSeriesTransformations::increasePrices( double val )
    {
        vector<double> res( m_prices.size() );

        transform( m_prices.begin(), m_prices.end(), res.begin(), bind2nd( plus<double>(), val ) );

        m_prices.swap( res );
    }

    void TimeSeriesTransformations::removePricesLessThan( double val )
    {
        m_prices.erase( remove_if( m_prices.begin(), m_prices.end(), bind2nd( less<double>(), val ) ), m_prices.end() );
    }

    void TimeSeriesTransformations::removePricesGreatherThan( double val )
    {
        m_prices.erase( remove_if( m_prices.begin(), m_prices.end(), bind2nd( greater<double>(), val ) ), m_prices.end() );
    }

    double TimeSeriesTransformations::getFirstPriceLessThan( double val )
    {
        if( m_prices.size() == Zero )
            return Zero;

        auto res = find_if( m_prices.begin(), m_prices.end(), bind2nd( less<double>(), val ) );

        if( res != m_prices.end() )
            return *res;

        return Zero;
    }

    void TimeSeriesTransformations::addValue( double val )
    {
        m_prices.push_back( val );
    }

    void TimeSeriesTransformations::addValues( const vector<double> &vals )
    {
        m_prices.insert( m_prices.end(), vals.begin(), vals.end() );
    }

    vector<double> TimeSeriesTransformations::getValues() const
    {
        return m_prices;
    }
}
