#ifndef STYLE_H
#define STYLE_H
#include "qfile.h"
#include "qapplication.h"
class CommonHelper
{
public:
    static void setStyle(const QString &style) {
        QFile qss(style);
        qss.open(QFile::ReadOnly);
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }
};
#endif // STYLE_H
