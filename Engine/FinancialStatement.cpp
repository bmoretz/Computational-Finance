#include "stdafx.h"
#include "FinancialStatement.h"

namespace Fundamentals
{
    #pragma region Constructor / Deconstructor

    FinancialStatement::FinancialStatement()
        : m_return( 0 )
    {
    }

    FinancialStatement::~FinancialStatement()
    {
    }

    FinancialStatement::FinancialStatement( const FinancialStatement &fs )
        : m_return( fs.m_return ),
          m_transactions( fs.m_transactions )
    {
    }

    FinancialStatement& FinancialStatement::operator=( const FinancialStatement &fs )
    {
        if( this != &fs )
        {
            m_return = fs.m_return;
            m_transactions = fs.m_transactions;
            m_transactions = fs.m_transactions;
        }

        return *this;
    }

    #pragma endregion

    double FinancialStatement::getReturn() const
    {
        return m_return;
    }

    void FinancialStatement::addTransaction( const string &security, double val )
    {
        m_transactions.push_back( make_pair( security, val ) );
    }

    auto_ptr<FinancialStatement> getSampleStatement()
    {
        auto_ptr<FinancialStatement> fs( new FinancialStatement );

        fs->addTransaction( "IBM", 102.2 );
        fs->addTransaction( "AAPL", 523.0 );

        return fs;
    }

    void transferFinancialStatement( auto_ptr<FinancialStatement> statement )
    {
        // perform transfer here
        // ....
        // statement is still valid

        cout << statement->getReturn() << endl;

        // statement is released here
    }
}
