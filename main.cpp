#include "price_proj_qt.h"
#include <QtWidgets/QApplication>
#include <qtextcodec.h>
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");
    QApplication a(argc, argv);
    price_proj_qt w;
    w.show();
    return a.exec();
}
