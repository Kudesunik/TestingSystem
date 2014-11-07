#ifndef PNGCONVERTER_H
#define	PNGCONVERTER_H

#include "LodePNG.h"
#include "TestingSystem.h"

#include <iostream>
#include <cstdlib>
#include <fstream>

class PNGConverter {
public:
    PNGConverter();
    void convert(std::string filename, TestingSystem::TImage *img);
    virtual ~PNGConverter();
private:
    std::ofstream pbmFile;
    void resize(int *mid, int height, int width, int *counter);
};

#endif
