#include "stdafx.h"
#include "GnuplotPlotter.h"

namespace Utility
{
    #pragma region Constructor / Deconstructor

    GnuplotPlotter::GnuplotPlotter( const string &fileName )
        : m_fileName( fileName ),
          m_isDate( false )
    {
    }

    GnuplotPlotter::GnuplotPlotter( const GnuplotPlotter &plotter )
        : m_fileName( plotter.m_fileName ),
          m_xheader( plotter.m_xheader ),
          m_yheader( plotter.m_yheader ),
          m_xdata( plotter.m_xdata ),
          m_ydata( plotter.m_ydata ),
          m_isDate( plotter.m_isDate )
    {
    }

    GnuplotPlotter& GnuplotPlotter::operator=( const GnuplotPlotter &plotter )
    {
        if( this != & plotter )
        {
            m_fileName = plotter.m_fileName;
            m_xheader = plotter.m_xheader;
            m_yheader = plotter.m_yheader;
            m_xdata = plotter.m_xdata;
            m_ydata = plotter.m_ydata;
            m_isDate = plotter.m_isDate;
        }

        return *this;
    }

    GnuplotPlotter::~GnuplotPlotter()
    {
    }

    #pragma endregion

    void GnuplotPlotter::generateCmds( const string &cmdFileName ) const
    {
        ofstream file;

        file.open( cmdFileName.c_str() );

        if( file.fail() )
        {
            cout << "failed to open the file" << m_fileName << endl;
            return;
        }

        if( m_isDate )
        {
            file << "set xdata time" << endl;
            file << "set timefmt \"%Y-%m-%d\"" << endl;
        }

        file << "set datafile separator \",\" " << endl;
        file << "plot '" << m_fileName << "' u 1:2 title columnhead w lines " << endl;
        file << "pause -1" << endl;
    }

    void GnuplotPlotter::setHeaders( const string &xheader, const string &yheader )
    {
        m_xheader = xheader;
        m_yheader = yheader;
    }

    void GnuplotPlotter::setData( const vector<double> &xdata, const vector<double> &ydata )
    {
        for( auto data : xdata )
        {
            stringstream ss;
            ss << data;
            m_xdata.push_back( ss.str() );
        }

        m_ydata = ydata;
        m_isDate = false;
    }

    void GnuplotPlotter::setData( const vector<string> &xdata, const vector<double> &ydata )
    {
        m_xdata = xdata;
        m_ydata = ydata;
        m_isDate = true;
    }

    void GnuplotPlotter::csvWrite()
    {
        ofstream file;

        file.open( m_fileName.c_str() );

        if( file.fail() )
        {
            cout << "failed to open the file" << m_fileName << endl;
            return;          
        }

        if( m_xdata.size() != m_ydata.size() )
        {
            cout << "data has incorrect size" << endl;
            return;
        }

        file << m_xheader << "," << m_yheader << endl;

        for( auto index = 0; index < m_xdata.size(); ++index )
        {
            file << m_xdata[ index ] << "," << m_ydata[ index ] << endl;
        }
    }
}
