#include "TestingSystem.h"
#include "PNGConverter.h"
#include "CreateImage.h"
#include <QFileDialog>
#include <QDialog>
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
    QObject::connect(widget.createImageMenu, SIGNAL(triggered()), this, SLOT(createImage()));
    QObject::connect(widget.loadedImageButton, SIGNAL(clicked()), this, SLOT(showLoadedImage()));
    QObject::connect(widget.digitalImageButton, SIGNAL(clicked()), this, SLOT(showBinaryImage()));
    QObject::connect(widget.recognizeButton, SIGNAL(clicked()), this, SLOT(recognize()));
}

void TestingSystem::createImage() {
    logger -> debug("[Create image] Start creating image...");
    CreateImage createImage;
    int createResult = createImage.exec();
    switch (createResult) {
        case QDialog::Rejected:
            logger -> debug("[Create image] Cancelled");
            break;
        case QDialog::Accepted:
            writeImage(createImage.getRows(), createImage.getColumns(), 
                       createImage.getCellSize(), createImage.getMarks(),
                       createImage.getFileName());
            break;
    }
    createImage.deleteLater();
    logger -> debug("[Create image] Done!");
}

void TestingSystem::writeImage(const int &rows, const int &columns, 
                               const int &cellSize, const std::string &ans, 
                               std::string fileName) {
    
    logger -> debug("[Write image] Start...");
    
    this -> fileName = "";
    this -> pbmFileName = "";
    widget.loadedImageButton -> setEnabled(false);
    
    int w, h;
    
    clearTImage();
    
    char *s = strtok((char*)ans.c_str(), " ");
    
    imgStruct.mx = cellSize * columns - columns + 1;
    imgStruct.my = cellSize * rows - rows + 1;
    
    for (h = 0; h < imgStruct.my; h++) {
        for (w = 0; w < imgStruct.mx; w++) {
            if (h % (cellSize - 1) == 0 || w % (cellSize - 1) == 0) {
                imgStruct.img[h][w] = 1;
            }
        }
    }
    
    h = 0;
    
    int cellSizeM = cellSize - 1;
    int wi, hi, wir; //width inner, height inner, width inner reverse
    
    while (s != NULL) {
            for (w = 0; w < imgStruct.mx; w += cellSizeM) {
                if (w == ((atoi(s) - 1) * cellSizeM)) {
                    wi = 0;
                    wir = cellSizeM;
                    for (hi = 0; hi < cellSize; hi++) {
                        imgStruct.img[h + hi][w + wi] = 1;
                        imgStruct.img[h + hi][w + wir] = 1;
                        wi++; wir--;
                    }
                }
            }
        h += cellSizeM;
        s = strtok(NULL, " ");
    }
    
    if (fileName.compare("")) {
        this -> pbmFileName = fileName.append(".pbm");
    }
    else {
        this -> pbmFileName = "unnamed.pbm";
    }
    
    qgs -> setSceneRect(qgs -> sceneRect());
    
    widget.pictureView -> setScene(qgs);
    
    writeToPBM();
    
    showImage(this -> pbmFileName);
    
    widget.digitalImageButton -> setEnabled(true);
    widget.recognizeButton -> setEnabled(true);
    
    logger -> debug("[Write image] Done!");
}

void TestingSystem::loadImage() {
    logger -> debug("[Loading image] Start...");
    
    widget.loadedImageButton -> setEnabled(false);
    widget.digitalImageButton -> setEnabled(false);
    
    QString fileName = QFileDialog::getOpenFileName(
            this,
            tr("Открыть файл"),
            "",
            tr("Изображения (*.png *.pbm)"));
    
    qgs -> setSceneRect(qgs -> sceneRect());
    widget.pictureView -> setScene(qgs);
    (this -> fileName) = fileName.toStdString();
    
    showImage(this -> fileName);
    
    std::string compareStr = ((this -> fileName)
            .substr((this -> fileName).find_last_of(".") + 1, (this -> fileName).length() - 1));
    
    if (!compareStr.compare("png")) {
        logger -> debug("[Loading image] PNG file detected");
        widget.loadedImageButton -> setEnabled(true);
    }
    
    if (!compareStr.compare("pbm")) {
        logger -> debug("[Loading image] PBM file detected");
        
        readFromPBM();
        
        (this -> pbmFileName) = fileName.toStdString();
        widget.digitalImageButton -> setEnabled(true);
        
        std::string fileEx = (this -> pbmFileName)
                .substr(0, (this -> pbmFileName).find_last_of("."))
                .append(".png");
        
        if (fileExists(fileEx)) {
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
    showImage(fileName);
}

void TestingSystem::showBinaryImage() {
    showImage(pbmFileName);
}

void TestingSystem::showImage(const std::string &filename) {
    logger -> debug("[Show image] Showing image...");
    qpm.load(QString::fromUtf8(filename.c_str()));
    qpm = qpm.scaledToHeight(widget.pictureView -> height() - 10);
    qpm = qpm.scaledToWidth(widget.pictureView -> width() - 10);
    qgs -> clear();
    qgs -> addPixmap(qpm);
    logger -> debug("[Show image] Done!");
}

void TestingSystem::recognize() {
    logger -> debug("[Recognize] Start recognizing");
    converter -> convert(fileName);
    writeToPBM();
    widget.digitalImageButton -> setEnabled(true);
    showBinaryImage();
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

void TestingSystem::readFromPBM() {
    logger -> debug("[Read PBM to structure file] Start reading...");

    std::ifstream pbmFile(fileName.c_str());

    std::string str;
    
    int w, h;

    if (pbmFile.is_open()) {
        std::getline(pbmFile, str);
        if (!str.compare("P1")) {
            std::getline(pbmFile, str);
            char *s = strtok(const_cast<char*>(str.c_str()), " ");
            imgStruct.mx = atoi(s);
            s = strtok(NULL, " ");
            imgStruct.my = atoi(s);
            
            for (h = 0; h < imgStruct.my; h++) {
                std::getline(pbmFile, str);
                if (str != "") {
                    char *s = strtok(const_cast<char*> (str.c_str()), " ");
                    for (w = 0; w < imgStruct.my; w++) {
                        imgStruct.img[h][w] = atoi(s);
                        s = strtok(NULL, " ");
                    }
                }
                else {
                    logger -> critical("[Read PBM to structure file] File format and image size mismatched");
                }
            }
            
        } else {
            logger -> critical("[Read PBM to structure file] Invalid file format");
        }
        pbmFile.close();
    }
    
    logger -> debug("[Read PBM to structure file] Done!");
}

void TestingSystem::writeToPBM() {
    logger -> debug("[Write structure to PBM file] Start writing...");
    
    std::ofstream pbmFile;
    
    if (pbmFileName == "") {
        pbmFileName = fileName.substr(0, fileName.find_last_of(".")).append(".pbm");
    }
    
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
    
    pbmFile.close();
    
    logger -> debug("[Write structure to PBM file] Done!");
}

inline bool TestingSystem::fileExists(const std::string &fileName) {
    std::ifstream file(fileName.c_str());
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
