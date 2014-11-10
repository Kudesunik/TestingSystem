#ifndef _TESTINGSYSTEM_H
#define	_TESTINGSYSTEM_H

#include "ui_TestingSystem.h"

class TestingSystem : public QMainWindow {
    Q_OBJECT
public:
    TestingSystem();
    
    static void fillTImageStruct(int *img, int mx, int my);
    
    static QMessageLogger *logger;
    
    typedef struct {
        int img[1000][1000];
        int mx;
        int my;
    } TImage;
    
    virtual ~TestingSystem();
    
public slots:
    void loadImage();
    void showLoadedImage();
    void showBinaryImage();
    void recognize();
    void exit();
    
private:
    void setupGUI();
    void clearTImage();
    void writeToPBM();
    void showImage(std::string *fileName);
    inline bool fileExists (std::string *fileName);
    Ui::TestingSystem widget;
    QGraphicsScene *qgs;
    QPixmap qpm;
    std::string fileName;
    std::string pbmFileName;
};

#endif
