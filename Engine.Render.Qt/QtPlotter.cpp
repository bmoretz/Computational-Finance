#include "QtPlotter.h"
#include <QtWidgets>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

QtPlotter::QtPlotter(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi( this );

      QPushButton *button = new QPushButton( QString("test"), this );

    button->move(100, 100);
    button->show();

    this->setCentralWidget( button );
}
