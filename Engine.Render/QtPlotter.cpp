#include "stdafx.h"
#include "QtPlotter.h"

namespace Rendering
{
    class PlotWindow :
            public QMainWindow
    {
    public:
        PlotWindow();
        ~PlotWindow();

        void paintEvent( QPaintEvent *event ) override;
        void setData( const vector<double> &xdata, const vector<double> &ydata );

    private:
        vector<double> m_xdata;
        vector<double> m_ydata;
    };

    #pragma region Constructor / Deconstructor

    QtPlotter::QtPlotter()
    {
    }

    QtPlotter::QtPlotter( const QtPlotter &q )
        : m_xdata( q.m_xdata ),
          m_ydata( q.m_ydata )
    {
    }

    QtPlotter& QtPlotter::operator=( const QtPlotter &q )
    {
        if( this != &q )
        {
            m_xdata = q.m_xdata;
            m_ydata = q.m_ydata;
        }

        return *this;
    }


    QtPlotter::~QtPlotter()
    {
    }

    #pragma endregion

    void QtPlotter::setData( const vector<double> &xdata, const vector<double> &ydata )
    {
        m_xdata = xdata;
        m_ydata = ydata;
    }

    int QtPlotter::plotWindowRun()
    {
        auto argv = static_cast<char *>( "plotter" );
        auto argc = 1;

        QApplication app( argc, &argv );

        QCoreApplication::setOrganizationName( "QtProject" );
        QCoreApplication::setApplicationName( "Application Example" );
        QCoreApplication::setApplicationVersion( QT_VERSION_STR );

        PlotWindow window;

        window.resize( 600, 600 );
        window.show();

        return app.exec();
    }

    PlotWindow::PlotWindow()
    {
    }

    PlotWindow::~PlotWindow()
    {
    }

    void PlotWindow::paintEvent( QPaintEvent *event )
    {
        QMainWindow::paintEvent( event );

        QPainter painter( this );

        auto
                marginX = 10.0,
                marginY = 10.0,
                lengthX = 500.0,
                lengthY = 400.0;

        int maxX = lengthX, maxY = lengthY;

        // Define Axis
        painter.drawLine( marginX, marginY, marginX, lengthY + marginY );
        painter.drawLine( marginX, lengthY + marginY, lengthX, lengthY + marginY );

        // find units
        auto largeX = 0, largeY = 0;
        auto largeXd = 0.0, largeYd = 0.0;

        for( unsigned index = 1; index < m_xdata.size(); ++index )
        {
            if( largeXd < m_xdata[ index ] ) largeXd = m_xdata[ index ];
            if( largeXd < m_ydata[ index ] ) largeYd = m_ydata[ index ];
        }

        largeX = static_cast<int>( largeXd + 1 );
        largeY = static_cast<int>( largeYd + 1 );

        auto
                unitX = maxX / largeX,
                unitY = maxY / largeY;

        for( auto index = 0; index < largeY; ++index )
        {
            painter.drawLine( marginX - 5, index * unitY + marginY, marginX, index * unitY + marginY );
        }

        for( auto index = 0; index < largeX; ++index )
        {
            painter.drawLine( marginX + index * unitX, lengthY + marginY, marginX + index * unitX, lengthY + 5 + marginY );
        }

        for( unsigned index = 1; index < m_xdata.size(); ++index )
        {
            painter.drawLine( marginX + unitX * m_xdata[ index - 1 ], unitY * m_ydata[ index - 1 ] + marginY,
                              marginX + unitX * m_xdata[ index ], unitY * m_ydata[ index ] + marginY );
        }
    }

    void PlotWindow::setData( const vector<double> &xdata, const vector<double> &ydata )
    {
        m_xdata = xdata;
        m_ydata = ydata;
    }
}
