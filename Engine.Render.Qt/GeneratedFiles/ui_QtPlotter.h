/********************************************************************************
** Form generated from reading UI file 'QtPlotter.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTPLOTTER_H
#define UI_QTPLOTTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtPlotterClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtPlotterClass)
    {
        if (QtPlotterClass->objectName().isEmpty())
            QtPlotterClass->setObjectName(QStringLiteral("QtPlotterClass"));
        QtPlotterClass->resize(600, 400);
        menuBar = new QMenuBar(QtPlotterClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtPlotterClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtPlotterClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtPlotterClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtPlotterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtPlotterClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtPlotterClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtPlotterClass->setStatusBar(statusBar);

        retranslateUi(QtPlotterClass);

        QMetaObject::connectSlotsByName(QtPlotterClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtPlotterClass)
    {
        QtPlotterClass->setWindowTitle(QApplication::translate("QtPlotterClass", "QtPlotter", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtPlotterClass: public Ui_QtPlotterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTPLOTTER_H
