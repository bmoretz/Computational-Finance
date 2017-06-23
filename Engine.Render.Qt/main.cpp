#include "QtPlotter.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );

    QtPlotter w;

    w.show();

    return a.exec();
}
