#include "CreateImage.h"

CreateImage::CreateImage() {
    widget.setupUi(this);
}

int CreateImage::getRows() {
    std::string rows = widget.rowsNumber -> text().toStdString();
    if (isNumber(rows)) {
        return atoi(rows.c_str());
    }
    return 5;
}

int CreateImage::getColumns() {
    std::string columns = widget.columnsNumber -> text().toStdString();
    if (isNumber(columns)) {
        return atoi(columns.c_str());
    }
    return 5;
}

int CreateImage::getCellSize() {
    std::string cellSize = widget.cellSize -> text().toStdString();
    if (isNumber(cellSize)) {
        return atoi(cellSize.c_str());
    }
    return 5;
}

std::string CreateImage::getMarks() {
    return widget.ansString -> text().toStdString();
}

std::string CreateImage::getFileName() {
    return widget.fileName -> text().toStdString();
}

inline bool CreateImage::isNumber(const std::string &str) {
    std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it)) ++it;
    return !str.empty() && it == str.end();
}

CreateImage::~CreateImage() {}
