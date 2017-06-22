#pragma once

using namespace std;

namespace NumericalMethods
{
    class NumVector
    {
    public:
        NumVector();
        NumVector( const NumVector &v );
        NumVector& operator=( const NumVector &v );
        ~NumVector();

        void add( double val );
        void removeLast();
        double get( int pos) const;
        size_t size() const;

    private:
        vector<double> m_values;
    };

    NumVector operator +( const NumVector &l, const NumVector& r );
    NumVector operator -( const NumVector &l, const NumVector& r );
    NumVector operator *( const NumVector &l, const NumVector& r );
}