#pragma once

namespace NumericalMethods
{
    class PolynomialInterpolation
    {
    public:
        PolynomialInterpolation();
        PolynomialInterpolation( const PolynomialInterpolation &p );
        PolynomialInterpolation& operator=( const PolynomialInterpolation &p );
        ~PolynomialInterpolation();

        void setPoints( const std::vector<double> &x, const std::vector<double> &y );
        double getPolynomial( double x );

    protected:
        std::vector<double> m_x, m_y;
    };
}