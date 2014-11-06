#ifndef _TESTINGSYSTEM_H
#define	_TESTINGSYSTEM_H

#include "ui_TestingSystem.h"

class TestingSystem : public QMainWindow {
    Q_OBJECT
public:
    TestingSystem();
    virtual ~TestingSystem();
private:
    Ui::TestingSystem widget;
};

#endif
