#pragma once

using namespace std;

namespace Common
{
    class TimeSeriesTransformations
    {
    public:
        TimeSeriesTransformations();
        TimeSeriesTransformations( const TimeSeriesTransformations& t );
        TimeSeriesTransformations& operator=( const TimeSeriesTransformations& t );
        ~TimeSeriesTransformations();

        void reducePrices( double val );
        void increasePrices( double val );
        void removePricesLessThan( double val );
        void removePricesGreatherThan( double val );
        double getFirstPriceLessThan( double val );

        void addValue( double val );
        void addValues( const vector<double> & vals );

        vector<double> getValues() const;

    protected:
        vector<double> m_prices;
    };
}
