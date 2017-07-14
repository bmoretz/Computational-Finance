#include "stdafx.h"
#include "VectorOperations.h"
#include <boost/numeric/ublas/vector.hpp>

using namespace boost::numeric::ublas;

namespace NumericalMethods
{
    #pragma region Constructor / Deconstructor


    VectorOperations::VectorOperations( const std::vector<double> data )
        : m_data( data )
    {
    }

    VectorOperations::VectorOperations( const VectorOperations &v )
        : m_data( v.m_data )
    {
    }

    VectorOperations& VectorOperations::operator=( const VectorOperations &v )
    {
        if( this != &v )
        {
            m_data = v.m_data;
        }

        return *this;
    }

    VectorOperations::~VectorOperations()
    {
    }

    #pragma endregion

    std::vector<double> VectorOperations::scaleMult( double scalar )
    {
        vector<double> vx;

        copy( m_data.begin(), m_data.end(), vx.end() );

        vector<double> res = vx * scalar;

        std::vector<double> v;
        copy( res.begin(), res.end(), v.end() );

        return v;
    }

    std::vector<double> VectorOperations::addVector( const std::vector<double> &v )
    {
        vector<double> v1, v2;

        copy( v.begin(), v.end(), v1.begin() );
        copy( m_data.begin(), m_data.end(), v1.begin() );

        auto result_vec = v1 + v2;

        std::vector<double> result;
        copy( result_vec.begin(), result_vec.end(), result.begin() );

        return result;
    }

    std::vector<double> VectorOperations::subtractVector( const std::vector<double> &v )
    {
        vector<double> v1, v2;

        copy( v.begin(), v.end(), v1.begin() );
        copy( m_data.begin(), m_data.end(), v1.begin() );

        auto result_vec = v1 - v2;

        std::vector<double> result;
        copy( result_vec.begin(), result_vec.end(), result.begin() );

        return result;
    }

    double VectorOperations::dotProd( const std::vector<double> &v )
    {
        vector<double> v1, v2;

        copy( v.begin(), v.end(), v1.begin() );
        copy( m_data.begin(), m_data.end(), v1.begin() );

        auto result = inner_prod( v1, v2 );

        return result;
    }

    double VectorOperations::norm()
    {
        vector<double> v;

        copy( m_data.begin(), m_data.end(), v.begin() );

        auto result = norm_2( v );

        return result;
    }
}
