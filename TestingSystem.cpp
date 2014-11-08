#include "TestingSystem.h"
#include "PNGConverter.h"
#include <QFileDialog>
#include <iostream>
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
    QObject::connect(widget.recognizeButton, SIGNAL(clicked()), this, SLOT(recognize()));
}

/**
 * TODO: add resize listener
 */
void TestingSystem::loadImage() {
    logger -> debug("[Loading image] Start...");
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть файл"), "", tr("PNG (*.*)"));
    qgs -> setSceneRect(qgs -> sceneRect());
    widget.pictureView -> setScene(qgs);
    widget.loadedImageButton -> setEnabled(true);
    filename = fileName.toStdString();
    logger -> debug("[Loading image] Filename writed: %s", filename.c_str());
    showLoadedImage();
    widget.loadedImageButton -> setEnabled(true);
    widget.recognizeButton -> setEnabled(true);
    logger -> debug("[Loading image] Done!");
}

void TestingSystem::showLoadedImage() {
    logger -> debug("[Show image] Showing image");
    qpm.load(QString::fromUtf8(filename.c_str()));
    qpm = qpm.scaledToHeight(widget.pictureView -> height());
    qpm = qpm.scaledToWidth(widget.pictureView -> width());
    qgs -> addPixmap(qpm);
    logger -> debug("[Show image] Done!");
}

void TestingSystem::recognize() {
    logger -> debug("[Recognize] Start recognizing");
    converter -> convert(filename);
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
    int h, w;
    
    imgStruct.mx = mx;
    imgStruct.my = my;
    
    for (h = 0; h < my; h++) {
        for (w = 0; w < mx; w++) {
            imgStruct.img[h][w] = img[h * (mx - 1) + h + w];
        }
    }
}

TestingSystem::~TestingSystem() {
    delete(logger);
    delete(converter);
    delete(qgs);
}
