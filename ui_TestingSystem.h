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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestingSystem
{
public:
    QAction *openImageMenu;
    QAction *exitMenu;
    QAction *saveParamMenu;
    QAction *openResultsMenu;
    QAction *saveMenu;
    QAction *saveAsMenu;
    QAction *recognitionParamMenu;
    QAction *addTestMenu;
    QAction *aboutMenu;
    QAction *watchTestsMenu;
    QAction *addGroupMenu;
    QAction *addStudentMenu;
    QAction *watchGroupMenu;
    QAction *printMenu;
    QAction *action;
    QWidget *centralwidget;
    QGraphicsView *pictureView;
    QPushButton *digitalImageButton;
    QPushButton *loadedImageButton;
    QPushButton *recognizedImageButton;
    QPushButton *recognizeButton;
    QFrame *line;
    QLabel *label;
    QLabel *label_2;
    QLabel *rowsNumLabel;
    QFrame *line_2;
    QLabel *columnsNumLabel;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QFrame *line_3;
    QLabel *groupNumLabel;
    QLabel *studentNumLabel;
    QLabel *testNumLabel;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *totalQuestionsLabel;
    QLabel *correctAnswersLabel;
    QLabel *markLabel;
    QFrame *line_4;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TestingSystem)
    {
        if (TestingSystem->objectName().isEmpty())
            TestingSystem->setObjectName(QStringLiteral("TestingSystem"));
        TestingSystem->resize(800, 600);
        openImageMenu = new QAction(TestingSystem);
        openImageMenu->setObjectName(QStringLiteral("openImageMenu"));
        openImageMenu->setEnabled(true);
        openImageMenu->setVisible(true);
        exitMenu = new QAction(TestingSystem);
        exitMenu->setObjectName(QStringLiteral("exitMenu"));
        exitMenu->setEnabled(true);
        saveParamMenu = new QAction(TestingSystem);
        saveParamMenu->setObjectName(QStringLiteral("saveParamMenu"));
        saveParamMenu->setEnabled(false);
        openResultsMenu = new QAction(TestingSystem);
        openResultsMenu->setObjectName(QStringLiteral("openResultsMenu"));
        openResultsMenu->setEnabled(false);
        saveMenu = new QAction(TestingSystem);
        saveMenu->setObjectName(QStringLiteral("saveMenu"));
        saveMenu->setEnabled(false);
        saveAsMenu = new QAction(TestingSystem);
        saveAsMenu->setObjectName(QStringLiteral("saveAsMenu"));
        saveAsMenu->setEnabled(false);
        recognitionParamMenu = new QAction(TestingSystem);
        recognitionParamMenu->setObjectName(QStringLiteral("recognitionParamMenu"));
        recognitionParamMenu->setEnabled(false);
        addTestMenu = new QAction(TestingSystem);
        addTestMenu->setObjectName(QStringLiteral("addTestMenu"));
        addTestMenu->setEnabled(false);
        aboutMenu = new QAction(TestingSystem);
        aboutMenu->setObjectName(QStringLiteral("aboutMenu"));
        aboutMenu->setEnabled(false);
        watchTestsMenu = new QAction(TestingSystem);
        watchTestsMenu->setObjectName(QStringLiteral("watchTestsMenu"));
        watchTestsMenu->setEnabled(false);
        addGroupMenu = new QAction(TestingSystem);
        addGroupMenu->setObjectName(QStringLiteral("addGroupMenu"));
        addGroupMenu->setEnabled(false);
        addStudentMenu = new QAction(TestingSystem);
        addStudentMenu->setObjectName(QStringLiteral("addStudentMenu"));
        addStudentMenu->setEnabled(false);
        watchGroupMenu = new QAction(TestingSystem);
        watchGroupMenu->setObjectName(QStringLiteral("watchGroupMenu"));
        watchGroupMenu->setEnabled(false);
        printMenu = new QAction(TestingSystem);
        printMenu->setObjectName(QStringLiteral("printMenu"));
        printMenu->setEnabled(false);
        action = new QAction(TestingSystem);
        action->setObjectName(QStringLiteral("action"));
        action->setEnabled(false);
        centralwidget = new QWidget(TestingSystem);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pictureView = new QGraphicsView(centralwidget);
        pictureView->setObjectName(QStringLiteral("pictureView"));
        pictureView->setGeometry(QRect(10, 10, 411, 511));
        digitalImageButton = new QPushButton(centralwidget);
        digitalImageButton->setObjectName(QStringLiteral("digitalImageButton"));
        digitalImageButton->setEnabled(false);
        digitalImageButton->setGeometry(QRect(150, 530, 131, 23));
        loadedImageButton = new QPushButton(centralwidget);
        loadedImageButton->setObjectName(QStringLiteral("loadedImageButton"));
        loadedImageButton->setEnabled(false);
        loadedImageButton->setGeometry(QRect(10, 530, 131, 23));
        recognizedImageButton = new QPushButton(centralwidget);
        recognizedImageButton->setObjectName(QStringLiteral("recognizedImageButton"));
        recognizedImageButton->setEnabled(false);
        recognizedImageButton->setGeometry(QRect(290, 530, 131, 23));
        recognizeButton = new QPushButton(centralwidget);
        recognizeButton->setObjectName(QStringLiteral("recognizeButton"));
        recognizeButton->setEnabled(false);
        recognizeButton->setGeometry(QRect(440, 530, 351, 23));
        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(420, 0, 21, 561));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(440, 10, 111, 21));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(440, 40, 111, 21));
        label_2->setFont(font);
        rowsNumLabel = new QLabel(centralwidget);
        rowsNumLabel->setObjectName(QStringLiteral("rowsNumLabel"));
        rowsNumLabel->setGeometry(QRect(570, 10, 111, 21));
        rowsNumLabel->setFont(font);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(430, 61, 371, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        columnsNumLabel = new QLabel(centralwidget);
        columnsNumLabel->setObjectName(QStringLiteral("columnsNumLabel"));
        columnsNumLabel->setGeometry(QRect(570, 40, 111, 21));
        columnsNumLabel->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(440, 80, 111, 21));
        label_5->setFont(font);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(440, 110, 111, 21));
        label_6->setFont(font);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(440, 140, 111, 21));
        label_7->setFont(font);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(430, 161, 371, 21));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        groupNumLabel = new QLabel(centralwidget);
        groupNumLabel->setObjectName(QStringLiteral("groupNumLabel"));
        groupNumLabel->setGeometry(QRect(570, 80, 111, 21));
        groupNumLabel->setFont(font);
        studentNumLabel = new QLabel(centralwidget);
        studentNumLabel->setObjectName(QStringLiteral("studentNumLabel"));
        studentNumLabel->setGeometry(QRect(570, 110, 111, 21));
        studentNumLabel->setFont(font);
        testNumLabel = new QLabel(centralwidget);
        testNumLabel->setObjectName(QStringLiteral("testNumLabel"));
        testNumLabel->setGeometry(QRect(570, 140, 111, 21));
        testNumLabel->setFont(font);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(440, 180, 111, 21));
        label_8->setFont(font);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(440, 210, 111, 21));
        label_9->setFont(font);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(440, 240, 111, 21));
        label_10->setFont(font);
        totalQuestionsLabel = new QLabel(centralwidget);
        totalQuestionsLabel->setObjectName(QStringLiteral("totalQuestionsLabel"));
        totalQuestionsLabel->setGeometry(QRect(570, 180, 111, 21));
        totalQuestionsLabel->setFont(font);
        correctAnswersLabel = new QLabel(centralwidget);
        correctAnswersLabel->setObjectName(QStringLiteral("correctAnswersLabel"));
        correctAnswersLabel->setGeometry(QRect(570, 210, 111, 21));
        correctAnswersLabel->setFont(font);
        markLabel = new QLabel(centralwidget);
        markLabel->setObjectName(QStringLiteral("markLabel"));
        markLabel->setGeometry(QRect(570, 240, 111, 21));
        markLabel->setFont(font);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(430, 260, 371, 21));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        TestingSystem->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestingSystem);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        TestingSystem->setMenuBar(menubar);
        statusbar = new QStatusBar(TestingSystem);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TestingSystem->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu->addAction(openImageMenu);
        menu->addAction(action);
        menu->addAction(openResultsMenu);
        menu->addSeparator();
        menu->addAction(saveMenu);
        menu->addAction(saveAsMenu);
        menu->addSeparator();
        menu->addAction(printMenu);
        menu->addSeparator();
        menu->addAction(exitMenu);
        menu_3->addAction(addTestMenu);
        menu_3->addAction(addGroupMenu);
        menu_3->addAction(addStudentMenu);
        menu_3->addAction(watchTestsMenu);
        menu_3->addAction(watchGroupMenu);
        menu_4->addAction(aboutMenu);

        retranslateUi(TestingSystem);

        QMetaObject::connectSlotsByName(TestingSystem);
    } // setupUi

    void retranslateUi(QMainWindow *TestingSystem)
    {
        TestingSystem->setWindowTitle(QApplication::translate("TestingSystem", "TestingSystem", 0));
        openImageMenu->setText(QApplication::translate("TestingSystem", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265...", 0));
        exitMenu->setText(QApplication::translate("TestingSystem", "\320\222\321\213\321\205\320\276\320\264", 0));
        saveParamMenu->setText(QApplication::translate("TestingSystem", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217", 0));
        openResultsMenu->setText(QApplication::translate("TestingSystem", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213...", 0));
        saveMenu->setText(QApplication::translate("TestingSystem", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        saveAsMenu->setText(QApplication::translate("TestingSystem", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", 0));
        recognitionParamMenu->setText(QApplication::translate("TestingSystem", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\200\320\260\321\201\320\277\320\276\320\267\320\275\320\260\320\262\320\260\320\275\320\270\321\217", 0));
        addTestMenu->setText(QApplication::translate("TestingSystem", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\265\321\201\321\202...", 0));
        aboutMenu->setText(QApplication::translate("TestingSystem", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0));
        watchTestsMenu->setText(QApplication::translate("TestingSystem", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\264\320\276\321\201\321\202\321\203\320\277\320\275\321\213\320\265 \321\202\320\265\321\201\321\202\321\213", 0));
        addGroupMenu->setText(QApplication::translate("TestingSystem", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\263\321\200\321\203\320\277\320\277\321\203...", 0));
        addStudentMenu->setText(QApplication::translate("TestingSystem", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260...", 0));
        watchGroupMenu->setText(QApplication::translate("TestingSystem", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\264\320\276\321\201\321\202\321\203\320\277\320\275\321\213\320\265 \320\263\321\200\321\203\320\277\320\277\321\213", 0));
        printMenu->setText(QApplication::translate("TestingSystem", "\320\237\320\265\321\207\320\260\321\202\321\214...", 0));
        action->setText(QApplication::translate("TestingSystem", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", 0));
        digitalImageButton->setText(QApplication::translate("TestingSystem", "\320\246\320\270\321\204\321\200\320\276\320\262\320\276\320\271", 0));
        loadedImageButton->setText(QApplication::translate("TestingSystem", "\320\227\320\260\320\263\321\200\321\203\320\266\320\265\320\275\320\275\321\213\320\271", 0));
        recognizedImageButton->setText(QApplication::translate("TestingSystem", "\320\240\320\260\321\201\320\277\320\276\320\267\320\275\320\260\320\275\320\275\321\213\320\271", 0));
        recognizeButton->setText(QApplication::translate("TestingSystem", "\320\240\320\260\321\201\320\277\320\276\320\267\320\275\320\260\321\202\321\214", 0));
        label->setText(QApplication::translate("TestingSystem", "\320\247\320\270\321\201\320\273\320\276 \321\201\321\202\321\200\320\276\320\272:", 0));
        label_2->setText(QApplication::translate("TestingSystem", "\320\247\320\270\321\201\320\273\320\276 \321\201\321\202\320\276\320\273\320\261\321\206\320\276\320\262:", 0));
        rowsNumLabel->setText(QApplication::translate("TestingSystem", "\320\235\320\265\321\200\320\260\321\201\320\277\320\276\320\267\320\275\320\260\320\275\320\276", 0));
        columnsNumLabel->setText(QApplication::translate("TestingSystem", "\320\235\320\265\321\200\320\260\321\201\320\277\320\276\320\267\320\275\320\260\320\275\320\276", 0));
        label_5->setText(QApplication::translate("TestingSystem", "\320\223\321\200\321\203\320\277\320\277\320\260 \342\204\226", 0));
        label_6->setText(QApplication::translate("TestingSystem", "\320\241\321\202\321\203\320\264\320\265\320\275\321\202 \342\204\226", 0));
        label_7->setText(QApplication::translate("TestingSystem", "\320\242\320\265\321\201\321\202 \342\204\226", 0));
        groupNumLabel->setText(QApplication::translate("TestingSystem", "\320\235\320\265\321\200\320\260\321\201\320\277\320\276\320\267\320\275\320\260\320\275\320\276", 0));
        studentNumLabel->setText(QApplication::translate("TestingSystem", "\320\235\320\265\321\200\320\260\321\201\320\277\320\276\320\267\320\275\320\260\320\275\320\276", 0));
        testNumLabel->setText(QApplication::translate("TestingSystem", "\320\235\320\265\321\200\320\260\321\201\320\277\320\276\320\267\320\275\320\260\320\275\320\276", 0));
        label_8->setText(QApplication::translate("TestingSystem", "\320\222\321\201\320\265\320\263\320\276 \320\262\320\276\320\277\321\200\320\276\321\201\320\276\320\262:", 0));
        label_9->setText(QApplication::translate("TestingSystem", "\320\237\321\200\320\260\320\262. \320\276\321\202\320\262\320\265\321\202\320\276\320\262:", 0));
        label_10->setText(QApplication::translate("TestingSystem", "\320\236\321\206\320\265\320\275\320\272\320\260:", 0));
        totalQuestionsLabel->setText(QApplication::translate("TestingSystem", "\320\235\320\265\321\200\320\260\321\201\320\277\320\276\320\267\320\275\320\260\320\275\320\276", 0));
        correctAnswersLabel->setText(QApplication::translate("TestingSystem", "\320\235\320\265\321\200\320\260\321\201\320\277\320\276\320\267\320\275\320\260\320\275\320\276", 0));
        markLabel->setText(QApplication::translate("TestingSystem", "\320\235\320\265\321\200\320\260\321\201\320\277\320\276\320\267\320\275\320\260\320\275\320\276", 0));
        menu->setTitle(QApplication::translate("TestingSystem", "\320\244\320\260\320\271\320\273", 0));
        menu_3->setTitle(QApplication::translate("TestingSystem", "\320\242\320\265\321\201\321\202\321\213 \320\270 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\321\213", 0));
        menu_4->setTitle(QApplication::translate("TestingSystem", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class TestingSystem: public Ui_TestingSystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTINGSYSTEM_H
