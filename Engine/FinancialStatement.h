#pragma once
#include <memory>

using namespace std;

namespace Fundamentals
{
    class FinancialStatement
    {
    public:
        FinancialStatement();
        ~FinancialStatement();
        FinancialStatement( const FinancialStatement& fs);
        FinancialStatement& operator=( const FinancialStatement &fs );

        double getReturn() const;
        void addTransaction( const string & security, double val );

    private:
        double m_return;
        vector<pair<string,double>> m_transactions;
    };

    auto_ptr<FinancialStatement> getSampleStatement();
    void transferFinancialStatement( auto_ptr<FinancialStatement> statement );
}