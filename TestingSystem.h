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
    void createImage();
    void recognize();
    void exit();
    
private:
    void setupGUI();
    void clearTImage();
    void readFromPBM();
    void writeToPBM();
    
    void writeImage(const int &rows,
            const int &columns,
            const int &cellSize,
            const std::string &ans,
            std::string fileName);
    
    void showImage(const std::string &fileName);
    inline bool fileExists (const std::string &fileName);
    Ui::TestingSystem widget;
    QGraphicsScene *qgs;
    QPixmap qpm;
    std::string fileName;
    std::string pbmFileName;
};

#endif
