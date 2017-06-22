#include "stdafx.h"
#include "TimeSeries.h"
#include "Common.h"

using namespace std;
using namespace Common;

namespace Common
{
    #pragma region Constructor / Deconstructor

    TimeSeries::TimeSeries()
    {
    }

    TimeSeries::TimeSeries( const TimeSeries &ts )
        : m_values( ts.m_values )
    {
    }

    TimeSeries& TimeSeries::operator=( const TimeSeries &ts )
    {
        if( this != &ts )
        {
            m_values = ts.m_values;
        }

        return *this;
    }

    TimeSeries::~TimeSeries()
    {
    }

    #pragma endregion

    void TimeSeries::addValue( double val )
    {
        m_values.push_back( val );
    }

    void TimeSeries::addValues( vector<double> values )
    {
        m_values.insert( m_values.end(), values.begin(), values.end() );
    }

    double TimeSeries::mean() const
    {
        return Common::mean( m_values );
    }

    double TimeSeries::stdDev() const
    {
        return Common::stdDev( m_values );
    }

    size_t TimeSeries::size() const
    {
        return m_values.size();
    }

    double TimeSeries::elem( int index )
    {
        return m_values.at( index );
    }
}