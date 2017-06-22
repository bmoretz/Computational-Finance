#include "stdafx.h"
#include "NumVector.h"

namespace NumericalMethods
{
    #pragma region Constructor / Deconstructor

    NumVector::NumVector()
    {
    }

    NumVector::NumVector( const NumVector &v )
    {
        m_values = v.m_values;
    }

    NumVector& NumVector::operator=( const NumVector &v )
    {
        if( this != &v )
        {
            m_values = v.m_values;
        }

        return *this;
    }

    NumVector::~NumVector()
    {
    }

    #pragma endregion

    void NumVector::add( double val )
    {
        m_values.push_back( val );
    }

    void NumVector::removeLast()
    {
        m_values.pop_back();
    }

    double NumVector::get( int pos ) const
    {
        return m_values.at( pos );
    }

    size_t NumVector::size() const
    {
        return m_values.size();
    }

    NumVector operator+( const NumVector &l, const NumVector &r )
    {
        if( l.size() != r.size() )
            throw new runtime_error( "vectors must have the same size" );

        NumVector result;

        for( auto index = 0; index < l.size(); ++index )
        {
            result.add( l.get( index ) + r.get( index ) );
        }

        return result;
    }

    NumVector operator-( const NumVector &l, const NumVector &r )
    {
        if( l.size() != r.size() )
            throw new runtime_error( "vectors must have the same size" );

        NumVector result;

        for( auto index = 0; index < l.size(); ++index )
        {
            result.add( l.get( index ) - r.get( index ) );
        }

        return result;
    }

    NumVector operator*( const NumVector &l, const NumVector &r )
    {
        if( l.size() != r.size() )
            throw new runtime_error( "vectors must have the same size" );

        NumVector result;

        for( auto index = 0; index < l.size(); ++index )
        {
            result.add( l.get( index ) * r.get( index ) );
        }

        return result;
    }
}
