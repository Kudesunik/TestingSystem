#include "PNGConverter.h"

PNGConverter::PNGConverter() {}

void PNGConverter::resize(int *mid, int height, int width, int *counter) {
    int *buf = new int[height * width + height + width];
    int midInt = 0;
    int n = 0;
    for (int h = 0; h < (height - 1); h += 2) {
        for (int w = 0; w < (width - 1); w += 2) {
            midInt = 0;
            midInt += mid[h * (width - 1) + h + w];
            midInt += mid[h * (width - 1) + h + w + 1];
            midInt += mid[(h + 1) * (width - 1) + h + w + 1];
            midInt += mid[(h + 1) * (width - 1) + h + w + 2];
            if (midInt >= 1) {
                buf[n] = 1;
            } else {
                buf[n] = 0;
            }
            n++;
        }
    }
    
    (*counter)++;
    for (int i = 0; i < n; i++) {
        mid[i] = buf[i];
    }
    if (n > 100000) {
        resize(mid, (height / 2), (width / 2), counter);
    }
    
    delete(buf);
}

void PNGConverter::convert(std::string filename) {
    
    std::vector<unsigned char> image;
    
    unsigned pWidth, pHeight;
    
    unsigned error = lodepng::decode(image, pWidth, pHeight, filename.c_str());
    
    if (error) {
        TestingSystem::logger -> debug("Decoder error");
    }
    
    unsigned int heightIter, widthIter, rgbaIter, data = 0, n = 0;
    
    int *mid = new int[pHeight * pWidth + pHeight + pWidth];
    
    for (heightIter = 0; heightIter < pHeight; heightIter++) {
        widthIter = 0;
        for (widthIter = 0; widthIter < pWidth; widthIter++) {
            data = 0; rgbaIter = 0;
            for (rgbaIter = 0; rgbaIter < 3; rgbaIter++) {
                data += (int)image[(((pWidth - 1) * heightIter + heightIter + widthIter) * 4) + rgbaIter];
            }
            if (data > 320) {
                mid[n] = 0;
            }
            else {
                mid[n] = 1;
            }
            n++;
        }
    }
    
    int counter = 1;
    
    resize(mid, pHeight, pWidth, &counter);
    
    n = 0;
    
    pHeight = (pHeight / (2 << (counter - 2)));
    pWidth = (pWidth / (2 << (counter - 2)));
    
    TestingSystem::fillTImageStruct(mid, (int) pWidth, (int) pHeight);
    
    delete(mid);
}

PNGConverter::~PNGConverter() {}
