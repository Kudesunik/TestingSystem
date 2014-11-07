#ifndef _TESTINGSYSTEM_H
#define	_TESTINGSYSTEM_H

#include "ui_TestingSystem.h"

class TestingSystem : public QMainWindow {
    Q_OBJECT
public:
    TestingSystem();
    
    static QMessageLogger* logger;
    
    typedef struct TImage {
        int img[1000][1000];
        int mx;
        int my;
    } TImage;
    
    virtual ~TestingSystem();
    
public slots:
    void loadImage();
    void showLoadedImage();
    void recognize();
    void exit();
    
private:
    void setupGUI();
    Ui::TestingSystem widget;
    QGraphicsScene* qgs;
    QPixmap qpm;
    std::string filename;
};

#endif
