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
    setupGUI();
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
    qgs = new QGraphicsScene(widget.pictureView);
    qgs -> setSceneRect(qgs -> sceneRect());
    widget.pictureView -> setScene(qgs);
    qpm = *(new QPixmap());
    widget.loadedImageButton -> setEnabled(true);
    filename = fileName.toStdString();
    logger -> debug("[Loading image] Filename writed: %s", filename.c_str());
    showLoadedImage();
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
    
}

void TestingSystem::exit() {
    logger -> debug("Exiting program. Bye!");
    QCoreApplication::quit();
}

TestingSystem::~TestingSystem() {
    
}
