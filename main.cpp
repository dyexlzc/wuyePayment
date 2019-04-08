#include "mainwindow.h"
#include <QtWidgets/qapplication.h>
#include<qapplication.h>
#include<qdesktopwidget.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
