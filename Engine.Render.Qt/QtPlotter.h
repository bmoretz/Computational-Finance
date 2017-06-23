#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtPlotter.h"

class QtPlotter :
        public QMainWindow
{
    Q_OBJECT

public:
    QtPlotter( QWidget *parent = Q_NULLPTR );

private:
    Ui::QtPlotterClass ui;
};
