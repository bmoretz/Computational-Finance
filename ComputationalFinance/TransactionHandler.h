#pragma once

using namespace std;

namespace Common
{
    enum TransactionType
    {
        TRANSACTION_BUY,
        TRANSACTION_SELL,
        TRANSACTION_COVER,
        TRANSACTION_SHORT
    };

    class TransactionTypeError
        : runtime_error
    {
    public:

        explicit TransactionTypeError( const string &s);    
    };

    class TransactionHandler
    {
    public:

        static const string SELL_OP;
        static const string BUY_OP;
        static const string SHORT_OP;
        static const string COVER_OP;

        explicit TransactionHandler( const string &fileName );
        TransactionHandler( const TransactionHandler& t );
        TransactionHandler& operator=( const TransactionHandler &t );
        ~TransactionHandler();

        void handleTransactions() const;

    private:
        string m_fileName;
    };
}
