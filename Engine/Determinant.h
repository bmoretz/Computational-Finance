#pragma once

#include "Matrix.h"

namespace NumericalMethods
{
    class Determinant
    {
    public:
        Determinant();
        Determinant( const Determinant &d );
        Determinant& operator=( const Determinant &d );
        ~Determinant();

        static double getDeterminant( const Matrix & m );
    };
}
