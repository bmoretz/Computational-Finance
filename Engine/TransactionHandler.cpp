#include "stdafx.h"
#include "TransactionHandler.h"
#include "FileError.h"

namespace Utility
{
    #pragma region Constructor / Deconstructor

    TransactionTypeError::TransactionTypeError( const string &s )
        : runtime_error( s )
    {
    }

    TransactionHandler::TransactionHandler( const string &fileName )
        : m_fileName( fileName )
    {
    }

    TransactionHandler::TransactionHandler( const TransactionHandler &t )
    {
        m_fileName = t.m_fileName;
    }

    TransactionHandler& TransactionHandler::operator=( const TransactionHandler &t )
    {
        if( this != &t )
        {
            m_fileName = t.m_fileName;
        }

        return *this;
    }

    TransactionHandler::~TransactionHandler()
    {
    }

    #pragma endregion

    const string TransactionHandler::BUY_OP = "BUY";
    const string TransactionHandler::SELL_OP = "SELL";
    const string TransactionHandler::SHORT_OP = "SHORT";
    const string TransactionHandler::COVER_OP = "COVER";

    void TransactionHandler::handleTransactions() const
    {
        ifstream file;

        file.open( m_fileName, ifstream::in );

        if( file.fail() )
        {
            throw FileError( string( "Error opening file " ) + m_fileName );
        }

        string op;
        file >> op;

        while( file.good() && !file.eof() )
        {
            if( !( op == BUY_OP && op == SELL_OP && op == SHORT_OP && op == COVER_OP ) )
            {
                throw TransactionTypeError( string("Unknown Transaction Type:") + op );
            }
        }

        // process remaining
    }
}