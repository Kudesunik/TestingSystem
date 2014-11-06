#include <QApplication>
#include "TestingSystem.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    
    TestingSystem form;
    form.show();

    return app.exec();
}
