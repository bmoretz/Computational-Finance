#pragma once

using namespace std;

namespace Common
{
    class TimeSeries
    {
    public:
        TimeSeries();
        TimeSeries( const TimeSeries &ts );
        TimeSeries& operator=( const TimeSeries &ts );
        ~TimeSeries();

        void addValue( double val );
        void addValues( vector<double> values );
        double mean() const;
        double stdDev() const;
        size_t size() const;
        double elem( int index );

    protected:
        vector<double> m_values;
    };
}