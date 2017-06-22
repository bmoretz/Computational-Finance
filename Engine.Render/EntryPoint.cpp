#include "stdafx.h"
#include "QtPlotter.h"

using namespace Rendering;


int main(int argc, char *argv[])
{
    QtPlotter plotter;

    vector<double> xdata, ydata;

    for( auto index = 0; index < 100; ++index )
    {
        auto x = index * 10 / 100.0;

        xdata.push_back( x );
        ydata.push_back( sin( x ) + 1 );
    }

    plotter.setData( xdata, ydata );

    return plotter.plotWindowRun();
}