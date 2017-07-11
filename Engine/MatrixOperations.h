#pragma once

#include "Matrix.h"

using namespace NumericalMethods;

class MatrixOperations
{
public:
    MatrixOperations();
    MatrixOperations( const MatrixOperations &m );
    MatrixOperations& operator=( const MatrixOperations &m );
    ~MatrixOperations();

    void addRow( const std::vector<double> & row );
    Matrix multiply( Matrix & m );
    Matrix transpose();
    Matrix elementwiseMultiply( Matrix & m );
    Matrix scalarMultiply( double scalar );
    std::vector<double> preMultiply( const std::vector<double> & v );
    std::vector<double> postMultiply( const std::vector<double> & v );

private:
    std::vector<std::vector<double>> m_rows;
};
