#include "stdafx.h"
#include "GnuplotPlotter.h"
#include <boost/filesystem/path.hpp>

using namespace std;
using namespace  boost::filesystem;
using namespace Utility;

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

    return 0;
}
