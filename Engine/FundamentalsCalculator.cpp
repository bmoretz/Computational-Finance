#include "stdafx.h"
#include "FundamentalsCalculator.h"

namespace Fundamentals
{
    #pragma region Constructor / Deconstructor

    FundamentalsCalculator::FundamentalsCalculator( const string &ticker, double price, double dividend )
        : m_ticker( ticker ),
          m_price( price ),
          m_dividend( dividend ),
          m_earningsEstimate( 0 ),
          m_numShares( 0 ),
          m_earnings( 0 ),
          m_bookValue( 0 ),
          m_assets( 0 ),
          m_liabilitiesAndIntangibles( 0 ),
          m_epsGrowth( 0 ),
          m_netIncome( 0 ),
          m_shareholdersEquity( 0 )
    {
    }

    FundamentalsCalculator::FundamentalsCalculator( const FundamentalsCalculator &f )
        : m_ticker( f.m_ticker ),
          m_price( f.m_price ),
          m_dividend( f.m_dividend ),
          m_earningsEstimate( f.m_earningsEstimate ),
          m_numShares( f.m_numShares ),
          m_earnings( f.m_earnings ),
          m_bookValue( f.m_bookValue ),
          m_assets( f.m_assets ),
          m_liabilitiesAndIntangibles( f.m_liabilitiesAndIntangibles ),
          m_epsGrowth( f.m_epsGrowth ),
          m_netIncome( f.m_netIncome ),
          m_shareholdersEquity( f.m_shareholdersEquity )
    {
    }

    FundamentalsCalculator& FundamentalsCalculator::operator=( const FundamentalsCalculator &f )
    {
        if( this != &f )
        {
            m_ticker = f.m_ticker;
            m_price = f.m_price;
            m_dividend = f.m_dividend;
            m_earningsEstimate = f.m_earningsEstimate;
            m_numShares = f.m_numShares;
            m_earnings = f.m_earnings;
            m_bookValue = f.m_bookValue;
            m_assets = f.m_assets;
            m_liabilitiesAndIntangibles = f.m_liabilitiesAndIntangibles;
            m_epsGrowth = f.m_epsGrowth;
            m_netIncome = f.m_netIncome;
            m_shareholdersEquity = f.m_shareholdersEquity;
        }

        return *this;
    }

    FundamentalsCalculator::~FundamentalsCalculator()
    {
    }

    #pragma endregion

    #pragma region Setters

    void FundamentalsCalculator::setNumOfShares( int n )
    {
        m_numShares = n;
    }

    void FundamentalsCalculator::setEarnings( double val )
    {
        m_earnings = val;
    }

    void FundamentalsCalculator::setExpectedEarnings( double val )
    {
        m_earningsEstimate = val;
    }

    void FundamentalsCalculator::setBookValue( double val )
    {
        m_bookValue = val;
    }

    void FundamentalsCalculator::setAssets( double val )
    {
        m_assets = val;
    }

    void FundamentalsCalculator::setLiabilitiesAndIntangibles( double val )
    {
        m_liabilitiesAndIntangibles = val;
    }

    void FundamentalsCalculator::setEpsGrowth( double val )
    {
        m_epsGrowth = val;
    }

    void FundamentalsCalculator::setNetIncome( double val )
    {
        m_netIncome = val;
    }

    void FundamentalsCalculator::setShareHoldersEquity( double val )
    {
        m_shareholdersEquity = val;
    }

    #pragma endregion

    double FundamentalsCalculator::PE() const
    {
        return ( m_price * m_numShares ) / m_earnings;
    }

    double FundamentalsCalculator::forwardPE() const
    {
        return ( m_price * m_numShares ) / m_earningsEstimate;
    }

    double FundamentalsCalculator::bookValue() const
    {
        return m_bookValue;
    }

    double FundamentalsCalculator::priceToBookRatio() const
    {
        return ( m_price * m_numShares ) / ( m_assets - m_liabilitiesAndIntangibles );
    }


    double FundamentalsCalculator::priceEarningsToGrowth() const
    {
        return PE() / m_epsGrowth;
    }

    double FundamentalsCalculator::returnOnEquity() const
    {
        return m_netIncome / m_shareholdersEquity;
    }

    double FundamentalsCalculator::getDividend() const
    {
        return m_dividend;
    }
}
