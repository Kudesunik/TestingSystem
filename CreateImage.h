#ifndef _CREATEIMAGE_H
#define	_CREATEIMAGE_H

#include "ui_CreateImage.h"

class CreateImage : public QDialog {
    Q_OBJECT
public:
    CreateImage();
    int getRows();
    int getColumns();
    int getCellSize();
    std::string getMarks();
    std::string getFileName();
    virtual ~CreateImage();
private:
    Ui::CreateImage widget;
    inline bool isNumber(const std::string &str);
};

#endif
