#pragma once
#include <vector>

namespace NumericalMethods
{
    class LinearInterpolation
    {
    public:
        LinearInterpolation();
        LinearInterpolation( const LinearInterpolation &l ) = default;
        LinearInterpolation& operator=( const LinearInterpolation &l );
        ~LinearInterpolation() = default;

        void setPoints( const std::vector<double> & x_vals, const std::vector<double> &y_vals);
        double getValue( double x );

    private:
        std::vector<double> m_y;
        std::vector<double> m_x;
    };
}