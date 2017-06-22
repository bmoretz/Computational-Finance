#pragma once
#include "TimeSeries.h"

using namespace std;

namespace Common
{
    class CorrelationCalculator
    {
    public:
        CorrelationCalculator( TimeSeries &tsA, TimeSeries &tsB );
        CorrelationCalculator( const CorrelationCalculator &cor );
        CorrelationCalculator& operator=( const CorrelationCalculator &cor );
        ~CorrelationCalculator();

        double correlation() const;

    private:
        TimeSeries &m_tsA;
        TimeSeries &m_tsB;
    };
}