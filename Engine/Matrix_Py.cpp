#include "stdafx.h"
#include "Matrix_Py.h"

#include <boost/python.hpp>
#include <boost/python/module.hpp>

using namespace boost::python;

namespace Python
{
	MatrixP::MatrixP( int a )
		: Matrix( a )
	{
	}

	MatrixP::MatrixP( const int a, const int b )
		: Matrix( a, b )
	{
	}

	void MatrixP::set( int a, int b, double v )
	{
		( *this )[ a ][ b ] = v;
	}

	double MatrixP::get( int a, int b )
	{
		return ( *this )[ a ][ b ];
	}

	BOOST_PYTHON_MODULE(matrix)
	{
		class_<MatrixP>("Matrix", init<int>())
			.def(init<int, int>())
			.def("add", &MatrixP::add)
			.def("subtract", &Matrix::subtract)
			.def("multiply", &Matrix::multiply)
		;
	}
}