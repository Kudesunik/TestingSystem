/********************************************************************************
** Form generated from reading UI file 'CreateImage.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEIMAGE_H
#define UI_CREATEIMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_CreateImage
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *columnsNumber;
    QLineEdit *rowsNumber;
    QLineEdit *ansString;
    QLabel *label_4;
    QLineEdit *cellSize;
    QLabel *label_5;
    QLineEdit *fileName;

    void setupUi(QDialog *CreateImage)
    {
        if (CreateImage->objectName().isEmpty())
            CreateImage->setObjectName(QStringLiteral("CreateImage"));
        CreateImage->setWindowModality(Qt::NonModal);
        CreateImage->resize(315, 278);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateImage->sizePolicy().hasHeightForWidth());
        CreateImage->setSizePolicy(sizePolicy);
        CreateImage->setMinimumSize(QSize(315, 250));
        CreateImage->setMaximumSize(QSize(315, 25000));
        CreateImage->setModal(false);
        buttonBox = new QDialogButtonBox(CreateImage);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(70, 240, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(CreateImage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 141, 31));
        label_2 = new QLabel(CreateImage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 141, 31));
        label_3 = new QLabel(CreateImage);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 80, 171, 41));
        columnsNumber = new QLineEdit(CreateImage);
        columnsNumber->setObjectName(QStringLiteral("columnsNumber"));
        columnsNumber->setGeometry(QRect(150, 49, 151, 31));
        rowsNumber = new QLineEdit(CreateImage);
        rowsNumber->setObjectName(QStringLiteral("rowsNumber"));
        rowsNumber->setGeometry(QRect(150, 10, 151, 31));
        ansString = new QLineEdit(CreateImage);
        ansString->setObjectName(QStringLiteral("ansString"));
        ansString->setGeometry(QRect(10, 120, 301, 31));
        label_4 = new QLabel(CreateImage);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 160, 121, 31));
        cellSize = new QLineEdit(CreateImage);
        cellSize->setObjectName(QStringLiteral("cellSize"));
        cellSize->setGeometry(QRect(130, 160, 171, 31));
        label_5 = new QLabel(CreateImage);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 200, 121, 31));
        fileName = new QLineEdit(CreateImage);
        fileName->setObjectName(QStringLiteral("fileName"));
        fileName->setGeometry(QRect(130, 200, 171, 31));

        retranslateUi(CreateImage);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateImage, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateImage, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateImage);
    } // setupUi

    void retranslateUi(QDialog *CreateImage)
    {
        CreateImage->setWindowTitle(QApplication::translate("CreateImage", "Create Image", 0));
        label->setText(QApplication::translate("CreateImage", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\321\202\321\200\320\276\320\272:", 0));
        label_2->setText(QApplication::translate("CreateImage", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\321\202\320\276\320\273\320\261\321\206\320\276\320\262:", 0));
        label_3->setText(QApplication::translate("CreateImage", "\320\236\321\202\320\262\320\265\321\202\321\213:", 0));
        label_4->setText(QApplication::translate("CreateImage", "\320\240\320\260\320\267\320\274\320\265\321\200\321\213 \321\217\321\207\320\265\320\271\320\272\320\270:", 0));
        cellSize->setText(QApplication::translate("CreateImage", "5", 0));
        label_5->setText(QApplication::translate("CreateImage", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260:", 0));
        fileName->setText(QApplication::translate("CreateImage", "unnamed", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateImage: public Ui_CreateImage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEIMAGE_H
