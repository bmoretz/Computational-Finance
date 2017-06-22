#include "stdafx.h"
#include "CorrelationCalculator.h"
#include "Common.h"

namespace Common
{
    #pragma region Constructor / Deconstructor

    CorrelationCalculator::CorrelationCalculator( TimeSeries &tsA, TimeSeries &tsB )
        : m_tsA( tsA ),
          m_tsB( tsB )
    {
    }

    CorrelationCalculator::CorrelationCalculator( const CorrelationCalculator &cor )
        : m_tsA( cor.m_tsA ),
          m_tsB( cor.m_tsB )
    {
    }

    CorrelationCalculator& CorrelationCalculator::operator=( const CorrelationCalculator &cor )
    {
        if( this != &cor )
        {
            m_tsA = cor.m_tsA;
            m_tsB = cor.m_tsB;
        }

        return *this;
    }

    CorrelationCalculator::~CorrelationCalculator()
    {
    }

    #pragma endregion

    double CorrelationCalculator::correlation() const
    {
        if( m_tsA.size() != m_tsB.size() )
            throw exception( string( "Unable to correlate time series with different dimensions" ).c_str() );

        auto numElements = m_tsA.size();
        
        auto
            n = 1.0 / ( numElements - 1.0 ),
            xBar = m_tsA.mean(), yBar = m_tsB.mean(),
            xSigma = m_tsA.stdDev(), ySigma = m_tsB.stdDev();

        auto summation = Zero;

        for( auto index = 0; index < numElements; index++ )
        {
            summation += ( ( m_tsA.elem( index ) - xBar ) / xSigma ) * ( ( m_tsB.elem( index ) - yBar ) / ySigma );
        }

        return n * summation;
    }
}