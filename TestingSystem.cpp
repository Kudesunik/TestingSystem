#include "TestingSystem.h"
#include "PNGConverter.h"
#include <QFileDialog>
#include <iostream>
#include <fstream>
#include <math.h>

TestingSystem::TImage imgStruct;

QMessageLogger *TestingSystem::logger = new QMessageLogger();
PNGConverter *converter = new PNGConverter();

TestingSystem::TestingSystem() {
    widget.setupUi(this);
    clearTImage();
    qgs = new QGraphicsScene(widget.pictureView);
    setupGUI();
}

void TestingSystem::clearTImage() {
    int h, w;
    
    imgStruct.mx = 0;
    imgStruct.my = 0;
    
    for (h = 0; h < 1000; h++) {
        for (w = 0; w < 1000; w++) {
            imgStruct.img[h][w] = 0;
        }
    }
}

void TestingSystem::setupGUI() {
    QObject::connect(widget.exitMenu, SIGNAL(triggered()), this, SLOT(exit()));
    QObject::connect(widget.openImageMenu, SIGNAL(triggered()), this, SLOT(loadImage()));
    QObject::connect(widget.loadedImageButton, SIGNAL(clicked()), this, SLOT(showLoadedImage()));
    QObject::connect(widget.digitalImageButton, SIGNAL(clicked()), this, SLOT(showBinaryImage()));
    QObject::connect(widget.recognizeButton, SIGNAL(clicked()), this, SLOT(recognize()));
}

/**
 * TODO: add resize listener
 */
void TestingSystem::loadImage() {
    logger -> debug("[Loading image] Start...");
    
    widget.loadedImageButton -> setEnabled(false);
    widget.digitalImageButton -> setEnabled(false);
    
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть файл"), "", tr("Изображения (*.png *.pbm)"));
    qgs -> setSceneRect(qgs -> sceneRect());
    widget.pictureView -> setScene(qgs);
    (this -> fileName) = fileName.toStdString();
    
    showImage(&(this -> fileName));
    
    std::string compareStr = ((this -> fileName).substr((this -> fileName).find_last_of(".") + 1, (this -> fileName).length() - 1));
    
    if (!compareStr.compare("png")) {
        logger -> debug("[Loading image] PNG file detected");
        widget.loadedImageButton -> setEnabled(true);
    }
    
    if (!compareStr.compare("pbm")) {
        logger -> debug("[Loading image] PBM file detected");
        (this -> pbmFileName) = fileName.toStdString();
        widget.digitalImageButton -> setEnabled(true);
        
        std::string fileEx = (this -> pbmFileName).substr(0, (this -> pbmFileName).find_last_of(".")).append(".png");
        
        logger -> debug("%s", fileEx.c_str());
        
        if (fileExists(&fileEx)) {
            (this -> fileName) = fileEx;
            widget.loadedImageButton -> setEnabled(true);
        }
        else {
            (this -> fileName) = "";
        }
    }
    
    widget.recognizeButton -> setEnabled(true);
    logger -> debug("[Loading image] Done!");
}

void TestingSystem::showLoadedImage() {
    showImage(&fileName);
}

void TestingSystem::showBinaryImage() {
    showImage(&pbmFileName);
}

void TestingSystem::showImage(std::string *filename) {
    logger -> debug("[Show image] Showing image...");
    qpm.load(QString::fromUtf8((*filename).c_str()));
    qpm = qpm.scaledToHeight(widget.pictureView -> height());
    qpm = qpm.scaledToWidth(widget.pictureView -> width());
    qgs -> addPixmap(qpm);
    logger -> debug("[Show image] Done!");
}

void TestingSystem::recognize() {
    logger -> debug("[Recognize] Start recognizing");
    if (!pbmFileName.compare("")) {
        converter -> convert(fileName);
        writeToPBM();
    }
    widget.digitalImageButton -> setEnabled(true);
    logger -> debug("[Recognize] Done!");
}

void TestingSystem::exit() {
    logger -> debug("Exiting program. Bye!");
    QCoreApplication::quit();
}

/**
 * Looks like I can't create static structure...
 * So, I can use this method to fill it from another class.
 * BTW: Multi-dimensional arrays are evil!
 * @param img
 * @param mx
 * @param my
 */
void TestingSystem::fillTImageStruct(int *img, int mx, int my) {
    logger -> debug("[Fill TImage Structure] Start filling...");
    int h, w;
    
    imgStruct.mx = mx;
    imgStruct.my = my;
    
    for (h = 0; h < my; h++) {
        for (w = 0; w < mx; w++) {
            imgStruct.img[h][w] = img[h * (mx - 1) + h + w];
        }
    }
    logger -> debug("[Fill TImage Structure] Done!");
}

void TestingSystem::writeToPBM() {
    logger -> debug("[Write structure to PBM file] Start writing...");
    
    std::ofstream pbmFile;
    
    pbmFileName = fileName.substr(0, fileName.find_last_of(".")).append(".pbm");
    pbmFile.open(pbmFileName.c_str());
    
    pbmFile << "P1" << std::endl;
    pbmFile << (imgStruct.mx) << " ";
    pbmFile << (imgStruct.my) << std::endl;
    
    int h, w;
    
    for (h = 0; h < (imgStruct.my); h++) {
        for (w = 0; w < (imgStruct.mx); w++) {
            pbmFile << (imgStruct.img)[h][w] << " ";
        }
        pbmFile << "\n";
    }
    logger -> debug("[Write structure to PBM file] Done!");
}

inline bool TestingSystem::fileExists(std::string *fileName) {
    std::ifstream file((*fileName).c_str());
    if (file.good()) {
        file.close();
        return true;
    } else {
        file.close();
        return false;
    }   
}

TestingSystem::~TestingSystem() {
    delete(logger);
    delete(converter);
    delete(qgs);
}
