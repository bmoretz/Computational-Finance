#include "stdafx.h"
#include "Determinant.h"
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/lu.hpp>

using namespace boost::numeric::ublas;

namespace NumericalMethods
{
    #pragma region Constructor / Deconstructor

    Determinant::Determinant()
    {
    }

    Determinant::Determinant( const Determinant &d )
    {
    }

    Determinant& Determinant::operator=( const Determinant &d )
    {
        if( this != &d )
        {
        }

        return *this;
    }


    Determinant::~Determinant()
    {
    }

    #pragma endregion

    // The sign is calculated from a given permutation.
    // Just flip the sign for each change in permutation.
    int getDeterminantSign( const permutation_matrix<size_t> &pm )
    {
        auto sign = 1;

        for( auto i = 0; i < pm.size(); ++i )
        {
            if( i != pm( i ) )
            {
                sign *= -1.0;
            }
        }

        return sign;
    }

    // Returns the value of the determinant for matrix m
    double computeDeterminant( matrix<double> &m )
    {
        permutation_matrix<size_t> pm( m.size1() );

        auto det = 1.0;

        if( lu_factorize( m, pm ) )
        {
            det = 0.0;
        }
        else
        {
            for( auto i = 0; i < m.size1(); i++ )
            {
                det *= m( i, i );
            }

            det = det * getDeterminantSign( pm );
        }

        return det;
    }

    double Determinant::getDeterminant( const Matrix &m )
    {
        auto rows = m.getRows();

        matrix<double> M( m.size1(), m.size2() );

        for( auto i = 0; i < rows.size(); ++i )
        {
            auto row = rows[ i ];

            for( auto j = 0; j < row.size(); ++j )
            {
                M( i, j ) = row[ j ];
            }
        }

        return computeDeterminant( M );
    }
}
