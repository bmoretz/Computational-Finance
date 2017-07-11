#pragma once

namespace NumericalMethods
{
    class VectorOperations
    {
    public:
        explicit VectorOperations( const std::vector<double> data );

        VectorOperations( const VectorOperations &v );
        VectorOperations& operator=( const VectorOperations &v );
        ~VectorOperations();

        std::vector<double> scaleMult( double scalar );
        std::vector<double> addVector( const std::vector<double> &v );
        std::vector<double> subtractVector( const std::vector<double> &v );

        double dotProd( const std::vector<double> &v );
        double norm();

    protected:
        std::vector<double> m_data;
    };
}