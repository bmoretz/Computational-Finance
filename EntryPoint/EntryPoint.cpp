#include "stdafx.h"
#include "GnuplotPlotter.h"
#include <boost/filesystem/path.hpp>
#include "LPSolver.h"

using namespace std;
using namespace  boost::filesystem;
using namespace Utility;
using namespace NumericalMethods;

int main( int argc, const char **argv )
{
    if( argc != 1 )
    {
        cout << "Invalid arguments. They are ignored.";
    }

    GnuplotPlotter plotter { "test.csv" };

    plotter.setHeaders( "x", "sin(x)" );

    vector<double> xdata, ydata;

    for( auto index = 0; index < 100; ++index )
    {
        auto x = index * 10 / 100.0;

        xdata.push_back( x );
        ydata.push_back( sin( x ) );
    }

    plotter.setData( xdata, ydata );
    plotter.csvWrite();
    plotter.generateCmds( "testcmds.gp" );

	Matrix A(3);

	A[0][0] = 1;	A[0][1] = 1;	A[0][2] = 1;
	A[1][0] = 10;	A[1][1] = 2;	A[1][2] = 4;
	A[2][0] = 2;	A[2][1] = 5;	A[2][2] = 6;

	const vector<double> c = { 10, 6, 4 };
	const vector<double> b = { 100, 600, 300 };

	LPSolver solver(A, b, c);

	solver.setMaximization();

    return 0;
}
