#pragma once

#include "Matrix.h"

using namespace NumericalMethods;

#include <iostream>

namespace Python
{
	class MatrixP : public Matrix
	{
	public:
		explicit MatrixP( int a );
		MatrixP( int a, int b );
		MatrixP( const MatrixP &p ) = default;
		~MatrixP() = default;

		void set( int a, int b, double v );
		double get( int a, int b );
	};
}
