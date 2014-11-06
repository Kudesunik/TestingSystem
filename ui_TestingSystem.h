/********************************************************************************
** Form generated from reading UI file 'TestingSystem.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTINGSYSTEM_H
#define UI_TESTINGSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestingSystem
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TestingSystem)
    {
        if (TestingSystem->objectName().isEmpty())
            TestingSystem->setObjectName(QStringLiteral("TestingSystem"));
        TestingSystem->resize(800, 600);
        centralwidget = new QWidget(TestingSystem);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        TestingSystem->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestingSystem);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        TestingSystem->setMenuBar(menubar);
        statusbar = new QStatusBar(TestingSystem);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestingSystem->setStatusBar(statusbar);

        retranslateUi(TestingSystem);

        QMetaObject::connectSlotsByName(TestingSystem);
    } // setupUi

    void retranslateUi(QMainWindow *TestingSystem)
    {
        TestingSystem->setWindowTitle(QApplication::translate("TestingSystem", "TestingSystem", 0));
    } // retranslateUi

};

namespace Ui {
    class TestingSystem: public Ui_TestingSystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTINGSYSTEM_H
