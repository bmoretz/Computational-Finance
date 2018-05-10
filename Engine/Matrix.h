#pragma once

namespace NumericalMethods
{
    class Matrix
    {
    public:

        typedef std::vector<double> Row;

        Matrix( int m, int n );
        explicit Matrix( int size );
        Matrix( const Matrix &m );
        explicit Matrix( std::vector<Row> rows );
        Matrix& operator=( const Matrix &m );
        ~Matrix() = default;

        void transpose();
        double trace();
        void add( const Matrix &m );
        void subtract( const Matrix &m );
        void multiply( const Matrix &m );

        std::vector<Row> getRows() const;

        Row& operator[]( int pos );
        bool operator==( const Matrix &m ) const;

		size_t numRows() const;

        size_t size1() const
        {
            return m_rows.size();
        }

        size_t size2() const
        {
            return size1() > 0 ?
                m_rows[ 0 ].size() : 0;
        }

    private:
        std::vector<Row> m_rows;
    };

    Matrix operator+( const Matrix &m1, const Matrix &m2 );
    Matrix operator*( const Matrix &m1, const Matrix &m2 );
    Matrix operator-( const Matrix &m1, const Matrix &m2 );
}