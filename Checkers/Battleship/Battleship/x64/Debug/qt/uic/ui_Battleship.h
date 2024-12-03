/********************************************************************************
** Form generated from reading UI file 'Battleship.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTLESHIP_H
#define UI_BATTLESHIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BattleshipClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BattleshipClass)
    {
        if (BattleshipClass->objectName().isEmpty())
            BattleshipClass->setObjectName("BattleshipClass");
        BattleshipClass->resize(600, 400);
        menuBar = new QMenuBar(BattleshipClass);
        menuBar->setObjectName("menuBar");
        BattleshipClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BattleshipClass);
        mainToolBar->setObjectName("mainToolBar");
        BattleshipClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(BattleshipClass);
        centralWidget->setObjectName("centralWidget");
        BattleshipClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(BattleshipClass);
        statusBar->setObjectName("statusBar");
        BattleshipClass->setStatusBar(statusBar);

        retranslateUi(BattleshipClass);

        QMetaObject::connectSlotsByName(BattleshipClass);
    } // setupUi

    void retranslateUi(QMainWindow *BattleshipClass)
    {
        BattleshipClass->setWindowTitle(QCoreApplication::translate("BattleshipClass", "Battleship", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BattleshipClass: public Ui_BattleshipClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTLESHIP_H
