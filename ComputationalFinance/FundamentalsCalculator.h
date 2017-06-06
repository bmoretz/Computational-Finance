#pragma once

using namespace std;

namespace Fundamentals
{
    class FundamentalsCalculator
    {
    public:
        FundamentalsCalculator( const string &ticker, double price, double dividend );
        FundamentalsCalculator( const FundamentalsCalculator &f );
        FundamentalsCalculator& operator=( const FundamentalsCalculator &f );
        ~FundamentalsCalculator();

        void setNumOfShares( int n );
        void setEarnings( double val );
        void setExpectedEarnings( double val );
        void setBookValue( double val );
        void setAssets( double val );
        void setLiabilitiesAndIntangibles( double val );
        void setEpsGrowth( double val );
        void setNetIncome( double val );
        void setShareHoldersEquity( double val );

        double PE() const;
        double forwardPE() const;
        double bookValue() const;
        double priceToBookRatio() const;
        double priceEarningsToGrowth() const;
        double returnOnEquity() const;
        double getDividend() const;

    private:
        string m_ticker;
        double m_price, m_dividend, m_earningsEstimate;
        int m_numShares;
        double m_earnings, m_bookValue, m_assets, m_liabilitiesAndIntangibles;
        double m_epsGrowth, m_netIncome, m_shareholdersEquity;
    };
}
