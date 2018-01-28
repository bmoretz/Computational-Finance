#include "stdafx.h"
#include "MatrixOperations.h"
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/lu.hpp>

using namespace boost::numeric::ublas;

#pragma region Constructor / Deconstructor

MatrixOperations::MatrixOperations()
    : m_rows( 0 )
{
}

MatrixOperations::MatrixOperations( const MatrixOperations &m )
    : m_rows( m.m_rows )
{
}

MatrixOperations& MatrixOperations::operator=( const MatrixOperations &m )
{
    if( this != &m )
    {
        m_rows = m.m_rows;
    }

    return *this;
}


MatrixOperations::~MatrixOperations()
{
}

#pragma endregion

static Matrix fromMatrix( const matrix<double> &mp )
{
    auto d1 = mp.size1();
    auto d2 = mp.size2();

    Matrix res( static_cast<int>( d1 ), static_cast<int>( d2 ) );

    for( auto i = 0; i < d1; ++i )
    {
        for( auto j = 0; j < d2; ++j )
        {
            res[ i ][ j ] = mp( i, j );
        }
    }

    return res;
}

void MatrixOperations::addRow( const std::vector<double> &row )
{
    m_rows.push_back( row );
}

Matrix MatrixOperations::multiply( Matrix &m )
{
    auto d1 = m_rows.size();
    auto d2 = m_rows[ 0 ].size();

    matrix<double> M1( d1, d2 );

    for( auto i = 0; i < d1; ++i )
    {
        for( auto j = 0; j < d2; ++j )
        {
            M1( i, j ) = m_rows[ i ][ j ];
        }
    }

    matrix<double> M2( d1, d2 );

    for( auto i = 0; i < d1; ++i )
    {
        for( auto j = 0; j < d2; ++j )
        {
            M2( i, j ) = m[ i ][ j ];
        }
    }

    auto mp = prod( M1, M2 );

    return fromMatrix( mp );
}

Matrix MatrixOperations::transpose()
{
	auto d1 = m_rows.size();
	auto d2 = m_rows[ 0 ].size();

    matrix<double> M( d1, d2 );

    for( auto i = 0; i < d1; ++i )
    {
        for( auto j = 0; j < d2; ++j )
        {
            M( i, j ) = m_rows[ i ][ j ];
        }
    }

    matrix<double> mp = trans( M );

    return fromMatrix( mp );
}

Matrix MatrixOperations::elementwiseMultiply( Matrix &m )
{
	auto d1 = m_rows.size();
	auto d2 = m_rows[ 0 ].size();

    matrix<double> M1( d1, d2 );

    for( auto i = 0; i < d1; ++i )
    {
        for( auto j = 0; j < d2; ++j )
        {
            M1( i, j ) = m_rows[ i ][ j ];
        }
    }

    matrix<double> M2( d1, d2 );

    for( auto i = 0; i < d1; ++i )
    {
        for( auto j = 0; j < d2; ++j )
        {
            M2( i, j ) = m[ i ][ j ];
        }
    }

    auto mp = element_prod( M1, M2 );

    return fromMatrix( mp );
}

Matrix MatrixOperations::scalarMultiply( double scalar )
{
	auto d1 = m_rows.size();
	auto d2 = m_rows[ 0 ].size();

    matrix<double> M( d1, d2 );

    for( auto i = 0; i < d1; ++i )
    {
        for( auto j = 0; j < d2; ++j )
        {
            M( i, j ) = m_rows[ i ][ j ];
        }
    }

    auto res = scalar * M;

    return fromMatrix( res );
}

std::vector<double> MatrixOperations::preMultiply( const std::vector<double> &v )
{
    vector<double> vec;

    copy( v.begin(), v.end(), vec.begin() );

	auto d1 = m_rows.size();
	auto d2 = m_rows[ 0 ].size();

    matrix<double> M( d1, d2 );

    for( auto i = 0; i < d1; ++i )
    {
        for( auto j = 0; j < d2; ++j )
        {
            M( i, j ) = m_rows[ i ][ j ];
        }
    }

    auto pv = prod( vec, M );

    std::vector<double> res;
    copy( pv.begin(), pv.end(), res.begin() );

    return res;
}

std::vector<double> MatrixOperations::postMultiply( const std::vector<double> &v )
{
    vector<double> vec;

    copy( v.begin(), v.end(), vec.begin() );

	auto d1 = m_rows.size();
	auto d2 = m_rows[ 0 ].size();

    matrix<double> M( d1, d2 );

    for( auto i = 0; i < d1; ++i )
    {
        for( auto j = 0; j < d2; ++j )
        {
            M( i, j ) = m_rows[ i ][ j ];
        }
    }

    auto pv = prod( M, vec );

    std::vector<double> res;
    copy( pv.begin(), pv.end(), res.begin() );

    return res;
}
